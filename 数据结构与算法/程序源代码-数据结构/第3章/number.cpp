//��ⱨ������
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
//----------------------------------------------------------
//-���ζ��еĻ��������㷨-----------------------------------
//----------------------------------------------------------
typedef struct 
{	ElemType data[MaxSize];				//��Ŷ���Ԫ��
	int front,rear;						//��ͷ�Ͷ�βָ��
} SqQueue;								//˳�������
void InitQueue(SqQueue *&q)				//��ʼ������
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)			//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)	//������
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)	//������
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//----------------------------------------------------------

void number(int n)
{
	int i;  ElemType e;
	SqQueue *q;					//���ζ���ָ��
	InitQueue(q);				//��ʼ������
	for (i=1;i<=n;i++)			//������ʼ����
		enQueue(q,i);
	printf("��������˳��:");
	while (!QueueEmpty(q))		//���в���ѭ��
	{
		deQueue(q,e);			//����һ��Ԫ��e
		printf("%d ",e);		//���Ԫ�ر��
		if (!QueueEmpty(q))		//���в���
		{
			deQueue(q,e);		//����һ��Ԫ��e
			enQueue(q,e);		//���ճ��е�Ԫ�ؽ���
		}
	}
	printf("\n");
	DestroyQueue(q);			//���ٶ���q
}
int main()
{
	int i,n=8;
	printf("��ʼ����:");
	for (i=1;i<=n;i++)
		printf("%d ",i);
	printf("\n");
	number(n);
	return 1;
}
