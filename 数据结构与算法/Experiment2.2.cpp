/**
 * @file Experiment2.2 .cpp
 * @author Ma Qingchao (mqc.study@outlook.com)
 * @brief 
 * 
 * 实验名称：栈与队列的实现与应用
 * 
 * 1、链栈的实现与应用
 * 2、环形队列的实现与应用
 * 3、利用定义的链栈 和 环形队列， 实现对一个环形队列的内容进行逆置
 * 
 * @Tips ：Talk is cheap. Show me the code. 
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include<stdlib.h>

// 1.链键 详情见 Homework4.2 链式键.cpp

// 2.环形队列的定义


#define MaxSize 5
#define ElemType char


typedef struct                                               
{    
    ElemType data[MaxSize];
    int front,rear;     //队首和队尾指针
}   SqQueue;

void InitQueue(SqQueue *&q)                                  
{  
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=-1;
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
{        
        if ((q->rear+1)%MaxSize==q->front)
	    return false;
        q->rear=(q->rear+1)%MaxSize;
        q->data[q->rear]=e;
		return true;
}

bool deQueue(SqQueue *&q,ElemType &e)                           //出队列
{      if (q->front==q->rear)   //队空下溢出
	return false;
       q->front = (q->front+1)%MaxSize;
       e=q->data[q->front]; 
	   return true;
}


// 3


int main()
{
	SqQueue *q;
	InitQueue(q);
	printf("%d\n",QueueEmpty(q));
	int a[3]= {'a','b','c'};
	for(int i=0;i<3;i++)
	{
		enQueue(q,a[i]);
	}
	printf("%d\n",QueueEmpty(q));
	char e ;
	for(int i=0;i<3;i++)
	{
		deQueue(q,e);
		printf("%c",e);
	}
	printf("\n");
	
	
	int b[3] = {'d','e','f'};
	for(int i=0;i<3;i++)
	{
		enQueue(q,b[i]);
	}
	
		for(int i=0;i<3;i++)
	{
		deQueue(q,e);
		printf("%c",e);
	}
	DestroyQueue(q);
    return 0;
}

