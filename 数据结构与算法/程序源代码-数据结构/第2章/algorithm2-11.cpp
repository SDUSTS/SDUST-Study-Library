//����2.11�����㷨:ͳ��ѭ��������L��ֵΪx�Ľ�������
#include "clinklist.cpp"
int count(LinkNode *L,ElemType x)
{
	int n=0;
	LinkNode *p=L->next;	//ָ���1�����ݽ��
	while (p!=L)
	{	
		if (p->data==x) n++;
		p=p->next;
	}
	return(n);
}
int main()
{
	ElemType a[]={1,2,2,4,2,3,5,2,1,4};
	ElemType x=2;
	LinkNode *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("���ֵΪ%d�Ľ�����:%d\n",x,count(L,x));
	DestroyList(L);
	return 1;
}
