/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the Error Handler within the game. This can
	also be used to send debug messages to the Console.
	
	The error messages here are stored as a Stack.
*/

#define KELNOID_ERROR_WARNING	0x00
#define KELNOID_ERROR_FATAL		0x10
#define KELNOID__DEBUG			0x20
#define KELNOID_SDL_ERROR		0x30

struct Error_Message {
	short errorType;
	string errorTitle;
	string errorMessage;
	Error_Message* nextNode;
};

namespace KEL_ERROR_HANDLER {
	/*
		This will make sure the Error Stack starts Empty.
		Call this up on the startup of the program.
	*/
	void init();
	
	/*
		Should be called at the end of the Program OR when the Stack
		needs to be killed off.
		This is also called up when the programming has had a fatal error.
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
