//����2.5�����㷨:������˳���L�����������ƶ���ż����ǰ��
#include "sqlist.cpp"  
void swap(int &x,int &y)				//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void move1(SqList *&L)
{
	int i=0,j=L->length-1;
	while (i<j)
	{
		while (i<j && L->data[j]%2==0)
			j--;					//��������ɨ��,��һ������Ԫ��
		while (i<j && L->data[i]%2==1)
			i++;					//��������ɨ��,��һ��ż��Ԫ��
		if (i<j)					//��i<j����L->data[i]��L->data[j]����
			swap(L->data[i],L->data[j]);
	}
}
void move2(SqList *&L)
{	int i=-1,j;
	for (j=0;j<=L->length-1;j++)
		if (L->data[j]%2==1)		//jָ������ʱ
		{
			i++;					//�������������1
			if (i!=j)				//��i��j�����
				swap(L->data[i],L->data[j]);//L->data[i]��L->data[j]����
		}
}

int main()
{
	SqList *L;
	ElemType a[]={8,2,7,1,5,10,4,6,3,9};
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("ִ���ƶ�����\n");
	move1(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}
