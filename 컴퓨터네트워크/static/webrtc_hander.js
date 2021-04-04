let socket = io.connect();

const stunServerConfig = {  
    iceServers: [{  
      url: "192.168.0.8:3000",  
      username: "user1",  
      credential: "123123"  
    }]  
  };

navigator.mediaDevices.getUserMedia({
    video: {
        mediaSource : "screen",
        width : { max : '1920'},
        height : { max : '1080'},
        framerate : {max : '10'}
        }
}).then(gotMedia);


let initiateBtn = document.getElementById('initiateBtn')
let initiator = false;

function aonclick(e) {
    initiator = true;
    socket.emit('initiate');
}



function gotMedia(stream) {
    let peer;
    if(initiator) {
        peer = new Peer({
            initiator,
            stream,
            config : stunServerConfig
        });
    } else {
        peer = new Peer({
            config : stunServerConfig
        });
    }
    peer.on('signal', function(data) {
        socket.emit('offer', JSON.stringify(data));
    });

    var video = document.querySelector('video');  
    video.srcObject = stream;  
    video.play();

        
    socket.on('offer', (data) => {  
        peer.signal(JSON.parse(data))  
    });
}



peer.on('stream', function (stream) {  
    // got remote video stream, now let's show it in a video tag  
    var video = document.querySelector('video');  
    video.srcObject = stream;  
    video.play();  
  })