#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//��̬�汾
void txl(struct txl2 * ps)//��ʼ��ͨѶ¼
{
	ps->mon = (struct txl1 *) malloc(sz1*sizeof(struct txl1));
	/*memset(ps->mon,' 0', sizeof(ps->mon));*/
	/*ps->size = 0;*/
	if (ps->mon == NULL){
		perror("����");
		return;
	}
	ps->size = 0;
	ps->jl = sz1;
}
void xhtxl(struct txl2*  ps)//�����ڴ�
{
	pree(ps->mon);
	ps->mon = NULL;
	ps->size = 0;
	ps->jl = 0;
}
//��̬�汾�������ϵ��
void tjhs(struct txl2* ps)//�����ϵ��
{
	if (ps->size == ps->jl)
	{
		struct txl1 * num = (struct txl1 *)realloc(ps->mon, (ps->jl + sz2)*sizeof(struct txl1));
		if (num != NULL){
			ps->mon = num;
			ps->jl += sz2;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("���ʧ��");
			return;
		}
	}
	else
	{
		printf("����������");
		scanf("%s" ,ps->mon[ps->size].mz );
		printf("����������");
		scanf("%d", &(ps->mon[ps->size].nl));
		printf("�������Ա�");
		scanf("%s", ps->mon[ps->size].xb);
		printf("������绰");
		scanf("%s", ps->mon[ps->size].zz);
		printf("������סַ");
		scanf("%s", ps->mon[ps->size].dh);
		
		ps->size++;
		printf("��ӳɹ�\n");

	}

}
void xs(const struct txl2* ps)//��ʾ����
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�>\n");
	}
	else
	{
		int i = 0;
		printf("%-s\t%-s\t%-s\t%-s\t%-s\n","����","����","�Ա�","�绰","סַ");
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
 int  chazhaohanshu(struct txl2* ps, char mz[MAX_mz])//���Һ���
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


void schs(struct txl2 * ps)//ɾ����ϵ��
{
	char mz[MAX_mz];
	printf("��������������>");
	scanf("%s", mz);
		int arr = chazhaohanshu(ps, mz);//���Һ���
		if (arr == -1)
		{
			printf("����ʧ�ܣ�û�е�ǰ��ϵ�ˣ�>");
		}
		else
		{
			int j = 0;
			for (j = arr; j < ps->size-1; j++)
			{
				ps->mon[arr] = ps->mon[arr + 1];

			}
			ps->size--;
			printf("ɾ���ɹ�");
		}
	}

void xghanshu(struct txl2*  ps)//�޸ĺ���
{

	char mz[MAX_mz];
	printf("�������޸�������");
	scanf("%s", mz);
	int arr = chazhaohanshu(ps, mz);
	if (arr == -1)
	{
		printf("Ҫ�޸ĵ��˲����ڣ�>\n");
	}
	else
	{
		printf("����������");
		scanf("%s", ps->mon[arr].mz);
		printf("����������");
		scanf("%d", &(ps->mon[arr].nl));
		printf("�������Ա�");
		scanf("%s", ps->mon[arr].xb);
		printf("������绰");
		scanf("%s", ps->mon[arr].zz);
		printf("������סַ");
		scanf("%s", ps->mon[arr].dh);

		printf("�޸ĳɹ���>\n");

	}


}

void jshs(struct txl2* ps)//������ϵ��
{ 
	
	char mz[MAX_mz];
	printf("��������������>");
	scanf("%s",mz);
	int arr = chazhaohanshu(ps, mz);
	if (arr == -1)
	{
		printf("����ʧ�ܣ�û�е�ǰ��ϵ�ˣ�>");
	}
	else
	{
		printf("%-s\t%-s\t%-s\t%-s\t%-s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-s\t%-d\t%-s\t%-s\t%-s\n",
			ps->mon[arr].mz,
			ps->mon[arr].nl,
			ps->mon[arr].xb,
			ps->mon[arr].zz,
			ps->mon[arr].dh);

	}
}




static int cmp(const void *a, const void *b)//�������Ĳ���

{

	return strcmp((*(struct txl1*)a).mz, (*(struct txl1*)b).mz);

}
void px(struct txl2*  ps) //������
{
	int sz = sizeof(ps->mon) / sizeof(ps->mon[0]);
	qsort(ps->mon, ps->size, sizeof(ps->mon[0]), &cmp);//ps->mon����Ҫ�����������ps->size�������Ԫ�ظ����� sizeof(ps->mon[0])��������ÿ��Ԫ�صĴ�С�� &cmp��ָ��ȽϺ����ĺ���ָ�룬����������˳��

	
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