//����2.10�����㷨:˫�����������
#include "dlinklist.cpp"
void sort(DLinkNode *&L)	
{	
	DLinkNode *p,*pre,*q;
	p=L->next->next;		//pָ��L�ĵ�2�����ݽ��
	L->next->next=NULL;		//����ֻ��һ�����ݽ��������
	while (p!=NULL)
	{	q=p->next;			//q����p����̽���ָ��
		pre=L;				//�������ͷ���бȽ�,preָ��p����ǰ�����
		while (pre->next!=NULL && pre->next->data<p->data)
			pre=pre->next;	//����������Ҳ���p����ǰ�����pre
		p->next=pre->next;	//��pre���֮����뵽p���
		if (pre->next!=NULL)
			pre->next->prior=p;
		pre->next=p;
		p->prior=pre;
		p=q;				//ɨ��ԭ˫�������µĽ��
	}
}

int main()
{
	ElemType a[]={1,8,0,4,9,7,5,2,3,6};
	DLinkNode *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("����\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}
