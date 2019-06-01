#include"login.h"



void loginInit() //页面初始化函数
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●           ATM机系统-登录界面           ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ● 账号/用户名：                          ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●    密    码：                          ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●        按空格键重置账号密码！          ●\n");
	printf("                       ●          按esc键退出程序！             ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	
}

int ChooseMenu(int IChoose,STAFF *staff_node,LIST *staff_head,LIST *bill_head, FILE *staff_fp,FILE *bill_fp)
{
	int rt = -1;
	int x2 = 23;
	int y2 = 19;

	switch(IChoose)
	 {
		
		 case 1://超级管理员界面
		 {
			 Gotoxy(x2+10,y2);
			 printf("登录成功，页面跳转中...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //停滞2秒清屏
			 system("cls");
			 rt = admin(staff_fp,staff_head);
			 if(rt==0)
			 {
				return 0;//用来注销判断
			 }
		 }break;

		 case 2://普通用户界面
		 {
			 Gotoxy(x2+10,y2);
			 printf("登录成功，页面跳转中...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //停滞2秒清屏
			 system("cls");
			 rt = user(staff_head,bill_head,staff_fp,bill_fp,staff_node);
			 if(rt==0)
			 {
				return 0;//用来注销判断
			 }

		 }break;

		 case 3://普通管理员界面
		 {
			 Gotoxy(x2+10,y2);
			 printf("登录成功，页面跳转中...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //停滞2秒清屏
			 system("cls");
			 rt = CommonAdmin(staff_fp,staff_head,staff_node);
			 if(rt==0)
			 {
				return 0;//用来注销判断
			 }
		 }break;
		 
		 default:
		 {

			 Gotoxy(x2+10,y2);
			 printf("登录失败，请重新输入...\n");
			 Gotoxy(x2+33,y2);
			 Sleep(2000); //停滞2秒清屏
			 
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
	int rt2 = -1;//用来判断是否从上一个界面注销
	char ch = 0;

	int x1 = 39;
	int y1 = 12;
	int x2 = 23;
	int y2 = 19;

	while(1)
	{ 
		flag = 0;
		ptemp =staff_head;
		loginInit(); //登录页面初始化
		Gotoxy(x1,y1);  //移动光标位置
		rt = glb_putString(acname,8,3,1);
		if(rt==0) //按esc返回
		{
			Gotoxy(x2+2,y2);
			printf("请连按 esc 键确认退出!按其他任意键取消!");
			ch=getch();
			if(ch == 27) //判断是否输入的是esc
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

		if(rt==2)//按空格刷新界面
		{
			system("cls");
			continue;
		}

		if(strlen(acname) ==0)
		{
			 Gotoxy(x2+10,y2);
			 printf("账号不能为空，请重新输入！");
			 Sleep(1500); //停滞1.5秒清屏
	         system("cls");
		     continue;
		}
		while(ptemp !=NULL)	//判断账户是否存在  
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
			ptemp = ptemp->next;   //指针偏移 找到下一个节点
			flag++;
		}	
		ptemp =staff_head;
		if(flag==List_Count(ptemp))
		{
			
			 Gotoxy(x2+10,y2);
			printf("账号不存在，请重新输入！\n");
			Sleep(1500); //停滞1.5秒清屏
	        system("cls");
			continue;
		}
		ptemp =staff_head;
		flag4 = 0;
		while(ptemp !=NULL)	//循环匹配   
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
			printf("该用户已注销，请重新输入！\n");
			Sleep(1500); //停滞1.5秒清屏
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
			if(rt==0) //按esc返回
			{
				Gotoxy(x2+2,y2);
				printf("请连按 esc 键确认退出!按其他任意键取消!");
				ch=getch();
				if(ch == 27) //判断是否输入的是esc
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
			
			if(rt==2)//按空格刷新界面
			{
				flag3 = 3;
					break;
			}

			if(strlen(acpwd) ==0)
			{
				Gotoxy(x2+10,y2);
				printf("密码不能为空，请重新输入！");
				
				Sleep(1500); //停滞1.5秒清屏

				Gotoxy(x2+10,y2);
				printf("                           ");


				
			//	system("cls");
		   		continue;
			}
			flag2 = 0;
			rt2 = -1;
			ptemp = staff_head;
			while(ptemp !=NULL)	//循环匹配   
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
				ptemp = ptemp->next;   //指针偏移 找到下一个节点
				flag2++;
			}	

			 if(rt2 ==0)//用来判断注销
			  {				
				  flag3= 3;
				  break;
				  
			  }

			ptemp =staff_head;
			if(flag2==List_Count(staff_head))
			{
				Gotoxy(x2+10,y2);
				printf("账号密码不匹配，请重新输入！\n");
				Sleep(1500); //停滞1.5秒清屏
				//system("cls");
				Gotoxy(x2+10,y2);
				printf("                              \n");
	        	continue;
			}
		}  
		if(flag3 ==3)//按空格刷新界面
		{

			system("cls");
			continue;
		}


	 
	
	}


     
}

