/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyWindow.h
 * Author: ryan
 *
 * Created on January 20, 2019, 9:45 PM
 */


#define MYWINDOW_H

#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include"GameEngine.h"
#include"Sprite.h"

class MyWindow {

 private:
    ALLEGRO_DISPLAY * Screen;
    ALLEGRO_BITMAP* Icon = 0;
	GameEngine engine;
     char player[2]={'P','L'};
     char enemy[2]={'E','N'};
     bool clearscreen;
	 bool error = false;
     int gamestate;
Sprite playerone,aiplayer[10]; 








public:
	bool Error();
    void GameClock();
    void WindowEvent();
    void GameLoop();
    void DrawScreen(Sprite &one, Sprite two[], int slot);
    void UpdateScreen();

   MyWindow();
  ~MyWindow();

};
