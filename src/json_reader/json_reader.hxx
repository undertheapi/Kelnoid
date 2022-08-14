/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the JSON Reader.
*/

struct JSON_OBJECT {
	string key;
	string value;
	JSON_OBJECT* ojectValue;
};

namespace KEL_JSON_READER {
	void init();
	
	/*
		Returns a FALSE if there was an error.
	*/
	bool run();
	
	/*
		This must be run after the JSON file is done with.
		This will clear the memory.
	*/
	void finish();
};
