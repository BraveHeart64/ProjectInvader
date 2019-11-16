#include"MenuSelection.h"
#include"Pictures.h"


void MenuInterface(){
    Menu();





}



void Menu(){
    // Main Menu Monique
    //sprite.imagey-50 will show the bullet sprite.imagex+150

    al_draw_text(game.header, al_map_rgb(255,255,255),300,10, ALLEGRO_ALIGN_CENTER,"Monique");
    al_draw_text(game.font, al_map_rgb(255,255,255),300,80, ALLEGRO_ALIGN_CENTER,"The Heroine From Russia");
    al_draw_text(game.font, al_map_rgb(255,255,255),300,140, ALLEGRO_ALIGN_CENTER,"The Invasion of Robtica!");


    //al_draw_bitmap_region(sprite.gamesprite,sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,0);


    //al_draw_scaled_bitmap(sprite.gamesprite,sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);
   // al_draw_scaled_bitmap(slides[0],sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);



    al_draw_text(game.font, al_map_rgb(255,255,255),300,290, ALLEGRO_ALIGN_CENTER,"Start");
    al_draw_text(game.font, al_map_rgb(255,255,255),300,340, ALLEGRO_ALIGN_CENTER,"Password");
    al_draw_text(game.font, al_map_rgb(255,255,255),300,380, ALLEGRO_ALIGN_CENTER,"Quit");

}



void ShootingInTheMenu(){



}



void MenuKeyDown(){
if(menustuff.menuon == 1){
                    sprite.screeny +=40;
                    menustuff.spritelocation +=1;
                    if(menustuff.spritelocation >=3){
                        sprite.screeny =280;
                        menustuff.spritelocation = 0;

                    }
                }



}



void MenuKeyUP(){

if( menustuff.menuon == 1){
                    sprite.screeny -=40;
                    menustuff.spritelocation -=1;

                    if(menustuff.spritelocation <=-1){
                        sprite.screeny =370 ;
                        menustuff.spritelocation = 2;

                    }
                }

}


void SelectAMenuChoice(){




}
