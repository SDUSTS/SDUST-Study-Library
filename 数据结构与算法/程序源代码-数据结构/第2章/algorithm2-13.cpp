//����2.13�����㷨:�ж�ѭ��˫����L�е����ݽ���Ƿ�Գơ�
#include "cdlinklist.cpp"
bool Symm(DLinkNode *L)
{	bool same=true;			//same��ʾL�Ƿ�Գƣ���ʼʱΪ��
	DLinkNode *p=L->next;	//pָ���׽��
	DLinkNode *q=L->prior;	//qָ��β���
	while (same)
	{	if (p->data!=q->data) //��Ӧ���ֵ����ͬ���˳�ѭ��
			same=false;
		else
		{	if (p==q || p==q->prior) break;
			q=q->prior;		//qǰ��һ����� 
			p=p->next;		//p����һ�����
		}
	} 
	return same;
}

int main()
{
	ElemType a[]={1,2,3,2,1};
	int n=5;
	DLinkNode *L;
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	if (Symm(L))
		printf("L�ǶԳƵ�\n");
	else
		printf("L�ǲ��ԳƵ�\n");
	DestroyList(L);
	return 1;
}
