#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/timer.h>
#include"GameSprite.h"
void MenuInterface();
void MenuKeyUP();
void MenuKeyDown();
void Menu();


struct Window{
    ALLEGRO_DISPLAY* window;
    ALLEGRO_BITMAP* icon;
    ALLEGRO_BITMAP* background;
    ALLEGRO_FONT * font, *header, *menu_text;
    ALLEGRO_PATH *path;
    int width;
    int height;
    ALLEGRO_TIMER* timer;

    char name[10];
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* que;

} game;





struct MenuScreen{

    int menuon;
    int menumove;
    int spritelocation;





} menustuff;



