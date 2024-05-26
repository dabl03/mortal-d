//Bibliotecas estandar:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <map>
#include <vector>
//Biblioteca no estandar:
#include <SDL2/sdl.h>
#include <SDL2/SDL_main.h>
//Mis encabezados:
#include "./include/define.h"
/**
 * Titulo de la ventana.
 */
const char* W_TITLE="Mortal-D";
unsigned int width_screen=600,height_screen=300;
//Lo use para familierizarme con glut en opengl.
//Point p_camara=Point(0,0);
//Person gamer=Person(width_screen/3,height_screen/2,1,1,50,50);
double speed_camara=1;
bool keyStates[MAX_KEY];//Estados de las teclas. Al llamar a key up se debe volver al false.
bool keySpecialStates[MAX_KEY_SPECIAL];
unsigned short tema=TEMA_GAME;
std::map<std::string,SDL_Surface*> images;
std::map<std::string,SDL_Surface*> resource_images;/*For already loaded resources*/
App app;
bool end=false;
/*Inicializar todas las configuraciones de sdl.*/
void sdl_initialize() {
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow(W_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_screen, height_screen, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", width_screen, height_screen, SDL_GetError());
		exit(1);
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	app.PrimarySurface=SDL_GetWindowSurface(app.window);

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}
void end_sdl(){
	if(app.renderer) {
		SDL_DestroyRenderer(app.renderer);
		app.renderer = NULL;
	}

	if(app.window) {
		SDL_DestroyWindow(app.window);
		app.window = NULL;
	}
	Load_Media::clear();
	puts("Bye:)");
    SDL_Quit();
}
int main (int argc, char **argv) {
	sdl_initialize();
	atexit(end_sdl);//Se llamara la funcion end_sdl cuando acabe el programa:).
	while (!end)
	{
		prepareScene();

		doInput();

		presentScene();

		SDL_Delay(TIME_OF_REFRESH_MILISECONDS);
	}
	return 0;
}



void doInput(){
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}