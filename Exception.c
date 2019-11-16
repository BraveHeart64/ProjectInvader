
#include<stdio.h>
#include<allegro5/allegro.h>
#include"Exception.h"



int CheckForNullforDisplay(ALLEGRO_DISPLAY* mydisplay,int check){

    if(mydisplay == 0){
     al_destroy_display(mydisplay);
        printf("%s","The Display has a null value");
       return check = 1;
    }
    return check;

}



int CheckForNullFont(ALLEGRO_FONT* myfont,int check){


     if(myfont == 0){
       al_destroy_font(myfont);
       printf("%s","The font has a Null value");
       return check = 1;
    }
    return check;
}



int CheckForNullBitMap(ALLEGRO_BITMAP* mybitmap,int check){


     if(mybitmap == 0){
        al_destroy_bitmap(mybitmap);
        printf("%s","The BitMap has a Null value");
       return check = 1;
    }
    return check;
}


int CheckForNullIcon(ALLEGRO_BITMAP* icon,int check){


     if(icon == 0){
        al_destroy_bitmap(icon);
        printf("%s","The BitMap has a Null value");
        check = 1;
        return check;
    }
    return check;
}
