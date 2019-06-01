#include"list.h"


   /*初始化链表*/
void *List_Init(void *data)
{
	LIST *head = NULL;
	head = (LIST *)malloc(sizeof(LIST));
	head->Data = data; //给头结点赋值
	head->next = NULL; //头结点指针域初始化为NULL

	return head; //返回头节点指针
}

     /*添加链表节点*/
void List_Add(LIST *head,void *data)
{
	LIST * pnew = NULL;
	LIST * ptemp = head;
	pnew = List_Init(data);//初始化新节点
  /*链表的最后一个节点的指针域为NULL，
	所以遍历循环找到最后一个节点*/
	while(NULL != ptemp->next)  
	{
		ptemp = ptemp->next;
	}
	ptemp->next = pnew;
	pnew->Data = data;//给新加的节点赋值
	pnew->next = NULL;
}

/*获取链表节点个数*/
int List_Count(LIST *head)
{
	LIST * ptemp = head;
	int count = 0;
	/*循环遍历*/
	while(ptemp != NULL)
	{
		count++;
		ptemp = ptemp->next;
	}
	return count;
}


/*获取链表第Index个个节点*/
void *List_GetNode(LIST *head,int Index)
{
	LIST *ptemp= head;
	int num = 1; 
	while(NULL != ptemp->next && num<Index )
	{ 
		ptemp = ptemp->next;
		num++;
	}
	return ptemp;
}

/*获取链表第Index个个节点的数据域*/
void *List_GetNode_Data(LIST *head,int Index)
{
	LIST *ptemp= head;
	int num = 1;
	
	if(ptemp ==NULL)
	{
		return NULL;
	}

	while(NULL != ptemp->next && num<Index )
	{ 
		ptemp = ptemp->next;
		num++;
	}
	return ptemp->Data;
}
    
/*释放链表，并返回头结点*/
void *List_Free(LIST *head)
{
	LIST *pnext = head;
	while(pnext != NULL)
	{
		pnext = pnext->next;
	/*先释放数据存储的内存空间*/
		free(head->Data);
	/*再释放链表节点的内存空间*/
		free(head);
		head = pnext;
	}
    return head;
}

 /*删除链表的第Index个节点*/
void List_Del(LIST *head,int Index)
{
	LIST *ptemp = head;
	LIST *pnext = NULL;
	/*调用函数返回第index-1个节点*/
	ptemp  = List_GetNode(head,Index-1);
	if(NULL != ptemp->next)
	{   /*真删除*/
		pnext = ptemp->next;
		ptemp->next = pnext->next;
		free(pnext);
	}
}
//判断链表中是否存在sName用户
int ExistUser(LIST *staff_head,char *sName)
{
	   STAFF *data = NULL;
	   LIST *ptemp = staff_head;
		while(ptemp != NULL)
		{
			data = (STAFF *)(ptemp->Data);
			if(strcmp(data->sName,sName) == 0)
			{
				return -1;//已存在用户返回-1
			}

				ptemp = ptemp->next;
		}	

		return 1;


}

/******************************************************
函数功能：从链表中读取数据添加到到文件末尾
head：源链表                     fp：目标文件
size：节点的数据域的结构体大小   num：要添加的节点数量
******************************************************/
  FILE * list2file(LIST *head,FILE *fp,int size,int num)
   {
	   int flag = 0;//用来控制输出节点个数
	   LIST * ptemp = head;
	   if(fp)
	   {
			while(flag<num)
			{
				fseek(fp,0,SEEK_END);
				fwrite(ptemp->Data,size,1,fp);
				fflush(fp);//刷新到文件中

				ptemp = ptemp->next;
				flag++;
			}
	   }	
		return fp;	
   }

