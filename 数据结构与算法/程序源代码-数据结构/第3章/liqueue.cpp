//���������㷨
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct DataNode
{	
	ElemType data;
	struct DataNode *next;
} DataNode;				//�������ݽ������
typedef struct
{	
	DataNode *front;
	DataNode *rear;
} LinkQuNode;			//��������
void InitQueue(LinkQuNode *&q)
{	
	q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front=q->rear=NULL;
}
void DestroyQueue(LinkQuNode *&q)
{
	DataNode *p=q->front,*r;//pָ���ͷ���ݽ��
	if (p!=NULL)			//�ͷ����ݽ��ռ�ÿռ�
	{	r=p->next;
		while (r!=NULL)
		{	free(p);
			p=r;r=p->next;
		}
	}
	free(p);
	free(q);				//�ͷ����ӽ��ռ�ÿռ�
}
bool QueueEmpty(LinkQuNode *q)
{
	return(q->rear==NULL);
}
void enQueue(LinkQuNode *&q,ElemType e)
{	DataNode *p;
	p=(DataNode *)malloc(sizeof(DataNode));
	p->data=e;
	p->next=NULL;
	if (q->rear==NULL)		//������Ϊ��,���½���Ƕ��׽�����Ƕ�β���
		q->front=q->rear=p;
	else
	{	q->rear->next=p;	//��p���������β,����rearָ����
		q->rear=p;
	}
}
bool deQueue(LinkQuNode *&q,ElemType &e)
{	DataNode *t;
	if (q->rear==NULL)		//����Ϊ��
		return false;
	t=q->front;				//tָ���һ�����ݽ��
	if (q->front==q->rear)  //������ֻ��һ�����ʱ
		q->front=q->rear=NULL;
	else					//�������ж�����ʱ
		q->front=q->front->next;
	e=t->data;
	free(t);
	return true;
}
