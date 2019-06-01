#include"user.h"
void user_ui()
{


	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                用户界面                ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ● 请输入你的选择：                       ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              1、余额查询               ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●              2、取    款               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              3、存    款               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              4、转    账               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              5、密码修改               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              6、记录查询               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              7、注    销               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              8、退    出               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");


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
			{//余额查询

				system("cls");
				//printf("添加新用户\n");
				
				rt = user_MoneyQuery(staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 2:
			{//取款

				system("cls");
				
				rt = user_GetMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 3:
			{//存款

				system("cls");
				
				rt =user_PutMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}

			}break;
		case 4:
			{//转账
				
				system("cls");
				
				rt =user_GiveMoney(staff_head,bill_head, staff_fp,bill_fp,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}
				
			}break;
		case 5:
			{//密码修改
				
				system("cls");
				
				rt = user_ModifyPsw(staff_fp,staff_head,staff_node);
				if(rt==0)
				{
					system("cls");
					continue;
				}


			}break;
		case 6:
			{//交易记录查询
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
				printf("按回车键确认注销,其他任意键取消！");
				ch = getch();
				
				if(ch ==13)
				{
					return 0;//用来判断退出
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
			printf("按回车键确认退出,其他任意键取消！");
			ch = getch();
			
			if(ch ==13)
			{
				Gotoxy(33,30);
				exit(0);//用来判断退出
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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                查询余额                ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●    您的账户：                          ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
    printf("                       ●    当前余额：                          ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●    用户操作：                          ●\n");
	printf("                       ●           返回请输入1                  ●\n");
	printf("                       ●           退出请输入2                  ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●        请输入您的选择：                ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");



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
			printf("是否确认退出？回车键确认，其他键取消!");
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
			printf("请输入正确的数字!");

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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●            修改用户密码界面            ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●       用户名：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●       旧密码：                         ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●       新密码：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     确认密码：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●          按空格键重置界面！            ●\n");
	printf("                       ●        按esc键返回上一个界面!          ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");




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

			char sPwd0[7] ={0};//旧密码
			char sPwd1[7] ={0};//新密码
			char sPwd2[7] ={0};//确认密码
			char ch = 0;
			int rt = -1;
			int x=40 ;
			int y=10;

			system("cls");
			user_ModifyPsw_ui();
			Gotoxy(x,y);
			printf("%s",staff_node->sName);//打印账号名

			Gotoxy(x,y+2);
			rt = glb_putString(sPwd0,6,3,0);//输入旧密码
			if(rt==0) //按esc返回
			{
				return 0;
			}
			if(rt==2)//按空格刷新界面
			{
				continue;
			}

			while(strcmp(sPwd0,staff_node->sPwd)!=0)//
				{
					Gotoxy(30,20);
					printf("用户旧密码错误，请重新输入！");
					Sleep(2000); //停滞1秒清除提示栏
					Gotoxy(30,20);
					printf("                              ");
					Gotoxy(x,y+2);
					printf("        ");
					Gotoxy(x,y+2);
					rt = glb_putString(sPwd0,6,3,0);//旧密码重新输入
					if(rt==0) //按esc返回
					{
						return 0;
					}
					if(rt==2)//按空格刷新界面
					{
						flag = 1;
						break;
					}
	
				}
			if(flag == 1)//按空格刷新界面
			{
				continue;
			}


			flag3= 0;
			while(1)
			{

					Gotoxy(x,y+4);
					printf("       ");
					Gotoxy(x,y+4);
					rt = glb_putString(sPwd1,6,3,0);//输入新密码
					if(rt==0) //按esc返回
					{
						return 0;
					}
					if(rt==2)//按空格刷新界面
					{
						flag3= 3;
						break;
					}
					if(strlen(sPwd1)!=6)
					{
						Gotoxy(30,20);
						printf("密码必须为六位，请重新输入！");
						Sleep(2000); //停滞1秒清除提示栏
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
			rt = glb_putString(sPwd2,6,3,0);//重复输入新密码
			if(rt==0) //按esc返回
			{
				return 0;
			}
			if(rt==2)//按空格刷新界面
			{
				continue;
			}

	
			flag2 = 0;
			while(strcmp(sPwd1,sPwd2)!=0)
			{
				Gotoxy(30,20);
				printf("两次密码不一致，请重新输入！");
				Sleep(2000); //停滞1秒清除提示栏
				Gotoxy(30,20);
				printf("                            ");

				Gotoxy(x,y+6);
				printf("        ");
				Gotoxy(x,y+6);
				rt = glb_putString(sPwd2,6,3,0);//重复输入新密码
				if(rt==0) //按esc返回
				{
					return 0;
				}
				if(rt==2)//按空格刷新界面
				{
					flag2 = 2;
					break;
				}

				
			}
			if(flag2 == 2)//按空格刷新界面
			{
				continue;
			}

			ptemp = staff_head;
			while(NULL !=ptemp)
			{	
		/*把void类型指针赋值给其他类型的指针，需要强制转化*/
				data = ((STAFF *)(ptemp->Data));
				if(strcmp(staff_node->sName,data->sName)==0)
				{ //账号匹配时
				
					break;
				}
				ptemp = ptemp->next;	
				
			}	

			strcpy(data->sPwd,sPwd2);

			list_to_file(staff_fp ,staff_head,sizeof(STAFF));

			Gotoxy(25,20);
			printf("修改成功，按回车继续，其他任意键返回！");
			
			ch = getch();
		   if(ch == 13)//按回车继续
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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                 存款界面               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     您的账户：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     当前金额：                         ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●     存款金额：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●          按空格键重置界面！            ●\n");
	printf("                       ●        按esc键返回上一个界面!          ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");




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
		if(rt==0) //按esc返回
		{
			return 0;
		}
		if(rt==2)//按空格刷新界面
		{
			continue;
		}
		if(atoi(putMoney)%100 !=0)
		{
			Gotoxy(30,18);
			printf("存款金额需为整百，请重新输入！");
			Sleep(2000);
			system("cls");
			continue;

		}

	
		

		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//获取当前时间

		time[10] = '\0';

		
		bill_data = (BILL *)malloc(sizeof(BILL));

		strcpy(bill_data->sAccount,sAccount);
		
		bill_data->dDealMoney=atoi(putMoney);
		bill_data->dLeftMoney = staff_node->Dmoney+atoi(putMoney);
		strcpy(bill_data->sDealTarget ,"ATM机");
		strcpy(bill_data->sMessage ,"存款");
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
		printf("存款成功！按任意键继续！");
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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                 取款界面               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     您的账户：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     当前金额：                         ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●     取款金额：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●          按空格键重置界面！            ●\n");
	printf("                       ●        按esc键返回上一个界面!          ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");





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
		if(rt==0) //按esc返回
		{
			return 0;
		}
		if(rt==2)//按空格刷新界面
		{
			continue;
		}
		if(atoi(GetMoney)%100 !=0)
		{
			Gotoxy(30,18);
			printf("取款金额需为整百，请重新输入！");
			Sleep(2000);
			system("cls");
			continue;

		}
		if(atoi(GetMoney)>staff_node->Dmoney)
		{
			Gotoxy(33,18);
			printf("余额不足，请重新输入！");
			Sleep(2000);
			system("cls");
			continue;

		}

		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//获取当前时间

		time[10] = '\0';

		
		bill_data = (BILL *)malloc(sizeof(BILL));

		strcpy(bill_data->sAccount,sAccount);
		
		bill_data->dDealMoney=atoi(GetMoney);
		bill_data->dLeftMoney = staff_node->Dmoney-atoi(GetMoney);
		strcpy(bill_data->sDealTarget ,"ATM机");
		strcpy(bill_data->sMessage ,"取款");
		strcpy(bill_data->sTime ,time);


		List_Add(bill_head,bill_data);

		list_to_file(bill_fp ,bill_head, sizeof(BILL));//修改账单文件

		while(NULL != ptemp)
		{
			staff_data = (STAFF *)(ptemp->Data);

			if(strcmp(staff_data->sAccount,sAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney-atoi(GetMoney);
			}
			ptemp = ptemp->next;

		}

		list_to_file(staff_fp ,staff_head,sizeof(STAFF));//修改用户文件


		Gotoxy(33,18);
		printf("取款成功！按任意键继续！");
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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                 转账界面               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     您的账户：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     当前余额：                         ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●     转账账号：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●     转账金额：                         ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●          按空格键重置界面！            ●\n");
	printf("                       ●        按esc键返回上一个界面!          ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");





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
		if(rt==0) //按esc返回
		{
			return 0;
		}
		if(rt==2)//按空格刷新界面
		{
			system("cls");
			continue;
		}
		
		ptemp = staff_head;
		while(NULL != ptemp)//判断链表中是否存在目标账户
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
			printf("目标账户不存在，请重新输入！");
			Sleep(2000);
			
			continue;
		}
		if(flag ==-1)
		{
			Gotoxy(35,20);
			printf("无效账户，请重新输入！");
			Sleep(2000);
			
			continue;
		}
		while(1)
		{
			Gotoxy(x,y+6);
			printf("         ");
			Gotoxy(x,y+6);
			rt = glb_putString(GiveMoney,8,1,1);//转账金额输入
			if(rt==0) //按esc返回
			{
				return 0;
			}
			if(rt==2)//按空格刷新界面
			{
				flag =-1;
				break;
			}
			/*
			if(atoi(GiveMoney)%100 !=0 && atoi(GiveMoney)== 0 )
			{
				Gotoxy(33,20);
				printf("转账金额需为整百，请重新输入！");
				Sleep(1000);
				Gotoxy(3,15);
				printf("                              ");
				continue;

			}
			*/
			
			if(atoi(GiveMoney)>(staff_node->Dmoney))
			{
				Gotoxy(33,20);
				printf("余额不足，请重新输入！");
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
		printf("目标用户为:%s,是否确认转账?",TargetName);
		Gotoxy(30,21);
		printf(" 按回车确认，其他任意键取消！");
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
		while(NULL != ptemp)//自己账户的余额减少
		{
			staff_data = (STAFF *)(ptemp->Data);
			
			if(strcmp(staff_data->sAccount,MyAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney-atoi(GiveMoney);
			}
			ptemp = ptemp->next;
			
		}

		ptemp = staff_head;
		while(NULL != ptemp)//目标账户的余额增加
		{
			staff_data = (STAFF *)(ptemp->Data);
			
			if(strcmp(staff_data->sAccount,TargetAccount) == 0)
			{
				staff_data->Dmoney=staff_data->Dmoney+atoi(GiveMoney);
			}
			ptemp = ptemp->next;
			
		}

		list_to_file(staff_fp ,staff_head,sizeof(STAFF));//修改文件


		
		strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//获取当前时间
		
		time[10] = '\0';
		
		
		bill_data1 = (BILL *)malloc(sizeof(BILL));
		
		strcpy(bill_data1->sAccount,MyAccount);
		
		bill_data1->dDealMoney=atoi(GiveMoney);
		bill_data1->dLeftMoney = staff_node->Dmoney-atoi(GiveMoney);
		strcpy(bill_data1->sDealTarget ,TargetAccount);
		strcpy(bill_data1->sMessage ,"转出");
		strcpy(bill_data1->sTime ,time);
		
		
		List_Add(bill_head,bill_data1);



		bill_data2 = (BILL *)malloc(sizeof(BILL));
		
		strcpy(bill_data2->sAccount,TargetAccount);
		
		bill_data2->dDealMoney=atoi(GiveMoney);
		bill_data2->dLeftMoney = staff_node->Dmoney+atoi(GiveMoney);
		strcpy(bill_data2->sDealTarget ,MyAccount);
		strcpy(bill_data2->sMessage ,"转入");
		strcpy(bill_data2->sTime ,time);
		
		
		List_Add(bill_head,bill_data2);
		
		list_to_file(bill_fp ,bill_head, sizeof(BILL));
		

		Gotoxy(26,20);
		printf("                                ");
		Gotoxy(30,21);
		printf("                              ");

		Gotoxy(33,20);


		printf("转账成功！按任意键继续！");
		ch = getch();
		system("cls");
		continue;
		
	}
	




}


void user_QueryBill_ui()
{
	printf("\n");
	printf("●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("●                                 用户账单信息                                   ●\n");
	printf("●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●\n");
	printf("●|   账号    |      时间     |  交易金额  |    余额   | 交易信息 |  交易对象    |●\n");
	printf("●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●|           |               |            |           |          |              |●\n");
	printf("●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("●        请按方向键来翻页！      ●            请输入时间来查询账单              ●\n");
	printf("●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●\n");
	printf("●             （↑）             ●                                              ●\n");
	printf("●             上一页             ●    起始时间：                                ●\n");
	printf("● （←）首页          末页（→） ●                                              ●\n");
	printf("●             下一页             ●    终止日期：                                ●\n");
	printf("●             （↓）             ●                                              ●\n");
	printf("●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡●\n");
	printf("●     按esc键返回上一个界面!     ●           按空格键清空时间栏输出!            ●\n");
	printf("●                                ●【时间格式例如：xxxx-xx-xx(用横杆分开年月日)】●\n");
	printf("●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                               ○                ○                                 \n");
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
		//把void类型指针赋值给其他类型的指针，需要强制转化
		data = ((BILL *)(ptemp->Data));
		
		if(strcmp(data->sAccount,sAccount) == 0)
		{
			if(flag==1)//第一次查询到时初始化表头
			{
				
				PersonalBill_head = List_Init(data);
				flag++;
				ptemp = ptemp->next;
				continue;
			}
			else
			{	//往链表中添加新节点			
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

			record = List_Count(ptemp); //总的记录条数
			
			
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//定义总的页数
			
			system("cls");
			user_QueryBill_ui();


			Gotoxy(35,28);
			printf("第%d页，共%d页",page,PageCount);

			data =(BILL *)malloc(sizeof(BILL));
			memset(data,0,sizeof(BILL));
			

			position = (page-1)*PageSize+1;//定义要打印节点的位置

			if(PageCount!=page)//除了最后一页，每一页打印PageSize条记录
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
			if(PageCount==page)//对最后一页进行特殊处理
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
	
	//获取用户自己的账单
	PersonalBill_head = GetPersonalBill(bill_head,staff_node);

	strftime(time,sizeof(time),"%Y-%m-%d",localtime(&t));//获取当前时间

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
				printf("未查询到结果！");
				Sleep(3000);
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);

			}
		
			bill_show(page, PersonalBill_head);
			if(find >0)
			{
				Gotoxy(x+2,y+3);
				printf("成功查询到%d条数据！",find);
				
			}
			record = List_Count(PersonalBill_head); //总的记录条数
		
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//定义总的页数
			
			 Gotoxy(x,y);

		   	rt = time_putString(BeginTime, 10);
			
		
			
			if(rt ==0)//按esc返回上一个界面
			{
				
				getch();
				return 0;
			}
			if(rt ==2)//按空格键时刷新界面
			{
				page = 1;
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);
				find = -1;
				continue;
			}
			
			
			if(rt  == 75)//按左，跳到首页
			{
				
				page=1;
				continue;
				
			}
			if(rt  == 72)//按上，跳到上一页
			{	
				page = page-1;
				if(page==0)
				{
					page=PageCount;
				}
				continue;
				
			}
			
			if(rt == 77 )//按右，跳到末页
			{
				
				page=PageCount;
				continue;
				
			}
			if(rt == 80)//按下，跳到下一页
			{

				page = (page%PageCount)+1;
				continue;
				
			}

			
			if(strcmp(BeginTime,time)>0 ||(strlen(BeginTime)!=10) || (BeginTime[4] != '-') ||(BeginTime[7] != '-'))
			{
				Gotoxy(x+2,y+3);
				printf("                       ");
				Gotoxy(x+2,y+3);
				printf("输入错误，请重新输入！");
				Sleep(1500);
				continue;

			}


			Gotoxy(x,y+2);

			rt = time_putString(EndTime, 10);
		
			
			if(rt ==27)
			{
				return 0;
			}
			if(rt ==32)//按空格键时刷新界面
			{
				page = 1;
				PersonalBill_head = GetPersonalBill(bill_head,staff_node);
				find = -1;
				continue;
			}
			
			if(rt  == 75)//按左，跳到首页
			{
				
				page=1;
				continue;
				
			}
			if(rt  == 72)//按上，跳到上一页
			{	
				page = page-1;
				if(page==0)
				{
					page=PageCount;
				}
				continue;
				
			}
			
			if(rt == 77 )//按右，跳到末页
			{
				
				page=PageCount;
				continue;
				
			}
			if(rt == 80)//按下，跳到下一页
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
				printf("输入错误，请重新输入！");
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
					if(flag==1)//第一次查询到时初始化表头
					{
						
						pnew = List_Init(data);
						flag++;
						ptemp = ptemp->next;
						continue;
						
					}
					else
					{	
						//往链表中添加新节点			
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







