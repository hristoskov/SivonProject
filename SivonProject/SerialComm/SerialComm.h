/*
 * SerialComm.h
 *
 *  Created on: 12.10.2013
 *      Author: Hristo
 */

#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include "../Include/wiringPi.h"
#include "../Include/wiringSerial.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <pthread.h>


union RxUnit {
	unsigned char u8[2];
	short s16;
};

struct sBuffer
{
	union {
		unsigned char u8[1024];
		short s16[512];
	};
	//	RxUnit data[512];
	int len;
};


/// @brief Map of the buffer sent to Arduino
struct sMapOut {
	union {
		unsigned short Digital[3];
		struct {
			struct {
				unsigned short O_HeaterSteam:1;
				unsigned short O_PumpAroma:1;
				unsigned short O_Blower:1;
				unsigned short O_Suction:1;
				unsigned short O_HeatBench:1;
				unsigned short O_Fountain:1;
				unsigned short O_SaunaPower:1;
				unsigned short O_SaunaHeater:1;
				unsigned short O_SaunaLight:1;
				unsigned short O_PumpSalt:1;
				unsigned short bReserved:3;
				unsigned short O_MVShower1:1;
				unsigned short O_MVShower2:1;
				unsigned short O_MVShower3:1;
			};
			struct {
				unsigned short O_MainLight:1;
				unsigned short O_SaunaEffectLight:1;
				unsigned short O_SteamBathEffectLight:1;
				unsigned short O_StartStemBath:1;
				unsigned short O_StopSteamBath:1;
				unsigned short O_StartSauna:1;
				unsigned short O_StopSauna:1;
				unsigned short bDummy:9;
			};
			unsigned short u16Dummy;
		};
	};
	union {
		short Analog[42];
		struct {
			short DelayHeaterSteam;
			short DelayPumpAroma;
			short DelayBlower;
			short DelaySuction;
			short DelayHeatBench;
			short DelayFountain;
			short SaunaDelayPower;
			short SaunaDelayHeater;
			short SaunaDelayLight;
			short DelayPumpSalt;
			short Reserved[3];
			short DelayMVShower[3];
			short SaunaEffectLightR;
			short SaunaEffectLightG;
			short SaunaEffectLightB;
			short SaunaEffectLightBrightness;
			short SteamBathEffectLightR;
			short SteamBathEffectLightG;
			short SteamBathEffectLightB;
			short SteamBathEffectLightBrightness;
			short MainLightBrightness;
			short Dummy1[5];
			short SP_TempSteamGenerator;
			short SP_TempBench;
			short SP_TempSauna;
			short SP_TempEmergency;
			short SP_TempReserved[2];
			short SP_RHumidity;
			short Dummy2[5];
		};
	};
};

