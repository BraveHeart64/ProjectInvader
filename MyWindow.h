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
#include"Sprite.h"

class MyWindow {

 private:
    ALLEGRO_DISPLAY * Screen;
    ALLEGRO_EVENT_QUEUE *que;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER * gameclock;
    ALLEGRO_BITMAP* Icon = 0;
     char player[2]={'P','L'};
     char enemy[2]={'E','N'};

    bool clearscreen;
    int gamestate;









public:

    void GameClock();
    void WindowEvent();
    void GameLoop();
    void DrawScreen(Sprite &one, Sprite &two);


   MyWindow();
  ~MyWindow();

};
