#define MAX 1000
#define sz1 3
#define sz2 2
#define MAX_mz 20
#define MAX_dh 13
#define MAX_xb 5
#define MAX_zz 20
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct txl1
{
	char  mz[MAX_mz];//名字
	int nl; //年龄
	char xb[MAX_xb];//性别
	char zz[MAX_zz];//住址
	char dh[MAX_dh];//电话

};
struct txl2
{
	struct txl1 *mon;
	int size;
	int jl;

};
enum xuanxiang 
{ 
	tuichu,
	tianjia,
	shanchu,
	jianshuo,
	xuigai,
	xianshi,
	paixv,
};

void txl(struct txl2* ps);//初始化函数
void tjhs(struct txl2* ps);//添加函数
void schs(struct txl2* ps); ///删除联系人
void xs(const struct txl2* ps);//显示联系人
void jshs(struct txl2* ps);//检索联系人
void xghanshu(struct txl2*  ps);//修改联系人
void px(struct txl2*  ps);//排序联系人 
void xhtxl(struct txl2*  ps);//回收内存函数