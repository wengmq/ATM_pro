#include"login.h"



void loginInit() //ҳ���ʼ������
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��           ATM��ϵͳ-��¼����           ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       �� �˺�/�û�����                          ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��    ��    �룺                          ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��        ���ո�������˺����룡          ��\n");
	printf("                       ��          ��esc���˳�����             ��\n");
	printf("                       �����������������������\n");
	
}

int ChooseMenu(int IChoose,STAFF *staff_node,LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp)
{
	int rt = -1;
	int x2 = 23;
	int y2 = 19;

	switch(IChoose)
	 {
		
		 case 1://��������Ա����
		 {
			 Gotoxy(x2+10,y2);
			 printf("��¼�ɹ���ҳ����ת��...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //ͣ��2������
			 system("cls");
			 rt = admin(staff_fp,staff_head);
			 if(rt==0)
			 {
				return 0;//����ע���ж�
			 }
		 }break;

		 case 2://��ͨ�û�����
		 {
			 Gotoxy(x2+10,y2);
			 printf("��¼�ɹ���ҳ����ת��...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //ͣ��2������
			 system("cls");
			 rt = user(staff_head,bill_head,staff_fp,bill_fp,staff_node);
			 if(rt==0)
			 {
				return 0;//����ע���ж�
			 }

		 }break;

		 case 3://��ͨ����Ա����
		 {
			 Gotoxy(x2+10,y2);
			 printf("��¼�ɹ���ҳ����ת��...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //ͣ��2������
			 system("cls");
			 rt = CommonAdmin(staff_fp,staff_head,staff_node);
			 if(rt==0)
			 {
				return 0;//����ע���ж�
			 }
		 }break;
		 
		 default:
		 {

			 Gotoxy(x2+10,y2);
			 printf("��¼ʧ�ܣ�����������...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //ͣ��2������
			 
			 system("cls");


		 }
	 }




}


void login(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp)
{

	char acname[20] = {0};
	char acpwd[20] = {0};
	LIST *ptemp =NULL;
	STAFF *data = NULL;
	int flag = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;
	int rt = 0;
	int rt2 = -1;//�����ж��Ƿ����һ������ע��
	char ch = 0;

	int x1 = 39;
	int y1 = 12;
	int x2 = 23;
	int y2 = 19;

	while(1)
	{ 
		flag = 0;
		ptemp =staff_head;
		loginInit(); //��¼ҳ���ʼ��
		Gotoxy(x1,y1);  //�ƶ����λ��
		rt = glb_putString(acname,8,3,1);
		if(rt==0) //��esc����
		{
			Gotoxy(x2+2,y2);
			printf("������ esc ��ȷ���˳�!�����������ȡ��!");
			ch=getch();
			if(ch == 27) //�ж��Ƿ��������esc
			{
				Gotoxy(x2+2,y2);
			printf("                                       ");
			    Gotoxy(x2+8,y2);
				exit(0);
			}
			else
			{
				system("cls");
			   continue;
			}
		}

		if(rt==2)//���ո�ˢ�½���
		{
			system("cls");
			continue;
		}

		if(strlen(acname) ==0)
		{
			 Gotoxy(x2+10,y2);
			 printf("�˺Ų���Ϊ�գ����������룡");
			 Sleep(1500); //ͣ��1.5������
	         system("cls");
		     continue;
		}
		while(ptemp !=NULL)	//�ж��˻��Ƿ����  
		{
			data = (STAFF *)(ptemp->Data);

			if(strcmp(acname,data->sName) ==0 )  
			{
				break;
			}
			if(strcmp(acname,data->sAccount) ==0 )  
			{
				break;
			}
			ptemp = ptemp->next;   //ָ��ƫ�� �ҵ���һ���ڵ�
			flag++;
		}	
		ptemp =staff_head;
		if(flag==List_Count(ptemp))
		{
			
			 Gotoxy(x2+10,y2);
			printf("�˺Ų����ڣ����������룡\n");
			Sleep(1500); //ͣ��1.5������
	        system("cls");
			continue;
		}
		ptemp =staff_head;
		flag4 = 0;
		while(ptemp !=NULL)	//ѭ��ƥ��   
			{
				
				data = (STAFF *)(ptemp->Data);
				
				//printf("sname:%s\n",data->sName);
				if(strcmp(acname,data->sName)==0)  
				{
					if(data->iEixt == 0)
					{
						flag4 = 4;
						break;
					}

				}
				ptemp = ptemp->next;
			}

		
		if(flag4 ==4)
		{

			Gotoxy(x2+10,y2);
			printf("���û���ע�������������룡\n");
			Sleep(1500); //ͣ��1.5������
			system("cls");
			continue;
		}

		
		while(1)
		{
			flag3 = 0;
			Gotoxy(x1,y1+2);
			printf("          ");
			Gotoxy(x1,y1+2);
			rt = glb_putString(acpwd,6,3,0);
			if(rt==0) //��esc����
			{
				Gotoxy(x2+2,y2);
				printf("������ esc ��ȷ���˳�!�����������ȡ��!");
				ch=getch();
				if(ch == 27) //�ж��Ƿ��������esc
				{
					Gotoxy(x2+2,y2);
				printf("                                       ");
					Gotoxy(x2+8,y2);
					exit(0);
				}
				else
				{
					flag3 = 3;
					break;
				}
			}
			
			if(rt==2)//���ո�ˢ�½���
			{
				flag3 = 3;
					break;
			}

			if(strlen(acpwd) ==0)
			{
				Gotoxy(x2+10,y2);
				printf("���벻��Ϊ�գ����������룡");
				
				Sleep(1500); //ͣ��1.5������

				Gotoxy(x2+10,y2);
				printf("                           ");


				
			//	system("cls");
		   		continue;
			}
			flag2 = 0;
			rt2 = -1;
			ptemp = staff_head;
			while(ptemp !=NULL)	//ѭ��ƥ��   
			{
				
				data = (STAFF *)(ptemp->Data);
				
				//printf("sname:%s\n",data->sName);
				if(strcmp(acname,data->sName) ==0 && strcmp(acpwd,data->sPwd) ==0 )  
				{
				
				  rt2 = ChooseMenu(data->iRole,data,staff_head,bill_head,staff_fp,bill_fp);
				  break;

				}
				if(strcmp(acname,data->sAccount) ==0 && strcmp(acpwd,data->sPwd) ==0 )  
				{
				
				  rt2 = ChooseMenu(data->iRole,data,staff_head,bill_head,staff_fp,bill_fp);
				  break;
				}
				ptemp = ptemp->next;   //ָ��ƫ�� �ҵ���һ���ڵ�
				flag2++;
			}	

			 if(rt2 ==0)//�����ж�ע��
			  {				
				  flag3= 3;
				  break;
				  
			  }

			ptemp =staff_head;
			if(flag2==List_Count(staff_head))
			{
				Gotoxy(x2+10,y2);
				printf("�˺����벻ƥ�䣬���������룡\n");
				Sleep(1500); //ͣ��1.5������
				//system("cls");
				Gotoxy(x2+10,y2);
				printf("                              \n");
	        	continue;
			}
		}  
		if(flag3 ==3)//���ո�ˢ�½���
		{

			system("cls");
			continue;
		}


	 
	
	}


     
}

