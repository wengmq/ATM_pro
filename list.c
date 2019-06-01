#include"list.h"


   /*��ʼ������*/
void *List_Init(void *data)
{
	LIST *head = NULL;
	head = (LIST *)malloc(sizeof(LIST));
	head->Data = data; //��ͷ��㸳ֵ
	head->next = NULL; //ͷ���ָ�����ʼ��ΪNULL

	return head; //����ͷ�ڵ�ָ��
}

     /*�������ڵ�*/
void List_Add(LIST *head,void *data)
{
	LIST * pnew = NULL;
	LIST * ptemp = head;
	pnew = List_Init(data);//��ʼ���½ڵ�
  /*��������һ���ڵ��ָ����ΪNULL��
	���Ա���ѭ���ҵ����һ���ڵ�*/
	while(NULL != ptemp->next)  
	{
		ptemp = ptemp->next;
	}
	ptemp->next = pnew;
	pnew->Data = data;//���¼ӵĽڵ㸳ֵ
	pnew->next = NULL;
}

/*��ȡ����ڵ����*/
int List_Count(LIST *head)
{
	LIST * ptemp = head;
	int count = 0;
	/*ѭ������*/
	while(ptemp != NULL)
	{
		count++;
		ptemp = ptemp->next;
	}
	return count;
}


/*��ȡ�����Index�����ڵ�*/
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

/*��ȡ�����Index�����ڵ��������*/
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
    
/*�ͷ�����������ͷ���*/
void *List_Free(LIST *head)
{
	LIST *pnext = head;
	while(pnext != NULL)
	{
		pnext = pnext->next;
	/*���ͷ����ݴ洢���ڴ�ռ�*/
		free(head->Data);
	/*���ͷ�����ڵ���ڴ�ռ�*/
		free(head);
		head = pnext;
	}
    return head;
}

 /*ɾ������ĵ�Index���ڵ�*/
void List_Del(LIST *head,int Index)
{
	LIST *ptemp = head;
	LIST *pnext = NULL;
	/*���ú������ص�index-1���ڵ�*/
	ptemp  = List_GetNode(head,Index-1);
	if(NULL != ptemp->next)
	{   /*��ɾ��*/
		pnext = ptemp->next;
		ptemp->next = pnext->next;
		free(pnext);
	}
}
//�ж��������Ƿ����sName�û�
int ExistUser(LIST *staff_head,char *sName)
{
	   STAFF *data = NULL;
	   LIST *ptemp = staff_head;
		while(ptemp != NULL)
		{
			data = (STAFF *)(ptemp->Data);
			if(strcmp(data->sName,sName) == 0)
			{
				return -1;//�Ѵ����û�����-1
			}

				ptemp = ptemp->next;
		}	

		return 1;


}

/******************************************************
�������ܣ��������ж�ȡ������ӵ����ļ�ĩβ
head��Դ����                     fp��Ŀ���ļ�
size���ڵ��������Ľṹ���С   num��Ҫ��ӵĽڵ�����
******************************************************/
  FILE * list2file(LIST *head,FILE *fp,int size,int num)
   {
	   int flag = 0;//������������ڵ����
	   LIST * ptemp = head;
	   if(fp)
	   {
			while(flag<num)
			{
				fseek(fp,0,SEEK_END);
				fwrite(ptemp->Data,size,1,fp);
				fflush(fp);//ˢ�µ��ļ���

				ptemp = ptemp->next;
				flag++;
			}
	   }	
		return fp;	
   }

/******************************************************
�������ܣ����ļ���ʼλ�ö�ȡ���ݵ�������
head��Ŀ������                     fp��Դ�ļ�
size���ڵ��������Ľṹ���С   num��Ҫ��ӵĽڵ�����
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
			fseek(fp,0,SEEK_END);//ƫ�Ƶ��ļ�β��
         	FileSize = ftell(fp)/size;//��ȡ��ǰ�ļ����ܵĵ�Ԫ��
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



   /*��ӡ�û��ṹ��������ͨ�ã�*/
void Staff_Printf(LIST *head)
{
	LIST *ptemp = head;
	STAFF *data = NULL;
	int x=5 ;
	int y=7 ;

		printf("\n");
	printf(" *********************************************************************************\n");
	printf(" *                                 ��ѯ�û�����                                  *\n");
	printf(" *********************************************************************************\n");
	printf(" *   �û���   *      �˺�     *    ����    *  ���  * �Ƿ����� *      ���       *\n");
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
/*��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��*/
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


/*��ӡѧ���ṹ��������ͨ�ã�*/
void Bill_Printf(LIST *head)
{
	BILL *data = NULL;
	LIST *ptemp = head;
	int x=4 ;
	int y=7 ;
	
	printf("\n");
	printf(" *********************************************************************************\n");
	printf(" *                                 �û��˵���Ϣ                                  *\n");
	printf(" *********************************************************************************\n");
	printf(" *    �˺�    *      ʱ��     *  ���׽��  *    ���   * ������Ϣ *    ����Դ    *\n");
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
/*��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��*/
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
