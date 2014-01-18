/*
 * SerialComm.cpp
 *
 *  Created on: 12.10.2013
 *      Author: Hristo
 */

#include "SerialComm.h"
#include <string.h>

SerialComm * SerialComm::_instance = NULL;
pthread_t SerialComm::threadPtr;
std::string SerialComm::uidata;

SerialComm::SerialComm() {
	memset(&VariablesIn, 0x00, sizeof(VariablesIn));
	memset(&VariablesOut, 0x00, sizeof(VariablesOut));
	VariablesIn.Buffer.len = 0;
	VariablesOut.Buffer.len = 0;
	port = "/dev/ttyAMA0";
	Connect();
	pthread_create(&threadPtr, NULL, SerialComm::Run, NULL);
//	pthread_join(threadPtr, NULL);
}

SerialComm::~SerialComm() {
	Disconnect();
}

void SerialComm::Connect() {
	fd = serialOpen(port.c_str(), 115200);
}

void SerialComm::Disconnect() {
	printf("disconnecting\n");
	serialClose(fd);
//	close(fd);
}

bool SerialComm::ReadData() {
//	printf("%d\n", sizeof(sMapIn));
	serialPrintf(fd, "r");
	delay(200);
	return ReadRAW();
}



void SerialComm::SendData() {
//	unsigned char dataOut[100];
	unsigned char CRC = 0;
//	printf("%d\n", sizeof(sMapOut));
//	memset(&VariablesOut, 0, sizeof(sVarsOut));

//	bufferOut.data.s16[5] = 0;
//	bufferOut.data.s16[6] = 4;
////	printf("%d", dataOut[5]);
//	bufferOut.data.s16[25] = 100;
	printf("%s\n", __FUNCTION__);
	unsigned char u8Retry=0;
//	do {
	serialPutchar(fd, 's');
	CRC = 's';
//	sMapOut *map = &VariablesOut.Names;
//	map->DelayBlower = 45;
//	map->SaunaDelayLight = 99;
//	map->Digital[0] = (1<<0);
//	map->O_Blower = 1;
	for (int i=0; i<90; i++)
	{
		CRC = VariablesOut.Buffer.u8[i]^CRC;
//		printf("%X %x", CRC, VariablesOut.Buffer.u8[i]);
		serialPutchar(fd, VariablesOut.Buffer.u8[i]);
//		printf("%d:%d ", i ,VariablesOut.Buffer.u8[i]);
	}
	printf("\nCRC:%X\n", CRC);
	serialPutchar(fd, CRC);
	for (int i=0; i<3; i++)
	{
//		printf("%d:%d ", i, VariablesOut.Names.Digital[i]);
	}
	for (int i=0; i<42; i++)
	{
//		printf("%d:%d ", i, VariablesOut.Names.Analog[i]);
	}
	for (int i=0; i<3; i++)
	{
		VariablesIn.Names.Digital[i] = VariablesOut.Names.Digital[i];
	}
	for (int i=0; i<42; i++)
	{
		VariablesIn.Names.Analog[i] = VariablesOut.Names.Analog[i];
	}
//	printf("\n");
//	serialPrintf(fd)
	delay(200);
//	u8Retry++;
//	} while ((u8Retry < 3)&&(false == ReadRAW()));
}

bool SerialComm::ReadRAW() {
//	printf("%s\n", __FUNCTION__);

	bool bReturn = false;
	sBuffer bufferIn; //= &VariablesIn.Buffer;
	unsigned char CRC = 0;
	int j=0;
	while (serialDataAvail(fd))
	{
		int ch = serialGetchar(fd);
//		printf("%d:%X ", j, ch);
		bufferIn.u8[j++] = (unsigned char) ch;
		//CRC ^= (unsigned char) ch;
	}
//	printf("\n");
	for (int i=0; i<(j-1); i++)
	{
		CRC ^= bufferIn.u8[i];
	}
//	printf("%s::Red %d bytes\n", __FUNCTION__, j);
	if ((bufferIn.u8[j-1]==CRC)&&(143==j)) {
		bufferIn.len = j;
		for (int i=0; i<j; i++)
		{
			VariablesIn.Buffer.u8[i] = bufferIn.u8[i];

		}
		for (int i=0; i<7; i++)
		{
//			printf("%d:%d ", i, VariablesIn.Names.Digital[i]);
		}
		for (int i=0; i<54; i++)
		{
//			printf("%d:%d ", i, VariablesIn.Names.Analog[i]);
		}
//		printf("\n");
		VariablesIn.Buffer.len = bufferIn.len;
		bReturn = true;
//		printf("%s::CRC %d\n", __FUNCTION__, CRC);
		printf("%s::Temp: %d\t%d\t%d\t%d\t%d\t%d\n", __FUNCTION__, VariablesIn.Names.Analog[41], VariablesIn.Names.Analog[42], VariablesIn.Names.Analog[43], VariablesIn.Names.Analog[44], VariablesIn.Names.Analog[45], VariablesIn.Names.Analog[46]);
		printf("%s::Analog: %d\t%d\t%d\t%d\t%d\t%d\n", __FUNCTION__, VariablesIn.Names.Analog[9], VariablesIn.Names.Analog[12], VariablesIn.Names.Analog[29], VariablesIn.Names.Analog[28], VariablesIn.Names.Analog[34], VariablesIn.Names.Analog[37]);
	}
	return bReturn;

}

void SerialComm::GetInputs(sVarsIn* inputs) {
	*inputs = VariablesIn;
}

int SerialComm::GetData(unsigned char* const data) {
//	for (int i=0; i<bufferIn.len; i++)
//	{
//		data[i] = bufferIn.data.u8[i];
//	}
//	return bufferIn.len;
	return 0;
}

void SerialComm::SetOutputs(sVarsOut* data) {
	VariablesOut = *data;
}

SerialComm * SerialComm::getInstance() {
	if (!_instance)
	{
		_instance = new SerialComm();
	}
	return _instance;
}

bool SerialComm::SetCommError(bool value) {
	VariablesIn.Names.bCommError = value;
}

void* SerialComm::Run(void* ptr) {

	int errCount = 0;
	if (_instance)
	while (true)
	{

		if (!_instance->ReadData())
		{
			if (errCount > 4)
			{
				_instance->SetCommError(true);
			}
			else
			{
				errCount++;
			}
		}
		else
		{
			errCount = 0;
		}
		delay(200);
	}
	return 0;
}
