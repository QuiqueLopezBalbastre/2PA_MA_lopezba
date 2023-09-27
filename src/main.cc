//Authors: Sergio Madaleno and Enrique López
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <esat/helpers.h>
#include <esat_extra/imgui.h>


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "../include/variables.h"
#include "../include/ball.h"
#include "../include/bricks.h"
#include "../include/collisions.h"
#include "../include/interface.h"
#include "../include/player.h"

void Init(){

  InitBall();
  g_player = InitPlayer();
  InitBrick();
}

void Draw(){

  DrawBall(g_ball);
  DrawPlayer(g_player);
  DrawBrick(g_brick);
}

void Update(){

  UpdateBall(&g_ball);
  PlayerMovement(&g_player);
  UpdateBrick(g_brick);
}

void Game(){

  switch(window_type){

    case TWindowType::main_menu:
        MainMenu();
        break;

    case TWindowType::start_game:
        Draw();
        Update();
        break;
  }
}

int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindowWidth,kWindowHeight);
  WindowSetMouseVisibility(true);

  srand(time(NULL));
  Init();

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && !quit_game){

  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    
    Game();

    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  esat::WindowDestroy();

  return 0;
}

