#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//动态版本
void txl(struct txl2 * ps)//初始化通讯录
{
	ps->mon = (struct txl1 *) malloc(sz1*sizeof(struct txl1));
	/*memset(ps->mon,' 0', sizeof(ps->mon));*/
	/*ps->size = 0;*/
	if (ps->mon == NULL){
		perror("错误");
		return;
	}
	ps->size = 0;
	ps->jl = sz1;
}
void xhtxl(struct txl2*  ps)//回收内存
{
	pree(ps->mon);
	ps->mon = NULL;
	ps->size = 0;
	ps->jl = 0;
}
//动态版本的添加联系人
void tjhs(struct txl2* ps)//添加联系人
{
	if (ps->size == ps->jl)
	{
		struct txl1 * num = (struct txl1 *)realloc(ps->mon, (ps->jl + sz2)*sizeof(struct txl1));
		if (num != NULL){
			ps->mon = num;
			ps->jl += sz2;
			printf("增容成功\n");
		}
		else
		{
			perror("添加失败");
			return;
		}
	}
	else
	{
		printf("请输入名字");
		scanf("%s" ,ps->mon[ps->size].mz );
		printf("请输入年龄");
		scanf("%d", &(ps->mon[ps->size].nl));
		printf("请输入性别");
		scanf("%s", ps->mon[ps->size].xb);
		printf("请输入电话");
		scanf("%s", ps->mon[ps->size].zz);
		printf("请输入住址");
		scanf("%s", ps->mon[ps->size].dh);
		
		ps->size++;
		printf("添加成功\n");

	}

}
void xs(const struct txl2* ps)//显示函数
{
	if (ps->size == 0)
	{
		printf("通讯录为空：>\n");
	}
	else
	{
		int i = 0;
		printf("%-s\t%-s\t%-s\t%-s\t%-s\n","姓名","年龄","性别","电话","住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-s\t%-d\t%-s\t%-s\t%-s\n",
				ps->mon[i].mz,
				ps->mon[i].nl,
				ps->mon[i].xb,
				ps->mon[i].zz,
				ps->mon[i].dh);
				
		}
	}
}
 int  chazhaohanshu(struct txl2* ps, char mz[MAX_mz])//查找函数
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->mon[ps->size].mz, mz));
		{
			return i;
		}	
	
	}	return -1;
}


void schs(struct txl2 * ps)//删除联系人
{
	char mz[MAX_mz];
	printf("请输入下姓名：>");
	scanf("%s", mz);
		int arr = chazhaohanshu(ps, mz);//查找函数
		if (arr == -1)
		{
			printf("查找失败，没有当前联系人：>");
		}
		else
		{
			int j = 0;
			for (j = arr; j < ps->size-1; j++)
			{
				ps->mon[arr] = ps->mon[arr + 1];

			}
			ps->size--;
			printf("删除成功");
		}
	}

void xghanshu(struct txl2*  ps)//修改函数
{

	char mz[MAX_mz];
	printf("请输入修改人名字");
	scanf("%s", mz);
	int arr = chazhaohanshu(ps, mz);
	if (arr == -1)
	{
		printf("要修改的人不存在：>\n");
	}
	else
	{
		printf("请输入名字");
		scanf("%s", ps->mon[arr].mz);
		printf("请输入年龄");
		scanf("%d", &(ps->mon[arr].nl));
		printf("请输入性别");
		scanf("%s", ps->mon[arr].xb);
		printf("请输入电话");
		scanf("%s", ps->mon[arr].zz);
		printf("请输入住址");
		scanf("%s", ps->mon[arr].dh);

		printf("修改成功：>\n");

	}


}

void jshs(struct txl2* ps)//检索联系人
{ 
	
	char mz[MAX_mz];
	printf("请输入下姓名：>");
	scanf("%s",mz);
	int arr = chazhaohanshu(ps, mz);
	if (arr == -1)
	{
		printf("查找失败，没有当前联系人：>");
	}
	else
	{
		printf("%-s\t%-s\t%-s\t%-s\t%-s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-s\t%-d\t%-s\t%-s\t%-s\n",
			ps->mon[arr].mz,
			ps->mon[arr].nl,
			ps->mon[arr].xb,
			ps->mon[arr].zz,
			ps->mon[arr].dh);

	}
}




static int cmp(const void *a, const void *b)//排序函数的参数

{

	return strcmp((*(struct txl1*)a).mz, (*(struct txl1*)b).mz);

}
void px(struct txl2*  ps) //排序函数
{
	int sz = sizeof(ps->mon) / sizeof(ps->mon[0]);
	qsort(ps->mon, ps->size, sizeof(ps->mon[0]), &cmp);//ps->mon：需要排序的数主，ps->size：数组的元素个数， sizeof(ps->mon[0])：数组中每个元素的大小， &cmp：指向比较函数的函数指针，决定了排序顺序。

	
	int i = 0; 
	for (i = 0; i < ps->size; i++)
	{
		printf("%-s\t%-d\t%-s\t%-s\t%-s\n",
			ps->mon[i].mz,
			ps->mon[i].nl,
			ps->mon[i].xb,
			ps->mon[i].zz,
			ps->mon[i].dh);

			
			

		
	}
}