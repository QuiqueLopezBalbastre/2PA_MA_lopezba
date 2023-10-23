/// @file global_data.h
/// @brief General data.
/// @author Sergio Madaleno <madalenofi@esat-alumni.es>

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
  Country
};



/// Global variable struct
struct GlobalData
{

  int table_id;

  char *user_query=nullptr;
  bool query_execute=false;

  unsigned char fps = 60;
  double current_time, last_time;
};

#endif
