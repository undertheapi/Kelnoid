/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the JSON Scanner.
	
	WARNING :: This JSON Scanner cann't handle FLOATS!
	There isn't anypoint so far with KELNOID.
*/

#define KEL_TOKEN_ERROR 0x00
#define KEL_TOKEN_NUMBER 0x01
#define KEL_TOKEN_STRING 0x02
#define KEL_TOKEN_LEFT_SQUARE_BRACKET 0x03
#define KEL_TOKEN_RIGHT_SQUARE_BRACKET 0x04
#define KEL_TOKEN_LEFT_BRACKET 0x05
#define KEL_TOKEN_RIGHT_BRACKET 0x06
#define KEL_TOKEN_COMMA 0x07
#define KEL_TOKEN_COLON 0x08

struct KEL_JSON_TOKEN {
	char type;
	int value;
};

namespace KEL_JSON_SCANNER {
	/*
		This will initiate the Scanner.
		If the file doesn't exist, this method will return a false.
	*/
	bool init(string);
	
	KEL_JSON_TOKEN getNextToken();
}