/**
 * @file show_tables.cc
 * @author Federico Sanjuan (sanjuanbare@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __SHOW_TABLES_H__
#define __SHOW_TABLES_H__ 1

struct GlobalData;

struct TableEmployee
{
    int id;
    char name[40];
    char surname[40];
    char address[40];
    int company;
    int city;
    int nacionality;
    int salary;
};

struct TableCompany
{
    int id;
    char name[40];
    char country[40];
};

struct TableCity
{
    int id;
    char name[40];
    char country[40];
};

struct TableCountry
{
    int id;
    char name[40];
};

void InitTable(int id);

static int TableEmployeeCallback(void *data, int argc, char **argv, char **colNames);

static int TableCompanyCallback(void *data, int argc, char **field_values, char **colNames);

static int TableCityCallback(void *data, int argc, char **field_values, char **colNames);

static int TableCountryCallback(void *data, int argc, char **field_values, char **colNames);

int ShowDatabaseTable(GlobalData *info);

void ShowQuery(GlobalData *info);

void Updatevalues(GlobalData* info);

void Executevalues(const char* sql);

void CreateWindow();
void CloseWindow();
#endif
