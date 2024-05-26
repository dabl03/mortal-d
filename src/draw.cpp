#include "include/draw.h"

void prepareScene(){
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(){
	SDL_RenderPresent(app.renderer);
}
void draw(){
	
}