//����2.6�����㷨:������L��ֳ�����������
#include "linklist.cpp"
void split(LinkNode *&L,LinkNode *&L1,LinkNode *&L2)
{	LinkNode *p=L->next,*q,*r1;	//pָ���1�����ݽ��
	L1=L;					//L1����ԭ��L��ͷ���
	r1=L1;					//r1ʼ��ָ��L1��β���
	L2=(LinkNode *)malloc(sizeof(LinkNode));	//����L2��ͷ���
	L2->next=NULL;			//��L2��ָ����ΪNULL
	while (p!=NULL)
	{	r1->next=p;			//����β�巨�����p(dataֵΪai)����L1��
		r1=p;
		p=p->next;			//p������һ�����(dataֵΪbi)
		q=p->next;			//����ͷ�巨�޸�p��next��,����q������p�ĺ�̽��
		p->next=L2->next;	//����ͷ�巨�����p����L2��
		L2->next=p;
		p=q;				//p����ָ��ai+1�Ľ��
	}
	r1->next=NULL;			//β���next�ÿ�
}
int main()
{
	LinkNode *L,*L1,*L2;
	int n=10;
	ElemType a[]={1,2,3,4,5,6,7,8,9,10};
	InitList(L);
	InitList(L1);
	InitList(L2);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("L->L1,L2\n");
	split(L,L1,L2);
	printf("L1:");DispList(L1);
	printf("L2:");DispList(L2);
	DestroyList(L1);
	DestroyList(L2);
	return 1;
}
