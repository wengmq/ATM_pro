#include"public.h"


int main()
{
    //system("color 06");

	


	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
   
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);// 设置为字体颜色为黄色
	
	ATM_pro();

	return 0;
}