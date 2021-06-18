#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include < string.h >


int main(void) {
    char** str = NULL;
    unsigned sizeX, sizeY = 100 , flag;
    char B[20]; 
    int A, k = 0;

    printf_s("number of lines: ");
    scanf_s("%d", &sizeX);

    gets_s(B,1);

    str = (char**)calloc(sizeX, sizeof(char*));
    for (int i = 0; i < sizeX; i++) 
       str[i] = (char*)calloc(sizeY, sizeof(char));  
    
    for (int i = 0; i < sizeX; i++)
    {    
        gets_s(str[i], sizeY);
    }
    printf_s("Output:\n");
    

    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; str[i][j] != '\0'; j++)
        {
            A = (str[i][j] - '0');
            if (A >= 0 && A <= 10)
            {
                B[k] = str[i][j];
                k++;
                
                A = (str[i][j+1] - '0' + 2);
                if (!(A >= 0 && A <= 10))
                {                  
                    printf_s("(");
                    for (int i = 0; i < atoi(B); i++)
                    {
                        if (atoi(B) % 2 == 0)
                            printf_s("+");  
                        if (atoi(B) % 2 == 1)
                            printf_s("-");
                    }
                    printf_s(")");

                    B[1] = '\0';
                    k = 0;
                }
                continue;
            }
            printf_s("%c", str[i][j]);
        }
        printf_s("\n");
    }
   
    for (int i = 0; i < sizeX; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}