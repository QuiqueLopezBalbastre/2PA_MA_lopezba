

#ifndef __INTERFACE_H__
#define __INTERFACE_H__ 1

struct GlobalData;

struct TableEmployee
{
    int id;
    char name[40];
    char surname[40];
    char adress[40];
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

static int TableEmployeeCallback(void *data, int argc, char **argv, char **colNames);

static int TableCompanyCallback(void *data, int argc, char **field_values, char **colNames);

static int TableCityCallback(void *data, int argc, char **field_values, char **colNames);

int TableCountryCallback(void *data, int argc, char **field_values, char **colNames);

void InitTable(int id);

int ShowDatabaseTable(GlobalData *info);

void Login(GlobalData *info);

void ButtonsWindow(GlobalData *info);

#endif
