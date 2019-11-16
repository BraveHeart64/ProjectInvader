#include"Animation.h"


int Animation_Right_X(int frames_x){
    int max_movement = 9;


    if(frames_x >= max_movement){
        frames_x = 0;
    }
    else{
        frames_x++;
    }

    return frames_x;
}




int Animation_Left_X(int frames_x){
    int max_movement = -1;


    if(frames_x != max_movement){
        frames_x = 7;
    }
    else{
        frames_x--;
    }

    return frames_x;
}




// the Y Animation is for Jumping
int Animation_Y(int frames_y){


    return frames_y;

}

// animate character shooting on the Y Axis
int Animation_Attacking_X(int frames_x){
    if(frames_x >=2){
        return frames_x == 0;
    }

    return frames_x;
}


int Animation_Attacking_Y(int frames_y){

    return frames_y;
}

