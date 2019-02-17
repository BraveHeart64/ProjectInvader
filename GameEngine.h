#pragma once

#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5\allegro_native_dialog.h>
#include"Sprite.h"


class GameEngine : Sprite{

private:
	ALLEGRO_EVENT_QUEUE *que;
	ALLEGRO_EVENT event;
	ALLEGRO_TIMER * gameclock;
	const float FramesPerSecond = 60;
	Sprite playerone, aiplayer[10];


public:


	ALLEGRO_EVENT_QUEUE * ReturnTheQue();
	ALLEGRO_EVENT ReturnEvent();
	ALLEGRO_TIMER * ReturnGameClockTicks();
	ALLEGRO_EVENT &RefOfEvent();
	void PaintSptirts(Sprite &playerone,Sprite aiplayer[],int slot );
	bool HitDection(Sprite &one, Sprite &two);
	void GamePhysics();
	void GameCondition();
	void LevelCounter();
	

	GameEngine();
	~GameEngine();


};