#include"public.h"


int main()
{
    //system("color 06");

	


	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
   
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);// ����Ϊ������ɫΪ��ɫ
	
	ATM_pro();

	return 0;
}