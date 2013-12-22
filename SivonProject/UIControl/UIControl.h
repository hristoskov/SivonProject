/*
 * UIControl.h
 *
 *  Created on: 13.10.2013
 *      Author: Hristo
 */

#ifndef UICONTROL_H_
#define UICONTROL_H_

#include "../Lib/json/json.h"
#include "../Lib/json/block_allocator.h"
//#include "../WebSocket/WebSocket.h"
#include "../SerialComm/SerialComm.h"

static std::string jsonText = "{'Digital': [sDigitalArray], 'Analog': [sAnalogArray] }";

class UIControl {
private:
//	const WebSocket *ws;
	sVarsOut vars;
public:
	UIControl();
	virtual ~UIControl();

	std::string FormatSendData(sVarsIn * data);
	void ParseData(std::string data);
	void ReadData(sVarsOut * const data);
};

#endif /* UICONTROL_H_ */
