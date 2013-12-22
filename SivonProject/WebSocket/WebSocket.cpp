/*
 * WebSocket.cpp
 *
 *  Created on: 12.10.2013
 *      Author: Hristo
 */

#include "WebSocket.h"

UIControl * WebSocket::ui = NULL;
SerialComm * WebSocket::com = NULL;

static struct libwebsocket_protocols protocols[] = {
		/* first protocol must always be HTTP handler */
		{
				"http-only",   // name
				WebSocket::callback_http, // callback
				0              // per_session_data_size
		},
		{
				"user-interface", // protocol name - very important!
				WebSocket::callback_user_interface,   // callback
				0                          // we don't use any per session data
		},
		{
				NULL, NULL, 0   /* End of list */
		}
};

libwebsocket * WebSocket::wsConnect = NULL;
std::list<libwebsocket *> WebSocket::ws;

WebSocket::WebSocket()
{
	// server url will be http://localhost:7681
	port = 9001;
	interface = NULL;
	// we're not using ssl
	cert_path = NULL;
	key_path = NULL;
	// no special options
	opts = 0;
	info = new lws_context_creation_info;
	info->port = port;
	info->iface = interface;
	info->protocols = protocols;
	info->extensions = NULL;
	info->ssl_cert_filepath = cert_path;
	info->ssl_private_key_filepath  =key_path;
	info->ka_probes = -1;
	info->ka_time = -1;
	info->options = opts;

	// create libwebsocket context representing this server
	context = libwebsocket_create_context(info);

	if (context == NULL) {
		fprintf(stderr, "libwebsocket init failed\n");
	//	return -1;
	}
}

int WebSocket::callback_http(struct libwebsocket_context* context,
		struct libwebsocket* wsi, enum libwebsocket_callback_reasons reason,
		void* user, void* in, size_t len) {
	return 0;
}

int WebSocket::callback_user_interface(struct libwebsocket_context* context,
		struct libwebsocket* wsi, enum libwebsocket_callback_reasons reason,
		void* user, void* in, size_t len)
{
	switch (reason) {
	case LWS_CALLBACK_ESTABLISHED:{ // just log message that someone is connecting
		printf("connection established 0x%lx\n", (unsigned long) wsi);
		wsConnect = wsi;
		ws.push_back(wsi);
		break;
	}

	case LWS_CALLBACK_RECEIVE:
		((char *)in)[len] = '\0';
		printf("rx %d '%s'\n", (int)len, (char *)in);
		if (ui)
		{
			ui->ParseData((char *)in);
			sVarsOut data;
			ui->ReadData(&data);
			if (com)
			{
				com->SetOutputs(&data);
				com->SendData();
			}
		}
		break;
	case LWS_CALLBACK_CLOSED:
		printf("Closed 0x%lx\n", (unsigned long) wsi);
//		for (std::list<libewbsocket *>::iterator it = ws.begin(); it != ws.end(); ++it)
//		{
//			if (*it==wsi)
//			{
//				ws.remove();
//			}
//		}
		ws.remove(wsi);
		wsConnect = NULL;
		break;
	default:
		break;
	}

	printf("Clients: %d\n", ws.size());

	return 0;
}

WebSocket::~WebSocket() {
	libwebsocket_context_destroy(context);
}

void WebSocket::RunService() {
	libwebsocket_service(context, 50);
}

void WebSocket::SendBroadcast(std::string SendMsg) {
//	if (wsConnect) {
//		libwebsocket_write( wsConnect, (unsigned char *)SendMsg.c_str(), (unsigned int)SendMsg.length(), LWS_WRITE_TEXT);
//	}
//	printf("Sending: %s\n", SendMsg.c_str());
	for (std::list<libwebsocket *>::iterator it = ws.begin(); it != ws.end(); ++it)
	{
		libwebsocket_write( *it, (unsigned char *)SendMsg.c_str(), (unsigned int)SendMsg.length(), LWS_WRITE_TEXT);
	}
}