/******************************************************
函数功能：从文件起始位置读取数据到链表中
head：目标链表                     fp：源文件
size：节点的数据域的结构体大小   num：要添加的节点数量
******************************************************/
   LIST *file2list(LIST *head,FILE *fp,int size,int num)
   {  
	   void * data = NULL;
	   LIST * ptemp = head;
	   int FileSize  = 0;
	   int flag = 0;

	   if(fp)
	   {

		   	rewind(fp);
			fseek(fp,0,SEEK_END);//偏移到文件尾部
         	FileSize = ftell(fp)/size;//获取当前文件的总的单元数
	        //printf("%d",FileSize);
			if(num>FileSize)
			{
				num = FileSize;
			}

		   if(NULL == ptemp  )
		   {
			   data = (void *)malloc(size);
			   rewind(fp);
			   fread(data,size,1,fp);
			   ptemp = List_Init(data);
				num--;
		   }
		   else if (NULL == ptemp->Data)
		   {
			   data = (void *)malloc(size);
			   rewind(fp);
			   fread(data,size,1,fp);
			   ptemp = List_Init(data);					
			   num--;
		   }
		   else
		   {  rewind(fp);}

		   while(flag<num )
		   {
			   data = NULL;
			   data = (void *)malloc(size);
			   fread(data,size,1,fp);
			   List_Add(ptemp,data);
			   flag++;
		   }
	   }
     return ptemp;	
   }



   /*打印用户结构体链表（不通用）*/
void Staff_Printf(LIST *head)
{
	LIST *ptemp = head;
	STAFF *data = NULL;
	int x=5 ;
	int y=7 ;

		printf("\n");
	printf(" *********************************************************************************\n");
	printf(" *                                 查询用户界面                                  *\n");
	printf(" *********************************************************************************\n");
	printf(" *   用户名   *      账号     *    密码    *  身份  * 是否销户 *      余额       *\n");
	printf(" *********************************************************************************\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *|           |               |            |        |          |                |*\n");
	printf(" *********************************************************************************\n");

	while(NULL !=ptemp)
	{
/*把void类型指针赋值给其他类型的指针，需要强制转化*/
		data = ((STAFF *)(ptemp->Data));

		Gotoxy(x,y);
		printf("%s",data->sName);
		Gotoxy(x+14,y);
		printf("%s",data->sAccount);
		Gotoxy(x+29,y);
		printf("%s",data->sPwd);
		Gotoxy(x+41,y);
		printf("%d",data->iRole);
		Gotoxy(x+52,y);
		printf("%d",data->iEixt);
		Gotoxy(x+65,y);
		printf("%0.lf",data->Dmoney);

		y++;
		ptemp = ptemp->next;
	}
	 Gotoxy(23,17);
}


/*打印学生结构体链表（不通用）*/
void Bill_Printf(LIST *head)
{
	BILL *data = NULL;
	LIST *ptemp = head;
	int x=4 ;
	int y=7 ;
	
	printf("\n");
	printf(" *********************************************************************************\n");
	printf(" *                                 用户账单信息                                  *\n");
	printf(" *********************************************************************************\n");
	printf(" *    账号    *      时间     *  交易金额  *    余额   * 交易信息 *    交易源    *\n");
	printf(" *********************************************************************************\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *|           |               |            |           |          |             |*\n");
	printf(" *********************************************************************************\n");

	while(NULL !=ptemp)
	{
/*把void类型指针赋值给其他类型的指针，需要强制转化*/
		data = ((BILL *)(ptemp->Data));

		Gotoxy(x,y);
		printf("%s",data->sAccount);
		Gotoxy(x+14,y);
		printf("%s",data->sTime);
		Gotoxy(x+29,y);
		printf("%.0lf",data->dDealMoney);
		Gotoxy(x+43,y);
		printf("%.0lf",data->dLeftMoney);
		Gotoxy(x+55,y);
		printf("%s",data->sMessage);
		Gotoxy(x+66,y);
		printf("%s",data->sDealTarget);

		y++;


		ptemp = ptemp->next;
	}
   Gotoxy(23,17);

}
