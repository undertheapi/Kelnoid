/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the JSON Reader.
*/

struct JSON_OBJECT {
	string key;
	string strValue;
	int intValue;
	JSON_OBJECT* ojectValue;
};



struct JSON_ARRAY {
	
};

struct JSON_VALUE {
	string key;
	string strValue;
	int intValue;
	JSON_OBJECT* ojectValue;
}

namespace KEL_JSON_READER {
	
	void init();
	
	/*
		Returns a FALSE if there was an error.
	*/
	bool run();
	
	JSON_OBJECT* getObject();
	
	JSON_OBJECT* getValue();
	
	/*
		There are no negative numbers for this Game Engine.
		If there is no number, this method will return a -1.
	*/
	int getNumber();
	
	string* getString();
	
	/*
		This must be run after the JSON file is done with.
		This will clear the memory.
	*/
	void finish();
};
