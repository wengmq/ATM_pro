#include"user.h"
void user_ui()
{


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                �û�����                ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       �� ���������ѡ��                       ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              1������ѯ               ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��              2��ȡ    ��               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              3����    ��               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              4��ת    ��               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              5�������޸�               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              6����¼��ѯ               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              7��ע    ��               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              8����    ��               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       �����������������������\n");


}

int user(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node)
{
	int rt = 0;
	char  Choice [2]={0};
	char ch = 0;
	while(1)
	{
		rt = 0;
		user_ui();
		Gotoxy(42,10);
		putString(Choice, 1, 1, 1);
		

		switch(atoi(Choice))
		{
		case 1:
			{//����ѯ

				system("cls");
				//printf("������û�\n");
				
				rt = user_MoneyQuery(staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 2:
			{//ȡ��

				system("cls");
				
				rt = user_GetMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 3:
			{//���

				system("cls");
				
				rt =user_PutMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 4:
			{//ת��
				
				system("cls");
				
				rt =user_GiveMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}
				
			}break;
		case 5:
			{//�����޸�
				
				system("cls");
				
				rt = user_ModifyPsw(staff_fp,staff_head,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}


			}break;
		case 6:
			{//���׼�¼��ѯ
				system("cls");
				
				rt = user_QueryBill(bill_head,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}
			}break;
		case 7:
			{
				
				Gotoxy(29,29);
				printf("���س���ȷ��ע��,���������ȡ����");
				ch = getch();
				
				if(ch ==13)
				{
					return 0;//�����ж��˳�
				}
				else
				{	
					system("cls");
					continue;
				}
				

			}break;
		case 8:
			{
			Gotoxy(29,29);
			printf("���س���ȷ���˳�,���������ȡ����");
			ch = getch();
			
			if(ch ==13)
			{
				Gotoxy(33,30);
				exit(0);//�����ж��˳�
			}
			else
			{	
				system("cls");
				continue;
			}
	

			}break;
		default :
			{
				system("cls");
					continue;

			}
		}


	}

}


void user_MoneyQuery_ui()
{


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                ��ѯ���                ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��    �����˻���                          ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
    printf("                       ��    ��ǰ��                          ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��    �û�������                          ��\n");
	printf("                       ��           ����������1                  ��\n");
	printf("                       ��           �˳�������2                  ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��        ����������ѡ��                ��\n");
	printf("                       ��                                        ��\n");
	printf("                       �����������������������\n");



}

int user_MoneyQuery(STAFF *staff_node)
{
	int x=39 ;
	int y=10;
	char ch1 = 0;
	char ch[2] = {0};
	system("cls");
	user_MoneyQuery_ui();

	Gotoxy(x,y);
	printf("%s",staff_node->sAccount);
	Gotoxy(x,y+3);
	printf("%0.lf",staff_node->Dmoney);


	while(1)
	{
		Gotoxy(49,22);
		printf("    ");
		Gotoxy(26,23);
		printf("                                     ");
		Gotoxy(49,22);
		putString(ch,1, 1,1);

		if(atoi(ch) == 1) 
		{
			return 0;

		}else if(atoi(ch) == 2)
		{
			Gotoxy(26,23);
			printf("�Ƿ�ȷ���˳����س���ȷ�ϣ�������ȡ��!");
			ch1 = getch();
			if(ch1 == 13)
			{
				Gotoxy(26,23);
			printf("                                     ");
				Gotoxy(33,23);
				exit(0);
			}
			else
			{
				continue;
			}

		}else
		{
			Gotoxy(37,23);
			printf("��������ȷ������!");

			Sleep(2000);
			Gotoxy(37,23);
			printf("                 ");
			continue;
		}

	}

	return 0;
}

void user_ModifyPsw_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��            �޸��û��������            ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��       �û�����                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��       �����룺                         ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��       �����룺                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     ȷ�����룺                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��          ���ո�����ý��棡            ��\n");
	printf("                       ��        ��esc��������һ������!          ��\n");
	printf("                       �����������������������\n");




}

int user_ModifyPsw(FILE *staff_fp,LIST *staff_head,STAFF *staff_node)
{


	while(1)
	{

		  //  LIST * staff_head = NULL;
			LIST * ptemp = NULL;
			STAFF *data = NULL;
			int flag = 0;
			int flag2 = 0;
			int flag3 = 0;

			char sPwd0[7] ={0};//������
			char sPwd1[7] ={0};//������
			char sPwd2[7] ={0};//ȷ������
			char ch = 0;
			int rt = -1;
			int x=40 ;
			int y=10;

			system("cls");
			user_ModifyPsw_ui();
			Gotoxy(x,y);
			printf("%s",staff_node->sName);//��ӡ�˺���

			Gotoxy(x,y+2);
			rt = glb_putString(sPwd0,6,3,0);//���������
			if(rt==0) //��esc����
			{
				return 0;
			}
			if(rt==2)//���ո�ˢ�½���
			{
				continue;
			}

			while(strcmp(sPwd0,staff_node->sPwd)!=0)//
				{
					Gotoxy(30,20);
					printf("�û�������������������룡");
					Sleep(2000); //ͣ��1�������ʾ��
					Gotoxy(30,20);
					printf("                              ");
					Gotoxy(x,y+2);
					printf("        ");
					Gotoxy(x,y+2);
					rt = glb_putString(sPwd0,6,3,0);//��������������
					if(rt==0) //��esc����
					{
						return 0;
					}
					if(rt==2)//���ո�ˢ�½���
					{
						flag = 1;
						break;
					}
	
				}
			if(flag == 1)//���ո�ˢ�½���
			{
				continue;
			}


			flag3= 0;
			while(1)
			{

					Gotoxy(x,y+4);
					printf("       ");
					Gotoxy(x,y+4);
					rt = glb_putString(sPwd1,6,3,0);//����������
					if(rt==0) //��esc����
					{
						return 0;
					}
					if(rt==2)//���ո�ˢ�½���
					{
						flag3= 3;
						break;
					}
					if(strlen(sPwd1)!=6)
					{
						Gotoxy(30,20);
						printf("�������Ϊ��λ�����������룡");
						Sleep(2000); //ͣ��1�������ʾ��
						Gotoxy(30,20);
						printf("                            ");

						continue;
					}
					break;

			}
			if(flag3 == 3)
			{
				continue;
			}

			Gotoxy(x,y+6);
			rt = glb_putString(sPwd2,6,3,0);//�ظ�����������
			if(rt==0) //��esc����
			{
				return 0;
			}
			if(rt==2)//���ո�ˢ�½���
			{
				continue;
			}

	
			flag2 = 0;
			while(strcmp(sPwd1,sPwd2)!=0)
			{
				Gotoxy(30,20);
				printf("�������벻һ�£����������룡");
				Sleep(2000); //ͣ��1�������ʾ��
				Gotoxy(30,20);
				printf("                            ");

				Gotoxy(x,y+6);
				printf("        ");
				Gotoxy(x,y+6);
				rt = glb_putString(sPwd2,6,3,0);//�ظ�����������
				if(rt==0) //��esc����
				{
					return 0;
				}
				if(rt==2)//���ո�ˢ�½���
				{
					flag2 = 2;
					break;
				}

				
			}
			if(flag2 == 2)//���ո�ˢ�½���
			{
				continue;
			}

			ptemp = staff_head;
			while(NULL !=ptemp)
			{	
		/*��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��*/
				data = ((STAFF *)(ptemp->Data));
				if(strcmp(staff_node->sName,data->sName)==0)
				{ //�˺�ƥ��ʱ
				
					break;
				}
				ptemp = ptemp->next;	
				
			}	

			strcpy(data->sPwd,sPwd2);

			list_to_file(staff_fp ,staff_head,sizeof(STAFF));

			Gotoxy(25,20);
			printf("�޸ĳɹ������س�������������������أ�");
			
			ch = getch();
		   if(ch == 13)//���س�����
		   {
				continue;
		   }
		   else
		   {
				return 0;
		   }

	}






}

void user_PutMoney_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                 ������               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     �����˻���                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     ��ǰ��                         ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��     ����                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��          ���ո�����ý��棡            ��\n");
	printf("                       ��        ��esc��������һ������!          ��\n");
	printf("                       �����������������������\n");




}
int user_PutMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node)
{
	while(1)
	{

		int x = 40;
		int y = 10;
		int rt = 0;
		LIST *ptemp = staff_head;
		char *sAccount = staff_node->sAccount; 
		STAFF * staff_data = NULL;
		BILL * bill_data = NULL;
		time_t t = time(0);
	    char time[11] = {0};
		char ch = 0;
		char putMoney[9] = {0};
		system("cls");
		user_PutMoney_ui();

		
		 Gotoxy(x,y);
		 printf("%s",staff_node->sAccount);
		 Gotoxy(x,y+2);
		 printf("%.0lf",staff_node->Dmoney);

		 Gotoxy(x,y+4);
		 rt = glb_putString(putMoney,8,1,1);
		if(rt==0) //��esc����
		{
			return 0;
		}
		if(rt==2)//���ո�ˢ�½���
		{
			continue;
		}
		if(atoi(putMoney)%100 !=0)
		{
			Gotoxy(30,18);
			printf("�������Ϊ���٣����������룡");
			Sleep(2000);
			system("cls");
			continue;

		}

	
		

		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//��ȡ��ǰʱ��

		time[10] = '\0';

		
		bill_data = (BILL *)malloc(sizeof(BILL));

		strcpy(bill_data->sAccount,sAccount);
		
		bill_data->dDealMoney=atoi(putMoney);
		bill_data->dLeftMoney = staff_node->Dmoney+atoi(putMoney);
		strcpy(bill_data->sDealTarget ,"ATM��");
		strcpy(bill_data->sMessage ,"���");
		strcpy(bill_data->sTime ,time);


		List_Add(bill_head,bill_data);

		list_to_file(bill_fp ,bill_head, sizeof(BILL));



		while(NULL != ptemp)
		{
			staff_data = (STAFF *)(ptemp->Data);

			if(strcmp(staff_data->sAccount,sAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney+atoi(putMoney);
			}
			ptemp = ptemp->next;

		}

		

		list_to_file(staff_fp ,staff_head,sizeof(STAFF));


		Gotoxy(33,18);
		printf("���ɹ����������������");
		ch = getch();
		system("cls");
		continue;

	}

}


void user_GetMoney_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                 ȡ�����               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     �����˻���                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     ��ǰ��                         ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��     ȡ���                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��          ���ո�����ý��棡            ��\n");
	printf("                       ��        ��esc��������һ������!          ��\n");
	printf("                       �����������������������\n");





}
int user_GetMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node)
{


while(1)
	{

		int x = 40;
		int y = 10;
		int rt = 0;
		LIST *ptemp = staff_head;
		char *sAccount = staff_node->sAccount; 
		STAFF * staff_data = NULL;
		BILL * bill_data = NULL;
		time_t t = time(0);
	    char time[11] = {0};
		char ch = 0;
		char GetMoney[9] = {0};
		system("cls");
		user_GetMoney_ui();

		
		 Gotoxy(x,y);
		 printf("%s",staff_node->sAccount);
		 Gotoxy(x,y+2);
		 printf("%.0lf",staff_node->Dmoney);

		 Gotoxy(x,y+4);
		 rt = glb_putString(GetMoney,8,1,1);
		if(rt==0) //��esc����
		{
			return 0;
		}
		if(rt==2)//���ո�ˢ�½���
		{
			continue;
		}
		if(atoi(GetMoney)%100 !=0)
		{
			Gotoxy(30,18);
			printf("ȡ������Ϊ���٣����������룡");
			Sleep(2000);
			system("cls");
			continue;

		}
		if(atoi(GetMoney)>staff_node->Dmoney)
		{
			Gotoxy(33,18);
			printf("���㣬���������룡");
			Sleep(2000);
			system("cls");
			continue;

		}

		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//��ȡ��ǰʱ��

		time[10] = '\0';

		
		bill_data = (BILL *)malloc(sizeof(BILL));

		strcpy(bill_data->sAccount,sAccount);
		
		bill_data->dDealMoney=atoi(GetMoney);
		bill_data->dLeftMoney = staff_node->Dmoney-atoi(GetMoney);
		strcpy(bill_data->sDealTarget ,"ATM��");
		strcpy(bill_data->sMessage ,"ȡ��");
		strcpy(bill_data->sTime ,time);


		List_Add(bill_head,bill_data);

		list_to_file(bill_fp ,bill_head, sizeof(BILL));//�޸��˵��ļ�

		while(NULL != ptemp)
		{
			staff_data = (STAFF *)(ptemp->Data);

			if(strcmp(staff_data->sAccount,sAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney-atoi(GetMoney);
			}
			ptemp = ptemp->next;

		}

		list_to_file(staff_fp ,staff_head,sizeof(STAFF));//�޸��û��ļ�


		Gotoxy(33,18);
		printf("ȡ��ɹ����������������");
		ch = getch();
		system("cls");
		continue;

	}



}


void user_GiveMoney_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                 ת�˽���               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     �����˻���                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     ��ǰ��                         ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��     ת���˺ţ�                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��     ת�˽�                         ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��          ���ո�����ý��棡            ��\n");
	printf("                       ��        ��esc��������һ������!          ��\n");
	printf("                       �����������������������\n");





}
int user_GiveMoney(LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp,STAFF *staff_node)
{
	while(1)
	{
		
		int x = 40;
		int y = 10;
		int rt = 0;
		int flag = 0;
		LIST *ptemp = staff_head;
		char *MyAccount = staff_node->sAccount; 
		char TargetAccount[9] = {0};
		char TargetName[8] = {0};

		STAFF * staff_data = NULL;
		BILL * bill_data1 = NULL;
		BILL * bill_data2 = NULL;
		time_t t = time(0);
		char time[11] = {0};
		char ch = 0;
		char GiveMoney[9] = {0};
		system("cls");
		user_GiveMoney_ui();
		
		
		Gotoxy(x,y);
		printf("%s",staff_node->sAccount);
		Gotoxy(x,y+2);
		printf("%.0lf",staff_node->Dmoney);
		
		Gotoxy(x,y+4);
		rt = glb_putString(TargetAccount,8,1,1);
		if(rt==0) //��esc����
		{
			return 0;
		}
		if(rt==2)//���ո�ˢ�½���
		{
			system("cls");
			continue;
		}
		
		ptemp = staff_head;
		while(NULL != ptemp)//�ж��������Ƿ����Ŀ���˻�
		{
			staff_data = (STAFF *)(ptemp->Data);
			
			if(strcmp(staff_data->sAccount,TargetAccount) == 0)
			{
				if(staff_data->iRole != 2)
				{
					flag = -1;
					break;	
				}


				strcpy(TargetName,staff_data->sName);
				
				break;
			}
			ptemp = ptemp->next;
			flag++;
			
		}
		if(flag ==List_Count(staff_head))
		{
			Gotoxy(33,20);
			printf("Ŀ���˻������ڣ����������룡");
			Sleep(2000);
			
			continue;
		}
		if(flag ==-1)
		{
			Gotoxy(35,20);
			printf("��Ч�˻������������룡");
			Sleep(2000);
			
			continue;
		}
		while(1)
		{
			Gotoxy(x,y+6);
			printf("         ");
			Gotoxy(x,y+6);
			rt = glb_putString(GiveMoney,8,1,1);//ת�˽������
			if(rt==0) //��esc����
			{
				return 0;
			}
			if(rt==2)//���ո�ˢ�½���
			{
				flag =-1;
				break;
			}
			/*
			if(atoi(GiveMoney)%100 !=0 && atoi(GiveMoney)== 0 )
			{
				Gotoxy(33,20);
				printf("ת�˽����Ϊ���٣����������룡");
				Sleep(1000);
				Gotoxy(3,15);
				printf("                              ");
				continue;

			}
			*/
			
			if(atoi(GiveMoney)>(staff_node->Dmoney))
			{
				Gotoxy(33,20);
				printf("���㣬���������룡");
				Sleep(1000);
				Gotoxy(33,20);
				printf("                       ");
				continue;

			}
		
			break;

		}
		if(flag == -1)
		{
			system("cls");
			continue;
		}
		Gotoxy(28,20);
		printf("Ŀ���û�Ϊ:%s,�Ƿ�ȷ��ת��?",TargetName);
		Gotoxy(30,21);
		printf(" ���س�ȷ�ϣ����������ȡ����");
		ch = getch();
		if(ch !='\r' )
		{
			system("cls");
			continue;
		}
		Gotoxy(26,20);
		printf("                                ");
		Gotoxy(30,21);
		printf("                              ");


		ptemp = staff_head;
		while(NULL != ptemp)//�Լ��˻���������
		{
			staff_data = (STAFF *)(ptemp->Data);
			
			if(strcmp(staff_data->sAccount,MyAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney-atoi(GiveMoney);
			}
			ptemp = ptemp->next;
			
		}

		ptemp = staff_head;
		while(NULL != ptemp)//Ŀ���˻����������
		{
			staff_data = (STAFF *)(ptemp->Data);
			
			if(strcmp(staff_data->sAccount,TargetAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney+atoi(GiveMoney);
			}
			ptemp = ptemp->next;
			
		}

		list_to_file(staff_fp ,staff_head,sizeof(STAFF));//�޸��ļ�


		
		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//��ȡ��ǰʱ��
		
		time[10] = '\0';
		
		
		bill_data1 = (BILL *)malloc(sizeof(BILL));
		
		strcpy(bill_data1->sAccount,MyAccount);
		
		bill_data1->dDealMoney=atoi(GiveMoney);
		bill_data1->dLeftMoney = staff_node->Dmoney-atoi(GiveMoney);
		strcpy(bill_data1->sDealTarget ,TargetAccount);
		strcpy(bill_data1->sMessage ,"ת��");
		strcpy(bill_data1->sTime ,time);
		
		
		List_Add(bill_head,bill_data1);



		bill_data2 = (BILL *)malloc(sizeof(BILL));
		
		strcpy(bill_data2->sAccount,TargetAccount);
		
		bill_data2->dDealMoney=atoi(GiveMoney);
		bill_data2->dLeftMoney = staff_node->Dmoney+atoi(GiveMoney);
		strcpy(bill_data2->sDealTarget ,MyAccount);
		strcpy(bill_data2->sMessage ,"ת��");
		strcpy(bill_data2->sTime ,time);
		
		
		List_Add(bill_head,bill_data2);
		
		list_to_file(bill_fp ,bill_head, sizeof(BILL));
		

		Gotoxy(26,20);
		printf("                                ");
		Gotoxy(30,21);
		printf("                              ");

		Gotoxy(33,20);


		printf("ת�˳ɹ����������������");
		ch = getch();
		system("cls");
		continue;
		
	}
	




}


void user_QueryBill_ui()
{
	printf("\n");
	printf("�������������������������������������������\n");
	printf("��                                 �û��˵���Ϣ                                   ��\n");
	printf("��ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
	printf("��|   �˺�    |      ʱ��     |  ���׽��  |    ���   | ������Ϣ |  ���׶���    |��\n");
	printf("��ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("��|           |               |            |           |          |              |��\n");
	printf("�������������������������������������������\n");
	printf("��        �밴���������ҳ��      ��            ������ʱ������ѯ�˵�              ��\n");
	printf("��ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
	printf("��             ������             ��                                              ��\n");
	printf("��             ��һҳ             ��    ��ʼʱ�䣺                                ��\n");
	printf("�� ��������ҳ          ĩҳ������ ��                                              ��\n");
	printf("��             ��һҳ             ��    ��ֹ���ڣ�                                ��\n");
	printf("��             ������             ��                                              ��\n");
	printf("��ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
	printf("��     ��esc��������һ������!     ��           ���ո�����ʱ�������!            ��\n");
	printf("��                                ��ʱ���ʽ���磺xxxx-xx-xx(�ú�˷ֿ�������)����\n");
	printf("�������������������������������������������\n");
	printf("                               ��                ��                                 \n");
	printf("                                                                                    \n");

                                
}
LIST *GetPersonalBill(LIST *bill_head,STAFF *staff_node)
{
	BILL *data = NULL;
	char *sAccount = staff_node->sAccount;
	LIST *ptemp = bill_head;
	LIST *PersonalBill_head = NULL;
	
	int flag = 1;

	data =(BILL *)malloc(sizeof(BILL));
	memset(data,0,sizeof(BILL));
	
	while(NULL !=ptemp)
	{
		//��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��
		data = ((BILL *)(ptemp->Data));
		
		if(strcmp(data->sAccount,sAccount) == 0)
		{
			if(flag==1)//��һ�β�ѯ��ʱ��ʼ����ͷ
			{
				
				PersonalBill_head = List_Init(data);
				flag++;
				ptemp = ptemp->next;
				continue;
			}
			else
			{	//������������½ڵ�			
				List_Add(PersonalBill_head,data);
				data =(BILL *)malloc(sizeof(BILL));
				memset(data,0,sizeof(BILL));
			}
		}
		
		
		
		ptemp = ptemp->next;
	}
	
	return PersonalBill_head;



}

void bill_show(int page, LIST *PersonalBill_head)
{
	BILL *data = NULL;
	LIST *ptemp = NULL;
	int i=0;
	int flag = 1;
	int PageSize = 10;

	int PageCount = 0;
	int record = 0;
	int position = 0;
	int x=4 ;
	int y=6 ;
	
			ptemp = PersonalBill_head;

			record = List_Count(ptemp); //�ܵļ�¼����
			
			
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//�����ܵ�ҳ��
			
			system("cls");
			user_QueryBill_ui();


			Gotoxy(35,28);
			printf("��%dҳ����%dҳ",page,PageCount);

			data =(BILL *)malloc(sizeof(BILL));
			memset(data,0,sizeof(BILL));
			

			position = (page-1)*PageSize+1;//����Ҫ��ӡ�ڵ��λ��

			if(PageCount!=page)//�������һҳ��ÿһҳ��ӡPageSize����¼
			{
				for(i=1;i<=PageSize;i++)
				{
					data =(BILL *)malloc(sizeof(BILL));
					memset(data,0,sizeof(BILL));
					data = (BILL *)List_GetNode_Data(ptemp,position++);
					
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

				}

			}
			if(PageCount==page)//�����һҳ�������⴦��
			{

				
				for(i=1;i<=(record-PageSize*(PageCount-1));i++)
				{
					Gotoxy(5,19);
					
					data =(BILL *)malloc(sizeof(BILL));
					memset(data,0,sizeof(BILL));
					data = (BILL *)List_GetNode_Data(ptemp,position++);
					
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
				}

			}

}

int user_QueryBill(LIST *bill_head,STAFF *staff_node)
{
	BILL *data = NULL;
	LIST *ptemp = bill_head;
	LIST *PersonalBill_head = NULL;
	LIST *pnew = NULL;
	char BeginTime[11] = {0};
	char EndTime[11] = {0};
	time_t t = time(0);
	char time[11] = {0};
	int rt = -1;
	int i = 0;
	int flag = 1;
	char ch = 0;
	int PageSize = 10;
	int page = 1;
	int PageCount = 0;
	int record = 0;
	int position = 0;
	int x = 49;
	int y = 20;
	int find = -1;
	
	//��ȡ�û��Լ����˵�
	PersonalBill_head = GetPersonalBill(bill_head,staff_node);

	strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//��ȡ��ǰʱ��

	time[10] = '\0';

//	Bill_Printf(PersonalBill_head);

//	Sleep(3000);
	while(1)
	{
			

			if(PersonalBill_head ==NULL)
			{
				system("cls");
				user_QueryBill_ui();
				Gotoxy(x+2,y+3);
				printf("δ��ѯ�������");
				Sleep(3000);
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);

			}
		
			bill_show(page, PersonalBill_head);
			if(find >0)
			{
				Gotoxy(x+2,y+3);
				printf("�ɹ���ѯ��%d�����ݣ�",find);
				
			}
			record = List_Count(PersonalBill_head); //�ܵļ�¼����
		
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//�����ܵ�ҳ��
			
			 Gotoxy(x,y);

		   	rt = time_putString(BeginTime, 10);
			
		
			
			if(rt ==0)//��esc������һ������
			{
				
				getch();
				return 0;
			}
			if(rt ==2)//���ո��ʱˢ�½���
			{
				page = 1;
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);
				find = -1;
				continue;
			}
			
			
			if(rt  == 75)//����������ҳ
			{
				
				page=1;
				continue;
				
			}
			if(rt  == 72)//���ϣ�������һҳ
			{	
				page = page-1;
				if(page==0)
				{
					page=PageCount;
				}
				continue;
				
			}
			
			if(rt == 77 )//���ң�����ĩҳ
			{
				
				page=PageCount;
				continue;
				
			}
			if(rt == 80)//���£�������һҳ
			{

				page = (page%PageCount)+1;
				continue;
				
			}

			
			if(strcmp(BeginTime,time)>0 ||(strlen(BeginTime)!=10) || (BeginTime[4] != '-') ||(BeginTime[7] != '-'))
			{
				Gotoxy(x+2,y+3);
				printf("                       ");
				Gotoxy(x+2,y+3);
				printf("����������������룡");
				Sleep(1500);
				continue;

			}


			Gotoxy(x,y+2);

			rt = time_putString(EndTime, 10);
		
			
			if(rt ==27)
			{
				return 0;
			}
			if(rt ==32)//���ո��ʱˢ�½���
			{
				page = 1;
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);
				find = -1;
				continue;
			}
			
			if(rt  == 75)//����������ҳ
			{
				
				page=1;
				continue;
				
			}
			if(rt  == 72)//���ϣ�������һҳ
			{	
				page = page-1;
				if(page==0)
				{
					page=PageCount;
				}
				continue;
				
			}
			
			if(rt == 77 )//���ң�����ĩҳ
			{
				
				page=PageCount;
				continue;
				
			}
			if(rt == 80)//���£�������һҳ
			{
				
				//printf("222222222222222\n");
				page = (page%PageCount)+1;
				continue;
				
			}

			while(  (strcmp(EndTime,BeginTime))<0 ||(strcmp(EndTime,time))>0 ||(strlen(EndTime)!=10) || (EndTime[4] != '-') || (EndTime[7] != '-')  )
			{
				Gotoxy(x+2,y+3);
				printf("                       ");
				Gotoxy(x+2,y+3);
				printf("����������������룡");
				Sleep(1500);
				Gotoxy(x+2,y+3);
				printf("                      ");

				Gotoxy(x,y+2);
				printf("           ");
				Gotoxy(x,y+2);
				rt = time_putString(EndTime, 10);
				
			}
			flag = 1;
			ptemp = PersonalBill_head;
			pnew = NULL;
			
			while(ptemp!=NULL)
			{
				data = (STAFF *)(ptemp->Data);
				if(strcmp(data->sTime,BeginTime)>=0 && strcmp(data->sTime,EndTime)<=0)
				{
					//printf("1111111111\n");
					if(flag==1)//��һ�β�ѯ��ʱ��ʼ����ͷ
					{
						
						pnew = List_Init(data);
						flag++;
						ptemp = ptemp->next;
						continue;
						
					}
					else
					{	
						//������������½ڵ�			
						List_Add(pnew,data);
						data =(BILL *)malloc(sizeof(BILL));
						memset(data,0,sizeof(BILL));
						
					}
					
				}
				ptemp = ptemp->next;
				
			}
			
			page = 1;
			if(pnew != NULL)
			{
				find =  List_Count(pnew);
			}
			else{ find = -1;}

			PersonalBill_head = pnew;
			
		

	}


}







