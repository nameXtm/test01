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
	char  mz[MAX_mz];//����
	int nl; //����
	char xb[MAX_xb];//�Ա�
	char zz[MAX_zz];//סַ
	char dh[MAX_dh];//�绰

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

void txl(struct txl2* ps);//��ʼ������
void tjhs(struct txl2* ps);//��Ӻ���
void schs(struct txl2* ps); ///ɾ����ϵ��
void xs(const struct txl2* ps);//��ʾ��ϵ��
void jshs(struct txl2* ps);//������ϵ��
void xghanshu(struct txl2*  ps);//�޸���ϵ��
void px(struct txl2*  ps);//������ϵ�� 
void xhtxl(struct txl2*  ps);//�����ڴ溯��