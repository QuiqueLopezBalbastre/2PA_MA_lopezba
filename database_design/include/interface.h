

#ifndef __INTERFACE_H__
#define __INTERFACE_H__ 1

struct GlobalData;

static int ImGuiCallback(void* data, int argc, char** argv, char** colNames);


void ShowDatabaseTable(/*const char *table_selected*/GlobalData *info);

void Login(GlobalData *info);

void Buttons(GlobalData *info);

#endif

