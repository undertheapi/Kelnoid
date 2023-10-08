/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Object File for the JSON Reader.
*/

#include <string>

using namespace std;

#include "json_reader.hxx"
#include "json_scanner.hxx"

void KEL_JSON_READER::init() {
	if (KEL_JSON_SCANNER::init("")) {
		
	} else {
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_FATAL, 
			"KEL_JSON_READER", 
			"The JSON Scanner cannot initiate correctly."
		);
	}
}

bool KEL_JSON_READER::run() {
	KEL_JSON_SCANNER::step();
	JSON_OBJECT* object = KEL_JSON_READER::getObject();
	
	if (object == NULL) {
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_FATAL, 
			"KEL_JSON_READER", 
			"There is an error reading the JSON File."
		);
		return false;
	}
	
	return true;
}

JSON_OBJECT* KEL_JSON_READER::getObject() {
	if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_LEFT_BRACKET) {
		KEL_JSON_SCANNER::step();
		if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_STRING) {
			KEL_JSON_SCANNER::step();
			JSON_OBJECT* object = new JSON_OBJECT;
			object->key = token.strValue;
			KEL_JSON_SCANNER::step();
			if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_COLON) {
				KEL_JSON_SCANNER::step();
				JSON_OBJECT* object = KEL_JSON_READER::getValue();
				if (object != NULL) {
					KEL_JSON_SCANNER::step();
					if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_RIGHT_BRACKET) {
						KEL_JSON_SCANNER::step();
						return object;
					} else {
						KEL_ERROR_HANDLER::push(
							KELNOID_ERROR_WARNING, 
							"KEL_JSON_READER", 
							"There is no Right Bracket ({). Line Number :: " + to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
						);
					}
				} else {
					KEL_ERROR_HANDLER::push(
						KELNOID_ERROR_WARNING, 
						"KEL_JSON_READER", 
						"There is no Object found. Line Number :: " + to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
					);
				}
			} else {
				KEL_ERROR_HANDLER::push(
					KELNOID_ERROR_WARNING, 
					"KEL_JSON_READER", 
					"There is no Colon found. Line Number :: " + to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
				);
			}
		} else {
			KEL_ERROR_HANDLER::push(
				KELNOID_ERROR_WARNING, 
				"KEL_JSON_READER", 
				"There is no String found. Line Number :: " + to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
			);
		}
	} else {
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_WARNING, 
			"KEL_JSON_READER", 
			"There is no Left Bracket ({). Line Number :: " + to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
		);
		return NULL;
	}
}

/*
	TODO :: Deal With Arrays.
*/
JSON_OBJECT* getValue() {
	JSON_OBJECT* object = new JSON_OBJECT;
	if (KEL_JSON_READER::getString() != NULL) {
		object->strValue = KEL_JSON_READER::getString();
		KEL_JSON_SCANNER::step();
	} else if (KEL_JSON_READER::getNumber() != -1) {
		object->strValue = KEL_JSON_READER::getNumber();
		KEL_JSON_SCANNER::step();
	} else if (KEL_JSON_READER::getObject() != NULL) {
		object = KEL_JSON_READER::getObject();
		KEL_JSON_SCANNER::step();
	} else {
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_WARNING, 
			"KEL_JSON_READER", 
			"No String, Number or Object was found. Line Number " + std::to_string(KEL_JSON_SCANNER::getNextToken().lineNumber)
		);
		return NULL;
	}
}

int KEL_JSON_READER::getNumber() {
	if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_NUMBER) {
		return KEL_JSON_SCANNER::getNextToken().intValue;
	} else {
		return -1;
	}
}


string* KEL_JSON_READER::getString() {
	if (KEL_JSON_SCANNER::getNextToken().type == KEL_TOKEN_STRING) {
		return KEL_JSON_SCANNER::getNextToken().strValue.c_str();
	} else {
		return NULL;
	}
}

void KEL_JSON_READER::finish() {
	
}
