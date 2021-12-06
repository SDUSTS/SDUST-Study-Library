#include <stdio.h>
#include <stdlib.h>
int qusort(int s[],int start,int end) ;
int main()
{
	int i,*a, n;;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);	        
    printf("请输入%d个数：\n",n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("\n");
	qusort(a,1,n);    
    printf("\n排序后的顺序是：\n");
    for(i=1;i<=n;i++)
        printf("%5d",a[i]);
	free(a);  
    return 0;
}
int qusort(int s[],int start,int end)    
{
    int i,j;    
    i=start;    
    j = end;    
    s[0]=s[start];   
    while(i<j){
        while(i<j&&s[0]<s[j])   
        j--; 
        if(i<j){
            s[i]=s[j];   
            i++;
        }
        while(i<j&&s[i]<=s[0])
            i++;    
        if(i<j){
            s[j]=s[i]; 
            j--;   
        }
    }
    s[i]=s[0];
    if (start<i)
        qusort(s,start,j-1); 
    if (i<end)
        qusort(s,j+1,end);
    return 0;
}

