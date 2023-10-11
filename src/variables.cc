#include "../include/variables.h"

const int kBrick_cols = 8;
const int kBrick_rows = 11;

// TBall g_ball;
// TBrick g_brick[kBrick_cols][kBrick_rows];
// TPlayer g_player;
// TWindowType window_type = TWindowType::main_menu;

float ball_coords[30 * 2] = {0.0f};
float transformed_coords[30 * 2] = {0.0f};

const int num_ball_points = 30;
bool initBall = false;

esat::Vec2 RightDown = {1.0f, 1.0f};
esat::Vec2 RightUp = {1.0f, -1.0f};
esat::Vec2 LeftUp = {-1.0f, -1.0f};
esat::Vec2 LeftDown = {-1.0f, 1.0f};

float kCricunfernece = 2 * PI;
const int kNumPointsBrick = 4;
float transformed_brick[2 * kNumPointsBrick] = {0.0f};

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

const int kWindowWidth=1200, kWindowHeight=800;
unsigned char fps=60;
double current_time, last_time;
