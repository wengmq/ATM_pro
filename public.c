#include "public.h"



int Gotoxy(int x,int y)
{
	HANDLE handle;
	COORD coord;
	coord.X=x;
	coord.Y=y;
	handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
	return 0;
}





void ATM_pro()

{

     FILE *staff_fp = file_openinit("staff.txt",staff_data_init);
	 LIST *staff_head = file_to_list(staff_fp,sizeof(STAFF));
	 STAFF *staff_node = NULL;


	 
	 FILE *bill_fp = file_openinit("bill.txt",bill_data_init);
	 LIST *bill_head = file_to_list(bill_fp,sizeof(BILL));
	
    //	Staff_Printf(staff_head);
    // getch();

	 login(staff_head,bill_head,staff_fp,bill_fp);
	 
	 

	 fclose(staff_fp);
}




void staff_data_init()
{
	FILE *staff_fp = NULL;

    LIST *staff_head = NULL;//定义成员的链表

          /*初始化数据*/
    STAFF staff1 = {"admin1","123456","10000001",1,1,1000};
	STAFF staff2 = {"admin2","123456","10000002",3,1,2000};
	STAFF staff3 = {"admin3","123456","10000003",3,1,3000};
	STAFF staff4 = {"admin4","123456","10000004",3,1,4000};
	STAFF staff5 = {"admin5","123456","10000005",3,1,0};
	STAFF staff6 = {"user1","123456","10000006",2,1,1000}; 
	STAFF staff7 = {"user2","123456","10000007",2,1,2000};
	STAFF staff8 = {"user3","123456","10000008",2,1,3000};
	STAFF staff9 = {"user4","123456","10000009",2,1,4000}; 
	STAFF staff10 = {"user5","123456","10000010",2,1,0};
	STAFF staff11 = {"user6","123456","10000011",2,1,0};
	STAFF staff12 = {"user7","123456","10000012",2,1,0};
	STAFF staff13 = {"user8","123456","10000013",2,1,0};
	STAFF staff14 = {"user9","123456","10000014",2,1,0};
	STAFF staff15 = {"user10","123456","10000015",2,1,0};
	STAFF *pstaff1 = &staff1; 
    STAFF *pstaff2 = &staff2; 
	STAFF *pstaff3 = &staff3; 
	STAFF *pstaff4 = &staff4; 
	STAFF *pstaff5 = &staff5;
	STAFF *pstaff6 = &staff6; 
    STAFF *pstaff7 = &staff7; 
	STAFF *pstaff8 = &staff8; 
	STAFF *pstaff9 = &staff9; 
	STAFF *pstaff10 = &staff10;
	STAFF *pstaff11 = &staff11; 
    STAFF *pstaff12 = &staff12; 
	STAFF *pstaff13 = &staff13; 
	STAFF *pstaff14 = &staff14; 
	STAFF *pstaff15 = &staff15;
	 
	 
	staff_head= List_Init(pstaff1);//初始化头结点
	List_Add(staff_head,pstaff2);//添加节点
	List_Add(staff_head,pstaff3);
	List_Add(staff_head,pstaff4);
	List_Add(staff_head,pstaff5);
	List_Add(staff_head,pstaff6);
	List_Add(staff_head,pstaff7);
	List_Add(staff_head,pstaff8);
	List_Add(staff_head,pstaff9);
	List_Add(staff_head,pstaff10);
	List_Add(staff_head,pstaff11);
	List_Add(staff_head,pstaff12);
	List_Add(staff_head,pstaff13);
	List_Add(staff_head,pstaff14);
	List_Add(staff_head,pstaff15);


//	printf("-----------init----------------\n");

//	Staff_Printf(staff_head);//打印链表
	/*打开文件*/
	staff_fp = file_open("staff.txt");
	
	/*从链表中读取数据到文件*/
	list_to_file(staff_fp,staff_head,sizeof(STAFF));

  //  printf("-----------read from file----------------\n");
	//stulist2 = List_Init(pstu1);
	staff_head = file_to_list(staff_fp,sizeof(STAFF));
//	Staff_Printf(staff_head);

//	 printf("-----------read end----------------\n");
	 fclose(staff_fp);

}

