/// @file global_data.h
/// @brief General data.
/// @author Sergio Madaleno <madalenofi@esat-alumni.es>

#ifndef __GLOBAL_DATA_H__
#define __GLOBAL_DATA_H__ 1

#include <esat/math.h>


// Constants
const int kWindow_width = 800, kWindow_height = 600;




struct GlobalData {

  char user_name[40];
  char pass_word[40];

    unsigned char fps = 60;
  double current_time, last_time;
};


#endif

