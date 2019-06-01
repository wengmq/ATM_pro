#ifndef _INPUTSTRING_H_
#define _INPUTSTRING_H_
#include"login.h"
#include<stdlib.h>
int Gotoxy(int x,int y);
/*****************************************************************************
	名称：控制输入函数
	参数：
		maxlen表示: 最大输入字符数
		putType表示: 
			0 (无控制)  1(只能输入数字)  2(只能输入字母)
		    3 (只能输入数字和字母)
		isPlaintext表示是否显示明文 1表示明文 0表示密文

 ************************************************************************/
int glb_putString(char str[20],int iMaxlen,int iPuttype,int isPlaintext);

void putString(char str[], int iMaxLen, int iPutType, int isPlaintext);

int time_putString(char str[], int iMaxLen);

int login_putString(char str[], int iMaxLen, int iPutType, int isPlaintext);
#endif