//˳�򴮻���������㷨
#include <stdio.h>
#define MaxSize 100
typedef struct
{	
	char data[MaxSize];
	int length;			//����
} SqString;
void StrAssign(SqString &s,char cstr[])	//�ַ�������������s
{
	int i;
	for (i=0;cstr[i]!='\0';i++)
		s.data[i]=cstr[i];
	s.length=i;
}
void DestroyStr(SqString &s)
{  }

void StrCopy(SqString &s,SqString t)	//������
{
	int i;
	for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}
bool StrEqual(SqString s,SqString t)	//�д����
{
	bool same=true;
	int i;
	if (s.length!=t.length)				//���Ȳ����ʱ����0
		same=false;
	else 
		for (i=0;i<s.length;i++)
			if (s.data[i]!=t.data[i])	//��һ����Ӧ�ַ�����ͬʱ����0
			{	same=false;
				break;
			}
	return same;
}
int StrLength(SqString s)	//�󴮳�
{
	return s.length;
}
SqString Concat(SqString s,SqString t)	//������
{
	SqString str;
	int i;
	str.length=s.length+t.length;
	for (i=0;i<s.length;i++)	//��s.data[0..s.length-1]���Ƶ�str
		str.data[i]=s.data[i];
	for (i=0;i<t.length;i++)	//��t.data[0..t.length-1]���Ƶ�str
		str.data[s.length+i]=t.data[i];
	return str;
}
SqString SubStr(SqString s,int i,int j)	//���Ӵ�
{
	SqString str;
	int k;
	str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;					//��������ȷʱ���ؿմ�
	for (k=i-1;k<i+j-1;k++)  		//��s.data[i..i+j]���Ƶ�str
		str.data[k-i+1]=s.data[k];
	str.length=j;
	return str;
} 
SqString InsStr(SqString s1,int i,SqString s2)	//���봮
{
	int j;
	SqString str;
	str.length=0;
	if (i<=0 || i>s1.length+1)  //��������ȷʱ���ؿմ�
		return str;
	for (j=0;j<i-1;j++)      		//��s1.data[0..i-2]���Ƶ�str
		str.data[j]=s1.data[j];
	for (j=0;j<s2.length;j++)		//��s2.data[0..s2.length-1]���Ƶ�str
		str.data[i+j-1]=s2.data[j];
	for (j=i-1;j<s1.length;j++)		//��s1.data[i-1..s1.length-1]���Ƶ�str
		str.data[s2.length+j]=s1.data[j];
	str.length=s1.length+s2.length;
	return str;
}
SqString DelStr(SqString s,int i,int j)		//��ɾȥ
{
	int k;
	SqString str;
	str.length=0;
	if (i<=0 || i>s.length || i+j>s.length+1) //��������ȷʱ���ؿմ�
		return str;
	for (k=0;k<i-1;k++)       		//��s.data[0..i-2]���Ƶ�str
		str.data[k]=s.data[k];
	for (k=i+j-1;k<s.length;k++)	//��s.data[i+j-1..s.length-1]���Ƶ�str
		str.data[k-j]=s.data[k];
	str.length=s.length-j;
	return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)	//�Ӵ��滻
{
	int k;
	SqString str;
	str.length=0;
	if (i<=0 || i>s.length || i+j-1>s.length) //��������ȷʱ���ؿմ�
		return str;
	for (k=0;k<i-1;k++)				//��s.data[0..i-2]���Ƶ�str
		str.data[k]=s.data[k];
	for (k=0;k<t.length;k++)   		//��t.data[0..t.length-1]���Ƶ�str
		str.data[i+k-1]=t.data[k];
	for (k=i+j-1;k<s.length;k++)	//��s.data[i+j-1..s.length-1]���Ƶ�str
		str.data[t.length+k-j]=s.data[k];
	str.length=s.length-j+t.length;
	return str;
}
void DispStr(SqString s)	//�����s
{
	int i;
	if (s.length>0)
	{	for (i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}
