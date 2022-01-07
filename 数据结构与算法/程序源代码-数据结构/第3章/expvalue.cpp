//��򵥱��ʽ��ֵ
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
//---------------------------------------------------------
//--�����ջ��������---------------------------------------
//---------------------------------------------------------
typedef struct 
{	char data[MaxSize];			//��������
	int top;					//ջ��ָ��
} SqStack;
void InitStack(SqStack *&s)		//��ʼ��ջ
{	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(SqStack *&s)	//����ջ
{
	free(s);
}
bool StackEmpty(SqStack *s)		//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push(SqStack *&s,char e)	//��ջԪ��e
{	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(SqStack *&s,char &e)	//��ջԪ��e
{	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack *s,char &e)	//ȡջ��Ԫ��e
{	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	return true;
}
//---------------------------------------------------------

void trans(char *exp,char postexp[])	//���������ʽexpת���ɺ�׺���ʽpostexp
{
	char e;
	SqStack *Optr;						//���������ջ
	InitStack(Optr);					//��ʼ�������ջ
	int i=0;							//i��Ϊpostexp���±�
	while (*exp!='\0')					//exp���ʽδɨ����ʱѭ��
	{	switch(*exp)
		{
		case '(':						//�ж�Ϊ������
			Push(Optr,'(');				//�����Ž�ջ
			exp++;						//����ɨ�������ַ�
			break;
		case ')':						//�ж�Ϊ������
			Pop(Optr,e);				//��ջԪ��e
			while (e!='(')				//��Ϊ'('ʱѭ��
			{
				postexp[i++]=e;			//��e��ŵ�postexp��
				Pop(Optr,e);			//������ջԪ��e
			}
			exp++;						//����ɨ�������ַ�
			break;
		case '+':						//�ж�Ϊ�ӻ����
		case '-':
			while (!StackEmpty(Optr))	//ջ����ѭ��
			{
				GetTop(Optr,e);			//ȡջ��Ԫ��e
				if (e!='(')				//e����'('
				{
					postexp[i++]=e;		//��e��ŵ�postexp��
					Pop(Optr,e);		//��ջԪ��e
				}
				else					//e��'(ʱ�˳�ѭ��
					break;
			}
			Push(Optr,*exp);			//��'+'��'-'��ջ
			exp++;						//����ɨ�������ַ�
			break;
		case '*':						//�ж�Ϊ'*'��'/'��
		case '/':
			while (!StackEmpty(Optr))	//ջ����ѭ��
			{
				GetTop(Optr,e);			//ȡջ��Ԫ��e
				if (e=='*' || e=='/')	//��ջ��'*'��'/'�������ջ����ŵ�postexp��
				{
					postexp[i++]=e;		//��e��ŵ�postexp��
					Pop(Optr,e);		//��ջԪ��e
				}
				else					//eΪ��'*'��'/'�����ʱ�˳�ѭ��
					break;
			}
			Push(Optr,*exp);			//��'*'��'/'��ջ
			exp++;						//����ɨ�������ַ�
			break;
		default:				//���������ַ�
			while (*exp>='0' && *exp<='9') //�ж�Ϊ����
			{	postexp[i++]=*exp;
				exp++;
			}
			postexp[i++]='#';	//��#��ʶһ����ֵ������
		}
	}
	while (!StackEmpty(Optr))	//��ʱexpɨ�����,ջ����ʱѭ��
	{
		Pop(Optr,e);			//��ջԪ��e
		postexp[i++]=e;			//��e��ŵ�postexp��
	}
	postexp[i]='\0';			//��postexp���ʽ��ӽ�����ʶ
	DestroyStack(Optr);			//����ջ		
}
//---------------------------------------------------------
//--������ջ��������---------------------------------------
//---------------------------------------------------------
typedef struct 
{	double data[MaxSize];			//�����ֵ
	int top;						//ջ��ָ��
} SqStack1;
void InitStack1(SqStack1 *&s)		//��ʼ��ջ
{	s=(SqStack1 *)malloc(sizeof(SqStack1));
	s->top=-1;
}
void DestroyStack1(SqStack1 *&s)	//����ջ
{
	free(s);
}
bool StackEmpty1(SqStack1 *s)		//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push1(SqStack1 *&s,double e)	//��ջԪ��e
{	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop1(SqStack1 *&s,double &e)	//��ջԪ��e
{	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop1(SqStack1 *s,double &e)	//ȡջ��Ԫ��e
{	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	return true;
}
//---------------------------------------------------------

double compvalue(char *postexp)	//�����׺���ʽ��ֵ
{
	double d,a,b,c,e;
	SqStack1 *Opnd;				//���������ջ
	InitStack1(Opnd);			//��ʼ��������ջ
	while (*postexp!='\0')		//postexp�ַ���δɨ����ʱѭ��
	{	
		switch (*postexp)
		{
		case '+':				//�ж�Ϊ'+'��
			Pop1(Opnd,a);		//��ջԪ��a
			Pop1(Opnd,b);		//��ջԪ��b
			c=b+a;				//����c
			Push1(Opnd,c);		//��������c��ջ
			break;
		case '-':				//�ж�Ϊ'-'��
			Pop1(Opnd,a);		//��ջԪ��a
			Pop1(Opnd,b);		//��ջԪ��b
			c=b-a;				//����c
			Push1(Opnd,c);		//��������c��ջ
			break;
		case '*':				//�ж�Ϊ'*'��
			Pop1(Opnd,a);		//��ջԪ��a
			Pop1(Opnd,b);		//��ջԪ��b
			c=b*a;				//����c
			Push1(Opnd,c);		//��������c��ջ
			break;
		case '/':				//�ж�Ϊ'/'��
			Pop1(Opnd,a);		//��ջԪ��a
			Pop1(Opnd,b);		//��ջԪ��b
			if (a!=0)
			{
				c=b/a;			//����c
				Push1(Opnd,c);	//��������c��ջ
				break;
			}
			else
		    {	
				printf("\n\t�������!\n");
				exit(0);		//�쳣�˳�
			}
			break;
		default:				//���������ַ�
			d=0;				//�������������ַ�ת���ɶ�Ӧ����ֵ��ŵ�d��
			while (*postexp>='0' && *postexp<='9')   //�ж�Ϊ�����ַ�
			{	
				d=10*d+*postexp-'0';  
				postexp++;
			}
			Push1(Opnd,d);		//����ֵd��ջ

			break;
		}
		postexp++;				//�������������ַ�
	}
	GetTop1(Opnd,e);			//ȡջ��Ԫ��e
	DestroyStack1(Opnd);		//����ջ		
	return e;					//����e
}
int main()
{
	char exp[]="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("��׺���ʽ:%s\n",exp);
	printf("��׺���ʽ:%s\n",postexp);
	printf("���ʽ��ֵ:%g\n",compvalue(postexp));
	return 1;
}