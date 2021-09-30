# include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);  // define the vulue of num 
	// Judge the 1st person's preferences and output the results
	if((num%2==0) && (num>4&&num<12 )){
		printf("YES ");
	}
	else{
	    printf("NO ");
	}
	// Judge the 4 person's preferences and output the results
	if((num%2!=0) &&(num<4||num>12 )){
		printf("YES ");
	}
	else{ 
	    printf("NO ");
	}
	// Judge the 2 person's preferences and output the results
	if(((num%2!=0) && (num>4&&num<12 ))||((num%2==0) && (num<4||num>12 ))){
		printf("YES ");
	}
	else{ 
	    printf("NO ");
	}
	// Judge the 3 person's preferences and output the results
	if((num%2==0) || (num>4&&num<12 )){
		printf("YES ");
	}
	else{ 
	    printf("NO ");
	}
	
	return 0;
 } 
 
