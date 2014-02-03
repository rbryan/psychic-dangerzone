#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>

int main(int argc, char** argv){
	
	SDL_Window* window;
	SDL_GLContext glCon;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Behold OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_OPENGL);
//	render = SDL_CreateRenderer(window, -1, 0);
//	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 750, 750);
	glCon = SDL_GL_CreateContext(window);

	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	uint32_t data[] = {0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 4, 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glEnable(GL_TEXTURE_2D);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(20);
	glBegin(GL_TRIANGLES);

	glColor3f(1, 1, 1);
	glTexCoord2f(0,0);
	glVertex3f(0, 0, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(0,1);
	glVertex3f(0, 1, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(1,1);
	glVertex3f(1, 1, 0);

	glEnd();
	SDL_GL_SwapWindow(window);
	SDL_Event event = {0};
	while(event.type!=SDL_QUIT)
		SDL_WaitEvent(&event);
	SDL_GL_DeleteContext(glCon);
	SDL_Quit();
	return 0;
}
