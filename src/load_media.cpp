#include "include/load_media.h"

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

bool load_media::load_json(char* name, json::Value* root) {
	char* name_file = new char[std::char_traits<char>::length(name) + 6];
	std::char_traits<CharT>::copy(name_file, name);
	std::char_traits<CharT>::copy(name_file, "json");
	std::ifstream ifs;
	Json::CharReaderBuilder builder;
	JSONCPP_STRING errs;
	ifs.open(name_file);
	builder["collectComments"] = true;
	if (!parseFromStream(builder, ifs, root, &errs)) {
		return false;
	}
	ifs.close();
	return true;
}
bool load_media::loads()
{
	json::Value root;
	load_media::load_json("map", &root);
	for (auto&&[k, v] : arr) {
		map.emplace_back(k,MAP);
	}
	return true;
}