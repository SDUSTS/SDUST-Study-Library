//����2.4�����㷨:������˳���L�Ե�һ��Ԫ��Ϊ�ֽ��ߣ���׼�����л���
#include "sqlist.cpp"  
void swap(int &x,int &y)				//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void move1(SqList *&L)
{	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];			//��data[0]Ϊ��׼
	while (i<j)						//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (i<j && L->data[j]>pivot)
			j--;						//��������ɨ��,��һ��С�ڵ���pivot��Ԫ��
		while (i<j && L->data[i]<=pivot)
			i++;						//��������ɨ��,��һ������pivot��Ԫ��
		if (i<j)
			swap(L->data[i],L->data[j]);//��L->data[i]��L->data[j]���н���
	}
	swap(L->data[0],L->data[i]);		//��L->data[0]��L->data[i]���н���
}

void move2(SqList *&L)
{	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];	//��data[0]Ϊ��׼
	while (i<j)  				//��˳������˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && L->data[j]>pivot)
			j--;				//��������ɨ��,��һ��С�ڵ���pivot��data[j]
		L->data[i]=L->data[j];	//�ҵ�������data[j],����data[i]��
		while (i<j && L->data[i]<=pivot)
			i++;				//��������ɨ��,��һ������pivot�ļ�¼data[i]
		L->data[j]=L->data[i];	//�ҵ�������data[i],����data[j]��
	}
	L->data[i]=pivot;
	printf("i=%d\n",i);
}

int main()
{
	SqList *L;
	ElemType a[]={1,9,8,7,6};
	CreateList(L,a,5);
	printf("L:");DispList(L);
	printf("ִ���ƶ�����\n");
	move1(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}
