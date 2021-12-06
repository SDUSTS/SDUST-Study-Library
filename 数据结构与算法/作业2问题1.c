#include <stdio.h> 
#include <stdlib.h>
int reoder(int a[],int n);
int main()
{
	int i,*a, n;;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);//sizeof(type);  注：数据类型必须用括号括住。如sizeof（int）“SIZEOF（INT）“指的是求括号中的类型，或者变量的大小	
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    reoder(a,n);
    free(a);  // 释放内存空间//  malloc 所动态分配的内存区域，位于堆上，需要我们程序员手动在使用完毕后进行 free
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
