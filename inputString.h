#ifndef _INPUTSTRING_H_
#define _INPUTSTRING_H_
#include"login.h"
#include<stdlib.h>
int Gotoxy(int x,int y);
/*****************************************************************************
	���ƣ��������뺯��
	������
		maxlen��ʾ: ��������ַ���
		putType��ʾ: 
			0 (�޿���)  1(ֻ����������)  2(ֻ��������ĸ)
		    3 (ֻ���������ֺ���ĸ)
		isPlaintext��ʾ�Ƿ���ʾ���� 1��ʾ���� 0��ʾ����

 ************************************************************************/
int glb_putString(char str[20],int iMaxlen,int iPuttype,int isPlaintext);

void putString(char str[], int iMaxLen, int iPutType, int isPlaintext);

int time_putString(char str[], int iMaxLen);

int login_putString(char str[], int iMaxLen, int iPutType, int isPlaintext);
#endif