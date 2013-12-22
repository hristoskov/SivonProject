
function open_winMain1() {
	window.location="main1.html";
}


function openSaunaSetings(){
	document.getElementById("elementSaunaArchive").style.visibility = "hidden";
	document.getElementById("elementSaunaSetings").style.visibility = "visible";

	
	hideSaunaElements();
}
function closeSaunaSetings(){
	document.getElementById("elementSaunaSetings").style.visibility = "hidden";
	document.getElementById("elementSaunaArchive").style.visibility = "hidden";
}
closeSaunaSetings();

function openSaunaArchive(){
	document.getElementById("elementSaunaSetings").style.visibility = "hidden";
	document.getElementById("elementSaunaArchive").style.visibility = "visible";
	
}






var timerSauna;
function hideSaunaElements()
{

	

	document.getElementById("elementSaunaButonSetings").style.visibility = "hidden";
	
	document.getElementById("elementSaunaMainLights").style.visibility = "hidden";
	document.getElementById("elementSaunaEffectLights").style.visibility = "hidden";
	document.getElementById("elementSaunaEffectLightsSlider").style.visibility = "hidden";
	document.getElementById("elementSaunaLeftTime").style.visibility = "hidden";

	clearInterval(timerSauna);
}

function showSaunaElements()
{
	clearInterval(timerSauna);

	
	document.getElementById("elementSaunaButonSetings").style.visibility = "visible";

	document.getElementById("elementSaunaMainLights").style.visibility = "visible";
	document.getElementById("elementSaunaEffectLights").style.visibility = "visible";
	document.getElementById("elementSaunaEffectLightsSlider").style.visibility = "visible";
	document.getElementById("elementSaunaLeftTime").style.visibility = "visible";

	
	timerSauna=setInterval(function(){hideSaunaElements()},20000);
}
hideSaunaElements();