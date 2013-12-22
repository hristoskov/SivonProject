/*
 * WebSocket.h
 *
 *  Created on: 12.10.2013
 *      Author: Hristo
 */

#ifndef WEBSOCKET_H_
#define WEBSOCKET_H_

#include "../UIControl/UIControl.h"
#include "../Include/libwebsockets.h"
#include <stdio.h>
#include <string>
#include <list>
#include <iostream>


class WebSocket {
private:

	int port;
	char *interface;
	struct libwebsocket_context *context;
	char *cert_path;
	char *key_path;
	int opts;
	lws_context_creation_info * info;

	static std::list<libwebsocket *> ws;
	static libwebsocket * wsConnect;
public:
	WebSocket();
	virtual ~WebSocket();

	static UIControl * ui;
	static SerialComm * com;

	static int callback_http(struct libwebsocket_context *context,
			struct libwebsocket *wsi,
			enum libwebsocket_callback_reasons reason, void *user,
			void *in, size_t len);
	static int callback_user_interface(struct libwebsocket_context *context,
			struct libwebsocket *wsi,
			enum libwebsocket_callback_reasons reason, void *user,
			void *in, size_t len);

	void RunService();
	void SendBroadcast(std::string SendMsg);
};

#endif /* WEBSOCKET_H_ */
