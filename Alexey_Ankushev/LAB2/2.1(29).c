//Lab2.1 Variant 29
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
void GetInfo(float *Length, float *Width, int *Windows, int *Doors, float *FullArea, float *FullPrice, float *Rolls, float *Price) {
    printf("����� �������: %.0f\n������ �������: %.0f\n���������� ����: %d\n���������� ������: %d\n",*Length,*Width, *Windows, *Doors);
    printf("������� ������� %.2f ��.�.\n", *FullArea);
    printf("��������� ��������: %.0f $\n", *FullPrice);
    printf("���������� �������: %.0f \n", *Rolls);
    printf("��������� ������ �����: %.0f$ \n", *Price);
}
void FullPriceOut(float *FullPrice, float *Rolls, float *Price) {
    float glue = ceilf(*Rolls/5);
    *FullPrice = ((*Rolls) * (*Price)) + 2, 5 * glue;
    printf("��������� �������� ����������: %.0f $\n", *FullPrice);
}
void  CountRolls(float *Rolls, float *FullArea) {
    *Rolls= (*FullArea/(0.5f*2.6f));
    
    printf("����������� ���������� �������: %.0f (+10 �� � ������ ������������)\n", *Rolls);
   
}
void GetArea(float *FullArea, float *FullWindowsArea, float *FullDoorsArea, float *Area) {
    *FullArea =(*Area - (*FullWindowsArea + *FullDoorsArea));
    
    printf("������� ������� ����������: %.2f ��.�.\n", *FullArea);
}
void EnterPrice(float * Price) {
    printf("������� ��������� ������ �����($): \n");
    scanf_s("%f", Price);
}
void EnterDoorsCount(int *Doors, float *DoorsArea) {
    printf("������� ���������� ������: \n");
    scanf_s("%d", Doors);
    *DoorsArea = (*Doors) * 1.845f;
}
void EnterWindowsCount(int *Windows, float *WindowsArea) {
    
    printf("������� ���������� ����: \n");
    scanf_s("%d", Windows);
    *WindowsArea = (*Windows) * 3.225f;
}
void EnterParametrs(float* Length, float* Width, float* Area) {
        system("cls");
        printf("������� ����� � ������ �������: \n");
        scanf_s("%f", Length);
        scanf_s("%f", Width);
        *Area = (((*Length) * 2.6f) + ((*Width) * 2.6f)) * 2;
    
}
void ShowMenu(int count) {
    char* a[]= {
        "���� ����� � ������ ������� (�)",
        "���� ���������� ����",
        "���� ���������� ������� ������",
        "���� ��������� ������� ������($)",
        "������ ������� ������� (��.�)",
        "������ ������������ ���������� ������� ������",
        "������ ��������� �������� (� ������ ����)",
        "����� ����������",
        "����� �� ���������"
    };
    if (count == -1) {
       
        for (int i = 0; i < 9; i++) {
            int b = i + 1;
            printf("%d.",b);
            printf("%s\n", a[i]);
        }
    }
    else {
       
        for (int i = 0; i < 9; i++) {
            int b = i + 1;
            if (count == i) {
                printf("***%d.", b);
                printf("%s***\n", a[i]);
            }
            else {
                printf("%d.", b);
                printf("%s\n", a[i]);
            }
            
        }
    }
}
void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count = -1;
    float Length = 0;
    float Width = 0;
    int Windows = 0;
    int Doors = 0;
    float Price = 0;
    float Area = 0;
    float DoorsArea = 0;
    float WindowsArea = 0;
    float FullArea = 0;
    float Rolls = 0;
    float FullPrice = 0;
    float GG = 0;
    ShowMenu(count);
	while (1) {
        switch (getch()) {
        case 72:
            system("cls");
            count--; 
            if (count < 0) {
                count = 8;
            }
            ShowMenu(count);
            break;
        case 80:
            system("cls");
            count++;
            if (count == 9) {
                count = 0;
            }
            ShowMenu(count);
            break;
        case 13:
            system("cls");
            switch (count) {
            case 0:
                EnterParametrs(&Length, &Width,&Area);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 1:
                EnterWindowsCount(&Windows, &WindowsArea);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 2:
                EnterDoorsCount(&Doors, &DoorsArea);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 3:
                EnterPrice(&Price);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 4:
                GetArea(&FullArea,&WindowsArea,&DoorsArea,&Area);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 5:
                CountRolls(&Rolls,&FullArea);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 6:
                FullPriceOut(&FullPrice,&Rolls,&Price);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 7:
                GetInfo(&Length, &Width, &Windows, &Doors, &FullArea, &FullPrice, &Rolls, &Price);
                getch();
                system("cls");
                ShowMenu(count);
                break;
            case 8:
                system("pause");
                break;
            }
            break;
        }
	}

}