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
#include "../include/game_data.h"


void Init(GameData* info){

  InitBall(info);
  info->player = InitPlayer();
  InitBrick(info);
}

void Draw(GameData* info){
  DrawBall(*(info));
  DrawPlayer((info->player));
  DrawBrick(*(info));
}

void Update(GameData* game_data){
  UpdateBall(&(game_data->ball));
  PlayerMovement((game_data), &game_data->player);
  UpdateBrick((game_data));
}

void Game(GameData* info){

  switch(info->window_type){

    case TWindowType::kTWindowType_MainMenu:
        MainMenu(info);
        break;

    case TWindowType::kTWindowType_StartGame:
        Draw(info);
        Update(info);
        break;
  }
}

int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindow_width,kWindow_height);
  WindowSetMouseVisibility(true);
  srand(time(NULL));
  
  GameData game_data;

  Init(&game_data);

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && game_data.window_type != TWindowType::kTWindowType_QuitGame){

  	game_data.last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    
    Game(&game_data);

    esat::DrawEnd();

   do{
    game_data.current_time = esat::Time();
    }while((game_data.current_time-game_data.last_time)<=1000.0/game_data.fps);
    
   esat::WindowFrame();
  }

  esat::WindowDestroy();

  return 0;
}

