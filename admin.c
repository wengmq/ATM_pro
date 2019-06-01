#include"admin.h"
void admin_ui()
{

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●             超级管理员界面             ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ● 请输入你的选择：                       ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              1、增加用户               ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●              2、删除用户               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              3、修改用户               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              4、查询用户               ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              5、注销                   ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              6、退出                   ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");

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
		{//增加用户

			system("cls");
			//printf("添加新用户\n");
			
			rt = admin_adduser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 2:
		{//删除用户

			system("cls");
			
			rt = admin_deleteuser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 3:
		{//修改用户

		    system("cls");
			
			rt = admin_modifyuser(staff_fp,staff_head);
			if(rt==0)
			{
				system("cls");
				continue;
			}

		}break;
	case 4:
		{ //查询用户 
			
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
			printf("按回车键确认注销,其他任意键取消！");
			ch = getch();
			
			if(ch ==13)
			{
				return 0;//用来判断注销
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
			printf("按回车键确认退出,其他任意键取消！");
			ch = getch();
			
			if(ch ==13)
			{
				Gotoxy(33,26);
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

	return 0;
}

void admin_adduser_ui()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●              添加用户界面              ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ● 请输入您要添加新用户的信息：           ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●        用户身份：                      ●\n");
    printf("                       ●                                        ●\n");
	printf("                       ●          用户名：                      ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●        用户密码：                      ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●        确认密码：                      ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ● 提示：                                 ●\n");
	printf("                       ●    用户身份： 1->超级管理员 , 2->用户  ●\n");
	printf("                       ●               3->普通管理员            ●\n");
	printf("                       ●    密码必须为6位！   用户名最多8位！   ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●        按esc键回到上一个界面！         ●\n");
	printf("                       ●          按空格重置所有输入！          ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");


	
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
		    printf("用户身份必须为1或2或3，请重新输入！");//输入用户身份位
			Sleep(2000); //停滞2秒清空提示栏
	        system("cls");
		    continue;
		}

		while(1)//重复输入名字，直到名字不重复
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
				printf("该账户已存在，请重新输入！");
				Sleep(2000); //停滞2秒清空提示栏
				Gotoxy(31,28);
				printf("                           ");
				Gotoxy(x,y+2);
				printf("        ");  //清空输入栏
				continue;
			}
			break;
		}
		if(flag == -1)//清屏
		{
			system("cls");
			continue;
		}

		flag = 0;
		while(1)
		{
			Gotoxy(x,y+4);
			rt = glb_putString(sPwd1, 6, 3, 0);//第一次输入密码
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
				printf("密码必须为6位，请重新输入！");
				Sleep(2000); //停滞2秒清空提示栏
				Gotoxy(29,28);
				printf("                            ");
				Gotoxy(x,y+4);
				printf("             ");  //清空输入栏
				
				Gotoxy(x,y+4);
				continue;

			}
				break;

		}
		if(flag == -2)//清屏
		{
			system("cls");
			continue;
		}

		flag = 0;
		while(1)
		{
			
			Gotoxy(x,y+6);
			rt = glb_putString(sPwd2, 6, 3, 0);//第二次输入确认密码
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
				printf("密码必须为六位，请重新输入！");
				Sleep(2000); //停滞2秒清空提示栏
				Gotoxy(29,28);
				printf("                            ");
				Gotoxy(x,y+6);
				printf("             ");  //清空输入栏
				
				Gotoxy(x,y+6);
				continue;

			}
			break;

		}

		if(flag == -2)//清屏
		{
			system("cls");
			continue;
		}



		flag = 0;
		while(strcmp(sPwd1,sPwd2) != 0)
		{
			Gotoxy(29,28);
		    printf("两次账号不一致，请重新输入！");
			Sleep(2000); //停滞2秒清空提示栏
			Gotoxy(29,28);
		    printf("                            ");
			Gotoxy(x,y+6);
			printf("             ");  //清空输入栏
			
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
		if(flag == -2)//清屏
		{
			system("cls");
			continue;
		}

		ptemp = staff_head;
    
	//	Staff_Printf(staff_head);
		while(ptemp->next != NULL)//找到最后一个节点
		{
			ptemp = ptemp->next;

		}


		strcpy(sAccount,((STAFF *)(ptemp->Data))->sAccount);
		Gotoxy(31,27);
		printf("您账号是：%d",atoi(sAccount)+1);//账号每次+1递增
		
		break;
	}
	pnew = (STAFF *)malloc(sizeof(STAFF));//给新节点数据域开辟空间
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
itoa()函数说明：

    itoa()用来将数字转化为字符串，atoi()用来将字符串转化为数字
	itoa()函数有3个参数：第一个参数是要转换的数字，第二个参数是要写入转换结果的目标字符串，
	第三个参数是转移数字时所用 的基数。在上例中，转换基数为10。10：十进制；2：二进制...
