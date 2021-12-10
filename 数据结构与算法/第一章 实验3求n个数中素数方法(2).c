#include <stdio.h>
#include <math.h>
int main(){
    int i,n; 
    scanf("%d",&n);
	for(i=2;i<n;i++){
		if(isss(i)==1){
			printf("%d ",i);
		}		
	}
	return 0;
}
int isss(int m)
{
 // 输入的整数m 
    int i;  // 循环次数
    int k;  // m 的平方根 
    // 求平方根，注意sqrt()的参数为 double 类型，这里要强制转换m的类型 
    k=(int)sqrt( (double)m );
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;
    // 如果完成所有循环，那么m为素数
    // 注意最后一次循环，会执行i++，此时 i=k+1，所以有i>k 
    if(i>k)
        return 1;
    else
		return 0;
}
