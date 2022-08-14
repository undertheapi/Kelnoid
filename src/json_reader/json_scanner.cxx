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

/*
	Yes, I cheated and got some of the code here:
	https://cplusplus.com/doc/tutorial/files/
	
	I want to make my own. BUT tright now I'll just getting this going.
*/
bool KEL_JSON_SCANNER::init(string _fileName) {
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