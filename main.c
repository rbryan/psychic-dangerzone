#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


int main(int argc, char** argv){
	
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Texture* texture;
	SDL_GLContext glCon;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Behold OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, 0);
	render = SDL_CreateRenderer(window, -1, 0);
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 750, 750);
	glCon = SDL_GL_CreateContext(window);
	SDL_Event event = {0};
	while(event.type!=SDL_QUIT)
		SDL_WaitEvent(&event);
	SDL_Quit();
	return 0;
}
