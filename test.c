#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void menu()
{
	printf("*****************************************\n");
	printf("******1.add ���       2.del ɾ�� *******\n");
	printf("******3.search ����     4.modify �޸�****\n");
	printf("******5.show  ��ʾ     6.sort ���� ******\n");
	printf("******0.exit �˳� ***********************\n");
	printf("*****************************************\n");
}




int main()
{
	
	int init = 0;
	struct txl2 num; //����ͨѶ¼
	txl(&num); //��ʼ��ͨѶ¼
	do
	{	
		menu();
			printf("��ѡ��:>");
			scanf("%d" , &init);
			switch (init)
			{
			
			case tianjia:
				tjhs(&num);//��Ӻ���
				break;
			case shanchu:
				schs(&num);//ɾ������
				break;
			case jianshuo://����
				jshs(&num);
				break;
			case 4://�޸ĺ��� 
				xghanshu(&num);
				break;
			case xianshi:
				xs(&num);//��ʾ����
				break;
			case paixv:
				px(&num);
				break;
			case tuichu:
				printf("�˳�ͨѶ¼:>");
				xhtxl(&num);//�����ڴ溯��
				break;
			default:
				printf("ѡ�����:>");
				break;
			}
	} while (init );
	return 0;
}