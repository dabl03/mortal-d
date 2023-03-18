#ifndef DATA_H
#define DATA_H 1
#include "define.h"
	class Data {
	public:
		SDL_Surface* img = NULL;
		char* name = NULL;
		Data(char* name);
		~Data();
	};
	class Map :public Data {
		SDL_Rect coord_background;
		int starting_point[2];//x e y
		SDL_Rect* coord_hotspot;
		Map(char* name_world,char* background_path);
	};
#endif