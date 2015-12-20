/*
 * motor_control_srvc.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Luis
 *
 */

#ifndef MOTOR_CONTROL_SRVC_H_
#define MOTOR_CONTROL_SRVC_H_


void* 	motor_control_srvc		(void *arg);
void 	server_writeData		(IedServer server);
void 	server_readData			(IedServer server);

#endif /* MOTOR_CONTROL_SRVC_H_ */
