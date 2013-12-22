
var flagNewSetPoint;
function TimeEndSteamBathHour(){
	flagNewSetPoint=1;
	var checkText=document.getElementById("TimeEndSteamBathHour").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 20) {

		ui.sp.TimeEndSteamBathHour = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
	}
	else
	{
		document.getElementById("TimeEndSteamBathHour").value = 0;
		this.FlagNewSP=0;
	}
}

function TimeEndSteamBathMin(){
	flagNewSetPoint=1;
	var checkText=document.getElementById("TimeEndSteamBathMin").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 60) {

		ui.sp.TimeEndSteamBathMin = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
	}
	else
	{
		document.getElementById("TimeEndSteamBathMin").value = 0;
		this.FlagNewSP=0;
	}
}


function inputSetTimeSalt(){
	flagNewSetPoint=1;
	var checkText=document.getElementById("inputSetTimeSalt").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 120) {

		ui.sp.inputSetTimeSalt = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
	}
	else
	{
		document.getElementById("inputSetTimeSalt").value = "";
		this.FlagNewSP=0;
	}

}

function CheckInputSetPointTempSteamBath()
{
	flagNewSetPoint=1;
	var checkText=document.getElementById("inputSetPointTempSteamBath").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 120) {

		ui.sp.TempSetPointSteamBath = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
	}
	else
	{
		document.getElementById("inputSetPointTempSteamBath").value = "";
		this.FlagNewSP=0;
	}

}

function CheckInputSetPointTempSteamBathBenchL()
{
	flagNewSetPoint=1;
	var checkText=document.getElementById("inputSetPointTempSteamBathBenchL").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 120) {

		ui.sp.TempBenchSetPoint = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
		

	}
	else
	{
		document.getElementById("inputSetPointTempSteamBathBenchL").value = "";
		this.FlagNewSP=0;
	}

}
function CheckInputSetPointTempSteamBathBenchR()
{
	flagNewSetPoint=1;
	var checkText=document.getElementById("inputSetPointTempSteamBathBenchR").value;
	if (parseInt(checkText, 10) > 0   && parseInt(checkText, 10) < 120) {

		ui.sp.TempBenchSetPoint = parseInt(checkText, 10);
		var str = ui.prepareForRpi();
		

	}
	else
	{
		document.getElementById("inputSetPointTempSteamBathBenchR").value = "";
		this.FlagNewSP=0;
	}

}


UIData.prototype.SetRGBValues = function(newValue)
{
	flagNewSetPoint=1;
	if (newValue >= 0 && newValue < 255) {
		this.sp.r = 255;
		this.sp.g = newValue;
		this.sp.b = 0;
	} else if (newValue >= 255 && newValue < 510) {
		this.sp.r = 510 - newValue;
		this.sp.g = 255;
		this.sp.b = 0;
	} else if (newValue >= 510 && newValue < 765) {
		this.sp.r = 0;
		this.sp.g = 255;
		this.sp.b = newValue - 510;
	} else if (newValue >= 765 && newValue < 1020) {
		this.sp.r = 0;
		this.sp.g = 1020 - newValue;
		this.sp.b = 255;
	} else if (newValue >= 1020 && newValue < 1275) {
		this.sp.r = newValue - 1020;
		this.sp.g = 0;
		this.sp.b = 255;
	} else if (newValue >= 1275) {
		this.sp.r = 255;
		this.sp.g = 0;
		this.sp.b = 1530 - newValue;
	}
	ui.prepareForRpi();
	this.sp.rgb = newValue;
	this.UpdateUI();
}



UIData.prototype.SetBrightnessValue = function(newValue)
{
	newValue = parseInt (newValue, 10);
	if (newValue >= 0 && newValue <=255)

		flagNewSetPoint=1;
	
		this.sp.brightness = parseInt (newValue, 10);
		ui.prepareForRpi();
	this.UpdateUI();
}

