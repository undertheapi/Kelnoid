#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h" 
#include <stdio.h>

int main( int argc, char* args[] ) 
{ 
  SDL_Window     *window;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0); 
  
  if(window==NULL)
  {   
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  
  SDL_Delay(3000);
  
  SDL_DestroyWindow(window); 
   
  SDL_Quit(); 

  return 0;   
}