//����2.8�����㷨:������L��������
#include "linklist.cpp"
void sort(LinkNode *&L)
{	LinkNode *p,*pre,*q;
	p=L->next->next;		//pָ��L�ĵ�2�����ݽ��
	L->next->next=NULL;		//����ֻ��һ�����ݽ��������
	while (p!=NULL)
	{	q=p->next;			//q����p����̽���ָ��
		pre=L;				//�������ͷ���бȽ�,preָ��p����ǰ�����
		while (pre->next!=NULL && pre->next->data<p->data)
			pre=pre->next;	//����������Ҳ���p����ǰ�����pre
		p->next=pre->next;	//��pre���֮�����p���
		pre->next=p;
		p=q;				//ɨ��ԭ���������µĽ��
	}
}
int main()
{
	LinkNode *L;
	int n=10;
	ElemType a[]={1,3,2,9,0,4,7,6,5,8};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("����\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}

