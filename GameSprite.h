/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameSprite.h
 * Author: ryan
 *
 * Created on January 20, 2019, 10:15 PM
 */

#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>



class GameSprite {
public:
    GameSprite();
    GameSprite(const GameSprite& orig);
    virtual ~GameSprite();
 
    
private:
    float speedx, speedy;
    float weaponsx, weaponsy;
    
};

#endif /* GAMESPRITE_H */

