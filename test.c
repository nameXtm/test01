#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void menu()
{
	printf("*****************************************\n");
	printf("******1.add 添加       2.del 删除 *******\n");
	printf("******3.search 检索     4.modify 修改****\n");
	printf("******5.show  显示     6.sort 排序 ******\n");
	printf("******0.exit 退出 ***********************\n");
	printf("*****************************************\n");
}




int main()
{
	
	int init = 0;
	struct txl2 num; //创建通讯录
	txl(&num); //初始化通讯录
	do
	{	
		menu();
			printf("请选择:>");
			scanf("%d" , &init);
			switch (init)
			{
			
			case tianjia:
				tjhs(&num);//添加函数
				break;
			case shanchu:
				schs(&num);//删除函数
				break;
			case jianshuo://检索
				jshs(&num);
				break;
			case 4://修改函数 
				xghanshu(&num);
				break;
			case xianshi:
				xs(&num);//显示函数
				break;
			case paixv:
				px(&num);
				break;
			case tuichu:
				printf("退出通讯录:>");
				xhtxl(&num);//回收内存函数
				break;
			default:
				printf("选择错误:>");
				break;
			}
	} while (init );
	return 0;
}