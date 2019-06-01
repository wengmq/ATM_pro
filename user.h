#ifndef _USER_H_
#define _USER_H_
#include"file.h"
#include"inputString.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>

void user_MoneyQuery_ui();
int user_MoneyQuery(STAFF *staff_node);

void user_ModifyPsw_ui();
int user_ModifyPsw(FILE *staff_fp,LIST *staff_head,STAFF *staff_node);


void user_QueryBill_ui();
LIST *GetPersonalBill(LIST *bill_head,STAFF *staff_node);
int user_QueryBill(LIST *bill_head,STAFF *staff_node);

void user_ui();
int user(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node);

void user_PutMoney_ui();
int user_PutMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node);

void user_GetMoney_ui();
int user_GetMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node);


void user_GiveMoney_ui();
int user_GiveMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node);

#endif