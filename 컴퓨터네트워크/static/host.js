'use strict';

var video = document.querySelector('video');
var canvas = window.canvas = document.querySelector('canvas');
canvas.width = 480;
canvas.height = 360;

var button = document.getElementById('buttonCapture');
button.onclick = function() {
  canvas.width = video.videoWidth;
  canvas.height = video.videoHeight;
  canvas.getContext('2d').
    drawImage(video, 0, 0, canvas.width, canvas.height);
};

var edge_constraints = {
  video: true
};

var ff_constraints = {
   video: {
      mediaSource: "window"
    },
 };

function handleSuccess(stream) {
  window.stream = stream; 
  video.srcObject = stream;
}

function handleError(error) {
  console.log('navigator.getDisplayMedia error: ', error);
}

/*
if (typeof(RTCIceGatherer) !== "undefined"){
        navigator.getDisplayMedia(edge_constraints).
        then(handleSuccess).catch(handleError);
      } else if (typeof(navigator.mediaDevices.getDisplayMedia) !== "undefined"){
        navigator.mediaDevices.getDisplayMedia(edge_constraints).then(handleSuccess).catch(handleError); 
      } else {
        navigator.mediaDevices.getUserMedia(ff_constraints).
        then(handleSuccess).catch(handleError);
}
*/

if (typeof(navigator.mediaDevices.getDisplayMedia) !== "undefined"){
  navigator.mediaDevices.getDisplayMedia(edge_constraints).then(handleSuccess).catch(handleError)
}