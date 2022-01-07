//˳����У��ǻ��ζ��У����������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;						//��ͷ�Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=-1;
}
void DestroyQueue(SqQueue *&q)			//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)	//����
{	if (q->rear==MaxSize-1)				//���������
		return false;					//���ؼ�
	q->rear++;							//��β��1
	q->data[q->rear]=e;					//rearλ�ò���Ԫ��e
	return true;						//������
}
bool deQueue(SqQueue *&q,ElemType &e)	//����
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front++;
	e=q->data[q->front];
	return true;
}
