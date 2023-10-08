/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Object File for the Bitmap Resource Manager. The methods are
	used to call up the Bitmaps that SDL will use.
*/

#include <map>

using namespace std;

#include "bitmap_manager.hxx"

map<string, SDL_Surface*> bitmapMap;

void KEL_BITMAP_MANAGER::init() {

}

bool KEL_BITMAP_MANAGER::loadBitmap(string _key, string _fileName) {
	SDL_Surface *image = SDL_LoadBMP(_fileName);
	if (!image) {
		KEL_ERROR_HANDLER::push(
			KELNOID_SDL_ERROR,
			"KEL_BITMAP_MANAGER SDL ERROR",
			SDL_GetError()
		);
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_WARNING,
			"KEL_BITMAP_MANAGER",
			"Failed to load the Image, File Name :: " + _fileName
		);
		return false;
	}
	bitmapMap[_key] = image;
	return true;
}

SDL_Surface* KEL_BITMAP_MANAGER::grabBitmap(string _key) {
	if (bitmapMap.contains(_key) {
		return bitmapMap[_key];
	} else {
		KEL_ERROR_HANDLER::push(
			KELNOID_ERROR_WARNING,
			"KEL_BITMAP_MANAGER",
			"Failed to load the Image with key :: " + _key
		);
		return NULL;
	}
}
