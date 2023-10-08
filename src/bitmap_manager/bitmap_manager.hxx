/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the Bitmap Resource Manager. The methods are
	used to call up the Bitmaps that SDL will use.
*/

#include "SDL2/SDL.h" 

namespace KEL_BITMAP_MANAGER {
	void init();
	
	/*
		Returns a FALSE if the Bitmap wasn't loaded.
	*/
	bool loadBitmap(string, string);
	
	/*
		If the Bitmap wasn't able to be found, the Method will return
		a NULL.
	*/
	SDL_Surface* grabBitmap(string);
};