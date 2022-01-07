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
typedef struct
{
	int i;
	int j;
	int di;
} Box;
typedef struct
{
	Box data[MaxSize];
    int top;
} StType;

void InitStack(StType *&s)
{	s=(StType *)malloc(sizeof(StType));
	s->top=-1;
}
void DestroyStack(StType *&s)
{
	free(s);
}
bool StackEmpty(StType *s)
{
	return(s->top==-1);
}
bool Push(StType *&s,Box e)
{
	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(StType *&s,Box &e)
{
	if (s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(StType *s,Box &e)
{
	if (s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
//---------------------------------------------------------
bool mgpath(int xi,int yi,int xe,int ye)
{
	Box path[MaxSize], e;
	int i,j,di,i1,j1,k;
	bool find;
	StType *st;
	InitStack(st);
	e.i=xi; e.j=yi;	e.di=-1;
	Push(st,e);
	mg[xi][yi]=-1;
	while (!StackEmpty(st))
	{
		GetTop(st,e);
		i=e.i; j=e.j; di=e.di;
		if (i==xe && j==ye)
		{
			printf("一条迷宫路径如下:\n");
			k=0;
			while (!StackEmpty(st))
			{
				Pop(st,e);
				path[k++]=e;
			}
			while (k>=1)
			{
				k--;
				printf("\t(%d,%d)",path[k].i,path[k].j);
				if ((k+2)%5==0)
					printf("\n");
			}
			printf("\n");
			DestroyStack(st);
			return true;
		}
		find=false;
		while (di<4 && !find)
		{
			di++;
			switch(di)
			{
			case 0:i1=i-1; j1=j;   break;
			case 1:i1=i;   j1=j+1; break;
			case 2:i1=i+1; j1=j;   break;
			case 3:i1=i;   j1=j-1; break;
			}
			if (mg[i1][j1]==0) find=true;
		}
		if (find)
		{

			st->data[st->top].di=di;
			e.i=i1; e.j=j1; e.di=-1;
			Push(st,e);
			mg[i1][j1]=-1;
		}
		else
		{
			Pop(st,e);
			mg[e.i][e.j]=0;
		}
	}
	DestroyStack(st);
	return false;
}
int main()
{
	mgpath(1,1,M,N);
	return 1;
}
