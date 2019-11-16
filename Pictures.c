#include"Pictures.h"
#include"MenuSelection.h"


void LoadSpriteData(){

    sprite.gamesprite = al_load_bitmap("SpriteSheet.png");
    sprite.Ammo = al_load_bitmap("bullet.png");
    game.icon = al_load_bitmap("icon3.png");
    game.header = al_load_ttf_font("Gradientico.ttf",72,0);
    game.font = al_load_ttf_font("Gradientico.ttf",32,0);
    slides[0] = sprite.gamesprite;
    slides[1] = sprite.gamesprite; // bullets
}
