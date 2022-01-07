//KMP�㷨
#include "sqstring.cpp"
void GetNext(SqString t,int next[])		//��ģʽ��t���nextֵ
{
	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1) 
	{	
		if (k==-1 || t.data[j]==t.data[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
		{	
			j++;k++;
			next[j]=k;
			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
       	}
       	else
		{
			k=next[k];
			//printf("(2) k=%d\n",k);
		}
	}
}
int KMPIndex(SqString s,SqString t)  //KMP�㷨
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length) 
	{
		if (j==-1 || s.data[i]==t.data[j]) 
		{
			i++;j++;  			//i,j����1
		}
		else j=next[j]; 		//i����,j����
    }
    if (j>=t.length)
		return(i-t.length);  	//����ƥ��ģʽ�������ַ��±�
    else  
		return(-1);        		//���ز�ƥ���־
}
int main()
{
	SqString s,t;
	StrAssign(s,"ababcabcacbab");
	StrAssign(t,"abcac");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("λ��:%d\n",KMPIndex(s,t));
	return 1;
}
