
function open_winMain1() {
	window.location="main1.html";
}


function openSteamBathSetings(){
	document.getElementById("elementSteamBathArchive").style.visibility = "hidden";
	document.getElementById("elementSteamBathSetings").style.visibility = "visible";

	
	hideSteamBathElements();
}
function closeSteamBathSetings(){
	document.getElementById("elementSteamBathSetings").style.visibility = "hidden";
	document.getElementById("elementSteamBathArchive").style.visibility = "hidden";
}
//closeSteamBathSetings();

function openSteamBathaArchive(){
	document.getElementById("elementSteamBathSetings").style.visibility = "hidden";
	document.getElementById("elementSteamBathArchive").style.visibility = "visible";
	
}



var timerSteamBath;
function hideSteamBathElements()
{

	document.getElementById("elementSteamBathButonSetings").style.visibility = "hidden";
	
	document.getElementById("elementSteamBathMainLights").style.visibility = "hidden";
	document.getElementById("elementSteamBathEffectLights").style.visibility = "hidden";
	document.getElementById("elementSteamBathEffectLightsSlider").style.visibility = "hidden";
	document.getElementById("elementSteamBathLeftTime").style.visibility = "hidden";

	clearInterval(timerSteamBath);
}

function showSteamBathElements()
{
	clearInterval(timerSteamBath);
	
	document.getElementById("elementSteamBathButonSetings").style.visibility = "visible";

	document.getElementById("elementSteamBathMainLights").style.visibility = "visible";
	document.getElementById("elementSteamBathEffectLights").style.visibility = "visible";
	document.getElementById("elementSteamBathEffectLightsSlider").style.visibility = "visible";
	document.getElementById("elementSteamBathLeftTime").style.visibility = "visible";

	
	timerSteamBath=setInterval(function(){hideSteamBathElements()},3000);
}
hideSteamBathElements();