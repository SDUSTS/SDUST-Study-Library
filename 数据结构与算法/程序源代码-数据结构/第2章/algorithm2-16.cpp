//����2.16�����㷨����Чɾ�����������ֵ�ظ����
#include "linklist.cpp"
void dels(LinkNode *&L)
{
	LinkNode *p=L->next,*q;
	while (p->next!=NULL) 
	{
		if (p->data==p->next->data)		//�ҵ��ظ�ֵ�Ľ��
		{
			q=p->next;					//qָ������ظ�ֵ�Ľ��
			p->next=q->next;			//ɾ��*q���
			free(q);
		}
		else							//�����ظ����,pָ������
			p=p->next;
	}
}
int main()
{
	LinkNode *L;
	ElemType a[]={1,2,2,2,3,3,3,3,3};
	CreateListR(L,a,9);
	printf("L:"); DispList(L);
	dels(L);
	printf("L:"); DispList(L);
	DestroyList(L);
	return 1;
}
