//����4.3�����㷨���Ѵ�s�����ȳ��ֵ��Ӵ�"ab"��Ϊ"xyz"
#include "listring.cpp"
void Repl(LinkStrNode *&s)
{
	LinkStrNode *p=s->next,*q;
	int find=0;
	while (p->next!=NULL && find==0)	//����'ab'�Ӵ�
	{
		if (p->data=='a' && p->next->data=='b')   	//�ҵ���ab�Ӵ�
		{	
			p->data='x';p->next->data='z';			//�滻Ϊxyz
			q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
			q->data='y';q->next=p->next;p->next=q;
			find=1;
		}
		else p=p->next; 
	}
}
int main()
{
	LinkStrNode *s;
	StrAssign(s,"aabcabcd");
	printf("s:");DispStr(s);
	printf("ab->xyz\n");
	Repl(s);
	printf("s:");DispStr(s);
	return 1;
}
