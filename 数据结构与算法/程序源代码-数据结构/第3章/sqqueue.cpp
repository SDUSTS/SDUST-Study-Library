#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define MaxSize 100
using namespace std;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;		//队首和队尾指针
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
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)		//队空下溢出
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
    cout<<"请输入排队病人的病历号："<<endl;
    cin>>n;
    cout<<"把排队病人的病历号n加入到队列q中："<<endl;
    enQueue(q,n);
    cout<<"病历号最前的排队病人现在就诊："<<endl;
    cout<<"病历号最前的排队病人就诊完毕，把病历号删除："<<endl;
    deQueue(q,a);
    cout<<a<<endl;
    cout<<"从队首到队尾列出所有的排队病人病历号："<<endl;
    deQueue(q,b);
    cout<<b<<endl;
    deQueue(q,c);
    cout<<c<<endl;
    deQueue(q,d);
    cout<<d<<endl;
    deQueue(q,n);
    cout<<n<<endl;
    cout<<"不在排队，余下依次就诊："<<endl;
    DestroyQueue(q);
}
