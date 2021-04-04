var express = require('express');
let app = express();
var server = require('http').createServer(app);
// http server를 socket.io server로 upgrade한다
var io = require('socket.io')(server);

app.use(express.static('./static'));

// namespace /chat에 접속한다.
let canvas_data;  //canvas에 대한 정보를 전달하기 위한 변수

var select = io.of('/select').on('connection', function(socket){
    console.log('host');

    socket.on('draw', function(data) {
        var room = socket.room = data.room;
        canvas_data = data.canvas_data;

        socket.join(room);

        
    });


});

var chat = io.of('/room').on('connection', function(socket) {
  socket.on('room', function(data){
    console.log(room);

    var room = socket.room = data.room;

    // room에 join한다
    socket.join(room);
    // room에 join되어 있는 클라이언트에게 메시지를 전송한다
  });

  socket.on('draw', function(canvas){
    canvas_data = canvas;
});

socket.on('get_canvas', function(data) {
    console.log('get_canvas');
    socket.emit('get_canvas', canvas_data);
})


});

server.listen(3000, function() {
  console.log('Socket IO server listening on port 3000');
});