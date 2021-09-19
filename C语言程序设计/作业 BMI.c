#include<stdio.h>
void BMI() //Define a function with no return value named BMI
{ 
    float weight; 
    float height; 

    printf("Please enter your height");
    scanf("%f",&height); 
    printf("Enter your weight");
    scanf("%f",&weight); 
    float BMI = weight/(height*height);//Formula for calculating BMI
    if(BMI<18.5) 
        //Determine the size of BIM
        printf("you are underweight");
    else if(BMI>=18.5&&BMI<=24.9) //when 18.5<=BMI<=24.9
        printf("you are normal");
    else if(BMI>=25&&BMI<=29.9) // when 25<BMI<24.9
        printf("you are overweight");
    else // when BMI>24.9 
    printf("you are obese");
}
