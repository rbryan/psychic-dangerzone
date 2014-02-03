#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <Imlib2.h>
#include <time.h>

#define BLOCKSPERSIDE 5

void drawImg(int X, int Y, int i){
	double delta = 2.0/BLOCKSPERSIDE;
	double x = X*delta-1;
	double y = Y*delta-1;

	glBindTexture(GL_TEXTURE_2D, i);
	glBegin(GL_TRIANGLES);

	glColor3f(1, 1, 1);
	glTexCoord2f(0,1);
	glVertex3f(x, y, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(0,0);
	glVertex3f(x, y+delta, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(1,0);
	glVertex3f(x+delta, y+delta, 0);

	glColor3f(1, 1, 1);
	glTexCoord2f(0,.999);
	glVertex3f(x, y, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(1,.999);
	glVertex3f(x+delta, y, 0);
	glColor3f(1, 1, 1);
	glTexCoord2f(1,0);
	glVertex3f(x+delta, y+delta, 0);

	glEnd();
}

int main(int argc, char** argv){
	
	SDL_Window* window;
	SDL_GLContext glCon;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Behold OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_OPENGL);
//	render = SDL_CreateRenderer(window, -1, 0);
//	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 750, 750);
	glCon = SDL_GL_CreateContext(window);


	GLuint tex[4];
	glGenTextures(4, tex);
	char line[50];
	int i = 0;
	for(; i < 4; i++){
		glBindTexture(GL_TEXTURE_2D, tex[i]);
//		uint32_t data[] = {0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFF000000, 0xFFFFFFFF, 0xFF000000, 0xFFFFFFFF};
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		sprintf(line, "img%d.png", i+1);
		imlib_context_set_image(imlib_load_image(line));
		uint32_t *data = imlib_image_get_data_for_reading_only();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imlib_image_get_width(), imlib_image_get_height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
		imlib_free_image();
	}

	glEnable(GL_TEXTURE_2D);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	srand(time(NULL));
	int j;
	for(i = 0; i < BLOCKSPERSIDE; i++){
		for(j = 0; j < BLOCKSPERSIDE; j++) drawImg(i, j, tex[4l*rand()/RAND_MAX]);
	}

	SDL_GL_SwapWindow(window);
	SDL_Event event = {0};
	while(event.type!=SDL_QUIT)
		SDL_WaitEvent(&event);
	SDL_GL_DeleteContext(glCon);
	SDL_Quit();
	return 0;
}
