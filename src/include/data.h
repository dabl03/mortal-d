#ifndef DATA_H
#define DATA_H 1
#include "define.h"
#include <cstring>
	class Data {
	public:
		SDL_Surface* img = NULL;
		char* name = NULL;
		Data(char * name,SDL_Surface* s);
		~Data();
	};
	class Level :public Data {
		SDL_Rect coord_background;
		int starting_point[2];//x e y
		SDL_Rect* coord_hotspot;
		Level(char* name_world,char* background_map_src,int x,int y);
	};
#endif