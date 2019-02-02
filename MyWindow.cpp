/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyWindow.cpp
 * Author: ryan
 * 
 * Created on January 20, 2019, 9:45 PM
 */

#include "MyWindow.h"
#include<iostream>
//#include"GameSprite.h"
using namespace std;

MyWindow::MyWindow(){
   al_init();
   al_init_image_addon();
   al_install_keyboard();

    Screen = 0;
    que = 0;
    gameclock = 0;
    
    const float FramesPerSecond = 60;
    clearscreen = true;
    gamestate = 0;
    Icon = al_load_bitmap("Graphics/gameicon.png");





   if(!al_init()){
      cout<<"Allegro failed to init";

    }
       Screen = al_create_display(500,500);
       
     if(Screen == 0){
       cout<<"failed to create the screen";

    }
       
    if(Icon == 0){
     cout<<"Icon is not loaded";
    gamestate = 10;
    }
    else{
         al_set_display_icon(Screen,Icon); 
     
    }

       
      gameclock = al_create_timer(1.0/FramesPerSecond);
     if(!gameclock){
      cout<<"failed to create the timer";
     }

     que = al_create_event_queue();
     if(!que){
      cout<<"failed to create the que event";
      al_destroy_display(Screen);
      al_destroy_timer(gameclock);

     }
     
      al_register_event_source(que, al_get_display_event_source(Screen));
      al_register_event_source(que,al_get_timer_event_source(gameclock));
      al_register_event_source(que,al_get_keyboard_event_source());

}






MyWindow::~MyWindow(){
al_destroy_timer(gameclock);
al_destroy_display(Screen);
al_destroy_event_queue(que);

};


void MyWindow::GameLoop(){


 
 al_clear_to_color(al_map_rgb(0,0,0));
 al_set_window_position(Screen, 1600,200);
 al_set_window_title(Screen,"Invaders");
 
  Sprite playerone,aiplayer;
  playerone.SetPosX(100);
  playerone.SetPosY(470);
  aiplayer.SetPosX(200);//200 4
  aiplayer.SetPosY(4);
  playerone.LoadShipType(player);
  aiplayer.LoadShipType(enemy);
   ALLEGRO_KEYBOARD_STATE key;
 
 al_draw_bitmap(playerone.GetShip(),playerone.GetPosX(),playerone.GetPosY(),0);
 al_draw_bitmap(aiplayer.GetShip(),aiplayer.GetPosX(),aiplayer.GetPosY(),0);

 al_start_timer(gameclock);
 DrawScreen(playerone,aiplayer);

  while(gamestate != 10){
   al_wait_for_event(que,&event);
  
   
   
     if(event.type == ALLEGRO_EVENT_TIMER){
         al_get_keyboard_state(&key);
         if(al_key_down(&key,ALLEGRO_KEY_RIGHT)&& playerone.GetPosX() <= 430){
             
             playerone.MoveRight();
            
         }else{
             
         }
         
          if(al_key_down(&key,ALLEGRO_KEY_LEFT)&& playerone.GetPosX() >= 0){
             playerone.MoveLeft();
         }
          else{
              
          }
       clearscreen = true;
       
     }
       else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        gamestate = 10;
       }

       // Main Game events in this code
       if(clearscreen && al_is_event_queue_empty(que)){
          clearscreen = false;
         // al_clear_to_color(al_map_rgb(0,0,0));
         
          
           DrawScreen(playerone, aiplayer);
         
       
       }
   
  }

}


/*
int MyWindow::keyboardEvents(int key){
    int up=5,down=2,left=1,right=3;
    
    
}
*/
void MyWindow::DrawScreen(Sprite &playerone,Sprite &aiplayer){
    al_clear_to_color(al_map_rgb(0,0,0));
     al_draw_bitmap(playerone.GetShip(),playerone.GetPosX(),playerone.GetPosY(),0);
     al_draw_bitmap(aiplayer.GetShip(),aiplayer.GetPosX(),aiplayer.GetPosY(),0);
   al_flip_display();

}