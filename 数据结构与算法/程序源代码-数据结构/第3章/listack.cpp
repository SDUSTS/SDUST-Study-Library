//��ջ���������㷨
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{	
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LinkStNode;					//��ջ����
void InitStack(LinkStNode *&s)
{
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}
void DestroyStack(LinkStNode *&s)
{
	LinkStNode *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//sָ��β���,�ͷ���ռ�
}
bool StackEmpty(LinkStNode *s)
{
	return(s->next==NULL);
}
void Push(LinkStNode *&s,ElemType e)
{	LinkStNode *p;
	p=(LinkStNode *)malloc(sizeof(LinkStNode));
	p->data=e;				//�½�Ԫ��e��Ӧ�Ľ��p
	p->next=s->next;		//����p�����Ϊ��ʼ���
	s->next=p;
}
bool Pop(LinkStNode *&s,ElemType &e)
{	LinkStNode *p;
	if (s->next==NULL)		//ջ�յ����
		return false;
	p=s->next;				//pָ��ʼ���
	e=p->data;
	s->next=p->next;		//ɾ��p���
	free(p);				//�ͷ�p���
	return true;
}
bool GetTop(LinkStNode *s,ElemType &e)
{	if (s->next==NULL)		//ջ�յ����
		return false;
	e=s->next->data;
	return true;
}
