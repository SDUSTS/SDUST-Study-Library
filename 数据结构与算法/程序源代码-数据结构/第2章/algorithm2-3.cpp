//����2.3�����㷨:��˳���L��ɾ������ֵΪx��Ԫ��
#include "sqlist.cpp"
void delnode1(SqList *&L,ElemType x)
{
	int k=0,i;  //k��¼ֵ������x��Ԫ�ظ���
	for  (i=0;i<L->length;i++) 
		if (L->data[i]!=x)
		{
			L->data[k]=L->data[i];
			k++;    //������x��Ԫ����1
		}
	L->length=k;  //˳���L�ĳ��ȵ���k
}
void delnode2(SqList *&L,ElemType x)
{ 
	int k=0,i=0; //k��¼ֵ����x��Ԫ�ظ���
	while (i<L->length) 
	{
		if (L->data[i]==x) 
			k++;
		else 
			L->data[i-k]=L->data[i]; //��ǰԪ��ǰ��k��λ��
		i++;
	}
	L->length-=k;	//˳���L�ĳ��ȵݼ�k
}

int main()
{
	ElemType a[]={1,2,2,1,0,2,4,2,3,1};
	ElemType x=2;
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("ɾ��ֵΪ%d��Ԫ��\n",x);
	delnode2(L,x);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}