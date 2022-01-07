//����3.8�����㷨����ֻ��β���ָ��rear��ѭ����������Ϊ����
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
} LinkNode;
void initQueue(LinkNode *&rear)				//��ʼ���������㷨
{
	rear=NULL;
}
void enQueue(LinkNode *&rear,ElemType e)	//���������㷨
{	
	LinkNode *p;
	p=(LinkNode *)malloc(sizeof(LinkNode));	//�����½��
	p->data=e;
	if (rear==NULL)							//ԭ����Ϊ��
	{
		p->next=p;							//����ѭ������
		rear=p;
	}
	else
	{
		p->next=rear->next;					//��p�����뵽rear���֮��
		rear->next=p;
		rear=p;								//��rearָ������²���Ľ��
	}
}
bool deQueue(LinkNode *&rear,ElemType &e)	//���������㷨
{
	LinkNode *q;
	if (rear==NULL)							//�ӿ�
		return false;
	else if (rear->next==rear)				//ԭ����ֻ��һ�����
	{
		e=rear->data;
		free(rear);
		rear=NULL;
	}
	else									//ԭ���������������ϵĽ��
	{	
		q=rear->next;
		e=q->data;
		rear->next=q->next;
		free(q);
	}
	return true;
}
bool queueEmpty(LinkNode *rear)				//�жӿ������㷨
{
	return(rear==NULL);
}

int main()
{
	LinkNode *q;
	ElemType e;
	initQueue(q);
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4); 
	printf("����˳��:");
	while (!queueEmpty(q))
	{
		deQueue(q,e);
		printf("%d ",e);
	}
	printf("\n"); 
	return 1;
}
