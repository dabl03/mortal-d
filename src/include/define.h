#ifndef DEFINE_H
#define DEFINE_H
#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
#endif
#include <map>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "data.h"
#include "draw.h"
#include "geometric_figure.h"
#include "load_media.h"
#include "person.h"
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
	enum TYPE{
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
	/// @brief Where all resource files are saved (path=SDL_Surface)
	extern std::map<std::string,SDL_Surface*> resource_images;
	void doInput();
#endif
