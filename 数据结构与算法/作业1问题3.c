# include <stdio.h>
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[11];  
    int index,num,i; 
    printf("Please enter the index of the inserted value");
    scanf("%d", &index);
    printf("«ÎPlease enter the inserted value:");
    scanf("%d", &num);
    for (i=0; i<11; i++)
    {
        if (i < index){
            b[i] = a[i]; 
        }else if (i == index){   
            b[i] = num; 
        }else {
            b[i] = a[i-1]; 
        }
    }
    for (i=0; i<11; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}


