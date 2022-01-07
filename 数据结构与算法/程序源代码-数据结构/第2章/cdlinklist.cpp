//ѭ��˫������������㷨
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
//ͷ�巨����ѭ��˫����
{
	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
	s=L->next;	
	while (s->next!=NULL)			//����β���,��sָ����
		s=s->next;
	s->next=L;						//β���next��ָ��ͷ���
	L->prior=s;						//ͷ����prior��ָ��β���

}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//β�巨����ѭ��˫����
{
	DLinkNode *s,*r;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  //����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		r->next=s;s->prior=r;	//�����s������r֮��
		r=s;
	}
	r->next=L;				//β���next��ָ��ͷ���
	L->prior=r;				//ͷ����prior��ָ��β���
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=L;
}
void DestroyList(DLinkNode *&L)
{
	DLinkNode *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(DLinkNode *L)
{
	return(L->next==L);
}
int ListLength(DLinkNode *L)
{
	DLinkNode *p=L;
	int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkNode *L)
{
	DLinkNode *p=L->next;
	while (p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(DLinkNode *L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p;
	if (L->next!=L)		//˫����Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return true;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return false;
			else
			{
				e=p->data;
				return true;
			}
		}
	}
	else				//˫����Ϊ�ձ�ʱ
		return 0;
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
	if (p->next==L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
		s->data=e;
		p->next=s;s->next=p;
		p->prior=s;s->prior=p;
		return true;
	}
	else if (i==1)					//ԭ˫����Ϊ�ձ�i=1ʱ
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
		s->data=e;
		s->next=p->next;p->next=s;	//�����s���뵽���p֮��
		s->next->prior=s;s->prior=p;
		return true;
	}
	else
	{	
		p=L->next;
		while (j<i-2 && p!=L)
		{	j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return false;
		else					//�ҵ���i-1�����*p
		{
			s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
			s->data=e;	
			s->next=p->next;	//�����s���뵽���p֮��
			if (p->next!=NULL) p->next->prior=s;
			s->prior=p;
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L,*q;
	if (p->next!=L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		if (i==1)					//i==1ʱ
		{	
			q=L->next;				//ɾ����1�����
			e=q->data;
			L->next=q->next;
			q->next->prior=L;
			free(q);
			return true;
		}
		else						//i��Ϊ1ʱ
		{	
			p=L->next;
			while (j<i-2 && p!=NULL)		
			{
				j++;
				p=p->next;
			}
			if (p==NULL)				//δ�ҵ���i-1�����
				return false;
			else						//�ҵ���i-1�����p
			{
				q=p->next;				//qָ��Ҫɾ���Ľ��
				if (q==NULL) return 0;	//�����ڵ�i�����
				e=q->data;
				p->next=q->next;		//�ӵ�������ɾ��q���
				if (p->next!=NULL) p->next->prior=p;
				free(q);				//�ͷ�q���
				return true;
			}
		}
	}
	else return false;					//ԭ˫����Ϊ�ձ�ʱ
}
