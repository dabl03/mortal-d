#ifndef LOAD_MEDIA_H
#define LOAD_MEDIA_H 1
	#include "define.h"
	#include <json/json.h>
	#include <vector>
	struct data{
		SDL_Surface* img;
		char* name;
		void* data_type;
		TYPE type;
	};
	class load_media{
	public:
		std::vector<SDL_Surface*> persons,
		maps,
		weapons;
	};
	void ShowBMP(char *file, SDL_Surface *screen, int x, int y);

#endif