#include "include/load_media.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
/// @todo Agregar variables globales para la musica.
/// @todo Hacer una funcion que libere la memoria ocupada por images y los demas que hagas.
bool Load_Media::load_json(std::string path, json* root) {
	std::ifstream ifs(path.c_str());
	if (!ifs.good()){
		std::cout<<"Error: File \""<<path<<"\n does not exist"<<std::endl;
		return false;
	}
	try {
		*root=json::parse(ifs,nullptr,true,true);
	}catch(const json::exception& e){//The file json no found
		std::cout<<"Error: "<<e.what()<<std::endl;
		ifs.close();
		return false;
	}
	ifs.close();
	return true;
}
bool Load_Media::loads()
{
	json root;
	if (!Load_Media::load_json("./media/map.json", &root))
		return false;

	//Loads all images
	for (const auto& imgs : root["Multimedia"]["img"]) {
		if (imgs["path"]==nullptr){
			std::cout<<"Warning: the image path is missing.\n\r"<<imgs<<std::endl;
			continue;
		}

		//We load the image in the RAM and keep in "resource_images"
		const std::string path=imgs["path"].dump();
		SDL_Surface* surface=add_resource_img(&path);
		
		//We check if the ID exists, if we do not ignore this.
		if (surface!=nullptr && imgs["id"]!=nullptr){
			this->images[imgs["id"]]=surface;
			std::cout<<"ID \""<<imgs["id"]<<"\" Now it contains the image"<<path<<std::endl;
		}
	}
	//Loads all sprites:
	for (auto& sprite : root["Multimedia"]["sprite"]){
		if (sprite["path"]==nullptr){
			std::cout<<"Warning: the image path is missing.\n\r"<<sprite<<std::endl;
			continue;
		}

		//We load the image in the RAM and keep in "resource_images"
		const std::string path=sprite["path"].dump();
		SDL_Surface* surface=add_resource_img(&path);
		
		//We check if the ID exists, if we do not ignore this.
		if (surface!=nullptr && sprite["id"]!=nullptr){
			if (sprite["dimension"]!=nullptr)//If the dimensions have been defined
				sprites[sprite["id"]]=new Sprite_(surface,sprite["dimension"][0],sprite["dimension"][1]);
			else //If not set to 32x32
				sprites[sprite["id"]]=new Sprite_(surface,32,32);
		}
	}
	return true;
}
Load_Media::Load_Media(){
	this->images["null"]=nullptr;
}
Load_Media::~Load_Media(){
	for( auto& pair : this->images){
		SDL_FreeSurface(pair.second);
	}
	this->images.clear();

	for( auto& pair : this->sprites){
		Sprite_* spt=pair.second;

		delete spt;
	}
	this->sprites.clear();
}
SDL_Surface* add_resource_img(const std::string* path){
	//We load the image in the RAM and keep in "Resource"
	SDL_Surface* surface;
	SDL_Surface* out;
	std::map<std::string, SDL_Surface*>::iterator ite=resource_images.find(*path);
	if(ite==resource_images.end()){//No exist the element
		surface=IMG_Load(path->c_str());
		if (surface==NULL){
			std::cout<<"WARNING: The image has not been loaded \""<<*path<<"\"."<<std::endl;
			return nullptr;
		}
		resource_images[*path]=surface;
	}else //There is the image.
		surface=ite->second;
	out = SDL_CreateRGBSurfaceWithFormat(0, surface->w, surface->h,
                                                 surface->format->BitsPerPixel,
                                                 surface->format->format);
	if (out == NULL){
		std::cout<<"Warning: Unable to copy image"<<std::endl;
		return nullptr;
	}
	SDL_BlitSurface(surface, NULL, out, NULL);
	return out;
}
void Load_Media::clear(){
	for( auto& pair : resource_images){
		SDL_FreeSurface(pair.second);
	}
	resource_images.clear();
}