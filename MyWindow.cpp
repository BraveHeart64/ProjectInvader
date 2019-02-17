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

#include"MyWindow.h"
#include<allegro5\allegro_native_dialog.h>

using namespace std;

MyWindow::MyWindow(){
   al_init();
   al_init_image_addon();
   al_install_keyboard();
   const float FramesPerSecond = 60;
   clearscreen = true;
   gamestate = 0;
   playerone.SetPosX(100);
   playerone.SetPosY(470);
   aiplayer[0].SetPosX(200);//200 4
   aiplayer[0].SetPosY(4);
   aiplayer[1].SetPosX(20);//200 4
   aiplayer[1].SetPosY(4);
   playerone.LoadShipType(player);
   aiplayer[0].LoadShipType(enemy);
   aiplayer[1].LoadShipType(enemy);
   Icon = al_load_bitmap("Graphics/gameicon.png");
   Screen = 0;




   if(!al_init()){
	  al_show_native_message_box(0, "AL_INIT_ERROR", "AL_init!", "!al_init() was not initiaited!", 0, 0);

    }
     Screen = al_create_display(500,500);
       
     if(Screen == 0){
    
	   al_show_native_message_box(0,"ScreenError","ScreenError","Screen was not loaded",0,0);
	   gamestate = 10;
	   Error();
    }
	 else {
      al_register_event_source(engine.ReturnTheQue(), al_get_display_event_source(Screen));
	  al_register_event_source(engine.ReturnTheQue(), al_get_timer_event_source(engine.ReturnGameClockTicks()));
      al_register_event_source(engine.ReturnTheQue(), al_get_keyboard_event_source());
	 }
       
    if(Icon == 0){
     
	 al_show_native_message_box(0, 0, 0, "Could not load the Icon", 0, 0);
	 al_show_native_message_box(0, "Icon is missiong", "Icon was not found in file", "Icon is gone!", 0, 0);
    gamestate = 10;
	Error();
    }
    if(error ==false){
         al_set_display_icon(Screen,Icon); 
     
    }


      
     

}



bool MyWindow::Error() {
	error = true;
	return error;
}


MyWindow::~MyWindow(){
al_destroy_display(Screen);
};


void MyWindow::GameLoop(){


	if (error == false) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_set_window_position(Screen, 600, 200);
		al_set_window_title(Screen, "Invaders");






		ALLEGRO_KEYBOARD_STATE key;
		al_start_timer(engine.ReturnGameClockTicks());


		while (gamestate != 10) {
			al_wait_for_event(engine.ReturnTheQue(), &engine.RefOfEvent());



			if (engine.ReturnEvent().type == ALLEGRO_EVENT_TIMER) {
				al_get_keyboard_state(&key);
				if (al_key_down(&key, ALLEGRO_KEY_RIGHT) && playerone.GetPosX() <= 430) {

					playerone.MoveRight();

				}

				if (al_key_down(&key, ALLEGRO_KEY_LEFT) && playerone.GetPosX() >= 0) {
					playerone.MoveLeft();
				}

				if (al_key_down(&key, ALLEGRO_KEY_SPACE)) {

					playerone.ShipShot();
					playerone.Recharge();

				}

				clearscreen = true;

			}
			else if (engine.ReturnEvent().type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				gamestate = 10;
			}

			// Main Game events in this code
			if (clearscreen && al_is_event_queue_empty(engine.ReturnTheQue())) {
				clearscreen = false;
				// al_clear_to_color(al_map_rgb(0,0,0));

				engine.PaintSptirts(playerone, aiplayer, 0);
				engine.HitDection(playerone, aiplayer[0]);
				engine.HitDection(playerone, aiplayer[1]);
				UpdateScreen();
			}



		}
	}

}


/*
int MyWindow::keyboardEvents(int key){
    int up=5,down=2,left=1,right=3;
    
    
}
*/






void MyWindow::UpdateScreen(){
    al_flip_display();  
}