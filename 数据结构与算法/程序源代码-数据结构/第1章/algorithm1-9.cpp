//����1.9�����㷨:�����ݹ��㷨��ʱ�临�Ӷ�
#include <stdio.h>
void fun(int a[],int n,int k)		//����a����n��Ԫ��,ִ��ʱ��ΪT1(n,k)
{
	int i;
	if (k==n-1)
	{
		for (i=0;i<n;i++)
			printf("%d\n",a[i]);	//�����ִ�д���Ϊn
	}
	else
	{	
		for (i=k;i<n;i++)
			a[i]=a[i]+i*i;			//�����ִ�д���Ϊn-k
		fun(a,n,k+1);				//ִ��ʱ��ΪT1(n,k+1)
	}
}
int main()
{
	int a[10]={0};
	fun(a,10,0);
	return 1;
}