//����3.5�����㷨���жϱ��ʽ�е������Ƿ����
#include "listack.cpp"
#include <string.h>
bool Match(char exp[],int n)
{
	int i=0; char e;
	bool match=true;
	LinkStNode *st;
	InitStack(st);						//��ʼ��ջ
	while (i<n && match)				//ɨ��exp�������ַ�
	{
		if (exp[i]=='(')				//��ǰ�ַ�Ϊ������,�����ջ
			Push(st,exp[i]);
		else if (exp[i]==')')			//��ǰ�ַ�Ϊ������
		{
			if (GetTop(st,e)==true)
			{	
				if (e!='(')				//ջ��Ԫ�ز�Ϊ'('ʱ��ʾ��ƥ��
					match=false;
				else
					Pop(st,e);			//��ջ��Ԫ�س�ջ
			}
			else  match=false;			//�޷�ȡջ��Ԫ��ʱ��ʾ��ƥ��
		}
		i++;							//�������������ַ�
	}
	if (!StackEmpty(st))				//ջ����ʱ��ʾ��ƥ��
		match=false;
	DestroyStack(st);					//����ջ
	return match;
}

int main()
{
	char exp[]="(1+2*(5+3)/2)";
	if (Match(exp,strlen(exp))==1)
		printf("���ʽ%s�������\n",exp);
	else
		printf("���ʽ%s���Ų����\n",exp);
	return 1;
}