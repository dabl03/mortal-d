#include "include/data.h"
Data::Data(char * name)
{
}
Data::~Data() {
	if (name)
		delete name;
	if (img)
		SDL_FreeSurface(img);

}