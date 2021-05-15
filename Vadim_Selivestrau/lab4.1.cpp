//variant(4.1(2))
#include <iostream>
int main()
{
    char* string = (char*)calloc(255, 1);
    rewind(stdin);
    fgets(string, 255, stdin);
    char* temp_string = (char*)calloc(255,1);
    string[strlen(string) - 1] = '\0';
    int i = 0, j=0,k=0;
    while (true)
    {
        temp_string[j] = string[i];
        if (string[i] == ',' || string[i] == ';' || string[i] == ':' 
            || string[i] == '.' || string[i] == '!' || string[i] == '?')
        {
            if (string[i+1] != ' ')
            {
                temp_string[j + 1] = ' ';
                j++;
            }
            if (string[i] == '.' || string[i] == '!' || string[i] == '?')
            {
                if (string[i + 1] == ' ')
                {
                    if (string[i + 2] >= 97 && string[i + 2] <= 122)
                    {
                        string[k+2] -= 32;
                    }
                }
                else 
                {
                    if (string[i + 1] >= 97 && string[i + 1] <= 122)
                    {
                        string[k+1] -= 32;
                    }
                }
            }
        }
        i++;
        j++;
        k++;
        if (string[i] == '\0')
        {
            break;
        }
    }
    printf("%s",temp_string);
    free(string);
    free(temp_string);
    //std::cout << "Hello World!\n";
}