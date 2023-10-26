/**
 * @file global_data.cc
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __GLOBAL_DATA_H__
#define __GLOBAL_DATA_H__ 1

#include <esat/math.h>

/// Constants
const int kWindow_width = 1200, kWindow_height = 800;
const int kRows = 3;
const int kTableEmployeeRows = 3;
const int kTableCompanyRows = 6;
const int kTableCityRows = 15;
const int kTableCountryRows = 5;


enum TableSelector
{
  Employee,
  Company,
  City,
  Country,
  Database
};

enum MenuSelector
{
  kMenuSelector_InitialMenu,
  kMenuSelector_ShowTable,
  kMenuSelector_ShowDatabase,
   kMenuSelector_UdateData,
  kMenuSelector_InsertData,
  kMenuSelector_RemoveData
};

/// Global variable struct
struct GlobalData
{
  int table_id;
  int menu_id;

  char *user_query=nullptr;
  
  char struct_database[80]="Select name From sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%'\0";

  bool query_execute=false;
  bool structb=false;
  unsigned char fps = 60;
  double current_time, last_time;
};

#endif
