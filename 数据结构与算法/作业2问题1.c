#include <stdio.h> 
#include <stdlib.h>
int reoder(int a[],int n);
int main()
{
	int i,*a, n;;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);//sizeof(type);  ע���������ͱ�����������ס����sizeof��int����SIZEOF��INT����ָ�����������е����ͣ����߱����Ĵ�С	
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    reoder(a,n);
    free(a);  // �ͷ��ڴ�ռ�//  malloc ����̬������ڴ�����λ�ڶ��ϣ���Ҫ���ǳ���Ա�ֶ���ʹ����Ϻ���� free
    return 0;
}
int reoder(int a[],int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i++)
    	printf("%d ", a[i]);
    return 0;
}
