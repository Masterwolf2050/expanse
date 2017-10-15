
// Includes
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
#include <curses.h>
#include <stdbool.h>
#include <X11/Xlib.h>


// Definitions

int sdlMain()
{
	// Used to check to see if SDL is running in the main loop
	bool running = true;
	SDL_Event event;
	SDL_Window* WinMain = NULL;

	
	
	WinMain = SDL_CreateWindow("Expanse",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		/*SDL_WINDOW_VULKAN*/SDL_WINDOW_OPENGL);
	

	if ( WinMain == NULL){
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	
	// Main Loop
	while(running)
	{
		// SDL Event Loop
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}
	
	// Close and destroy the window
	SDL_DestroyWindow(WinMain);	
	// Clean up
	SDL_Quit();					
	return 0;
}
