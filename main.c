/*
                        AmoreSoftware Licsense

                        To Be Deterimined, all rights belong to Ryan Love and Bobby Clack  to use main.c,Draw.c , MenuSeleections and all other except Exception.h

                        The codes belongs to Ryan Love and the art belongs to both Bobby Clark and Ryan Love
                        The License is Priotary Open source depending on the specifice parts of this program, please read all licsense
                        to make sure you are in your legal rights.

                        TBD





*/





#include<stdio.h>
#include<stdlib.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/timer.h>
#include"Draw.h"
#include"MenuSelection.h"
#include"Exception.h"
#include"GameSprite.h"
#include"Pictures.h"
#include"Animation.h"


 int check = 0;


int EndProgramOnError();



void PlayerInit(){
    sprite.imagex = 0;
    sprite.imagey = 450;
    sprite.region_height = 50;
    sprite.region_width = 50;
    sprite.screenx = 80;
    sprite.screeny = 280;
    sprite.framex[0] = 0;
    sprite.framey[0] = 450;
    sprite.player_shooting = -1;

    sprite.shooting_animation = -1;

    sprite.framex[1]= 50;
    sprite.framey[1]= 400;



}


void KeyBoolenSetUp() {
	sprite.key[0]= false;
	sprite.key[1] = false;
	sprite.key[2] = false;
	sprite.key[3] = false;
	sprite.key[4] = false;
	sprite.key[5] = false;
}

void init_Window() {
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	PlayerInit();
	KeyBoolenSetUp();
    //sprite.framex[0] = 0;
   // sprite.framey[1] = 50;
    sprite.running = 0;
    sprite.jumping = 0;
    shooting_x = 0;
    shooting_y = 0;


    menustuff.menumove = 3;
    menustuff.menuon =1;
    menustuff.spritelocation = 0;
    game.path =  al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(game.path,"Graphics");
    al_change_directory(al_path_cstr(game.path, '/'));

    LoadSpriteData();





    game.background = Place(game.background);

    check = CheckForNullforDisplay(game.background, check);
    EndProgramOnError();

    check = CheckForNullFont(game.font, check);
    EndProgramOnError();

    check = CheckForNullFont(game.header, check);
    EndProgramOnError();

    check = CheckForNullBitMap(sprite.gamesprite, check);
    EndProgramOnError();

    check = CheckForNullIcon(game.icon, check);
    EndProgramOnError();


    game.timer = 0;
    game.window = 0;
    const float fps = 60;
    game.timer = al_create_timer(1.0/fps);

    char name[10] = "Monique";
    game.width = 600;
    game.height = 600;

    game.window = al_create_display(game.height,game.width);
    al_set_window_title(game.window,name);
    al_set_display_icon(game.window,game.icon);

}


int EndProgramOnError(){
   if(check == 1){
        return 1;
    }
    return 1;

}



void clean_UP(){
    //al_destroy_timer(game.fps);
    al_destroy_display(game.window);
    al_destroy_event_queue(game.que);
    al_destroy_timer(game.timer);
    al_destroy_bitmap(game.icon);
    al_destroy_bitmap(game.background);
    al_destroy_bitmap(sprite.gamesprite);
    al_destroy_bitmap(sprite.Ammo);
    al_destroy_font(game.font);
    al_destroy_font(game.header);
    al_destroy_font(game.menu_text);
    al_destroy_path(game.path);
}









void GameControls(){
    // we will put player controls here in the future
	bool ActionPressed[2] = { true,false };


		if (game.event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (game.event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    sprite.key[Key_UP] = true;
                    // makes the charact look up

                    MenuKeyUP();//implemented in MenuSelection.c
                break;


                case ALLEGRO_KEY_DOWN:
                    sprite.key[Key_DOWN] = true;
                    // show a duck animation
				break;


                case ALLEGRO_KEY_LEFT:
                    sprite.key[Key_LEFT] = true;
                    // needs to subtract from the animation
				break;


                case ALLEGRO_KEY_RIGHT:
                    sprite.key[Key_RIGHT] = true;
                    // needs to add to the script

				break;


                case ALLEGRO_KEY_ENTER:
                    sprite.key[Key_DOWN] = true;
                     sprite.player_shooting = 1;


                break;


                case ALLEGRO_KEY_SPACE:
                    sprite.key[Key_DOWN] = true;

                    if(sprite.key[Key_DOWN] == true){
                        sprite.imagey-=50;
                        sprite.imagex+=0;//50

                    }


                    //al_draw_bitmap_region(slides[0],sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,0);

                break;




			}


		}


		 if (game.event.type == ALLEGRO_EVENT_KEY_UP) {
			switch (game.event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    sprite.key[Key_UP] = false;
                break;

                case ALLEGRO_KEY_DOWN:
                    sprite.key[Key_DOWN] = false;
                    MenuKeyDown();
				break;


                case ALLEGRO_KEY_LEFT:
                    sprite.key[Key_LEFT] = false;
				break;


                case ALLEGRO_KEY_RIGHT:
                    sprite.key[Key_RIGHT] = false;

				break;

				case ALLEGRO_KEY_SPACE:
				sprite.key[Key_DOWN] = false;

				 // release the gun
                 sprite.imagex = 0;
                 sprite.imagey = 450;
				// al_draw_bitmap_region(sprite.gamesprite,sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,0);

				break;

				case ALLEGRO_KEY_ENTER:
				sprite.key[Key_ENTER] = false;

                sprite.shooting_animation = 0;
                sprite.player_shooting = 0 ;


				// al_draw_bitmap_region(sprite.gamesprite,sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,0);

				break;




			}



		}


}


void LevelOne(){

 int brush = 50;


            for(int i = 0 ;i <11; ++i){ // O(N)

                al_draw_bitmap_region(game.background,0,450,50,50,brush*i,550,0);

            }


 al_flip_display();

}


void LevelProgression(int CurrentLevel){

    switch(CurrentLevel){
        case 0:
            MenuInterface();

        break;

        case 1:
            LevelOne();
        break;

        case 2:

        break;

        case 3:

        break;

        case 4:

        break;

        case 5:

        break;

    }
}



void mainLoop(){
    int run  = 0;
    int paint = 0;
    int levelcounter = 0;
    game.que =  al_create_event_queue();
    al_register_event_source(game.que,al_get_display_event_source(game.window));
    al_register_event_source(game.que,al_get_timer_event_source(game.timer));
    al_register_event_source(game.que, al_get_keyboard_event_source());
    al_start_timer(game.timer);
    al_clear_to_color(al_map_rgb(0,0,0));

    if(check ==1){
        run = 100;
    }

    while(run != 100){

        al_wait_for_event(game.que,&game.event);

        if(game.event.type == ALLEGRO_EVENT_TIMER){
            paint = 1;


        }
        else if(game.event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            run = 100;
            break;
        }

        GameControls();




        if(paint && al_is_event_queue_empty(game.que)){
            paint = 0;
            al_clear_to_color(al_map_rgb(0,0,0));
            LevelProgression(levelcounter);
            RederGraphics();
            al_flip_display();
        }

    }


}


int main(int argc, char* argv[])
{

    init_Window();
    mainLoop();



    clean_UP();
    return 0;
}

