//�ö�������Թ�����
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
//----------------------------------------------------------
//-�ǻ��ζ��еĻ��������㷨---------------------------------
//----------------------------------------------------------
typedef struct 
{	int i,j;						//�����λ��
	int pre;						//��·������һ�����ڶ����е��±�
} Box;								//��������
typedef struct
{
	Box data[MaxSize];
	int front,rear;					//��ͷָ��Ͷ�βָ��
} QuType;							//˳�������


void InitQueue(QuType *&q)			//��ʼ������
{	q=(QuType *)malloc (sizeof(QuType));
	q->front=q->rear=-1;
}
void DestroyQueue(QuType *&q)		//���ٶ���
{
	free(q);
}
bool QueueEmpty(QuType *q)			//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(QuType *&q,Box e)		//������
{	if (q->rear==MaxSize-1)			//���������
		return false;				//���ؼ�
	q->rear++;						//��β��1
	q->data[q->rear]=e;				//rearλ�ò���Ԫ��e
	return true;					//������
}
bool deQueue(QuType *&q,Box &e)	//������
{	if (q->front==q->rear)			//�ӿ������
		return false;
	q->front++;
	e=q->data[q->front];
	return true;
}
//----------------------------------------------------------

void print(QuType *qu,int front)	//�Ӷ���qu�����·��
{
	int k=front,j,ns=0;
	printf("\n");
	do				//�����ҵ����·��,����·���ϵķ����pre��Ա���ó�-1
	{	j=k;
		k=qu->data[k].pre;
		qu->data[j].pre=-1;
	} while (k!=0);
	printf("һ���Թ�·������:\n");
	k=0;
	while (k<MaxSize)  //����������preΪ-1�ķ���,�����������·��
	{	if (qu->data[k].pre==-1)
		{	ns++;
			printf("\t(%d,%d)",qu->data[k].i,qu->data[k].j);
			if (ns%5==0) printf("\n");	//ÿ���ÿ5�������һ��
		}
		k++;
	}
	printf("\n");
}
bool mgpath1(int xi,int yi,int xe,int ye)	//����·��Ϊ:(xi,yi)->(xe,ye)
{
	Box e;
	int i,j,di,i1,j1;
	QuType *qu;						//����˳���ָ��qu
	InitQueue(qu);					//��ʼ������qu
	e.i=xi; e.j=yi; e.pre=-1;
	enQueue(qu,e);					//(xi,yi)����
	mg[xi][yi]=-1;					//���丳ֵ-1,�Ա���ع����ظ�����
	while (!QueueEmpty(qu))			//�Ӳ�����ѭ��
	{	
		deQueue(qu,e);				//���ӷ���e,���ڲ��ǻ��ζ��У��ó���Ԫ�����ڶ�����
		i=e.i; j=e.j;
		if (i==xe && j==ye)			//�ҵ��˳���,���·��
		{	
			print(qu,qu->front);	//����print�������·��
			DestroyQueue(qu);		//���ٶ���
			return true;			//�ҵ�һ��·��ʱ������
		}
		for (di=0;di<4;di++)		//ѭ��ɨ��ÿ����λ,��ÿ�����ߵķ�����������
		{	
			switch(di)
			{
			case 0:i1=i-1; j1=j;   break;
			case 1:i1=i;   j1=j+1; break;
			case 2:i1=i+1; j1=j;   break;
			case 3:i1=i;   j1=j-1; break;
			}
			if (mg[i1][j1]==0)
			{
				e.i=i1; e.j=j1; 
				e.pre=qu->front;	//ָ��·������һ��������±�
				enQueue(qu,e);		//(i1,j1)�������
				mg[i1][j1]=-1;		//���丳ֵ-1,�Ա���ع����ظ�����
			}
		}
     }
	DestroyQueue(qu);			//���ٶ���
	return false;				//δ�ҵ��κ�·��ʱ���ؼ�
}
int main()
{
	mgpath1(1,1,M,N);
	return 1;
}