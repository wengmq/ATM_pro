
#include  "file.h"

//������д���ļ���β��

void file_add(FILE *fp,void *data,int size)
{
	fseek(fp,0,SEEK_END);
	fwrite(data,size,1,fp);
	fflush(fp);
}

//�ļ���λ��������
void file_updata(FILE *fp,void *data,int size,int index)
{
	fseek(fp,size*(index-1),SEEK_SET);
	fwrite(data,size,1,fp);
	fflush(fp);

}


FILE * file_open(char * filename)
{
	FILE * fp =NULL;
	fp = fopen(filename,"r+");   //r ��һ���Ѿ����ڵ��ļ�  w �½��ļ�
	if(!fp)
	{
		fp = fopen(filename,"w+"); 
	
	}
	return fp;
}


FILE * file_openinit(char * filename,void (*init)(FILE *fp))
{


	FILE * fp =NULL;
	fp = fopen(filename,"r+");   //r ��һ���Ѿ����ڵ��ļ�  w �½��ļ�
	if(!fp)
	{
	
		fp = fopen(filename,"w+"); 
		init(fp);
		
	
	}
	return fp;

}

//����д�ļ�
void list_to_file(FILE *fp ,LIST *head,int size)
{


	void *data;
	LIST *p = NULL;
	int count = List_Count(head);
	int i = 0;
	rewind(fp);
	for( i = 1;i <=count ;i++)
	{
		p = List_GetNode(head,i);
		data = p->Data;
		
		fwrite(data,size,1,fp);
		
		fflush(fp);
	}
}


LIST *  file_to_list(FILE *fp,int size)
{
	LIST *head = NULL;
	void *data = NULL;
	data = malloc(size);
	memset(data,0,size);
	rewind(fp);
	fread(data,size,1,fp);
	head = List_Init(data);
	
	data = malloc(size);
	memset(data,0,size);

	while( fread(data,size,1,fp)>0 )
	{
		List_Add(head,data);
		data = malloc(size);
		memset(data,0,size);
	}
	return head;
}


