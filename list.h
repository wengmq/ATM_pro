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
	void *Data;  /*数据域*/ 
	struct list *next;/*指针域*/
}LIST;



//初始化链表
	void *List_Init(void *data);

//添加链表节点
	void List_Add(LIST *head,void *data);

//获取链表节点个数
	int List_Count(LIST *head);

//Index---链表节点编号，head---链表头节点
//获取链表某个节点(返回链表节点的data)
	void *List_GetNode(LIST *head,int Index);

/*获取链表第Index个个节点的数据域*/
void *List_GetNode_Data(LIST *head,int Index);

//释放链表
	void * List_Free(LIST *head);

//删除链表的某个节点
	void List_Del(LIST *head,int Index);


//打印Staff链表信息
	void Staff_Printf(LIST *head);

//判断链表中是否存在sName用户
	int ExistUser(LIST *staff_head,char *sName);



/******************************************************
函数功能：从链表中读取数据添加到到文件末尾
head：源链表                     fp：目标文件
size：节点的数据域的结构体大小   num：要添加的节点数量
******************************************************/
    FILE * list2file(LIST *head,FILE *fp,int size,int num);


/******************************************************
函数功能：从文件起始位置读取数据到链表中
head：目标链表                     fp：源文件
size：节点的数据域的结构体大小   num：要添加的节点数量
******************************************************/
    LIST * file2list(LIST *head,FILE *fp,int size,int num);

#endif