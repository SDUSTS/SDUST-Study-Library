#include<stdio.h>
void Pyramid()
                    //Define a function called Pyramid without return value 
{
  int i,j,k;
  int n;            //Define the height of the pyramid n 
  printf("Please enter the height of the pyramid\n");
  scanf("%d",&n); 
  
  for(i=1;i<=n;i++) // loop output i-th line
      {
      for(k=i;k<=n-1;k++)
        {
                    //Circularly output the spaces in the i-th line, the number of cycles i
          printf(" ");
        }
       for(j=1;j<=2*i-1;j++)
       {
                    //Circularly output the * in the ith row, and the number of cycles is j
          printf("*");
        }
      printf("\n"); 
      }
}
