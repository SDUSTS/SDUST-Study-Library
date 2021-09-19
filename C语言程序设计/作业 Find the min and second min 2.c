#include<stdio.h>
void findmin2()
{
      int a[100]; 
      int i,min,min2; 
      i=0; 
      while(i<4)
      {
        //Assign each input number to each corresponding array
        
        scanf("%d",&a[i]);
        i++;
      }
      min=a[0]; 
      min2=a[0]+a[1]; 
      i=0;
  
      /*Calculate the minimum value*/
  
      while(i<4)
      {
        // When Min>a[i]
        if(min>a[i])
        min2=min; 
        min=a[i]; 
        i++;
      }
      i=0;
  
      /*Calculate the second smallest value*/
  
      while(i<4)
      {
        //When Min<a[i]
        if(min<a[i]&&min2>=a[i]);
        min2=a[i];
        i++;
      }
      printf("The minimum value is%d\n",min);
      printf("The next smallest value is%d\n",min2); 
}
