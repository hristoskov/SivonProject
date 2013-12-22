/*
 * main.cpp
 *
 *  Created on: 12.10.2013
 *      Author: Hristo
 */


#include <iostream>
#include "SerialComm/SerialComm.h"
#include "WebSocket/WebSocket.h"
#include "Lib/json/json.h"
#include "Lib/json/block_allocator.h"
#include <string.h>
#include <string>
#include <algorithm>
#include "UIControl/UIControl.h"


int main(void)
{

	SerialComm * com = SerialComm::getInstance();
	UIControl ui;
	WebSocket ws;
	ws.ui = &ui;
	ws.com = com;

	//----------------------- daemonize

//    /* Our process ID and Session ID */
//    pid_t pid, sid;
//
//    /* Fork off the parent process */
//    pid = fork();
//    if (pid < 0) {
//            exit(EXIT_FAILURE);
//    }
//    /* If we got a good PID, then
//       we can exit the parent process. */
//    if (pid > 0) {
//            exit(EXIT_SUCCESS);
//    }
//
//    /* Change the file mode mask */
//    umask(0);
//
//    /* Open any logs here */
//
//    /* Create a new SID for the child process */
//    sid = setsid();
//    if (sid < 0) {
//            /* Log the failure */
//            exit(EXIT_FAILURE);
//    }
//
//
//
//    /* Change the current working directory */
//    if ((chdir("/")) < 0) {
//            /* Log the failure */
//            exit(EXIT_FAILURE);
//    }
//
//    /* Close out the standard file descriptors */
//    close(STDIN_FILENO);
//    close(STDOUT_FILENO);
//    close(STDERR_FILENO);

	//---------------------- daemonize

	//	json_value *val;

//	//	unsigned char buff[1024];
//
//	union {
//		unsigned char buff[1024];
//		short buffS[512];
//	} ff;
//
//	int len;

//	com.ReadData();
//	com.SendData();
//	len = com.GetData(ff.buff);

//	printf("Red %d bytes\n", len);
//	for (int i=0; i<len/2; i++)
//	{
//		printf("%d ", ff.buffS[i]);
//	}
//	fflush(stdout);

	std::string str;
//	char tmpSend[1024];
//	int k=0;
	while (true)
	{
		ws.RunService();
//		com.ReadData();

//		if (k>100) k=0;
//		sprintf(tmpSend, tmp, k++, k);

		sVarsIn serial_inputs;
		com->GetInputs(&serial_inputs);
//		std::cout << sizeof (sMapIn) << std::endl;
		str = ui.FormatSendData(&serial_inputs);

//		sVarsOut serial_outputs;
//		ui.ReadData(str);


		ws.SendBroadcast(str);
	}

	return 0;
}
