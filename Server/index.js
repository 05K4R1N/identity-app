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
	console.log(data);
});

port.on('error', function(){
	console.log(err);
});