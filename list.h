#ifndef _LIST_H_
#define _LIST_H_
#include<stdio.h>
#include<stdlib.h>
/*
typedef struct studentData{
	char acNO[10];  
	char acName[10];  
	int iAge;  
	int aScore;  
}STU_DATA;
*/
#include"struct.h"

typedef struct list
{
	void *Data;  /*������*/ 
	struct list *next;/*ָ����*/
}LIST;



//��ʼ������
	void *List_Init(void *data);

//�������ڵ�
	void List_Add(LIST *head,void *data);

//��ȡ����ڵ����
	int List_Count(LIST *head);

//Index---����ڵ��ţ�head---����ͷ�ڵ�
//��ȡ����ĳ���ڵ�(��������ڵ��data)
	void *List_GetNode(LIST *head,int Index);

/*��ȡ�����Index�����ڵ��������*/
void *List_GetNode_Data(LIST *head,int Index);

//�ͷ�����
	void * List_Free(LIST *head);

//ɾ�������ĳ���ڵ�
	void List_Del(LIST *head,int Index);


//��ӡStaff������Ϣ
	void Staff_Printf(LIST *head);

//�ж��������Ƿ����sName�û�
	int ExistUser(LIST *staff_head,char *sName);



/******************************************************
�������ܣ��������ж�ȡ������ӵ����ļ�ĩβ
head��Դ����                     fp��Ŀ���ļ�
size���ڵ��������Ľṹ���С   num��Ҫ��ӵĽڵ�����
******************************************************/
    FILE * list2file(LIST *head,FILE *fp,int size,int num);


/******************************************************
�������ܣ����ļ���ʼλ�ö�ȡ���ݵ�������
head��Ŀ������                     fp��Դ�ļ�
size���ڵ��������Ľṹ���С   num��Ҫ��ӵĽڵ�����
******************************************************/
    LIST * file2list(LIST *head,FILE *fp,int size,int num);

#endif