#include <stdio.h>
#include <stdlib.h>
#include <GL/glfw.h>

int main(int argc, char** argv){
	puts("Hello world!");
	if(!glfwInit()) puts("Oh no!");
	else puts("Oh yeah!");
	return 0;
}