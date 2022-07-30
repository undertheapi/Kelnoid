/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the Error Handler within the game. This can
	also be used to send debug messages to the Console.
	
	The error messages here are stored as a Stack.
*/

#define KELNOID_ERROR_WARNING 0x00
#define KELNOID_ERROR_FATAL   0x10
#define KELNOID_ERROR_DEBUG   0x20

struct Error_Message {
	short errorType;
	string errorTitle;
	string errorMessage;
	Error_Message* nextNode;
};

Error_Message topOfStack*;

namespace ERROR_HANDLER {
	/*
		This will make sure the Error Stack starts Empty.
	*/
	void init();
	
	/*
		Should be called at the end of the Program OR when the Stack
		needs to be killed off. 
	*/
	void kill();
	
	/*
		This will push an error message to the stack and run it.
	*/
	void push(short, string, string);
	
	/*
		Dumps the text of the Error Stack to the Console. This will NOT clear it.
	*/
	void dump();
};
