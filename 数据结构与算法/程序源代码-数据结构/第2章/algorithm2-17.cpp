//����2.17�����㷨���������ȳ�������˳������λ����
#include "sqlist.cpp"
ElemType M_Search(SqList *A, SqList *B)	//A��B�ĳ�����ͬ
{	int i=0, j=0, k=0;
	while (i<A->length && j<B->length)	//�������о�û��ɨ����
	{	k++;							//��ǰ�鲢��Ԫ�ظ�����1
		if (A->data[i]<B->data[j])		//�鲢��С��Ԫ��A->data[i]
		{	if (k==A->length)			//����ǰ�鲢��Ԫ���ǵ�n��Ԫ��
				return A->data[i];		//����A->data[i]
			i++;
		}
		else							//�鲢��С��Ԫ��B->data[j]
		{	if (k==B->length)			//����ǰ�鲢��Ԫ���ǵ�n��Ԫ��
				return B->data[j];		//����B->data[j]
			j++; 
		}
	}
}

int main()
{
	SqList *L1,*L2;
	int n=5;
	ElemType a[]={11,13,15,17,19};
	ElemType b[]={2,4,6,8,20};
	CreateList(L1,a,n);
	CreateList(L2,b,n);
	printf("L1:"); DispList(L1);
	printf("L2:"); DispList(L2);
	printf("L1,L2����λ��:%d\n",M_Search(L1,L2));
	DestroyList(L1);
	DestroyList(L2);
	return 1;
}
