//����2.15�����㷨:��3����������Ĺ������
#include "linklist.cpp"
void Commnode(LinkNode *&LA,LinkNode *LB,LinkNode *LC)
{
	LinkNode *pa=LA->next,*pb=LB->next,*pc=LC->next,*q,*r;
	LA->next=NULL;  		//��ʱLA��Ϊ�½��������ͷ���
	r=LA;					//rʼ��ָ���µ��������һ�����
	while (pa!=NULL)		//���Ҿ������Ĺ�����㲢����������
	{	
		while (pb!=NULL && pa->data>pb->data) //pa��ָ�����LB�н����бȽ�
			pb=pb->next;
		while (pc!=NULL && pa->data>pc->data) //pa��ָ�����LC�н����бȽ�
			pc=pc->next;
		if (pb!=NULL && pc!=NULL && pa->data==pb->data && pa->data==pc->data) //pa��ָ����ǹ������
		{	
			r->next=pa;			//��*pa�����뵽LA��
			r=pa;		
			pa=pa->next;		//pa�Ƶ���һ�����
		}
		else               		//pa��ָ��㲻�ǹ������,��ɾ��֮
		{	
			q=pa;
			pa=pa->next;		//pa�Ƶ���һ�����
			free(q);			//�ͷŷǹ������
		}
	}
	r->next=NULL;			//���½�������β����next���ÿ�
}
int main()
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]={1,3,5,8};
	ElemType b[]={2,3,6,7,8,10};
	ElemType c[]={1,3,8,9,20};
	CreateListR(L1,a,4);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,6);
	printf("L2:");DispList(L2);
	CreateListR(L3,c,5);
	printf("L3:");DispList(L3);
	printf("��ȡ����Ԫ��\n");
	Commnode(L1,L2,L3);
	printf("L1:");DispList(L1);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}

