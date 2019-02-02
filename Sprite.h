/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerSprite.h
 * Author: ryan
 *
 * Created on January 20, 2019, 10:48 PM
 */

#ifndef SPRITE_H
#define SPRITE_H
#include"GameSprite.h"
#include<string>

class Sprite : public GameSprite {
    
    private:  
    ALLEGRO_BITMAP*  ship = 0;
    int posx, posy;
    int height, width;
    float speedx,  speedy;
    char shiptype[1];
    
public:
    
     int  CreateShip(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy);
     void UpdateSprite(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy );
     void SetPosX(int x);
     void SetPosY(int y);
     int GetPosX();
     int GetPosY();
     int MoveLeft();
     int MoveRight();
     
     void SpriteCollision(ALLEGRO_BITMAP& image,ALLEGRO_BITMAP& imagetwo);
     void LoadShipType( char Ship[1]);
     ALLEGRO_BITMAP* GetShip();  

    
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();


};

#endif /* SPRITE_H */

