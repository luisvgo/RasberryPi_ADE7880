#include "iec61850_server.h"

#ifndef IEC_WRAPPER_H
#define IEC_WRAPPER_H

#define CONFIGURATION_FILE "./iec_server.cfg"
#define PASSWORD_DB "./iec_server_passwords.db"

typedef struct {
	void (*write)(IedServer);
	void (*read)(IedServer);
	int running;
	IedServer server;
} IecThreadParams;

int initIECServer(void (*write)(IedServer), void (*read)(IedServer), int running);
void runIECServer(void * context);
void stopIECServer();
int readCfgVal(char *valName, char **value);
bool clientAuthenticator(void* parameter, AcseAuthenticationParameter authParameter, void** securityToken);
#endif
