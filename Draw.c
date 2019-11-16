#include<stdio.h>
#include"Draw.h"
#include"MenuSelection.h"




ALLEGRO_BITMAP* Place(ALLEGRO_BITMAP* image ){
    image = al_load_bitmap("gameObjects2.png");

//  image = al_create_sub_bitmap(image,0,0,50,550);

    return image;
}





// MainLoop to place all data on the screen and render graphics to the screen
void RederGraphics(){
/*
    if(sprite.shooting_animation == 0){
     al_draw_scaled_bitmap(slides[0],sprite.framex[0],sprite.framey[1],sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);


    }
    else if(sprite.shooting_animation == 1){
    //sprite.shooting_animation++;
      al_draw_scaled_bitmap(slides[0],sprite.framex[1],sprite.framey[1],sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);
       // if(sprite.shooting_animation >=2){
       //     sprite.shooting_animation =-1;
      //  }

    } // need one for walking and jumping as well fore the player
    else{ // idle animatione

        al_draw_scaled_bitmap(slides[0],sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);
       // sprite.shooting_animation==0;
    }
*/


    if(sprite.player_shooting==1){
            sprite.shooting_animation++;
            al_draw_scaled_bitmap(slides[0],sprite.framex[sprite.shooting_animation],sprite.framey[1],sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);
            if(sprite.shooting_animation>=2){
                sprite.shooting_animation = -1;

            }
    }
    else{

        al_draw_scaled_bitmap(slides[0],sprite.imagex,sprite.imagey,sprite.region_height,sprite.region_width,sprite.screenx,sprite.screeny,80,80,0);
    }




}

void DestroyImages(){



}
