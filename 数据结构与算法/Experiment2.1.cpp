/**
 * @file Experiment2.1 .cpp
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

#define MaxSize 5
#define ElemType char

//Defines the structure of a stack structure
typedef struct linknode                                   
{
    ElemType data;   
    struct linknode *next;                                
    //���� LinkStNode *next;
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
        p->data = e;		//�½�Ԫ��e��Ӧ�Ľ��*p        
        p->next=s->next;	//����*p�����Ϊ��ʼ���       
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
