#ifndef _COMMONADMIN_H_
#define _COMMONADMIN_H_
#include"file.h"
#include"inputString.h"
#include<stdlib.h>
#include<string.h>

void CommonAdmin_ui();
int CommonAdmin(FILE *staff_fp,LIST *staff_head,STAFF *staff_node);

void CommonAdmin_adduser_ui();

int CommonAdmin_adduser(FILE *staff_fp,LIST *staff_head);

void CommonAdmin_queryuser_ui();

int CommonAdmin_queryuser(FILE *staff_fp,LIST *staff_head);

void CommonAdmin_deleteuser_ui();
int CommonAdmin_deleteuser(FILE *staff_fp,LIST *staff_head);

void CommonAdmin_modifyuser_ui();
int CommonAdmin_modifyuser(FILE *staff_fp,LIST *staff_head,STAFF *staff_node);

#endif