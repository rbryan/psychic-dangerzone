#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>

int main(int argc, char** argv){
	
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Texture* texture;
	SDL_GLContext glCon;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Behold OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, 0);
//	render = SDL_CreateRenderer(window, -1, 0);
//	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 750, 750);
	glCon = SDL_GL_CreateContext(window);
	char data[] = {0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 200, 200};
	glDrawElements(GL_LINES, 1, GL_UNSIGNED_BYTE, data);
	SDL_GL_SwapWindow(window);
	SDL_Event event = {0};
	while(event.type!=SDL_QUIT)
		SDL_WaitEvent(&event);
	SDL_Quit();
	return 0;
}
