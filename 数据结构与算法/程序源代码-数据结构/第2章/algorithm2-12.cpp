//����2.12�����㷨:��ѭ��˫����L��ɾ����һ��ֵΪx�Ľ�㡣
#include "cdlinklist.cpp"
bool delelem(DLinkNode *&L,ElemType x)
{
	DLinkNode *p=L->next; 
	while (p!=L && p->data!=x)
		p=p->next;
	if (p!=L)						//�ҵ���һ��Ԫ��ֵΪx�Ľ��
	{
		p->next->prior=p->prior;	//ɾ�����*p
		p->prior->next=p->next;
		free(p);
		return true;
	}
	else 
		return false;
}
int main()
{
	ElemType a[]={1,2,2,4,2,3,5,2,1,4};
	ElemType x=1;
	DLinkNode *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("ɾ����һ�����ֵΪ%d�Ľ��\n",x);
	if (delelem(L,x))
	{
		printf("L:");DispList(L);
	}
	else
		printf("ѭ��˫����L�в�����Ԫ��ֵΪ%d�Ľ��\n",x);
	DestroyList(L);
	return 1;
}
