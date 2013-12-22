var wsUri = "ws://192.168.2.98:9001/";
var output; 
var websocket;

function init()
{
//	output = document.getElementById("output");
	testWebSocket();
}
function testWebSocket()
{
	websocket = new WebSocket(wsUri, "user-interface");
	websocket.onopen = function(evt) { onOpen(evt) };
	websocket.onclose = function(evt) { onClose(evt) };
	websocket.onmessage = function(evt) { onMessage(evt) };
	websocket.onerror = function(evt) { onError(evt) };
}

function onOpen(evt)
{
//	writeToScreen("CONNECTED");
//	doSend("WebSocket rocks");
}

function onClose(evt)
{
//	writeToScreen("DISCONNECTED");
}

function onMessage(evt)
{
//	writeToScreen('<span style="color: blue;">RESPONSE: ' + evt.data+'</span>');
//	websocket.close();
	console.log(evt.data);
	ui.pvLoadFromJson(evt.data);
	ui.spLoadFromJson(evt.data);
}

function onError(evt)
{
//	writeToScreen('<span style="color: red;">ERROR:</span> ' + evt.data);
}

function doSend(message)
{
//	writeToScreen("SENT: " + message);
	console.log(message);
	websocket.send(message);
	ui.FlagNewSP = 0;
}

function writeToScreen(message)
{
	var pre = document.createElement("p");
	pre.style.wordWrap = "break-word";
	pre.innerHTML = message;
	output.appendChild(pre);
}

//init();

window.addEventListener("load", init, false); 