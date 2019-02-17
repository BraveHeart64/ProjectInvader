#include"GameEngine.h"
#include<iostream>


GameEngine::GameEngine() {
	al_init();
	que = al_create_event_queue();

	gameclock  = al_create_timer(1.0 / FramesPerSecond);
	al_start_timer(gameclock);

	if (!gameclock) {
	
		al_show_native_message_box(0, "AL_INIT_TIMER", "AL_TIMER!", "The Game clock has failed :(", 0, 0);
	}


	if (!que) {
		
		al_show_native_message_box(0, "AL_que_event_error", "que event failed", "!the que failed on create", 0, 0);
		al_destroy_timer(gameclock);

	}
}



GameEngine::~GameEngine(){
	al_destroy_timer(gameclock);
	al_destroy_event_queue(que);

}



ALLEGRO_EVENT_QUEUE * GameEngine::ReturnTheQue() {

	return que;
}
ALLEGRO_EVENT GameEngine::ReturnEvent() {

	return event;
}


ALLEGRO_EVENT &GameEngine::RefOfEvent() {

	return event;
}


ALLEGRO_TIMER * GameEngine::ReturnGameClockTicks() {

	return gameclock;

}


bool GameEngine::HitDection(Sprite &one, Sprite &two) {
	int spritewidth = al_get_bitmap_height(two.GetSprite())- 2;

	if(one.GetShotx() + spritewidth < two.GetPosX() || one.GetShotx() > two.GetPosX() + spritewidth
		|| one.GetShoty() + spritewidth < two.GetPosY() ||
			one.GetShoty() > two.GetPosY() + spritewidth) {
		return false;
	}
	else {
		two.SetPosX(4000);

	}

	/*
		if(one.GetShotx() + al_get_bitmap_width(one.GetSprite()) < two.GetPosX() || one.GetShotx() > two.GetPosX() + al_get_bitmap_width(two.GetSprite())
		|| one.GetShoty() + al_get_bitmap_height(one.GetSprite()) < two.GetPosY() ||
			one.GetShoty() > two.GetPosY() + al_get_bitmap_height(two.GetSprite())) {
		return false;
	}
	else {
		two.SetPosX(4000);

	}

	
	*/
	return true;
}

void GameEngine::PaintSptirts(Sprite &playerone, Sprite aiplayer[],int slot) {
	slot = 0;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(playerone.GetSprite(), playerone.GetPosX(), playerone.GetPosY(), 0);
	al_draw_bitmap(aiplayer[slot].GetSprite(), aiplayer[slot].GetPosX(), aiplayer[slot].GetPosY(), 0);
	slot++;
	al_draw_bitmap(aiplayer[slot].GetSprite(), aiplayer[slot].GetPosX(), aiplayer[slot].GetPosY(), 0);

	if (playerone.ShotFired() == true) {
		al_draw_bitmap(playerone.LoadShotToScreen(), playerone.GetShotx(), playerone.GetShoty(), 0);

	}


}