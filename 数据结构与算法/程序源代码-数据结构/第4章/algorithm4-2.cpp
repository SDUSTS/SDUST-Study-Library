//����4.2�����㷨����s�е�һ�����������ͬ�ַ����ɵ�ƽ̨
#include "sqstring.cpp"
void LongestString(SqString s,int &index,int &maxlen)
{
	int length,i=1,start;		//length����ƽ̨�ĳ���
	index=0,maxlen=1;			//index�����ƽ̨��s�еĿ�ʼλ��,maxlen�����䳤��
	while (i<s.length)
	{
		start=i-1;				//���Ҿֲ��ظ��Ӵ�
		length=1;
		while (i<s.length && s.data[i]==s.data[i-1])
		{	
			i++;
			length++;
		}
		if (maxlen<length)		//��ǰƽ̨���ȴ�,�����maxlen
		{	
			maxlen=length;
			index=start;
		}
		i++;
	}
}
int main()
{
	SqString s;
	int i,j,k;
	//StrAssign(s,"aabcsaaaabcdeab");
	StrAssign(s,"AAAABBBCCCC");
	printf("s:");DispStr(s);
	LongestString(s,i,j);
	printf("�ƽ̨:");
	for (k=i;k<i+j;k++)
		printf("%c",s.data[k]);
	printf("\n");
	return 1;
}