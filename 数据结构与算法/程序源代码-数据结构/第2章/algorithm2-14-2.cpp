//����2.14�����㷨����·�鲢:���õ�����ʵ��
#include "linklist.cpp"
void UnionList1(LinkNode *LA,LinkNode *LB,LinkNode *&LC)
{
	LinkNode *pa=LA->next,*pb=LB->next,*pc,*s;
	LC=(LinkNode *)malloc(sizeof(LinkNode));		//����LC��ͷ���
	pc=LC;							//pcʼ��ָ��LC�����һ�����
	while (pa!=NULL && pb!=NULL)
	{	
		if (pa->data<pb->data)
		{	
			s=(LinkNode *)malloc(sizeof(LinkNode));//����pa���
			s->data=pa->data;
			pc->next=s;pc=s;		//����β�巨�����s���뵽LC�����
			pa=pa->next;
		} 
		else
		{	
			s=(LinkNode *)malloc(sizeof(LinkNode));//����pb���
			s->data=pb->data;
			pc->next=s;pc=s;		//����β�巨�����s���뵽LC�����
			pb=pb->next;
		}
	}
	while (pa!=NULL)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));	//����pa���
		s->data=pa->data;
		pc->next=s;pc=s;		//����β�巨�����s���뵽LC�����
		pa=pa->next;
	}
	while (pb!=NULL)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));	//����pa���
		s->data=pb->data;
		pc->next=s;pc=s;		//����β�巨�����s���뵽LC�����
		pb=pb->next;
	}
	pc->next=NULL;
}
int main()
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]={1,3,5};
	ElemType b[]={2,4,8,10};
	CreateListR(L1,a,3);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,4);
	printf("L2:");DispList(L2);
	printf("�鲢\n");
	UnionList1(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}

