//���Ա��Ӧ��:������ļ���Ȼ���ӵ��㷨
#include <stdio.h>
#include <malloc.h>
#define MaxCol  10			//�������
typedef int ElemType;
typedef struct Node1		//���ݽ������
{	
	ElemType data[MaxCol];
	struct Node1 *next;		//ָ�������ݽ��
} DList;
typedef struct Node2		//ͷ�������
{	
	int Row,Col;			//����������
	DList *next;			//ָ���һ�����ݽ��
} HList;
void CreateTable(HList *&h)
{
	int i,j;
	DList *r,*s;
	h=(HList *)malloc(sizeof(HList));		//����ͷ���
	h->next=NULL;
	printf("�������,����:");
	scanf("%d%d",&h->Row,&h->Col);
	for (i=0;i<h->Row;i++)
	{	printf("  ��%d��:",i+1);
		s=(DList *)malloc(sizeof(DList));	//�������ݽ��
		for (j=0;j<h->Col;j++)				//����һ�е����ݳ���ͳ��
			scanf("%d",&s->data[j]);
		if (h->next==NULL)					//�����һ�����ݽ��
			h->next=s;
		else								//�����������ݽ��
			r->next=s;						//�����s���뵽���r���֮��
		r=s;								//rʼ��ָ�����һ�����ݽ��
	}
	r->next=NULL;							//��β���next���ÿ�
}
void DispTable(HList *h)
{
	int j;
	DList *p=h->next;
	while (p!=NULL)
	{	for (j=0;j<h->Col;j++)
			printf("%4d",p->data[j]);
		printf("\n");
		p=p->next;
	}
}
void LinkTable(HList *h1,HList *h2,HList *&h)
{
	int f1,f2,i;
	DList *p=h1->next,*q,*s,*r;
	printf("�����ֶ���:��1����λ��,��2����λ��:");
	scanf("%d%d",&f1,&f2);
	h=(HList *)malloc(sizeof(HList));
	h->Row=0;
	h->Col=h1->Col+h2->Col;
	h->next=NULL;
	while (p!=NULL)
	{	q=h2->next;
		while (q!=NULL)
		{	if (p->data[f1-1]==q->data[f2-1])		//��Ӧ�ֶ�ֵ���
			{	s=(DList *)malloc(sizeof(DList));	//����һ�����ݽ��
				for (i=0;i<h1->Col;i++)				//���Ʊ�1�ĵ�ǰ��
					s->data[i]=p->data[i];
				for (i=0;i<h2->Col;i++)
					s->data[h1->Col+i]=q->data[i];	//���Ʊ�2�ĵ�ǰ��
				if (h->next==NULL)				//�����һ�����ݽ��
					h->next=s;
				else							//�����������ݽ��
					r->next=s;
				r=s;							//rʼ��ָ��������ݽ��
				h->Row++;						//��������1
			}
			q=q->next;							//��2����һ����¼
		}
		p=p->next;								//��1����һ����¼
	}
	r->next=NULL;								//��β���next���ÿ�
}
int main()
{
	HList *h1,*h2,*h;
	printf("��1:\n");	
	CreateTable(h1);			//������1
	printf("��2:\n");  
	CreateTable(h2);			//������2
	LinkTable(h1,h2,h);			//����������
	printf("���ӽ����:\n");	
	DispTable(h);				//������ӽ��
	return 1;
}
