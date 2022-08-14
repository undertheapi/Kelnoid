/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Object File for the Error Handler within the game.
*/

#include <cstddef>
#include <string>

using namespace std;

#include "error_handler.hxx"

Error_Message topOfStack*;

void KEL_ERROR_HANDLER::init() {
	topOfStack = NULL;
}

void KEL_ERROR_HANDLER::kill() {
	delete topOfStack;
}

void KEL_ERROR_HANDLER::push(short _type, string _title, string _message) {
	Error_Message newMessage* = new Error_Message(_type, _title, _message);
	
	if (topOfStack == NULL) {
		topOfStack->nextNode = NULL;
		topOfStack = newMessage
	} else {
		newMessage->nextNode = topOfStack;
		topOfStack = newMessage;
	}
	
	switch (_type) {
		case KELNOID_ERROR_WARNING:
			KEL_ERROR_HANDLER::dump();
			break
		case KELNOID_ERROR_FATAL:
			KEL_ERROR_HANDLER::dump();
			KEL_ERROR_HANDLER::kill();
			break;
		case KELNOID_ERROR_DEBUG:
			// print just the message! 
			break;
		default:
	}
}

void KEL_ERROR_HANDLER::dump() {
	Error_Message* message = topOfStack;
	
	if (message == NULL) {
		// nothing in the Error Stack, make sure this is put to the console.
	} else {
		while (message != NULL) {
			switch (message->errorType) {
				case KELNOID_ERROR_WARNING:
					// WARNING ONLY
					break
				case KELNOID_ERROR_FATAL:
					// FATAL 
					break;
				case KELNOID_ERROR_DEBUG:
					// DEBUG
					break;
				default:
			}
			message = message->nextNode;
		}
	}
}