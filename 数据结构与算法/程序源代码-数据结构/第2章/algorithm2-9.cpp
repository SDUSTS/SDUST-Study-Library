//����2.9�����㷨:˫�������н������
#include "dlinklist.cpp"
void reverse(DLinkNode *&L)		//˫����������
{
	DLinkNode *p=L->next,*q;	//pָ�򿪺ý��
	L->next=NULL;				//����ֻ��ͷ����˫����L
	while (p!=NULL)				//ɨ��L�����ݽ��
	{	q=p->next;				//��ͷ�巨���޸�p����next��,��q�������̽��
		p->next=L->next;		//����ͷ�巨��p�����뵽˫������
		if (L->next!=NULL)		//��L�д������ݽ��,�޸���ǰ��ָ��
			L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;					//��p����ָ�����̽��
	}
}
int main()
{
	ElemType a[]={1,8,0,4,9,7,5,2,3,6};
	DLinkNode *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("����\n");
	reverse(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}
