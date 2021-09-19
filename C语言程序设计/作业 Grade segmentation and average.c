#include<stdio.h>
void GradeSandA()
{
  float sum;                //Total score
  float ave;                //average score
  int excellent;            // excellent score
  int good;                 //Good score
  int medium;               //Moderate score 
  int pass;                 //Passing score
  int fail;                 //Failing score
  int counter;              //Counting device
  int grade;                //Individual score
  printf("ÊäÈë10¸ö³É¼¨");
  
  for(counter=0;counter<10;counter++)
    
  /*Calculate the number of students in each score band*/
  {
    scanf("%d",&grade);     // Enter grades 
    sum=sum+grade;
    if(grade>=90)           //Calculate the number of students with excellent grades 
    excellent+=1;
    else if(grade>=80)      //Calculate the number of students with good grades
    good+=1;
    else if(grade>=70)      //Calculate the number of students with medium grades
    medium+=1;    
    else if(grade>=60)      //Calculate the number of students with pass grades
    pass+=1;
    else                    //Calculate the number of students with fail grades
    fail+=1;
  }
   ave=sum/10;              //Calculate average score 
  
  /*Output the number of students in each score band*/
  
  printf("%d with an excellent score\n",excellent);
  printf("%d%d with an good score\n",good);
  printf("%d%d with an medium score\n",medium);
  printf("%d%d with an pass score\n",pass);
  printf("%d%d with an fail score\n",fail);
  printf("The average score is %d\n",ave);
}
