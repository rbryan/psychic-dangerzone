#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

SDL_Window* winderp;
SDL_Renderer* render;
SDL_Texture* texture;
SDL_GLContext glCon;

int main(int argc, char** argv){
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	winderp = SDL_CreateWindow("Behold OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, 0);
	render = SDL_CreateRenderer(winderp, -1, 0);
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 750, 750);
	glCon = SDL_GL_CreateContext(winderp);
	SDL_Event event = {0};
	while(event.type!=SDL_QUIT)
		SDL_WaitEvent(&event);
	SDL_Quit();
	return 0;
}
