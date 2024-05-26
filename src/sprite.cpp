#include "./include/sprite.h"

Sprite_::Sprite_(SDL_Surface* surface,const unsigned int col_width,const unsigned int high_col){
  this->sprite=surface;
  this->sprite_rect=new SDL_Rect();
  this->sprite_rect->w=col_width;
  this->sprite_rect->h=high_col;
  this->sprite_rect->x=0;
  this->sprite_rect->y=0;
}
Sprite_::~Sprite_(){
  SDL_FreeSurface(this->sprite);
  this->sprite=nullptr;

  delete this->sprite_rect;
  this->sprite_rect=nullptr;
}
void Sprite_::select_sprite(unsigned int x, unsigned int y){
  this->sprite_rect->x = x * this->sprite_rect->w;
  this->sprite_rect->y = y * this->sprite_rect->h;
}
void Sprite_::draw(SDL_Surface *window_surface, SDL_Rect *position){
  SDL_BlitSurface(this->sprite,this->sprite_rect,window_surface,position);
}
void Sprite_::draw(SDL_Surface *window_surface, const int x,const int y){
  SDL_Rect position={x:x,y:y,0,0};
  SDL_BlitSurface(this->sprite,this->sprite_rect,window_surface,&position);
}