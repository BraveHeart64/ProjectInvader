/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerSprite.cpp
 * Author: ryan
 * 
 * Created on January 20, 2019, 10:48 PM
 */

#include "Sprite.h"

Sprite::Sprite() {
     height= width=0;;
     speedx=speedy=0.0;
    
    
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
}




     void Sprite::SetPosX(int x){
         posx = x;
     }
     
     void Sprite::SetPosY(int y){
         posy=y;
     }
     
     int Sprite::MoveLeft(){
       return  posx=posx-2;
     }
     
     int Sprite::MoveRight(){
        return posx=posx+2;
     }
     
     int Sprite::GetPosX(){
     
         return posx;
     }
     
     int Sprite::GetPosY(){
     
         return posy;
     }











void Sprite::LoadShipType( char ShipType[2]){
 
 shiptype[0] = ShipType[0]; 
 
    if(shiptype[0] == 'P' ){
    ship = al_load_bitmap("Graphics/Fighter.png");
    }
  
   if(shiptype[0]== 'E'){
     ship = al_load_bitmap("Graphics/greenzipper.png");  
    }    
}
   

int Sprite::CreateShip(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy){
   
     return speedx; 
   }
   
   
void Sprite::UpdateSprite(ALLEGRO_BITMAP* Image,int height, int width, float speedx, float speedy ){
     
     
     
     }
   
     
void Sprite::SpriteCollision(ALLEGRO_BITMAP& image,ALLEGRO_BITMAP& imagetwo){
     
     
     }
    
ALLEGRO_BITMAP* Sprite:: GetShip(){
    
    return ship;
    
}


