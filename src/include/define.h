#ifndef DEFINE_H
#define DEFINE_H
#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
#endif
#include <SDL2/SDL.h>

	#define GL_PI 3.141592
	#define TIME_OF_REFRESH_MILISECONDS 5
	#define TEMA_MAIN 0
	#define TEMA_GAME 1
	#define MAX_KEY_SPECIAL 246
	#define MAX_KEY 267
	typedef struct {
		SDL_Renderer *renderer;
		SDL_Window *window;
		SDL_Surface* PrimarySurface;
	} App;
	union TYPE{
		IMG,
		MAP,
		GAMER,
		ENEMY,
		WEAPONS,
		OBJECT,
		TYPE_TOTAL
	};
	extern unsigned int width_screen;
	extern unsigned int height_screen;
	extern App app;//Puntero a la ventana.
	void doInput();
	
#endif
