#ifndef LOAD_MEDIA_H
#define LOAD_MEDIA_H 1
	#include "define.h"
	#include "data.h"
	#include <vector>
	#include <string>
	#include <fstream>
	#include <jsoncpp/json.h>
	
	class load_media{
	public:
		std::vector<Data*> persons,
		maps,
		weapons;
		static bool load_json(char* name, json::Value* root);
		bool loads();
	};
	void ShowBMP(char *file, SDL_Surface *screen, int x, int y);

#endif