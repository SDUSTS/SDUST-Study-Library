/**
 * @file Experiment2.2 .cpp
 * @author Ma Qingchao (mqc.study@outlook.com)
 * @brief 
 * 
 * ʵ�����ƣ�ջ����е�ʵ����Ӧ��
 * 
 * 1����ջ��ʵ����Ӧ��
 * 2�����ζ��е�ʵ����Ӧ��
 * 3�����ö������ջ �� ���ζ��У� ʵ�ֶ�һ�����ζ��е����ݽ�������
 * 
 * @Tips ��Talk is cheap. Show me the code. 
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include<stdlib.h>

// 1.���� ����� Homework4.2 ��ʽ��.cpp

// 2.���ζ��еĶ���


#define MaxSize 5
#define ElemType char


typedef struct                                               
{    
    ElemType data[MaxSize];
    int front,rear;     //���׺Ͷ�βָ��
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

bool deQueue(SqQueue *&q,ElemType &e)                           //������
{      if (q->front==q->rear)   //�ӿ������
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

