#include"admin.h"
void admin_ui()
{

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��             ��������Ա����             ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       �� ���������ѡ��                       ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              1�������û�               ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��              2��ɾ���û�               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              3���޸��û�               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              4����ѯ�û�               ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              5��ע��                   ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              6���˳�                   ��\n");
	printf("                       ��                                        ��\n");
	printf("                       �����������������������\n");

}


int admin(FILE *staff_fp,LIST *staff_head)
{
		
	int rt = 0;
	char  Choice [2]={0};
	char ch = 0;
while(1)
{
	rt = 0;
	admin_ui();
	Gotoxy(42,10);
	putString(Choice, 1, 1, 1);
	

	switch(atoi(Choice))
	{
	case 1:
		{//�����û�

			system("cls");
			//printf("������û�\n");
			
			rt = admin_adduser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 2:
		{//ɾ���û�

			system("cls");
			
			rt = admin_deleteuser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 3:
		{//�޸��û�

		    system("cls");
			
			rt = admin_modifyuser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 4:
		{ //��ѯ�û� 
			
			system("cls");
			
			rt = admin_queryuser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}


		}break;
	case 5:
		{
			Gotoxy(29,25);
			printf("���س���ȷ��ע��,���������ȡ����");
			ch = getch();
			
			if(ch ==13)
			{
				return 0;//�����ж�ע��
			}
			else
			{	
				system("cls");
				continue;
			}

            
			
	
		}break;
	case 6:
	{
		
			Gotoxy(29,25);
			printf("���س���ȷ���˳�,���������ȡ����");
			ch = getch();
			
			if(ch ==13)
			{
				Gotoxy(33,26);
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

	return 0;
}

void admin_adduser_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��              ����û�����              ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       �� ��������Ҫ������û�����Ϣ��           ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��        �û���ݣ�                      ��\n");
    printf("                       ��                                        ��\n");
	printf("                       ��          �û�����                      ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��        �û����룺                      ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��        ȷ�����룺                      ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       �� ��ʾ��                                 ��\n");
	printf("                       ��    �û���ݣ� 1->��������Ա , 2->�û�  ��\n");
	printf("                       ��               3->��ͨ����Ա            ��\n");
	printf("                       ��    �������Ϊ6λ��   �û������8λ��   ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��        ��esc���ص���һ�����棡         ��\n");
	printf("                       ��          ���ո������������룡          ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��                                        ��\n");
	printf("                       �����������������������\n");


	
}

int admin_adduser(FILE *staff_fp,LIST *staff_head)
{

	LIST *ptemp = NULL;
	STAFF *pnew = NULL;
	STAFF *data = NULL;
	//STAFF  pnew2 ={"","","",0,0,0};
	char iRole[2] ;
	char sName [8];
	char sPwd1 [7];
	char sPwd2 [7];
	char sAccount[9];
	int flag = 0;
	int x = 43;
	int y = 10;
	int rt = 0;

	while(1)
	{
		system("cls");
		admin_adduser_ui();

		Gotoxy(x,y);
		rt = glb_putString(iRole, 1, 1, 1);
		if(rt==0)
			return 0;
		if(rt==2)
			continue;
		if(atoi(iRole)!=1 && atoi(iRole)!=2 && atoi(iRole)!=3)
		{
			Gotoxy(28,28);
		    printf("�û���ݱ���Ϊ1��2��3�����������룡");//�����û����λ
			Sleep(2000); //ͣ��2�������ʾ��
	        system("cls");
		    continue;
		}

		while(1)//�ظ��������֣�ֱ�����ֲ��ظ�
		{
			Gotoxy(x,y+2);
			rt = glb_putString(sName, 8, 3, 1);
			if(rt==0)
				return 0;
			if(rt==2)
			{
				flag = -1;
				break;
			}

			if(ExistUser(staff_head,sName) == -1)
			{
				Gotoxy(31,28);
				printf("���˻��Ѵ��ڣ����������룡");
				Sleep(2000); //ͣ��2�������ʾ��
				Gotoxy(31,28);
				printf("                           ");
				Gotoxy(x,y+2);
				printf("        ");  //���������
				continue;
			}
			break;
		}
		if(flag == -1)//����
		{
			system("cls");
			continue;
		}

		flag = 0;
		while(1)
		{
			Gotoxy(x,y+4);
			rt = glb_putString(sPwd1, 6, 3, 0);//��һ����������
			if(rt==0)
				return 0;
			if(rt==2)
			{
				flag = -2;
				break;
			}
			if(strlen(sPwd1)!=6)
			{
				Gotoxy(29,28);
				printf("�������Ϊ6λ�����������룡");
				Sleep(2000); //ͣ��2�������ʾ��
				Gotoxy(29,28);
				printf("                            ");
				Gotoxy(x,y+4);
				printf("             ");  //���������
				
				Gotoxy(x,y+4);
				continue;

			}
				break;

		}
		if(flag == -2)//����
		{
			system("cls");
			continue;
		}

		flag = 0;
		while(1)
		{
			
			Gotoxy(x,y+6);
			rt = glb_putString(sPwd2, 6, 3, 0);//�ڶ�������ȷ������
			if(rt==0)
				return 0;
			if(rt==2)
			{
				flag = -2;
				break;
			}
			if(strlen(sPwd2)!=6)
			{
				Gotoxy(29,28);
				printf("�������Ϊ��λ�����������룡");
				Sleep(2000); //ͣ��2�������ʾ��
				Gotoxy(29,28);
				printf("                            ");
				Gotoxy(x,y+6);
				printf("             ");  //���������
				
				Gotoxy(x,y+6);
				continue;

			}
			break;

		}

		if(flag == -2)//����
		{
			system("cls");
			continue;
		}



		flag = 0;
		while(strcmp(sPwd1,sPwd2) != 0)
		{
			Gotoxy(29,28);
		    printf("�����˺Ų�һ�£����������룡");
			Sleep(2000); //ͣ��2�������ʾ��
			Gotoxy(29,28);
		    printf("                            ");
			Gotoxy(x,y+6);
			printf("             ");  //���������
			
			Gotoxy(x,y+6);
			rt = glb_putString(sPwd2, 6, 3, 0);
            if(rt==0)
				return 0;
			if(rt==2)
			{
				flag = -2;
			    break;
			}

		}
		if(flag == -2)//����
		{
			system("cls");
			continue;
		}

		ptemp = staff_head;
    
	//	Staff_Printf(staff_head);
		while(ptemp->next != NULL)//�ҵ����һ���ڵ�
		{
			ptemp = ptemp->next;

		}


		strcpy(sAccount,((STAFF *)(ptemp->Data))->sAccount);
		Gotoxy(31,27);
		printf("���˺��ǣ�%d",atoi(sAccount)+1);//�˺�ÿ��+1����
		
		break;
	}
	pnew = (STAFF *)malloc(sizeof(STAFF));//���½ڵ������򿪱ٿռ�
	strcpy(pnew->sName,sName);
//	pnew->sName=sName;
	strcpy(pnew->sPwd,sPwd2);
//	pnew->sPwd=sPwd2;
	itoa(atoi(sAccount)+1, sAccount, 10);
	strcpy(pnew->sAccount,sAccount);
//	pnew->sAccount=sAccount;
	pnew->iRole = atoi(iRole);
	pnew->iEixt = 1;
	pnew->Dmoney =0;
/************************************************************************************
itoa()����˵����

    itoa()����������ת��Ϊ�ַ�����atoi()�������ַ���ת��Ϊ����
	itoa()������3����������һ��������Ҫת�������֣��ڶ���������Ҫд��ת�������Ŀ���ַ�����
	������������ת������ʱ���� �Ļ������������У�ת������Ϊ10��10��ʮ���ƣ�2��������...
*************************************************************************************/
	List_Add(staff_head,pnew);


	list_to_file(staff_fp ,staff_head,sizeof(STAFF)); //����д���ļ�

	Gotoxy(31,28);
	printf("��ӳɹ�,����������أ�");
	getch();
	system("cls");
	return 0;
}

void admin_queryuser_ui()
{
	printf("\n");
	printf("���������������������������������������������\n");
	printf("��                                   ��ѯ�û�����                                     ��\n");
	printf("��************************************************************************************��\n");
	printf("��|  �û���   |      �˺�     |    ����    |     ���     | �Ƿ����� |     ���      |��\n");
	printf("��|***********|***************|************|**************|**********|***************|��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��|           |               |            |              |          |               |��\n");
	printf("��************************************************************************************��\n");
	printf("��        �밴���������ҳ��      ��         �������û�������ѯ�û���Ϣ               ��\n");
	printf("��********************************��**************************************************��\n");
	printf("��             ������             ��                                                  ��\n");
	printf("��             ��һҳ             ��                                                  ��\n");
	printf("�� ��������ҳ          ĩҳ������ ��      �û�����                                    ��\n");
	printf("��             ��һҳ             ��                                                  ��\n");
	printf("��             ������             ��                                                  ��\n");
	printf("��********************************��**************************************************��\n");
	printf("��     �밴���¼��������ѯ��     ��                                                  ��\n");
	printf("��********************************��**************************************************��\n");
	printf("��      ��,������������Ա         ��                                                  ��\n");
	printf("��      ��.������ͨ����Ա         ��             ��esc��������һ���˵���              ��\n");
	printf("��      ��/������ͨ�û�           ��                ���ո��ˢ�½��棡                ��\n");
	printf("���������������������������������������������\n");
}

void staff_show(int page, LIST *staff_head)
{
	LIST *ptemp = staff_head;
	LIST *pnew = NULL;
	STAFF *data = NULL;
	char ch;
	char  role[6] ={0};
	char exit[4] ={0};
	int i =0;
	int PageSize = 10;
	//int page = 1;
	int PageCount = 0;
	int record = 0;
	int position = 0;
    int rt = -1;
	int flag = 1;
	
			int x=5 ;
	        int y=6 ;
			
			record = List_Count(ptemp); //�ܵļ�¼����
			
			
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//�����ܵ�ҳ��
			
			system("cls");
		    admin_queryuser_ui();

			Gotoxy(50,25);
			printf("��%dҳ����%dҳ",page,PageCount);


			data =(STAFF *)malloc(sizeof(STAFF));
			memset(data,0,sizeof(STAFF));
			

			position = (page-1)*PageSize+1;//����Ҫ��ӡ�ڵ��λ��

			if(PageCount!=page)//�������һҳ��ÿһҳ��ӡPageSize����¼
			{
				for(i=1;i<=PageSize;i++)
				{
					data =(STAFF *)malloc(sizeof(STAFF));
					memset(data,0,sizeof(STAFF));
					data = (STAFF *)List_GetNode_Data(ptemp,position++);

					if(data->iRole ==1)
						strcpy(role,"��������Ա");
					else if(data->iRole ==3)
						strcpy(role,"��ͨ����Ա");
					else
						strcpy(role,"�û�");
					
					
					if(data->iEixt ==1)
						strcpy(exit,"no");
					else
						strcpy(exit,"yes");
					
					Gotoxy(x,y);
					printf("%s",data->sName);
					Gotoxy(x+14,y);
					printf("%s",data->sAccount);
					Gotoxy(x+29,y);
					printf("%s","******");
					if(data->iRole==1 || data->iRole==3)
					{
						Gotoxy(x+41,y);
						printf("%s",role);
					}
					else
					{
						Gotoxy(x+44,y);
						printf("%s",role);
					}
					Gotoxy(x+58,y);
					printf("%s",exit);
					Gotoxy(x+71,y);
					printf("%.0lf",data->Dmoney);
					
					y++;

				}

			}
			if(PageCount==page)//�����һҳ�������⴦��
			{

				
				for(i=1;i<=(record-PageSize*(PageCount-1));i++)
				{
					data =(STAFF *)malloc(sizeof(STAFF));
					memset(data,0,sizeof(STAFF));

					data = (STAFF *)List_GetNode_Data(ptemp,position++);

					if(data->iRole ==1)
						strcpy(role,"��������Ա");
					else if(data->iRole ==3)
						strcpy(role,"��ͨ����Ա");
					else
						strcpy(role,"�û�");
					
					
					if(data->iEixt ==1)
						strcpy(exit,"no");
					else
						strcpy(exit,"yes");
					
					Gotoxy(x,y);
					printf("%s",data->sName);
					Gotoxy(x+14,y);
					printf("%s",data->sAccount);
					Gotoxy(x+29,y);
					printf("%s","******");
					if(data->iRole==1 || data->iRole==3)
					{
						Gotoxy(x+41,y);
						printf("%s",role);
					}
					else
					{
						Gotoxy(x+44,y);
						printf("%s",role);
					}
					Gotoxy(x+58,y);
					printf("%s",exit);
					Gotoxy(x+71,y);
					printf("%.0lf",data->Dmoney);
					
					y++;

				}

			}
	

}

LIST *get_list_by_role(LIST *staff_head,int Role)
{
	int flag = 1;
	LIST *ptemp = staff_head;
	LIST *pnew = NULL;
	STAFF *data =NULL;
	
	while(ptemp!=NULL)
	{
		data = (STAFF *)(ptemp->Data);
		if(data->iRole == Role)
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

	return pnew;


}


int admin_queryuser(FILE *staff_fp,LIST *staff_head)
{
	
	LIST *ptemp = staff_head;
	LIST *pnew = NULL;
	STAFF *data = NULL;
	char ch;
	int i =0;
	int flag = 0;
	int page = 1;
	int PageCount = 0;
	int record = 0;
	int PageSize = 10;
	int inputMax = 8;
	
	int x= 49;
	int y = 21;

	char sSearchName[9] = {0};

	ptemp = staff_head;

		//Staff_Printf(ptemp);

	    //Sleep(3000);

	for(i =0;i<=inputMax;i++)//���������ַ���
	{
		system("cls");
		if(ptemp == NULL)//����ѯû�н��ʱ����ֻ��Ӧһ�����棬����ӡ����
		{
			admin_queryuser_ui();
			Gotoxy(x+1,y+4);
			printf("���޴��ˣ���");
		}
		else
		{
			staff_show(page, ptemp);//������ʱ��ӡptemp����ĵ�pageҳ������
		}
		Gotoxy(x,y);
		printf("%s",sSearchName);//��ӡ�Ѿ�������ַ�
	   
		record = List_Count(ptemp); //�ܵļ�¼����

		PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//�����ܵ�ҳ��

		ch = getch();	
		if(ch ==27) //��escʱ���ص���һ������
		{
			return 0;
		}

		if(ch == 44)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,1);//��������Ա
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 46)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,3);//��ͨ����Ա
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 47)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,2);//��ͨ�û�
			
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 32)//���ո�ʱˢ�½���
		{
		
			page = 1;
			ptemp =staff_head;
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if( ch == 75)//����������ҳ
		{
			page = 1;
			
			i--;
			continue;
		}
		if( ch == 72)//���ϣ�������һҳ
		{	
			page = page-1;
			if(page==0)
			{
				page=PageCount;
			}
			i--;
			continue;
		}
		
		if(ch == 77 )//���ң�����ĩҳ
		{
			page = PageCount;
			i--;
			continue;
		}
		if(ch == 80 )//���£�������һҳ
		{
			page = page%PageCount+1;
			i--;
			continue;
		}
		if(ch == '\b')
		{
			if(strlen(sSearchName)>0)
			{
				printf("\b \b");
				i--;
				sSearchName[i] = '\0';
			//	Gotoxy(15,27);
			//	printf("����ɾ����\n");
			//	Sleep(2000);
				i--;//��i++����
			}
			else
			{
				Gotoxy(x+8,y+2);
				printf("�Ѿ������һλ�ˣ�");
				Sleep(1500);
				ptemp = staff_head;
				i--;
				continue;
				
			}


		}
	
		if ( !(( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) || ( ch >= '0' && ch <= '9' )||(ch =='\b')))
		{
			i--;
			//Gotoxy(10,27);
			//printf("error\n");
			//Sleep(2000);
			continue;
		}
		if(strlen(sSearchName)==inputMax)
		{
			i--;
			Gotoxy(x+1,y+2);
			printf("�������8λ��\n");
			Gotoxy(x+strlen(sSearchName),y);
			Sleep(1500);
			continue;
		}
		if(ch !='\b')
		{
			sSearchName[i] = ch;
			sSearchName[i+1] = '\0';
		}
		Gotoxy(x,y);
		printf("%s",sSearchName);
		//x++;
		flag = 1;
		ptemp = staff_head;
		pnew = NULL;
		
		while(ptemp!=NULL)
		{
			data = (STAFF *)(ptemp->Data);
			if(strstr(data->sName,sSearchName)!=NULL)
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
		ptemp = pnew;
		
	}

	return 0;
}

void admin_deleteuser_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       �����������������������\n");
	printf("                       ��                                        ��\n");
	printf("                       ��              ɾ���û�����              ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��****************************************��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��  ������Ҫɾ���û����û���              ��\n");
	printf("                       ��                                        ��\n");
	printf("                       ��         �û�����                       ��\n");
    printf("                       ��                                        ��\n");
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

int admin_deleteuser(FILE *staff_fp,LIST *staff_head)
{

	while(1)
	{

		
			LIST * ptemp = NULL;
			STAFF *data = NULL;
			int flag = 0;
			char sName[9] ={0};
			char ch = 0;
			int rt = -1;
			int x=23 ;
			int y=17 ;
		//	staff_head =  file_to_list(staff_fp,sizeof(STAFF));

			system("cls");
			admin_deleteuser_ui();
			Gotoxy(42,12);

			rt = glb_putString(sName,8,3,1);
			if(rt==0) //��esc����
			{
				return 0;
			}
			if(rt==2)//���ո�ˢ�½���
			{
			    continue;
			}
			ptemp = staff_head;

			flag = 0;
			while(NULL !=ptemp)
			{
				
		/*��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��*/
				data = ((STAFF *)(ptemp->Data));

				if(strcmp(sName,data->sName)==0 && (data->Dmoney !=0))
				{ //����Ϊ0 ʱ����ɾ��
					flag = -1;
					break;
				}
				if(strcmp(sName,data->sName)==0 && (data->iEixt == 0))
				{ //�Ѿ�ע��ʱ������Ϣ
					flag = -4;
					break;
				}


				if(strcmp(sName,data->sName)==0)
				{  //ƥ�䵽�û����������λ����0
				   Gotoxy(x+4,y);
				   printf("�Ƿ�ȷ��ɾ�������س�ȷ��!������ȡ��!");
				   
				   ch = getch();
				   if(ch == 13)//���س�����
				   {
					data->iEixt = 0;
					flag = -2; //��ʾ��Ϣ
				   }
				   else
				   {
					flag =-3; //ȡ������
				   }
					break;
				}

				flag++;
				ptemp = ptemp->next;
			}
			if(flag ==  List_Count(staff_head))
			{
			   Gotoxy(x+8,y);
			   printf("���û������ڣ����������룡");
			   Sleep(2000); //ͣ��2������
			   continue;
			}
		    if(flag == -1)
			{
			   Gotoxy(x+6,y);
			   printf("�û�������Ϊ0�����������룡");
			   Sleep(2000);
			   continue;
			}

			if(flag == -4)
			{
			   Gotoxy(x+6,y);
			   printf("�û���������״̬�����������룡");
			   Sleep(2000);
			   continue;
			}
			if(flag == -2)//ɾ���ɹ�����ʾ��Ϣ
			{

			  list_to_file(staff_fp ,staff_head,sizeof(STAFF));
			
			   Gotoxy(x+3,y);
			   printf("ɾ���ɹ������س�������������������أ�");
			   //Sleep(1000);
			   //continue;
			   
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
			if(flag ==-3)//ȡ��ɾ��
			{
				Gotoxy(x+3,y);
				printf("                                       ");//�����ʾ��
				Gotoxy(x+13,y);
				printf("�ɹ�ȡ��ɾ����");
				Sleep(2000); //ͣ��2������
				continue;
			}


	}
	
	return 1;

}


void admin_modifyuser_ui()
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

//#if 0
int admin_modifyuser(FILE *staff_fp,LIST *staff_head)
{

	while(1)
	{

		
			LIST * ptemp = NULL;
			STAFF *data = NULL;
			int flag = 0;
			int flag2 = 0;
			int flag3 = 0;
			int flag4 = 0;
			int flag5 = 0;
			char sName[9] ={0};
			char sPwd0[7] ={0};//������
			char sPwd1[7] ={0};//������
			char sPwd2[7] ={0};//ȷ������
			char ch = 0;
			int rt = -1;
			int x=40 ;
			int y=10;
		
			system("cls");
			admin_modifyuser_ui();
			Gotoxy(x,y);

			rt = glb_putString(sName,8,3,1);
			if(rt==0) //��esc����
			{
				return 0;
			}
			if(rt==2)//���ո�ˢ�½���
			{
			    continue;
			}
			ptemp = staff_head;

			flag = 0;

			while(NULL !=ptemp)
			{
				
		/*��void����ָ�븳ֵ���������͵�ָ�룬��Ҫǿ��ת��*/
				data = ((STAFF *)(ptemp->Data));

				if(strcmp(sName,data->sName)==0)
				{ //�˺�ƥ��ʱ
					flag = 1;
					break;
				
				}
			    	flag++;
				ptemp = ptemp->next;	
				
			}	
			if(flag ==  List_Count(staff_head)) //��ѯ�����û�ʱ
			{
			   Gotoxy(30,20);
			   printf("���û������ڣ����������룡");
			   Sleep(2000); //ͣ��2������
			   continue;
			}
			if(flag == 1)  //��ѯ���û�ʱ
			{

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


				if(strcmp(sPwd0,data->sPwd)==0)
				{
					flag5 =0;
					while(1)
					{
						Gotoxy(x,y+4);
						printf("       ");
						Gotoxy(x,y+4);
						rt = glb_putString(sPwd1,6,3,0);//���������ʱ������������
						if(rt==0) //��esc����
						{
							return 0;
						}
						if(rt==2)//���ո�ˢ�½���
						{
							flag5 =5;
							break;

						}
						if(strlen(sPwd1)!=6)
						{
							Gotoxy(30,20);
							printf("�������Ϊ6λ�����������룡");
							Sleep(2000); //ͣ��2������
							Gotoxy(30,20);
							printf("                           ");
							continue;
							
						}

						break;
					}
					if(flag5 ==5)
					{
						continue;						
					}
					flag4  = 4;
				}
				else
				{
					flag2  = 0;
					while(strcmp(sPwd0,data->sPwd)!=0)//������û��Ծ�һֱ����
					{
						Gotoxy(28,20);
						printf("���û�������������������룡");
						Sleep(2000); //ͣ��1�������ʾ��
						Gotoxy(28,20);
						printf("                              ");

						Gotoxy(x,y+2);
						printf("        ");//������һ������
						Gotoxy(x,y+2);
						rt = glb_putString(sPwd0,6,3,0);//���������
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


				}
			     ////////////����������////////////////////
				if(flag4 != 4)
				{
					flag5= 0;
					while(1)
					{
						Gotoxy(x,y+4);
						printf("       ");
						Gotoxy(x,y+4);
						rt = glb_putString(sPwd1,6,3,0);//���������ʱ������������
						if(rt==0) //��esc����
						{
							return 0;
						}
						if(rt==2)//���ո�ˢ�½���
						{
							flag5= 0;
							break;
						}
						if(strlen(sPwd1)!=6)
						{
							Gotoxy(30,20);
							printf("�������Ϊ6λ�����������룡");
							Sleep(2000); //ͣ��2������
							Gotoxy(30,20);
							printf("                           ");
							continue;
							
						}

						break;
					}
					if(flag5 ==5)
					{
						continue;						
					}
				}
				////////////�ظ�����������//////////////////
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

				flag3 = 0;
				while(strcmp(sPwd1,sPwd2)!=0)
				{
					Gotoxy(28,20);
					printf("�������벻һ�£����������룡");
					Sleep(2000); //ͣ��1�������ʾ��
					Gotoxy(28,20);
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
						flag3 = 3;
						break;
					}

					
				}

				if(flag3 == 3)//���ո�ˢ�½���
				{
					continue;
				}
				strcpy(data->sPwd,sPwd2);

				list_to_file(staff_fp ,staff_head,sizeof(STAFF));

				Gotoxy(26,20);
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

 
			}// ��ѯ���û��� 
	

	}
	
	return 1;

}

//#endif