UIData.prototype.SetMainlightValue = function(newValue)
{
	newValue = parseInt (newValue, 10);
	flagNewSetPoint=1;
	if (newValue >= 0 && newValue <=255)
		this.FlagNewSP=1;
		this.sp.mainLight = newValue;
		ui.prepareForRpi();
	this.UpdateUI();
}

UIData.prototype.SetTmerSaltValue = function(newValue)
{
	flagNewSetPoint=1;
	if (newValue >= 0 && newValue <=255)
		this.sp.timerSalt= newValue;
	this.UpdateUI();
}

UIData.prototype.SetRGB = function()
{

	flagNewSetPoint=1;
		this.sp.rgbOnOff = (this.sp.rgbOnOff) ? 0:1;

		this.prepareForRpi();
	this.UpdateUI();
}

UIData.prototype.SetMixRGB = function()
{
	flagNewSetPoint=1;
		this.sp.rgbMixOnOff = (this.sp.rgbMixOnOff) ? 0:1;

		this.prepareForRpi();
	this.UpdateUI();
}





UIData.prototype.SetMainLight = function(newValue)
{

	
	flagNewSetPoint=1;

		this.sp.mainLightOnOff = (this.sp.mainLightOnOff) ? 0:1;
		this.prepareForRpi();
		

	this.UpdateUI();
	
	
	
	
}


UIData.prototype.SetBench = function()
{
	flagNewSetPoint=1;

		this.sp.bench = (this.sp.bench) ? 0:1;

		this.prepareForRpi();
	this.UpdateUI();
}

UIData.prototype.SetFontain = function()
{
	flagNewSetPoint=1;

		this.sp.fontain = (this.sp.fontain) ? 0:1;
		this.prepareForRpi();
		

	this.UpdateUI();
}

UIData.prototype.SteamBathOn = function()
{
	flagNewSetPoint=1;

		this.sp.SteamBathOn = (this.sp.SteamBathOn) ? 0:1;
		this.sp.bench = this.sp.SteamBathOn;
		this.sp.rgbOnOff = this.sp.SteamBathOn;
		this.sp.mainLightOnOff = this.sp.SteamBathOn;
		this.sp.fontain = this.sp.SteamBathOn;

	this.prepareForRpi();
	this.UpdateUI();

}




function SetFlagNewSetPoint() {
	ui.FlagNewSP = 1;
	flagNewSetPoint=1;
}



