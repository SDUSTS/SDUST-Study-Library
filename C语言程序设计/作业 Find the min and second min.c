#include<stdio.h>
int search(int key,int a[],int length); //Declare the search function
int findmin() //Define a function named ifcomputer 
{
  int a[100],n,min,min2; 
  
  /*Determine how many numbers there are in total*/ 
  
  unsigned int i ; 
  printf("\n\t\t\tPlease enter the number of elements in the array ");
  scanf("%d",&n);
  if(n<1)
  {
    return 0;
  }
  else
  { 
    //Assign each input number to each corresponding array
    printf("\n\t\t\tPlease enter %d integers: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]) ;
  }
   min=a[0];
   for (i=0;i<n;i++)
   { 
       //Find the minimum value min
     
       if(min>a[i])
       {
         min2=min; //Find the second smallest value Min2
         min=a[i];
        }
    }
   printf("\n\t\t\tmin=%d\n",min); 
   printf("\n\t\t\tmin2=%d\n",min2); 
   puts("\n\tConfirm whether you want to view the position of the minimum value in the array/n");
   puts("\n\tenter 0 to view, and enter 1 to not view?");
   printf("\n\t\t\t");
   int c;
   scanf("%d",&c);

  switch(c)
  {
      case(0):
      {
          printf("\n\t\t\tThe position of min is£º");
          search(min,a,n);//Call the search function
           break;
      }
      default:
      {
          puts("The program ends.");break;
      }
   }
  return 0 ;
}

  /*Calculate the position of the number in a set of numbers*/


int search(int key,int a[],int length)
{
  
  //Define the search function
  
  int i;
  for(i=0;i<length;i++)
  
  {
    if(key==a[i])
    {
      printf("%d",i=i+1);
      printf("\n");
      break;
    }
  }
  return key;
}
