#ifndef VARIABLES
#define VARIABLES

#include <esat/math.h>

#define PI 3.14159265

struct TBall
{
    esat::Vec2 position, speed, scale, direction;
    bool active;
    int initial_direction;
};

struct TBrick
{
    esat::Vec2 position, scale;
    bool active;
    int hp;
};

struct TPlayer
{
    esat::Vec2 position, speed, scale;
    esat::Vec2 *points, *world_points;
};
enum struct TWindowType
{
    main_menu,
    start_game,
    quit_game
};

extern const int kBrick_cols;
extern const int kBrick_rows;

extern TBall g_ball;
extern TBrick g_brick[8][11];
extern TWindowType window_type;

extern TPlayer g_player;

extern float ball_coords[30 * 2];
extern float transformed_coords[30 * 2];

extern const int num_ball_points;
extern bool initBall;

extern esat::Vec2 RightDown;
extern esat::Vec2 RightUp;
extern esat::Vec2 LeftUp;
extern esat::Vec2 LeftDown;

extern float kCricunfernece;
extern const int kNumPointsBrick;
extern float transformed_brick[2 * 4];

extern float brick_points[8];

extern const int kWindowWidth, kWindowHeight;
extern unsigned char fps;
extern double current_time, last_time;

struct GameData{
    esat::Vec2 player_position, ball_position;
    bool ball_active;
    TBrick brick[8][11];
    int window_status;
};


#endif