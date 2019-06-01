#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <windows.h>
#include"admin.h"
#include"user.h"
#include"list.h"
#include"struct.h"
#include"inputString.h"

	void loginInit();
	int ChooseMenu(int IChoose,STAFF *staff_node,LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp);
    void login(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp);


	//void login_putString(char str[], int iMaxLen, int iPutType, int isPlaintext);
#endif