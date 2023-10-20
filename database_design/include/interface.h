

#ifndef __INTERFACE_H__
#define __INTERFACE_H__ 1

struct GlobalData;

struct Ttable1{
int id;
char name[40];
char surname[40];
char adress[40];
int company;
int city;
int nacionality;
int salary;
};

static int ImGuiCallback(void* data, int argc, char** argv, char** colNames);

void Inittable();

int ShowDatabaseTable(void);


//void ShowDatabaseTable(/*const char *table_selected*/GlobalData *info);

void Login(GlobalData *info);

void Buttons(GlobalData *info);

#endif

