/// @brief database.h header file  
/// @author Fede Sanjuan <sanjuanbare@esat-alumni.com>

#ifndef __DATABASE_H__
#define __DATABASE_H__ 1


#include <esat_extra\sqlite3.h>



struct Ttable1{
int id;
char name[16];
char adress[16];
char city[16];
};

struct Ttable2{
int id;
char name[16];
char city[16];
};


struct Ttable3{
int id;
int id_company;
char city[16];
};


struct Ttable4{
int id;
int id_employee_;
int id_company_;
float salary;
};






/** @brief initializes struct with default values. .
* 
*/

void InitStruct();

/** @brief initializes struct with default values. .
* @param used pointer void.
* @param init_colums colums.
* @param field_values result colum.
* @param colum_names num of the colums.
*/

int CallbackTables(void * used, int num_columns, char **field_values, char **colum_names); 


int CallbackTables(void *, int, char **, char **);

/** @brief Change de CallBack in the main .
* @param void pointer the struct.

*/
int ChargeTable1(void);
int ChargeTable2(void);
int ChargeTable3(void);
int ChargeTable4(void);


#endif
