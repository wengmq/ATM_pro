#ifndef _ADMIN_H_
#define _ADMIN_H_
#include"file.h"
#include"inputString.h"
#include<stdlib.h>
#include<string.h>

void admin_ui();
int admin(FILE *staff_fp,LIST *staff_head);

void admin_adduser_ui();
int ExistUser(LIST *staff_head,char *sName);
int admin_adduser(FILE *staff_fp,LIST *staff_head);

void admin_queryuser_ui();
void staff_show(int page, LIST *staff_head);
LIST *get_list_by_role(LIST *staff_head,int Role);
int admin_queryuser(FILE *staff_fp,LIST *staff_head);

void admin_deleteuser_ui();
int admin_deleteuser(FILE *staff_fp,LIST *staff_head);

void admin_modifyuser_ui();
int admin_modifyuser(FILE *staff_fp,LIST *staff_head);

#endif