#include <stdio.h>
int factorial(int n) ;
int main(){
int n ,sum;
scanf("%d",&n);
int output = 0;
while (n>1)
{
	sum = factorial(n) ;
	output = output + sum;
	n--;
}
printf("%d",output) ;
}
int factorial(int n) 
{
int i,s=1;
for(i=1;i<=n;i++)s=s*i;
return s;
}

