#include "include/data.h"
 
Data::Data(char * name,SDL_Surface* s){
	this->name=new char[strlen(name)+1];
	std::strcpy(this->name,name);
	this->img=s;
}
Data::~Data() {
	if (this->name)
		delete this->name;
	if (this->img)
		SDL_FreeSurface(this->img);
}
Level::Level(char* name_world,char* background_map_src,int x,int y):Data(name_world,IMG_Load(background_map_src)){
	this->coord_background.x=x;
	this->coord_background.y=y;
	this->coord_background.w=this->img->w;
	this->coord_background.h=this->img->h;
} 