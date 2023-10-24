

#ifndef __INTERFACE_H__
#define __INTERFACE_H__ 1

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
