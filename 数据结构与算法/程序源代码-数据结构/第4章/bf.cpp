//BF�㷨
#include "sqstring.cpp"
int index(SqString s,SqString t)
{
	int i=0,j=0;
	while (i<s.length && j<t.length) 
	{
		if (s.data[i]==t.data[j])  	//����ƥ����һ���ַ�
		{	
			i++;				//�������Ӵ�����ƥ����һ���ַ�
			j++;  
		}
		else          			//�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
		{	
			i=i-j+1;			//��������һ��λ�ÿ�ʼƥ��
			j=0; 				//�Ӵ���ͷ��ʼƥ��
		}
	}
	if (j>=t.length)   
		return(i-t.length);  		//����ƥ��ĵ�һ���ַ����±�
	else  
		return(-1);        		//ģʽƥ�䲻�ɹ�
}
int main()
{
	SqString s,t;
	StrAssign(s,"ababcabcacbab");
	StrAssign(t,"abcac");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("λ��:%d\n",index(s,t));
	return 1;
}
