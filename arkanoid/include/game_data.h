/// @file game_data.h
/// @brief General game data.
/// @author Gustavo Aranda <garanda@esat.es>

#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__ 1

#include <esat/math.h>

#include "bricks.h"
#include "ball.h"
#include "player.h"

#define PI 3.1416f

enum TWindowType {
  kTWindowType_MainMenu,  // main_menu,
  kTWindowType_StartGame, // start_game,
  kTWindowType_QuitGame   // quit_game
};

// Constants
const int kBrick_cols = 8;
const int kBrick_rows = 11;
const int kNum_ball_points = 30;
const int kNum_points_brick = 4;
const float kCircunference = 2.0f * PI;
const int kWindow_width = 1200, kWindow_height = 800;


struct GameData {
  esat::Vec2 player_position, ball_position;
  bool ball_active;
  TBrick brick[8][11];
  int window_status;

  TBall ball;
  TPlayer player;
  TBrick brick[8][11];
  TWindowType window_type;

  float ball_coords[30 * 2] = {0.0f};
  float transformed_coords[30 * 2] = {0.0f};

  esat::Vec2 right_down = {1.0f, 1.0f};
  esat::Vec2 right_up   = {1.0f, -1.0f};
  esat::Vec2 left_up    = {-1.0f, -1.0f};
  esat::Vec2 left_down  = {-1.0f, 1.0f};

  float transformed_brick[2 * kNum_points_brick] = {0.0f};

  float brick_points[8] = {
        -1.0f,
        0.5f,
        1.0f,
        0.5f,
        1.0f,
        -0.5f,
        -1.0f,
        -0.5f,
  };
    
  unsigned char fps = 60;
  double current_time, last_time;
};


#endif

