#include<stdio.h>
int isss(int n);
int main(){
    int i,n; 
    scanf("%d",&n);
	for(i=0;i<n;i++){
		if(isss(i)==1){
			printf("%d ",i);
		}		
	}
	return 0;
}
int isss(int n){
	int i;
    for (i =2 ; i<n ; i++){
        if(n%i==0){
            return 0;
        }
        return 1;
    }
}

