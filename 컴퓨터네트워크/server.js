let express = require('express');

const app = express();
let fs = require('fs');
let https = require('https');

const options = {
	key: fs.readFileSync('./keys/private.pem'),
	cert: fs.readFileSync('./keys/public.pem')
};


let server = require('https').createServer(options ,app);



//서버를 socket IO 서버로 업그레이드 합니다.
let io = require('socket.io')(server)

app.use(express.static('./static'));

//캔버스에 대한 정보를 담을려는 변수 canvas_data
let canvas_data = new Array();

//좌표값들이 저장되어 있는 배열
let location = new Array();

//현재 생성되어있는 방들의 정보를 담고있는 배열
let cur_rooms = new Array();

//룸안에 몇명있는지 보여주는 배열
let room_cnt = new Array();

let room_cnt_num = 0;

let temp = new Array();

//socket io에 접속 했을때 connection 이벤트 핸들러
io.on('connect', function(socket){

    //인덱스 페이지에 현재 열려있는 방들의 정보를 알려주기 위한 함수
    socket.on("index", function(data) {
        //index페이지 접속을 전달 받으면 현재 열려있는 방들의 정보를 전달해줍니다
        console.log(room_cnt);
       
        socket.emit('index', {cur_rooms : cur_rooms, room_cnt : room_cnt});
        
    })


    // 접속한 클라이언트의 정보 수신
    socket.on('login', function(data){
  
        io.emit('login', data.name);

    });

    socket.on('chat', function(data) {

        //socket.broadcast.emit('chat', msg);         

        // 메시지를 전송한 클라이언트에게만 메시지를 전송한다
        // socket.emit('s2c chat', msg);

        // 접속된 모든 클라이언트에게 메시지를 전송한다
        io.emit('chat');

        // 특정 클라이언트에게만 메시지를 전송한다
        // io.to(id).emit('s2c chat', data);
    });

    //호스트가 화면을 공유할때 실행되는 함수입니다.
    socket.on('draw', function(data){

        let room = data.room;

        //입력 받은 방을 서버에 저장합니다
        cur_rooms.push(data.room);

        //해당 방에대한 사진을 저장합니다.
        canvas_data[room] = data.canvas;

        socket.room = room;

        //룸의 정보를 담습니다
        temp[room] = room_cnt_num;
        
        room_cnt[room_cnt_num] = 1;

        room_cnt_num++;

        //방의 location에 대한 새로운 배열을 생성합니다.
        location[room] = new Array();
        location[room].push({x : 1, y : 1});

        

        console.log('create room : ' + room);
        io.to(room).emit('get_canvas', {location : location[room], canvas : data.canvas});
    });

    //화면 변경 요청시
    socket.on('change', function(data) {
        let room = data.room;

        canvas_data[room] = data.canvas;
        console.log('change request : ' + room);

        io.to(room).emit('change', {location : location[room], canvas : canvas_data[room]});
    });

    //화면 공유 페이지
    socket.on('get_canvas', function(data) {
        console.log('get_canvas join ' + data.room);
        let room = socket.room = data.room;

        //열명이 넘을경우 
        if(room_cnt[temp[room]] > 10) {
            socket.emit('over');
            return ;
        }

        //룸 사람수 증가
        room_cnt[temp[room]]++;

        socket.join(room);
        socket.emit('get_canvas', { location : location[room], canvas_data : canvas_data[room]});
    })

    socket.on('send_location', function(data) {
        let room = data.room
        location[room].push({ x : data.x, y : data.y});
        socket.to(room).emit('send_location', {x : data.x, y : data.y});
    })

    socket.on('forceDisconnect', function() {
        socket.disconnect();
      })


    
    socket.on('disconnect', function() {
        console.log('user disconnected: ' + socket.room);
        let room = socket.room;
        //사람이 나갈경우 room - 1
        room_cnt[temp[room]]--;

    });

});


io.on('initiate', () => {
    io.emit('initiate');
})

io.on('offer', (data) => {  
    socket.broadcast.emit('offer', data);  
  });


server.listen(3000, function() {
    console.log('server running 3000')
});

