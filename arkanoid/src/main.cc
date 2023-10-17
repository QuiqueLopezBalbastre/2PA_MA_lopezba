//Authors: Sergio Madaleno and Enrique López
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <esat/helpers.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "../include/ball.h"
#include "../include/bricks.h"
#include "../include/collisions.h"
#include "../include/interface.h"
#include "../include/player.h"
//#include "variables.cc"
#include "game_data.h"

void Init(GameData* game_data){

  InitBall(game_data);
  game_data->g_player = InitPlayer();
  InitBrick(game_data);
}

void Draw(GameData* game_data){

  DrawBall(&(game_data->g_ball));
  DrawPlayer(&(game_data->g_player));
  DrawBrick(&(game_data->g_brick));
}

void Update(GameData* game_data){

  UpdateBall(&(game_data->g_ball));
  PlayerMovement(&(game_data->g_player));
  UpdateBrick(&(game_data->g_brick));
}

void Game(GameData* game_data){

  switch(window_type){

    case TWindowType::main_menu:
        MainMenu(game_data);
        break;

    case TWindowType::start_game:
        Draw(game_data);
        Update(game_data);
        break;
  }
}

int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindowWidth,kWindowHeight);
  WindowSetMouseVisibility(true);
  srand(time(NULL));

  // Create GameData instance
  GameData game_data;

  Init(&game_data);

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && window_type != TWindowType::quit_game){

  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    
    Game(&game_data);

    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  esat::WindowDestroy();

  return 0;
}

