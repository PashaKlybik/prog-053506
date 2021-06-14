#include "main.h"
#include <stdio.h>

int main()
{
    struct money buffer;
    reinput(&buffer);

    nextStep(buffer);
    return 0;
}

void outputMoney(struct money buffer)
{
    char input[10];
    printf("Which currency to use?\n1 --- USD\n2 ---- BYN\n3 --- EUR\n4 --- RUB\n");
    
    scanf("%s", input);
    switch(input[0])    
    {
        case '1':
        {
            printf("Result: %lf", buffer.USD);
            break;
        }
        case '2':
        {
            printf("Result: %lf", buffer.BYN);
            break;
        }
        case '3':
        {
            printf("Result: %lf", buffer.EUR);
            break;
        }
        case '4':
        {
            printf("Result: %lf", buffer.RUB);
            break;
        }

    }
}

void printCurrecies()
{
    printf("Currency ---------  BUY  ----- SELL\n");
    printf("         USD       2.600 ----- 2.604\n");
    printf("         RUB(100)  3.527 ----- 3.532\n");
    printf("         EUR       3.108 ----- 3.110\n\n");
}

void credits()
{
    printf("Contact data:\n");
    printf("Phone: +375 33 603 96 91\n");
    printf("E-mail: Nikita_dem@list.ru\n\n");
}

void getProfit(struct money buffer)
{
    double bufferProfit = buffer.BYN * 0.004;
    printf("If u buy USD bank will get %lf BYN\n", bufferProfit);

    bufferProfit = buffer.BYN * 0.002;    
    printf("If u buy EUR bank will get %lf BYN\n", bufferProfit);
    
    bufferProfit = buffer.BYN * 0.005;
    printf("If u buy RUB bank will get %lf BYN\n", bufferProfit);

    printf("The best deal for the bank is %lf profit with RUB deal\n", bufferProfit);
}

void reinput(struct money *buffer)
{
    struct money buffer1;
    printf("Input money in BYN");
    scanf("%lf", &buffer1.BYN);

    buffer1.EUR = buffer1.BYN/2.6;
    buffer1.USD = buffer1.BYN/3.108;
    buffer1.RUB = buffer1.BYN*100/3.527;

    *buffer = buffer1;
}


void nextStep(struct money buffer)
{
    char input[10];
    do
    {
        printf("Choouse next activity:\n1 ---- Output RUB/USD/BYN/EUR\n");
        printf("2 --- Get currencies for today\n");
        printf("3 --- Count profit\n");
        printf("4 --- Bank credits\n");
        printf("5 --- Reinput data\n");
        printf("S --- exit application\n");
        scanf("%s",&input);
        switch(input[0])
        {
            case '1':
            {
                outputMoney(buffer);
                break;
            }
            case '2':
            {
                printCurrecies();
                break;
            }
            case '3':
            {
                getProfit(buffer);
                break;
            }
            case '4':
            {
                credits();
                break;
            }
            case '5':
            {
                reinput(&buffer);
                break;
            }
            default:
            {
                printf("Wrong input");
                break;
            }
        }
    } while (input[0] != 'S');
    
}
