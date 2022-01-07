#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define MaxSize 100
using namespace std;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)		//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
int main()
{
    SqQueue *q;
    InitQueue(q);
    ElemType n,a=1,b=2,c=3,d=4;
    enQueue(q,a);
     enQueue(q,b);
      enQueue(q,c);
       enQueue(q,d);
    cout<<"�������ŶӲ��˵Ĳ����ţ�"<<endl;
    cin>>n;
    cout<<"���ŶӲ��˵Ĳ�����n���뵽����q�У�"<<endl;
    enQueue(q,n);
    cout<<"��������ǰ���ŶӲ������ھ��"<<endl;
    cout<<"��������ǰ���ŶӲ��˾�����ϣ��Ѳ�����ɾ����"<<endl;
    deQueue(q,a);
    cout<<a<<endl;
    cout<<"�Ӷ��׵���β�г����е��ŶӲ��˲����ţ�"<<endl;
    deQueue(q,b);
    cout<<b<<endl;
    deQueue(q,c);
    cout<<c<<endl;
    deQueue(q,d);
    cout<<d<<endl;
    deQueue(q,n);
    cout<<n<<endl;
    cout<<"�����Ŷӣ��������ξ��"<<endl;
    DestroyQueue(q);
}
