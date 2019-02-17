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
    ALLEGRO_BITMAP* shot[3];
    int posx, posy;
    int shotx, shoty;
    int height, width;
    bool firing;
    bool recharge;
    float speedx,  speedy;
    char shiptype[1];
    
public:
    
     void  CreateShip(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy);
     void UpdateSprite(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy );
     void SetPosX(int x);
     void SetPosY(int y);
     void ShipShot();
     bool ShotFired();
     bool Recharge();
     ALLEGRO_BITMAP* LoadShotToScreen();
     int GetPosX();
     int GetPosY();
     
     int GetShotx();
     int GetShoty();
     
     int MoveLeft();
     int MoveRight();
     
     void SpriteCollision(ALLEGRO_BITMAP& image,ALLEGRO_BITMAP& imagetwo);
     void LoadShipType( char Ship[1]);
     ALLEGRO_BITMAP* GetSprite();

    
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();


};

#endif /* SPRITE_H */

