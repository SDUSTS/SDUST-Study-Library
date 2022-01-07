//˫������������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//����˫����������
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n)
//ͷ�巨��˫����
{
	DLinkNode *s;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//β�巨��˫����
{
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		r->next=s;s->prior=r;	//�����s������r֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)
{
	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}
bool ListEmpty(DLinkNode *L)
{
	return(L->next==NULL);
}
int ListLength(DLinkNode *L)
{
	DLinkNode *p=L;
	int i=0;
	while (p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkNode *L)
{
	DLinkNode *p=L->next;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(DLinkNode *L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L;
	if (i<=0) return false;		//i���󷵻ؼ�
	while (j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}
int LocateElem(DLinkNode *L,ElemType e)
{
	int n=1;
	DLinkNode *p=L->next;
	while (p!=NULL && p->data!=e)
	{
		n++;
		p=p->next;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(DLinkNode *&L,int i,ElemType e)
{
	int j=0;
	DLinkNode *p=L,*s;
	if (i<=0) return false;		//i���󷵻ؼ�
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����
		return false;
	else						//�ҵ���i-1�����p
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
		s->data=e;	
		s->next=p->next;		//�����s���뵽���p֮��
		if (p->next!=NULL) 
			p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L,*q;
	if (i<=0) return false;		//i���󷵻ؼ�
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����
		return false;
	else						//�ҵ���i-1�����p
	{
		q=p->next;				//qָ��Ҫɾ���Ľ��
		if (q==NULL) 
			return false;		//�����ڵ�i�����
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��*q���
		if (p->next!=NULL) p->next->prior=p;
		free(q);				//�ͷ�q���
		return true;
	}
}
