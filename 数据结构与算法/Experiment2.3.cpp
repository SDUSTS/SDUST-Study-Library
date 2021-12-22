/**
 * @file Experiment2.3 .cpp
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

#define MaxSize 6
#define ElemType char

//Defines the structure of a stack structure
typedef struct linknode                                   
{
    ElemType data;   
    struct linknode *next;                               
    //或者 LinkStNode *next;
}LinkStNode;  

//   Initialize the stack
void InitStack(LinkStNode *&s)
{      
    s=(LinkStNode *)malloc(sizeof(LinkStNode));
    s->next= NULL;                                       
} 

//  Destruction of the stack  
void  DestroyStack(LinkStNode *&s)                        
{
    LinkStNode *p=s,*q=s->next;                           
      while (q!=NULL)                                   
      {	
        free(p);                                         
        p=q;                                          
        q=p->next;                                 
      }
    free(s);
}
//  Check whether the stack is empty
bool StackEmpty(LinkStNode *s)
{
       return(s->next==NULL);                            
}

//push on
void Push(LinkStNode *&s,ElemType e)
{     
        LinkStNode *p;                                    
        p=(LinkStNode *)malloc(sizeof(LinkStNode));      
        p->data = e;		//新建元素e对应的结点*p          
        p->next=s->next;	//插入*p结点作为开始结点       
        s->next=p;                                       
}

// pop off
bool Pop(LinkStNode *&s,ElemType &e)                      
{     
    LinkStNode *p;
    if (s->next==NULL)	                                
	  return false;
    p=s->next;			                                   
    e = p-> data;                                        
    s->next=p->next;                                      	
    free(p);			                                        
    return true;
}




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

bool deQueue(SqQueue *&q,ElemType &e)                        
{      if (q->front==q->rear)   
	return false;
       q->front = (q->front+1)%MaxSize;
       e=q->data[q->front]; 
	   return true;
}



int main(){
	SqQueue *q;
	InitQueue(q);								//A
	
	int k[6]= {'a','b','c','d','e','f'};
	for(int i=0;i<6;i++)
	{
		enQueue(q,k[i]);
	}											//B
	
	LinkStNode *s;  
	InitStack(s);								//C
	
	char e ;
	for(int i=0;i<6;i++)
	{
		deQueue(q,e);
		printf("%c",e);
		Push(s,e);
	}											//D
	
	printf("\n");
	for(int i=0;i<6;i++)
	{
		Pop(s,e);
		printf("%c",e);
		enQueue(q,e);					
	}											//E
	printf("\n");
	
	for(int i=0;i<6;i++)
	{
		deQueue(q,e);
		printf("%c",e);
	}											//F
	
	DestroyStack(s);
	DestroyQueue(q);							//G
	return 0;
} 
