#ifndef _STRUCT_H_
#define _STRUCT_H_



typedef struct STAFF_t
{
	char sName[9]; //用户名
	char sPwd[7];  //密码
	char sAccount[9]; //账号
	int iRole;  //用户身份
    int  iEixt;  //标识符用来删除
	double Dmoney; //余额
}STAFF;


typedef struct BILL_t
{
	char sAccount[9];//账号
	char sTime[11];//交易时间2018-09-27
	double dDealMoney;//交易金额
	double dLeftMoney;//余额
	char sMessage[11];//交易信息
	char sDealTarget[9];//交易源


}BILL;

#endif

