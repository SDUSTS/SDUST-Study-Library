//����2.7�����㷨:ɾ��������L�����Ԫ�صĽ��
#include "linklist.cpp"
void delmaxnode(LinkNode *&L)
{
	LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)					//��pɨ������������,preʼ��ָ����ǰ�����
	{
		if (maxp->data<p->data)		//���ҵ�һ������Ľ��
		{	maxp=p;					//����maxp
			maxpre=pre;				//����maxpre
		}
		pre=p;						//p��preͬ������һ�����
		p=p->next;
	}
	maxpre->next=maxp->next;		//ɾ��maxp���
	free(maxp);						//�ͷ�maxp���
}
int main()
{
	LinkNode *L;
	int n=10;
	ElemType a[]={1,3,2,9,0,4,7,6,5,8};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("ɾ�����ֵ���\n");
	delmaxnode(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}