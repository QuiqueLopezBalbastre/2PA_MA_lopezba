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
#include "../include/global_functions.h"
#include "../include/show_tables.h"
#include "../include/buttons_window.h"
#include "../include/query_window.h"
#include "../include/insertdata.h"
#include "../include/remove_data.h"

int esat::main(int argc, char **argv)
{
  esat::WindowInit(kWindow_width, kWindow_height);
  WindowSetMouseVisibility(true);
  srand(time(NULL));

  GlobalData global_data;
  global_data.user_query = (char *)calloc(80, sizeof(char));
  esat::SpriteHandle esat_logo = esat::SpriteFromFile("../data/esat_logo.png");

  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape))
  {

    global_data.last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    TopWindow(&global_data);

    CreateWindow("Menu selection window", {20.0f, 60.0f}, {140.0f, 250.0f});
    MenuSelectionWindow(&global_data);
    CloseWindow();
    CreateWindow("Table selection window", {20.0f, 320.0f}, {140.0f, 310.0f});
    if (global_data.menu_id == MenuSelector::kMenuSelector_ShowTable ||
        global_data.menu_id == MenuSelector::kMenuSelector_RemoveData ||
        global_data.menu_id == MenuSelector::kMenuSelector_InsertData ||
        global_data.menu_id == MenuSelector::kMenuSelector_UpdateData)
    {
      TableSelectionWindow(&global_data);
    }
    CloseWindow();
    CreateWindow("Main window", {180.0f, 60.0f}, {1000, 570});
    switch (global_data.menu_id)
    {

    case MenuSelector::kMenuSelector_InitialMenu:
      esat::DrawSprite(esat_logo, kWindow_width * 0.45f, kWindow_width * 0.20f);
      break;

    case MenuSelector::kMenuSelector_ShowTable:
      global_data.structb = false;
      ShowDatabaseTable(&global_data);
      break;

    case MenuSelector::kMenuSelector_UpdateData:
      Updatevalues(&global_data);
      break;

    case MenuSelector::kMenuSelector_InsertData:
      InsertDataTable(&global_data);
      break;

    case MenuSelector::kMenuSelector_RemoveData:
      RemoveData(&global_data);
      break;
    case MenuSelector::kMenuSelector_ShowDatabase:
      global_data.structb = true;
      ShowDatabaseStructure(&global_data);
      break;
    case MenuSelector::kMenuSelector_Query:
      // ShowQuery();
      ShowQuery(&global_data);
      break;
    }
    CloseWindow();
    /*
     */
    CreateWindow("Bottom window", ImVec2(20.0f, 640.0f), ImVec2(1160, 150));
    BottomWindow(&global_data);
    CloseWindow();

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