*************************************************************************************/
	List_Add(staff_head,pnew);


	list_to_file(staff_fp ,staff_head,sizeof(STAFF)); //数据写入文件

	Gotoxy(31,28);
	printf("添加成功,按任意键返回！");
	getch();
	system("cls");
	return 0;
}

void admin_queryuser_ui()
{
	printf("\n");
	printf("●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("●                                   查询用户界面                                     ●\n");
	printf("●************************************************************************************●\n");
	printf("●|  用户名   |      账号     |    密码    |     身份     | 是否销户 |     余额      |●\n");
	printf("●|***********|***************|************|**************|**********|***************|●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●|           |               |            |              |          |               |●\n");
	printf("●************************************************************************************●\n");
	printf("●        请按方向键来翻页！      ○         请输入用户名来查询用户信息               ●\n");
	printf("●********************************○**************************************************●\n");
	printf("●             （↑）             ○                                                  ●\n");
	printf("●             上一页             ○                                                  ●\n");
	printf("● （←）首页          末页（→） ○      用户名：                                    ●\n");
	printf("●             下一页             ○                                                  ●\n");
	printf("●             （↓）             ○                                                  ●\n");
	printf("●********************************○**************************************************●\n");
	printf("●     请按以下键来分类查询！     ○                                                  ●\n");
	printf("●********************************○**************************************************●\n");
	printf("●      【,】→超级管理员         ○                                                  ●\n");
	printf("●      【.】→普通管理员         ○             按esc键返回上一级菜单！              ●\n");
	printf("●      【/】→普通用户           ○                按空格键刷新界面！                ●\n");
	printf("●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
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
			
			record = List_Count(ptemp); //总的记录条数
			
			
			PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//定义总的页数
			
			system("cls");
		    admin_queryuser_ui();

			Gotoxy(50,25);
			printf("第%d页，共%d页",page,PageCount);


			data =(STAFF *)malloc(sizeof(STAFF));
			memset(data,0,sizeof(STAFF));
			

			position = (page-1)*PageSize+1;//定义要打印节点的位置

			if(PageCount!=page)//除了最后一页，每一页打印PageSize条记录
			{
				for(i=1;i<=PageSize;i++)
				{
					data =(STAFF *)malloc(sizeof(STAFF));
					memset(data,0,sizeof(STAFF));
					data = (STAFF *)List_GetNode_Data(ptemp,position++);

					if(data->iRole ==1)
						strcpy(role,"超级管理员");
					else if(data->iRole ==3)
						strcpy(role,"普通管理员");
					else
						strcpy(role,"用户");
					
					
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
			if(PageCount==page)//对最后一页进行特殊处理
			{

				
				for(i=1;i<=(record-PageSize*(PageCount-1));i++)
				{
					data =(STAFF *)malloc(sizeof(STAFF));
					memset(data,0,sizeof(STAFF));

					data = (STAFF *)List_GetNode_Data(ptemp,position++);

					if(data->iRole ==1)
						strcpy(role,"超级管理员");
					else if(data->iRole ==3)
						strcpy(role,"普通管理员");
					else
						strcpy(role,"用户");
					
					
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

	for(i =0;i<=inputMax;i++)//控制输入字符串
	{
		system("cls");
		if(ptemp == NULL)//当查询没有结果时，就只答应一个界面，不打印数据
		{
			admin_queryuser_ui();
			Gotoxy(x+1,y+4);
			printf("查无此人！！");
		}
		else
		{
			staff_show(page, ptemp);//有数据时打印ptemp链表的第page页的数据
		}
		Gotoxy(x,y);
		printf("%s",sSearchName);//打印已经输入的字符
	   
		record = List_Count(ptemp); //总的记录条数

		PageCount = (record%PageSize == 0? record/PageSize : record/PageSize+1);//定义总的页数

		ch = getch();	
		if(ch ==27) //按esc时，回到上一个界面
		{
			return 0;
		}

		if(ch == 44)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,1);//超级管理员
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 46)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,3);//普通管理员
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 47)
		{
		
			page = 1;
			ptemp =get_list_by_role(staff_head,2);//普通用户
			
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if(ch == 32)//按空格时刷新界面
		{
		
			page = 1;
			ptemp =staff_head;
			i=-1;
			sSearchName[0] = '\0';
			continue;

		}
		if( ch == 75)//按左，跳到首页
		{
			page = 1;
			
			i--;
			continue;
		}
		if( ch == 72)//按上，跳到上一页
		{	
			page = page-1;
			if(page==0)
			{
				page=PageCount;
			}
			i--;
			continue;
		}
		
		if(ch == 77 )//按右，跳到末页
		{
			page = PageCount;
			i--;
			continue;
		}
		if(ch == 80 )//按下，跳到下一页
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
			//	printf("这是删除！\n");
			//	Sleep(2000);
				i--;//和i++抵消
			}
			else
			{
				Gotoxy(x+8,y+2);
				printf("已经是最后一位了！");
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
			printf("最多输入8位！\n");
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
	printf("                       ●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●              删除用户界面              ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●****************************************●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●  请输入要删除用户的用户名              ●\n");
	printf("                       ●                                        ●\n");
	printf("                       ●         用户名：                       ●\n");
    printf("                       ●                                        ●\n");
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
			if(rt==0) //按esc返回
			{
				return 0;
			}
			if(rt==2)//按空格刷新界面
			{
			    continue;
			}
			ptemp = staff_head;

			flag = 0;
			while(NULL !=ptemp)
			{
				
		/*把void类型指针赋值给其他类型的指针，需要强制转化*/
				data = ((STAFF *)(ptemp->Data));

				if(strcmp(sName,data->sName)==0 && (data->Dmoney !=0))
				{ //但余额不为0 时不能删除
					flag = -1;
					break;
				}
				if(strcmp(sName,data->sName)==0 && (data->iEixt == 0))
				{ //已经注销时返回信息
					flag = -4;
					break;
				}


				if(strcmp(sName,data->sName)==0)
				{  //匹配到用户，将其存在位置于0
				   Gotoxy(x+4,y);
				   printf("是否确认删除？按回车确认!其他键取消!");
				   
				   ch = getch();
				   if(ch == 13)//按回车继续
				   {
					data->iEixt = 0;
					flag = -2; //提示信息
				   }
				   else
				   {
					flag =-3; //取消操作
				   }
					break;
				}

				flag++;
				ptemp = ptemp->next;
			}
			if(flag ==  List_Count(staff_head))
			{
			   Gotoxy(x+8,y);
			   printf("该用户不存在，请重新输入！");
			   Sleep(2000); //停滞2秒清屏
			   continue;
			}
		    if(flag == -1)
			{
			   Gotoxy(x+6,y);
			   printf("用户余额必须为0，请重新输入！");
			   Sleep(2000);
			   continue;
			}

			if(flag == -4)
			{
			   Gotoxy(x+6,y);
			   printf("用户已是销户状态，请重新输入！");
			   Sleep(2000);
			   continue;
			}
			if(flag == -2)//删除成功的提示信息
			{

			  list_to_file(staff_fp ,staff_head,sizeof(STAFF));
			
			   Gotoxy(x+3,y);
			   printf("删除成功，按回车继续，其他任意键返回！");
			   //Sleep(1000);
			   //continue;
			   
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
			if(flag ==-3)//取消删除
			{
				Gotoxy(x+3,y);
				printf("                                       ");//清空提示栏
				Gotoxy(x+13,y);
				printf("成功取消删除！");
				Sleep(2000); //停滞2秒清屏
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
			char sPwd0[7] ={0};//旧密码
			char sPwd1[7] ={0};//新密码
			char sPwd2[7] ={0};//确认密码
			char ch = 0;
			int rt = -1;
			int x=40 ;
			int y=10;
		
			system("cls");
			admin_modifyuser_ui();
			Gotoxy(x,y);

			rt = glb_putString(sName,8,3,1);
			if(rt==0) //按esc返回
			{
				return 0;
			}
			if(rt==2)//按空格刷新界面
			{
			    continue;
			}
			ptemp = staff_head;

			flag = 0;

			while(NULL !=ptemp)
			{
				
		/*把void类型指针赋值给其他类型的指针，需要强制转化*/
				data = ((STAFF *)(ptemp->Data));

				if(strcmp(sName,data->sName)==0)
				{ //账号匹配时
					flag = 1;
					break;
				
				}
			    	flag++;
				ptemp = ptemp->next;	
				
			}	
			if(flag ==  List_Count(staff_head)) //查询不到用户时
			{
			   Gotoxy(30,20);
			   printf("该用户不存在，请重新输入！");
			   Sleep(2000); //停滞2秒清屏
			   continue;
			}
			if(flag == 1)  //查询到用户时
			{

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


				if(strcmp(sPwd0,data->sPwd)==0)
				{
					flag5 =0;
					while(1)
					{
						Gotoxy(x,y+4);
						printf("       ");
						Gotoxy(x,y+4);
						rt = glb_putString(sPwd1,6,3,0);//旧密码输对时，输入新密码
						if(rt==0) //按esc返回
						{
							return 0;
						}
						if(rt==2)//按空格刷新界面
						{
							flag5 =5;
							break;

						}
						if(strlen(sPwd1)!=6)
						{
							Gotoxy(30,20);
							printf("密码必须为6位，请重新输入！");
							Sleep(2000); //停滞2秒清屏
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
					while(strcmp(sPwd0,data->sPwd)!=0)//旧密码没输对就一直输入
					{
						Gotoxy(28,20);
						printf("该用户旧密码错误，请重新输入！");
						Sleep(2000); //停滞1秒清除提示栏
						Gotoxy(28,20);
						printf("                              ");

						Gotoxy(x,y+2);
						printf("        ");//覆盖上一次输入
						Gotoxy(x,y+2);
						rt = glb_putString(sPwd0,6,3,0);//输入旧密码
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


				}
			     ////////////输入新密码////////////////////
				if(flag4 != 4)
				{
					flag5= 0;
					while(1)
					{
						Gotoxy(x,y+4);
						printf("       ");
						Gotoxy(x,y+4);
						rt = glb_putString(sPwd1,6,3,0);//旧密码输对时，输入新密码
						if(rt==0) //按esc返回
						{
							return 0;
						}
						if(rt==2)//按空格刷新界面
						{
							flag5= 0;
							break;
						}
						if(strlen(sPwd1)!=6)
						{
							Gotoxy(30,20);
							printf("密码必须为6位，请重新输入！");
							Sleep(2000); //停滞2秒清屏
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
				////////////重复输入新密码//////////////////
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

				flag3 = 0;
				while(strcmp(sPwd1,sPwd2)!=0)
				{
					Gotoxy(28,20);
					printf("两次密码不一致，请重新输入！");
					Sleep(2000); //停滞1秒清除提示栏
					Gotoxy(28,20);
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
						flag3 = 3;
						break;
					}

					
				}

				if(flag3 == 3)//按空格刷新界面
				{
					continue;
				}
				strcpy(data->sPwd,sPwd2);

				list_to_file(staff_fp ,staff_head,sizeof(STAFF));

				Gotoxy(26,20);
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

 
			}// 查询到用户的 
	

	}
	
	return 1;

}

//#endif