/// @brief Map of the buffer received from Arduino
struct sMapIn {
	union {
		unsigned short Digital[7];
		struct {
			struct {
				unsigned short O_HeaterSteam:1;
				unsigned short O_PumpAroma:1;
				unsigned short O_Blower:1;
				unsigned short O_Suction:1;
				unsigned short O_HeatBench:1;
				unsigned short O_Fountain:1;
				unsigned short O_SaunaPower:1;
				unsigned short O_SaunaHeater:1;
				unsigned short O_SaunaLight:1;
				unsigned short O_PumpSalt:1;
				unsigned short bReserved1:3;
				unsigned short O_MVShower1:1;
				unsigned short O_MVShower2:1;
				unsigned short O_MVShower3:1;
			};
			struct {
				unsigned short O_MainLight:1;
				unsigned short O_SaunaEffectLight:1;
				unsigned short O_SteamBathEffectLight:1;
				unsigned short O_StartStemBath:1;
				unsigned short O_StopSteamBath:1;
				unsigned short O_StartSauna:1;
				unsigned short O_StopSauna:1;
				unsigned short bDummy1:9;
			};
			struct {
				unsigned short I_SteamGeneratorNO:1;
				unsigned short I_AlarmLowLevelNO:1;
				unsigned short I_AlarmHighLevelNO:1;
				unsigned short I_ThermalSteamGNO:1;
				unsigned short I_LevelAromaNC:1;
				unsigned short I_LevelSaltNO:1;
				unsigned short I_ButtonSaltNO:1;
				unsigned short I_PowerSaunaNO:1;
				unsigned short I_HeaterSaunaNO:1;
				unsigned short I_ThermalSauna:1;
				unsigned short I_PanicSteamBath:1;
				unsigned short I_PanicSauna:1;
				unsigned short I_ButtonShower1:1;
				unsigned short I_ButtonShower2:1;
				unsigned short I_ButtonShower3:1;
				unsigned short S_HeaterSteam:1;
			};
			struct {
				unsigned short S_PumpAroma:1;
				unsigned short S_Blower:1;
				unsigned short S_Suction:1;
				unsigned short S_HeatBench:1;
				unsigned short S_Fountain:1;
				unsigned short S_SaunaPower:1;
				unsigned short S_SaunaHeater:1;
				unsigned short S_SaunaLight:1;
				unsigned short S_PumpSalt:1;
				unsigned short bReserved2:3;
				unsigned short S_MVShower1:1;
				unsigned short S_MVShower2:1;
				unsigned short S_MVShower3:1;
				unsigned short S_MainLight:1;
			};
			struct {
				unsigned short S_SaunaEffectLight:1;
				unsigned short S_SteamBathEffectLight:1;
				unsigned short S_StartStemBath:1;
				unsigned short S_StopSteamBath:1;
				unsigned short S_StartSauna:1;
				unsigned short S_StopSauna:1;
				unsigned short bCommError:1;
				unsigned short bDummy2:9;
			};
			struct {
				unsigned short I_AlarmCabin:1;
				unsigned short I_AlarmBench:1;
				unsigned short I_AlarmSensorRH:1;
				unsigned short I_AlarmPowerSteamGen:1;
				unsigned short I_AlarmNoWater:1;
				unsigned short I_AlarmTankFull:1;
				unsigned short I_AlarmHeatSteamGen:1;
				unsigned short I_AlarmAromaLowLevel:1;
				unsigned short I_AlarmAromaHighLevel:1;
				unsigned short I_AlarmPanicSteamBath:1;
				unsigned short I_AlarmPanicSauna:1;
				unsigned short bDummy3:5;
			};
			unsigned short u16Dummy;
		};
	};
	union {
		short Analog[54];
		struct {
			short Dummy1[3];
			short DelayHeaterSteam;
			short DelayPumpAroma;
			short DelayBlower;
			short DelaySuction;
			short DelayHeatBench;
			short DelayFountain;
			short SaunaDelayPower;
			short SaunaDelayHeater;
			short SaunaDelayLight;
			short DelayPumpSalt;
			short Reserved[3];
			short DelayMVShower[3];
			short SaunaEffectLightR;
			short SaunaEffectLightG;
			short SaunaEffectLightB;
			short SaunaEffectLightBrightness;
			short SteamBathEffectLightR;
			short SteamBathEffectLightG;
			short SteamBathEffectLightB;
			short SteamBathEffectLightBrightness;
			short MainLightBrightness;
			short Dummy2[5];
			short SP_TempSteamGenerator;
			short SP_TempBench;
			short SP_TempSauna;
			short SP_TempEmergency;
			short SP_TempReserved[2];
			short SP_RHumidity;
			short Dummy3;
			short PV_TempSteamGenerator;
			short PV_TempBench;
			short PV_TempSauna;
			short PV_TempEmergency;
			short PV_TempReserved[2];
			short PV_RHumidity;
			short PV_RH_Reserved;
			short Dummy4[5];
		};
	};
};

union sVarsOut {
	sBuffer Buffer;
	sMapOut Names;
};

union sVarsIn {
	sBuffer Buffer;
	sMapIn Names;
};

class SerialComm {
private:
	static pthread_t threadPtr;
	static SerialComm * _instance;

	int fd;
	//	sBuffer bufferIn;
	//	sBuffer bufferOut;
	sVarsIn VariablesIn;
	sVarsOut VariablesOut;
	//	unsigned char bufferOut[1024];
	std::string port;
	void Connect();
	void Disconnect();
	bool ReadRAW();
	bool SetCommError(bool value);
protected:
	SerialComm();
public:
	static SerialComm * getInstance();
	virtual ~SerialComm();

	static std::string uidata;

	bool ReadData();
	void SendData();
	void GetInputs(sVarsIn *inputs);
	int GetData(unsigned char * const data);
//	void GetDataIn(sVarsIn *data);
	void SetOutputs(sVarsOut *data);
	static void * Run(void * ptr);
};

#endif /* SERIALCOMM_H_ */
