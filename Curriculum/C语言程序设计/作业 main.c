#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

/*The following is custom header file */

#include"Find the min and second min.h"
#include"Find the min and second min 2.h"
#include"Pyramid.h"
#include"BMI.h"
#include"Grade segmentation and average.h"

void edge();

//Declare custom function edge

int main(int argc, char *argv[])
{
 int n; 
 do
 {
     edge();                                                              //Use the edge function
     printf("\n\t\t\t:Please choose the answer you want\n");              //topic 
     printf("\n\t\t\t1:Find a person's BMI\n");                           //Homework 1
     printf("\n\t\t\t2:Find the min and second min of any numbers\n");    //Homework 2
     printf("\n\t\t\t3:Find the min and second min of 21 numbers\n");     //Homework 2
     printf("\n\t\t\t4:Pyramid\n");                                       //Homework 3 
     printf("\n\t\t\t5:Grade segmentation and average\n");                //Homework 4 
     printf("\n\t\t\t6:Exit£¡\n");                                        //exit the program
     edge(); 

     printf("\n\t\t\t");
     scanf("%d",&n); 
     system("cls");                                                       //Refresh the screen
     switch(n)
     {                                                                    //Analyzing digital input
         case 1: BMI(); break;                                            //If the number entered is 1, run the BMI function
         case 2: findmin();break; //If the number entered is 2, run the findmin function
         case 3: findmin2();break; //If the number entered is 3, run the findmin2 function
         case 4: Pyramid(); break; //If the number entered is 4, run the Pyramid function
         case 5: GradeSandA();break; //If the number entered is 4, run the GradeSandA function 
      }
     getch(); 
     system("cls");
 }while(n!=6); //When n is not equal to 5, continue to execute the program after do
}


/*Output two consecutive lines *Compose the visual boundary.*/

void edge()
{                                                                       //Define the edge function 
  int i;
  int n=0;
  while(n<2)
  {
    for(i=0;i<=56;i++)                                                    //The first 20 empty output spaces, the last 20 empty output*, to form a fr
    {
          if(i>=20)
          printf("*");
          else printf(" ");
     }
  n++;                                                                   //Through the while loop, output two lines continuously
  printf("\n");
 }
}
