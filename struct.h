#ifndef _STRUCT_H_
#define _STRUCT_H_



typedef struct STAFF_t
{
	char sName[9]; //�û���
	char sPwd[7];  //����
	char sAccount[9]; //�˺�
	int iRole;  //�û����
    int  iEixt;  //��ʶ������ɾ��
	double Dmoney; //���
}STAFF;


typedef struct BILL_t
{
	char sAccount[9];//�˺�
	char sTime[11];//����ʱ��2018-09-27
	double dDealMoney;//���׽��
	double dLeftMoney;//���
	char sMessage[11];//������Ϣ
	char sDealTarget[9];//����Դ


}BILL;

#endif

