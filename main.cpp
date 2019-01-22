/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ryan
 *
 * Created on January 20, 2019, 9:41 PM
 */

#include<allegro5/allegro5.h>
#include<iostream>
#include"MyWindow.h"
using namespace std;






int main(int argc, char ** argv){


MyWindow window;


window.GameLoop();







return 0;
}
