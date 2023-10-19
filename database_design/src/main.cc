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



unsigned char fps = 60;
double current_time, last_time;
const int kWindow_width = 800, kWindow_height = 600;





int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindow_width,kWindow_height);
  WindowSetMouseVisibility(true);
  srand(time(NULL));
  


  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)){

  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    


    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  esat::WindowDestroy();

  return 0;
}