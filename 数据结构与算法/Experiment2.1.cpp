/**
 * @file Experiment2.1 .cpp
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

#define MaxSize 5
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
int main(){
	LinkStNode *s;  
	InitStack(s);
	printf("%d\n",StackEmpty(s));
	int a[5]={'a','b','c','d','e'};
	for(int i=0;i<5;i++)
	{
		Push(s,a[i]);
	}
	printf("%d\n",StackEmpty(s));
	
	char e;
	for(int i=0;i<5;i++)
	{
		Pop(s,e);
		printf("%c",e);
	}
	printf("\n%d\n",StackEmpty(s));
	DestroyStack(s);
	return 0;
} 
