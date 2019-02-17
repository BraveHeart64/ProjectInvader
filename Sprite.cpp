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
     height= width=0;
     speedx=speedy=0.0;
    recharge = true;
    
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
    shot[0] = 0;
    shot[1] =0;
    shot[2] = 0;
    al_destroy_bitmap(ship);
    firing = false;
  
    
    
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

     
     
     void Sprite::ShipShot(){
         
         if(recharge == true){
            shotx = posx+27;
            shoty = posy-20;
            firing = true;
         }  
     }

     
     
     int Sprite::GetShotx(){
         return shotx;
     }
     
     
     
     bool Sprite::Recharge(){
       return  recharge = false;
     }
     
     
     int Sprite::GetShoty(){
         shoty = shoty -2;
      
         
         if(shoty <= 10){
             shoty = -100;
             recharge = true;
         }
         return shoty;
     }
     
     
     bool Sprite::ShotFired(){
         return firing;
         
     }
     

   





void Sprite::LoadShipType( char ShipType[2]){
 
 shiptype[0] = ShipType[0]; 
 
    if(shiptype[0] == 'P' ){
     ship = al_load_bitmap("Graphics/Fighter.png");
     
     shot[0] = al_load_bitmap("Graphics/CommetShot.png");
     shot[1] = al_load_bitmap("Graphics/CommetShot.png");
     shot[2] = al_load_bitmap("Graphics/CommetShot.png");
   
     
    } 
   if(shiptype[0]== 'E'){
     ship = al_load_bitmap("Graphics/greenzipper.png");
     
     shot[0] = al_load_bitmap("Graphics/ BoltShot.png");
     shot[1] = al_load_bitmap("Graphics/ BoltShot.png");
     shot[2] = al_load_bitmap("Graphics/ BoltShot.png");
   
    }    
}
   

  ALLEGRO_BITMAP* Sprite::LoadShotToScreen(){
         
          
         
         return shot[0];
     }








ALLEGRO_BITMAP* Sprite:: GetSprite(){
    
    return ship;
    
}