function UIData()
{
	// Setpoints
	this.sp = new UISetpoints();
	// Process values
	this.pv = new UIProcessValues();
	this.FlagNewSP = 0;


	UIData.prototype.SetPV = function(vals)
	{
//		for (i=0; i<16; i++)
//		{
//		this.pv.inputs[i] = vals[i];
//		this.pv.ouputs[i] = vals[i+16];
//		}
//		this.pv.Humidity = vals[32];
//		this.pv.Temp = vals[33];
//		this.pv.r = vals[34];
//		this.pv.g = vals[35];
//		this.pv.b = vals[36];
//		this.pv.brightness = vals[37];
//		this.pv.MainLightValue = vals[38];
//		this.pv.SaltTime = vals[39];
//		this.pv.MainLightOnOff = vals[40];
//		this.pv.RGBOnOff = vals[41];

	}

	UIData.prototype.UpdateUI = function()
	{
		if (flagNewSetPoint==0){
	
		document.getElementsByClassName("TempPV")[0].innerText = this.pv.MeasureTempSteamBath;
		document.getElementsByClassName("TempPV")[0].innerText = this.pv.MeasureTempSteamBath;
		document.getElementsByClassName("TempPV")[1].innerText = this.pv.MeasureTempSteamBath;
		//document.getElementsByClassName("HumidityPV")[0].innerText = this.pv.Humidity;
		document.getElementsByClassName("TempSP")[0].innerText = this.sp.SetPointTempSteamBath;
		document.getElementById("inputSetPointTempSteamBath").value = this.sp.TempSetPointSteamBath;
		document.getElementById("EffectColor").value = this.sp.rgb;
		document.getElementById("EffectBright").value = this.sp.brightness;
		document.getElementById("MainBright").value = this.sp.mainLight;
		document.getElementById("EffectOnOff").innerText = (this.sp.rgbOnOff) ? "ON": "OFF";
		document.getElementById("MainLightOnOff").innerText = (this.sp.mainLightOnOff) ? "ON": "OFF";
		document.getElementsByClassName("BenchOnOff")[0].innerText = (this.sp.bench) ? "ON": "OFF";
		document.getElementsByClassName("BenchOnOff")[1].innerText = (this.sp.bench) ? "ON": "OFF";
		document.getElementById("FontainOnOff").innerText = (this.sp.fontain) ? "ON": "OFF";
		document.getElementById("SteamBathOn").src = (this.sp.SteamBathOn) ? "Pic/Stop_Button.png": "Pic/Start_Button.png";
		document.getElementsByClassName("FountainDiv")[0].style.visibility = (this.sp.fontain) ? "visible" : "hidden";
		document.getElementsByClassName("MainLightsLight")[0].style.visibility = (this.sp.mainLightOnOff) ? "visible" : "hidden";
		document.getElementsByClassName("MainLightsLight")[1].style.visibility = (this.sp.mainLightOnOff) ? "visible" : "hidden";
		document.getElementsByClassName("SeatLight")[0].style.visibility = (this.sp.bench) ? "visible" : "hidden";
		document.getElementsByClassName("Steam")[0].style.visibility = (this.sp.SteamBathOn) ? "visible" : "hidden";
		document.getElementsByClassName("Steam")[1].style.visibility = (this.sp.SteamBathOn) ? "visible" : "hidden";
		document.body.style.background = 'rgb('+this.sp.r+','+this.sp.g+','+this.sp.b+')';
		document.getElementById("attention").style.visibility = (this.pv.alarmTemp4SteamBath || this.pv.alarmSupplySteamBathHeater) ? "visible" : "hidden";
		document.getElementById("TimeLeftSteamBathMin").innerText = this.pv.TimeLeftSteamBathMin;
		document.getElementById("TimeLeftSteamBathHour").innerText = this.pv.TimeLeftSteamBathHour;
		
		document.getElementById("S_PumpSalt").style.visibility = (this.pv.S_PumpSalt) ? "visible" : "hidden";
		
		
		
		document.getElementById("inputSetPointTempSteamBathBenchR").value = this.sp.TempBenchSetPoint;
		document.getElementById("inputSetPointTempSteamBathBenchL").value = this.sp.TempBenchSetPoint;
		document.getElementById("MeasureTempSteamBathBenchL").innerText = this.pv.MeasureTempBenchSteamBath;
		document.getElementById("MeasureTempSteamBathBenchR").innerText = this.pv.MeasureTempBenchSteamBath;
		document.getElementById("EffectMixOnOff").innerText = (this.sp.rgbMixOnOff) ? "Mix ON": "Mix OFF";
		
		document.getElementById("inputSetTimeSalt").value = this.sp.inputSetTimeSalt;
		document.getElementById("TimeEndSteamBathMin").value = this.sp.TimeEndSteamBathMin;
		document.getElementById("TimeEndSteamBathHour").value = this.sp.TimeEndSteamBathHour;
		

		}
		


	}

	UIData.prototype.spLoadFromJson = function(jsonText)
	{
		var rcv = eval( '(' + jsonText + ')');
		this.sp.load(rcv.Digital, rcv.Analog);
		this.UpdateUI();
	}

	UIData.prototype.prepareForRpi = function() 
	{
//		this.sp.Temp = document.getElementById("inputSetPointTempSteamBath").value;
		console.log("ll:" + this.sp.prepare());
		doSend(this.sp.prepare());
		flagNewSetPoint = 0;
		return(this.sp.prepare());
	}

	UIData.prototype.pvLoadFromJson = function(jsonText)
	{
		var rcv = eval( '(' + jsonText + ')');
//		this.pv = 
		this.pv.load(rcv.Digital, rcv.Analog);
		this.UpdateUI();
	}

}

