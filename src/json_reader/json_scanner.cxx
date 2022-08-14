/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Object File for the JSON Scanner.
	
	WARNING :: This JSON Scanner cann't handle FLOATS!
	There isn't anypoint so far with KELNOID.
*/

#include <fstream>

using namespace std;

#include "../error_handler/error_handler.hxx"
#include "json_scanner.hxx"

streampos size;
char* memblock;

int memoryIndex;
int lineCounter;

/*
	Yes, I cheated and got some of the code here:
	https://cplusplus.com/doc/tutorial/files/
	
	I want to make my own. BUT right now I'll just getting this going.
*/
bool KEL_JSON_SCANNER::init(string _fileName) {
	memoryIndex = 0;
	lineCounter = 1;
	
	ifstream inputFile (_fileName.c_str(), ios::in|ios::binary|ios::ate);
	
	if (inputFile.is_open()) {
		size = file.tellg();
		memblock = new char [size];
		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();
	} else {
		KEL_ERROR_HANDLER::push(KELNOID_ERROR_WARNING, "KEL_JSON_SCANNER", "The JSON file given does not exist.");
		return false;
	}
}

KEL_JSON_TOKEN KEL_JSON_SCANNER::getNextToken() {
	if (size != memoryIndex + 1) {
		/*
			This part wipes out the whitespace.
		*/
		while (
			memblock[memoryIndex] == ' ' || 
			memblock[memoryIndex] == 0x0a ||	// Line Feed (LF) ASCII
			memblock[memoryIndex] == 0x09		// Horizontal Tab (HT) ASCII
		) {
			++memoryIndex;
		}
		
		/*
			Carriage Return (CR) ASCII.
			We need to keep track of the Line Number.
		*/
		if (memblock[memoryIndex] == 0x0d) {
			++lineCounter;
			++memoryIndex;
		}
		
		KEL_JSON_TOKEN retToken;
		
		switch (memblock[memoryIndex]) {
			'[':
				retToken.type = KEL_TOKEN_LEFT_SQUARE_BRACKET;
				break;
			']':
				retToken.type = KEL_TOKEN_RIGHT_SQUARE_BRACKET;
				break;
			'{':
				retToken.type = KEL_TOKEN_LEFT_BRACKET;
				break;
			'}':
				retToken.type = KEL_TOKEN_RIGHT_BRACKET;
				break;
			',':
				retToken.type = KEL_TOKEN_COMMA;
				break;
			':':
				retToken.type = KEL_TOKEN_COLON;
				break;
			0x22: // Double Quote
				/*
					We have the Start of a String, let's process it!
				*/
				string accululator = "";
				while (memblock[memoryIndex] != 0x22) {
					++memoryIndex;
					if (memblock[memoryIndex] >= 0x20 && memblock[memoryIndex] <= 0x7e) {
						accululator += memblock[memoryIndex];
					} else if (memblock[memoryIndex] == 0x0a || memblock[memoryIndex] == 0x0d) {
						KEL_ERROR_HANDLER::push(KELNOID_ERROR_WARNING, "KEL_JSON_SCANNER", "Strings can only be declared on one line.");
						retToken.type = KEL_TOKEN_ERROR;
						delete memblock;
						return retToken;
					} else {
						KEL_ERROR_HANDLER::push(KELNOID_ERROR_WARNING, "KEL_JSON_SCANNER", "There is an Invalid Character within a JSON String.");
						retToken.type = KEL_TOKEN_ERROR;
						delete memblock;
						return retToken;
					}
				}
				++memoryIndex;
				
		}
	} else {
		KEL_JSON_TOKEN eofToken;
		eofToken.type = KEL_TOKEN_END_OF_FILE;
		
		delete memblock;
		
		return eofToken;
	}
}