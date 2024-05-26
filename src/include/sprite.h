#ifndef SPRITE_H
  #define SPRITE_H 1
  #include <SDL2/SDL_rect.h>
  #include <SDL2/SDL_surface.h>
class Sprite_{
  public:
    /**
     * @brief Construct a new Sprite_ object
     * 
     * @param[in] surface The image containing the sprites
     * @param[in] col_width The width of the sprite
     * @param[in] high_col The length of the sprite
     */
    Sprite_(SDL_Surface* surface,const unsigned int col_width,const unsigned int high_col);
    /** Draw the current sprite.
     * 
     * @param[out] window_surface Canvas where you are going to draw
     * @param[in] position Where to draw on the canvas
     */
    void draw(SDL_Surface *window_surface, SDL_Rect *position);
    void draw(SDL_Surface *window_surface, const int x,const int y);
    /**Select the image sprite.
     * 
     * @param x 
     * @param y 
     */
    void select_sprite(unsigned int x, unsigned int y);
    ~Sprite_();
  protected:
    SDL_Rect* sprite_rect;
    SDL_Surface* sprite;
};

#endif