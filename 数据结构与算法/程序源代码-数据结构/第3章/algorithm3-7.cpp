//����3.7�����㷨���ö���Ԫ�ظ��������βָ��Ļ��ζ���
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front;			//��ͷָ��
	int count;			//������Ԫ�ظ���
} QuType;
void InitQueue(QuType *&qu)						//��ʼ���������㷨
{	qu=(QuType *)malloc(sizeof(QuType));
	qu->front=0;
	qu->count=0;
}
void DestroyQueue(QuType *&qu)
{
	free(qu);
}
bool EnQueue(QuType *&qu,ElemType x)			//���������㷨
{	int rear;									//��ʱ��βָ��
	if (qu->count==MaxSize)						//���������
		return false;
	else
	{	rear=(qu->front+qu->count)%MaxSize;		//���βλ��
		rear=(rear+1)%MaxSize;					//��βѭ����1
		qu->data[rear]=x;
		qu->count++;							//Ԫ�ظ�����1
		return true;
	}
}
bool DeQueue(QuType *&qu,ElemType &x)			//���������㷨
{	if (qu->count==0)							//�ӿ������
		return false;
	else
	{	qu->front=(qu->front+1)%MaxSize;		//��ͷѭ����1
		x=qu->data[qu->front];
		qu->count--;							//Ԫ�ظ�����1
		return true;
	}
}
bool QueueEmpty(QuType *qu)						//�жӿ������㷨
{
	return(qu->count==0);
}
int main()
{
	QuType *q;
	ElemType e;
	InitQueue(q);
	EnQueue(q,1);
	EnQueue(q,2);
	EnQueue(q,3);
	EnQueue(q,4);
	printf("����˳��:");
	while (!QueueEmpty(q))
	{
		DeQueue(q,e);
		printf("%d ",e);
	}
	printf("\n");
	DestroyQueue(q);
	return 1;
}







