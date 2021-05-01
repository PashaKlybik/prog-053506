//ВАРИАНТ - 9
#include <Windows.h>
#include <iostream>
void Menu()
{
    printf("1 - Ввод значения длины\n");
    printf("2 - Перевод длины в русские традиционные единицы\n");
    printf("3 - Перевод длины в английские традиционные единицы\n"); 
    printf("4 - Вывод отчета, представляющего введенное значение в \n\t1) километрах, \n\t2) метрах, \n\t3) сантиметрах, \n\t4) миллиметрах.\n"); 
    printf("5 - Информация о версии и авторе программы\n"); 
    printf("6 - Выход из программы.\n");
}
int main()
{
    setlocale(LC_ALL, "rus");
    int choice = 1;
    Menu();
    scanf_s("%d", &choice);
    while (choice > 6 || choice < 0)
    {
        printf("некорректный ввод");
        system("cls");
        Menu();
        scanf_s("%d", &choice);
    }
    
    float km = 0, m = 0, cm = 0, mm = 0;
    while (choice != 6) 
    {
        switch (choice)
        {
        case 1:
            system("cls");
            printf("введите данные\nкилометры ");
            scanf_s("%f", &km);
            printf("метры ");
            scanf_s("%f", &m);
            printf("сантиметры ");
            scanf_s("%f", &cm);
            printf("миллиметры ");
            scanf_s("%f", &mm);
            system("cls");
            Menu();
            scanf_s("%d", &choice);
            break;
        case 2: //russian
        {
            system("cls");
            int all_mm = km * 1000000 + m * 1000 + cm * 10 + mm;
            float vershok = all_mm / 44.45;
            int arshin = 0, sazhen=0, versta =0;
            while (1)
            {
                if (vershok>=16)
                {
                    arshin++;
                    vershok -= 16;
                }
                else if (arshin >= 3)
                {
                    arshin -= 3;
                    sazhen++;
                }
                else if (sazhen >= 500)
                {
                    versta++;
                    sazhen -= 500;
                }
                else
                {
                    break;
                }

            }
            system("cls");
            printf("вёрст - %d\nсажней - %d\nаршин - %d\nвершков - %f", versta, sazhen, arshin, vershok);
            Sleep(2300);
            system("cls");
            Menu();
            scanf_s("%d", &choice);
            break;
        }
        case 3: //not russian
        {
            float all_cm = km * 100000 + m * 100 + cm + mm / 10;
            float diujm = all_cm / 2.54;
            int fut =0 ,jard=0,mile = 0;
            while (1) 
            {
                if (diujm>=12)
                {
                    fut++;
                    diujm -= 12;
                }
                else if (fut>=3)
                {
                    fut -= 3;
                    jard++;
                }
                else if (jard>=1760)
                {
                    jard -= 1760;
                    mile++;
                }
                else 
                {
                    break;
                }
            }
            system("cls");
            printf("миль - %d\nярдов - %d\nфутов - %d\nдюймов - %f", mile, jard, fut, diujm);
            Sleep(3500);
            system("cls");
            Menu();
            scanf_s("%d", &choice);
            break;
        }
        case 4:
        {
            system("cls");
            int temp_choice = 0;
            printf("1) километры, \n2) метры, \n3) сантиметры, \n4) миллиметры,\n5) выход\n");
            scanf_s("%d", &temp_choice);
            while (temp_choice > 5 || temp_choice < 0)
            {
                printf("некорректный ввод");
                system("cls");
                printf("1) километры, \n2) метры, \n3) сантиметры, \n4) миллиметры,\n5)выход\n");
                scanf_s("%d", &temp_choice);
            }
            switch (temp_choice)
            {
            case 1:
            {
                system("cls");
                float all_km = km + m / 1000 + cm / 100000 + mm / 1000000;
                printf("итого километров %f", all_km);
                Sleep(3500);
                break;
            }
            case 2:
            {
                system("cls");
                float all_m = km * 1000 + m + cm /100 + mm / 1000;
                printf("итого метров %f", all_m);
                Sleep(3500);
                break;
            }
            case 3:
            {
                system("cls");
                float all_cm = km * 100000 + m * 100 + cm + mm / 10 ;
                printf("итого сантиметров %f", all_cm);
                Sleep(3500);
                break;
            }
            case 4:
            {
                system("cls");
                float all_mm = km * 1000000 + m * 1000 + cm * 10 + mm;
                printf("итого миллиметров %f", all_mm);
                Sleep(3500);
                break;
            }
            case 5:
                system("cls");
                Menu();
                scanf_s("%d", &choice);
                break;
            }
            break;
        }
        case 5:
            system("cls");
            printf("версия 1.0\n\tcreated by Vadim Selivestrau\n");
            printf("press 1 -> go to menu\n");
            int temp = 0;
            scanf_s("%d", &temp);
            while (temp !=1) 
            {
                printf("error input, try again");
                scanf_s("%d", &temp);
            }
            system("cls");
            Menu();
            scanf_s("%d", &choice);
            break;
        }
    }   
}