#include "include/load_media.h"
#include <string>
#include <jsoncpp/json.h>
#include <fstream>
void ShowBMP(char *file, SDL_Surface *screen, int x, int y)
{
    SDL_Surface *image;
    SDL_Rect dest;

    /* Cargamos el archivo BMP en la superficie */
    image = SDL_LoadBMP(file);
    if ( image == NULL ) {
        fprintf(stderr, "No pude cargar %s: %s\n",
	        file, SDL_GetError());
        return;
    }

    /* Volcamos en la superficie de pantalla. */
    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;
    SDL_BlitSurface(image, NULL, screen, &dest);

    /* Actualizamos la porcion de pantalla que ha cambiado */
    SDL_UpdateRects(screen, 1, &dest);

    SDL_FreeSurface(image);
}
bool load_media::load(char* name){
	char* name_file=new char[std::char_traits<char>::length(name)+6];
	std::char_traits<CharT>::copy(name_file,name);
	std::char_traits<CharT>::copy(name_file,"json");
	Json::Value root;
	std::ifstream ifs;
	ifs.open(name_file);

	return false;
}