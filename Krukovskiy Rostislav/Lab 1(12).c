//task 1.2 var 12

int count(int num);
int countAny(int counter, int i);
------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    long num =0, counter, i, j;
    int digit;
    int number10 = 0;
    printf("Enter the number");
    scanf("%ld",&num);
    counter=count(num);

    if(counter==0){
        printf("No such numbers");
    } else 
    {
        for (j = counter; j > 0; j--) 
        {
            for (i = 0; i < counter; i++) 
            {
                int any=countAny(counter,i);
                number10 +=  any;
                
            }
            if(number10<=num)
            {   for (i = 0; i < counter; i++) 
                {
                     printf("1");
                }
                printf("-%d     ", number10); 
            }
        
        counter--;
        number10 = 0;   
        }
    }
    getchar();
    return 0;
}

int count(int num){
    int counter=0;
     while (num > 0) {
        num /= 2;
        counter++;
    }
    return counter;
}

int countAny(int counter, int i){
    int any=1;
    while (counter - i - 1) {
                any *= 2;
                counter--;
            }
    return any;
}