void bill_data_init()
{
	
	FILE *bill_fp = NULL;
    
	LIST *bill_head = NULL;
              /*初始化数据*/
    BILL bill1 = {"10000006","2018-09-23",500,1500,"存款","ATM机"};
	BILL bill2 = {"10000006","2018-09-23",500,2000,"存款","ATM机"};
	BILL bill3 = {"10000006","2018-09-24",500,1500,"取款","ATM机"};
	BILL bill4 = {"10000006","2018-09-24",500,1000,"取款","ATM机"};
	BILL bill5 = {"10000006","2018-09-26",500,1500,"存款","ATM机"};
	BILL bill6 = {"10000006","2018-09-29",500,2000,"存款","ATM机"};
	BILL bill7 = {"10000006","2018-09-29",500,1500,"取款","ATM机"};
	BILL bill8 = {"10000006","2018-10-01",500,1000,"取款","ATM机"};
	BILL bill9 = {"10000006","2018-10-02",500,1500,"存款","ATM机"};
	BILL bill10 = {"10000006","2018-10-03",500,2000,"存款","ATM机"};
	BILL bill11 = {"10000006","2018-10-04",500,1500,"取款","ATM机"};
	BILL bill12 = {"10000006","2018-10-05",500,1000,"取款","ATM机"};








	BILL bill13 = {"10000007","2018-09-23",500,2500,"存款","ATM机"};
	BILL bill14 = {"10000007","2018-09-23",500,3000,"存款","ATM机"};
	BILL bill15 = {"10000007","2018-09-24",500,2500,"取款","ATM机"};
	BILL bill16 = {"10000007","2018-09-24",500,2000,"取款","ATM机"};
    BILL bill17 = {"10000007","2018-09-26",500,2500,"存款","ATM机"};
	BILL bill18 = {"10000007","2018-09-27",500,3000,"存款","ATM机"};
	BILL bill19 = {"10000007","2018-09-28",500,2500,"取款","ATM机"};
	BILL bill20 = {"10000007","2018-09-29",500,2000,"取款","ATM机"};
    BILL bill21 = {"10000007","2018-09-30",500,2500,"存款","ATM机"};
	BILL bill22 = {"10000007","2018-10-01",500,3000,"存款","ATM机"};
	BILL bill23 = {"10000007","2018-10-02",500,2500,"取款","ATM机"};
	BILL bill24 = {"10000007","2018-10-03",500,2000,"取款","ATM机"};

	BILL bill25= {"10000007","2018-10-04",1000,1000,"转出","10000006"};
	BILL bill26 = {"10000006","2018-10-04",1000,2000,"转入","10000007"};
	BILL bill27= {"10000006","2018-10-06",1000,1000,"转出","10000007"};
	BILL bill28 = {"10000007","2018-10-06",1000,2000,"转入","10000006"};
	BILL *pbill1 = &bill1; 
    BILL *pbill2 = &bill2; 
	BILL *pbill3 = &bill3; 
	BILL *pbill4 = &bill4; 
	BILL *pbill5 = &bill5;
	BILL *pbill6 = &bill6; 
    BILL *pbill7 = &bill7; 
	BILL *pbill8 = &bill8; 
	BILL *pbill9 = &bill9; 
	BILL *pbill10 = &bill10;
	BILL *pbill11 = &bill11; 
	BILL *pbill12 = &bill12;
	BILL *pbill13 = &bill13; 
	BILL *pbill14 = &bill14; 
	BILL *pbill15 = &bill15;
	BILL *pbill16 = &bill16; 
    BILL *pbill17 = &bill17; 
	BILL *pbill18 = &bill18; 
	BILL *pbill19 = &bill19; 
	BILL *pbill20 = &bill20;
	BILL *pbill21 = &bill21; 
    BILL *pbill22 = &bill22; 
	BILL *pbill23 = &bill23; 
	BILL *pbill24 = &bill24; 
	BILL *pbill25 = &bill25;
	BILL *pbill26 = &bill26; 
    BILL *pbill27 = &bill27; 
	BILL *pbill28 = &bill28; 
	 
	bill_head= List_Init(pbill1);//初始化头结点
	List_Add(bill_head,pbill2);//添加节点
	List_Add(bill_head,pbill3);
	List_Add(bill_head,pbill4);
	List_Add(bill_head,pbill5);
	List_Add(bill_head,pbill6);
	List_Add(bill_head,pbill7);
	List_Add(bill_head,pbill8);
	List_Add(bill_head,pbill9);
	List_Add(bill_head,pbill10);
	List_Add(bill_head,pbill11);
	List_Add(bill_head,pbill12);
	List_Add(bill_head,pbill13);
	List_Add(bill_head,pbill14);
	List_Add(bill_head,pbill15);
	List_Add(bill_head,pbill16);
	List_Add(bill_head,pbill17);
	List_Add(bill_head,pbill18);
	List_Add(bill_head,pbill19);
	List_Add(bill_head,pbill20);
	List_Add(bill_head,pbill21);
	List_Add(bill_head,pbill22);
	List_Add(bill_head,pbill23);
	List_Add(bill_head,pbill24);
	List_Add(bill_head,pbill25);
	List_Add(bill_head,pbill26);
	List_Add(bill_head,pbill27);
	List_Add(bill_head,pbill28);
	
//	printf("-----------init----------------\n");

	/*打开文件*/
//	Bill_Printf(bill_head);
	bill_fp = file_open("bill.txt");
	/*从链表中读取数据到文件*/
	list_to_file(bill_fp,bill_head,sizeof(BILL));

  //  printf("-----------read from file----------------\n");
	//stulist2 = List_Init(pstu1);
     bill_head = file_to_list(bill_fp,sizeof(BILL));
//	Staff_Printf(staff_head);
//	Bill_Printf(bill_head);
//	 printf("-----------read end----------------\n");
	 fclose(bill_fp);





}