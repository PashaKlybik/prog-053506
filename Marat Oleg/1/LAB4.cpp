
#pragma hdrstop
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma argsused
using namespace std;
int main()
{
    int mas1[] = { 0,1,2,3,4,5 };
    int mas2[3];
    string Fam[] = { "Ysikov","Masikov","Mamas","Kolov","Lebedev" };
    string Poxhlan[] = { "zdorov","s4ast'ia","Deneg","yda4i","mashiny","Dom" };
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {

        for (int i = 0; i < 3; i++)
            mas1[i] = i;
        cout << Fam[i];
        cout << ":";
        for (int i = 0; i < 3; i++)
        {
            int a = 6;
            int x = rand() % a;
            int l = mas1[x];
            for (int j = 0, b = 0; j < 6; j++)
            {
                if (j != x)
                {
                    mas2[b] = mas1[j];
                    b++;
                }
            }
            for (int j1 = 0; j1 < i; j1++)
            {
                mas1[j1] = mas2[j1];
            }
            cout << Poxhlan[l] << " ";
            a--;
        }
        cout << endl;
    }
    getch();
    return 0;
}