function UISetpoints()
{


	this.bench = 0;
	this.TempSetPointSteamBath = 0;
	this.fontain = 0;	
	this.mainLightOnOff = 0;
	this.SteamBathOn = 0;
	this.rgbOnOff = 0;
	this.steam = 0;
	this.rgbMixOnOff = 0;
	this.r = 0; 
	this.g = 0;
	this.b = 0;
	this.brightness = 0;
	this.TempSetPointSteamBath = 0;
	this.mainLight = 0; 
	this.TempBenchSetPoint = 0;
	this.inputSetTimeSalt = 0; 
	this.TimeEndSteamBathMin = 0;
	this.TimeEndSteamBathHour = 0;

	UISetpoints.prototype.load = function(digital, analog) {

		this.SteamBathOn = digital[0];
		this.bench = digital[1];
		this.fontain = digital[2];
		this.mainLightOnOff = digital[3];
		this.rgbOnOff = digital[5];
		this.rgbMixOnOff = digital[4];
		
		this.TempSetPointSteamBath = analog[0];	
		this.TempBenchSetPoint = analog[1];	
		this.r = analog[2]; 
		this.g = analog[3];
		this.b = analog[4];	
		this.brightness = analog[5];	
		this.mainLight = analog[6]; 
		this.TimeEndSteamBathHour = analog[7];
		this.TimeEndSteamBathMin = analog[8];
		this.inputSetTimeSalt = analog[9]; 







	}
	UISetpoints.prototype.prepare = function() {
		function snd() {
			this.Digital = new Array();
			for (var i=0; i<48; i++) this.Digital[i] = 0;
			this.Analog = new Array();
			for (var i=0; i<42; i++) this.Analog[i] = 0;
		}
		var send = new snd();
		
		send.Digital[0] = this.SteamBathOn;
		send.Digital[1] = this.bench;
		send.Digital[2] = this.fontain;
		send.Digital[3] = this.mainLightOnOff;
		send.Digital[5] = this.rgbOnOff;
		send.Digital[4] = this.rgbMixOnOff;
		
		
		
		send.Analog[0] = this.TempSetPointSteamBath;		
		send.Analog[1] = this.TempBenchSetPoint;	
		send.Analog[2] = this.r;
		send.Analog[3] = this.g;
		send.Analog[4] = this.b;	
		send.Analog[5] = this.brightness;
		send.Analog[6] = this.mainLight;
		send.Analog[7] = this.TimeEndSteamBathHour;
		send.Analog[8] = this.TimeEndSteamBathMin;
		send.Analog[9] = this.inputSetTimeSalt

		

		



		
		
		return JSON.stringify(send);
	}
}

function UIProcessValues()
{

	this.MeasureTempSteamBath=0;

	this.alarmTemp4SteamBath = 0;
	this.alarmSupplySteamBathHeater = 0;
	this.MeasureTempBenchSteamBath = 0;
	this.TimeLeftSteamBathHour = 0;
	this.TimeLeftSteamBathMin = 0;
	this.S_PumpSalt = 0;
	

	UIProcessValues.prototype.load = function(digital, analog) {
		
		this.MeasureTempSteamBath = analog[42];
		this.MeasureTempBenchSteamBath = analog[43];
		this.TimeLeftSteamBathHour = analog[44];
		this.TimeLeftSteamBathMin = analog[45];
		
		this.alarmTemp0 = digital[44];
		this.alarmTemp1 = digital[45];
		this.alarmTemp2 = digital[46];
		this.alarmTemp3 = digital[47];
		this.alarmTemp4SteamBath = digital[48];
		this.alarmTemp5 = digital[49];
		
		this.alarmSupplySteamBathHeater = digital[56];
		this.S_PumpSalt = digital[80];


	}
}
