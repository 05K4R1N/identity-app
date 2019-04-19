const http = require('http');
const express = require('express');
const socketIO = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketIO.listen(server);

app.use(express.static(__dirname + '/public'))
server.listen(3000, function(){
	console.log("SERVIDOR  escuchabndo en el puerto 3000");
});

const Serialport = require('serialport');
const Readline = Serialport.parsers.Readline;

const port = new Serialport('/dev/ttyACM0', {
	baudRate: 9600
});

const parser = port.pipe(new Readline({delimiter: '\r\n'}));

parser.on('open', function(){
	console.log("conexion establecida");
});

parser.on('data', function(data){
	console.log(parseInt(data) + " Latidos por minuto");
});

port.on('error', function(){
	console.log(err);
});