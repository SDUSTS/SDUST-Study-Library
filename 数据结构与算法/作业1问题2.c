#include<stdio.h>
int find(int a[],int len,int key);
int main()
{
	int a[10]={1,2,3,4,5,6,23,23};
	int i,j,position;
	int key;
	scanf("%d", &key);
	position = find(a,10,key);
	if(position==0){
		printf("Not found");
	}
	else{
		printf("%d",position+1);
	}
	return 0 ;
}
int find(int a[],int len,int key)
{
	int i,j=-1;
	for (i = 0; i<len; i++) {
		if (a[i] == key) {
	    j = i;
	    break;
		}
	}
	return j;	
}



