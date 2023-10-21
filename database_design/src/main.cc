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

#include "../include/global_data.h"
#include "../include/interface.h"



int esat::main(int argc, char **argv)
{
  esat::WindowInit(kWindow_width, kWindow_height);
  WindowSetMouseVisibility(true);
  srand(time(NULL));

  GlobalData global_data;

  //ShowDatabaseTable();
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape))
  {

    global_data.last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    Login(&global_data);
    //ShowDatabaseTable(&global_data);
    Buttons(&global_data);
    ShowDatabaseTable(&global_data);
    esat::DrawEnd();

    do
    {
      global_data.current_time = esat::Time();
    } while ((global_data.current_time - global_data.last_time) <= 1000.0 / global_data.fps);

    esat::WindowFrame();
  }

  esat::WindowDestroy();

  return 0;
}