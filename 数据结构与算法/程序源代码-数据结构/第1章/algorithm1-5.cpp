//����1.5�����㷨:��һԪ���η��̵ĸ�
#include <stdio.h>
#include <math.h>
int solution(double a,double b,double c,double &x1,double &x2) 
{	
	double d;
	d=b*b-4*a*c;
	if (d>0)
	{	x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		return 2;			//2��ʵ�� 
	}
	else if (d==0)
	{	x1=(-b)/(2*a);
		return 1;	 		//1��ʵ�� 
	} 
	else					//d<0�����
		return 0;			//������ʵ��
}
int main()
{
	double a=2,b=-6,c=3;
	double x1,x2;
	int s=solution(a,b,c,x1,x2);
	if (s==1)
		printf("һ������x=%lf\n",x1);
	else if (s==2)
		printf("��������x1=%lf,x2=%lf\n",x1,x2);
	else
	printf("û�и�\n");
	return 1;
}
