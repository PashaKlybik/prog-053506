#include <stdio.h>
#include <windows.h>

int leap (int year)
{
    int leap = 0;
    leap = year % 4 == 0 ? year % 100 == 0 ? year % 400 == 0 ? 1 : 0 : 1 : 0;
    return leap;
}

int inputDay (int day, int month, int leap)
{
    while (1)
    {
        printf("Введите день:");
        scanf("%d", &day);
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day > 31 || day <= 0)
            {
                printf("\nНекорректные данные. Повторите ввод.\n");
            }
            else
                return day;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30 || day <= 0)
            {
                printf("\nНекорректные данные. Повторите ввод.\n");
            }
            else
                return day;
        }
        else if (month == 2 && leap == 1)
        {
            if (day > 29 || day <= 0)
            {
                printf("\nНекорректные данные. Повторите ввод.\n");
            }
            else
                return day;
        }
        else if (month == 2 && leap == 0)
        {
            if (day > 28 || day <= 0)
            {
                printf("\nНекорректные данные. Повторите ввод.\n");
            }
            else
                return day;
        }
    }
}

int inputYear(int year)
{
    printf("\nВведите год:");
    scanf("%d", &year);
    if (year > 9999 || year < 0)
        printf("\nНекорректные данные. Повторите ввод.\n");
    else
        return year;
}

int inputMonth(int month)
{
    int chMon = 0;
    while(chMon == 0)
    {
        printf("Введите месяц:");
        scanf("%d", &month);
        if (month>12||month<=0)
            printf("\nНекорректные данные. Повторите ввод.\n");
        else
            chMon = 1;
    }
    return month;
}

void convertToStrMonth (int month)
{
    if (month == 1) printf(" января ");
    if (month == 2) printf(" февраля ");
    if (month == 3) printf(" марта ");
    if (month == 4) printf(" апреля ");
    if (month == 5) printf(" мая ");
    if (month == 6) printf(" июня ");
    if (month == 7) printf(" июля ");
    if (month == 8) printf(" августа ");
    if (month == 9) printf(" сентября ");
    if (month == 10) printf(" октября ");
    if (month == 11) printf(" ноября ");
    if (month == 12) printf(" декабря ");
}

void dayOfWeek (int day, int month, int year, int leap)
{
    int temp1 = year/100;
    int temp2 = year/100;
    for(;;)
    {
        temp1 = temp1++;
        if (temp1%4 == 0)
            break;
    }
    int tempYearIndex = (temp1 - 1 - temp2)*2;

    int yearIndex = (tempYearIndex + year%100 + (year%100)/4)%7;
    int monthIndex = 0;

    if (month == 1 || month == 10)
        monthIndex = 1;
    else if (month == 5)
        monthIndex = 2;
    else if (month == 8)
        monthIndex = 3;
    else if (month == 2 || month == 3|| month == 11)
        monthIndex = 4;
    else if (month == 6)
        monthIndex = 5;
    else if (month == 12 || month == 9)
        monthIndex = 6;
    else if (month == 4 || month ==7)
        monthIndex = 0;

    int dayIndex = (day + monthIndex + yearIndex)%7;
    if (leap == 1&&month<3)
        dayIndex--;
    switch (dayIndex)
    {
        case 0:
            printf("суббота");
            break;
        case 1:
            printf("воскресенье");
            break;
        case 2:
            printf("понедельник");
            break;
        case 3:
            printf("вторник");
            break;
        case 4:
            printf("среда");
            break;
        case 5:
            printf("четверг");
            break;
        case 6:
            printf("пятница");
            break;
    }

}

int pozition (int day, int month, int leap)
{
    int pozition = 0;
    for (int i = 1; i <= month; i++)
    {
        if (i == month)
        {
            pozition =pozition+day;
            return pozition;
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            pozition = pozition + 31;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            pozition =pozition + 30;
        else if (i == 2 && leap == 0)
            pozition =pozition + 28;
        else if (i == 2 && leap == 1)
            pozition = pozition + 29;
    }
}

int Jesus(int pozition, int year)
{
    int days = 0;
    for (int i = 1; i <= year; i++)
    {
        if (i == year)
        {
            days = days + pozition;
            return days;
        }

        if (leap(i) == 1)
            days = days + 366;
        else
            days = days + 365;
    }
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int day = 0, month = 0, year = 0;
    year = inputYear(year);
    month = inputMonth(month);
    day = inputDay(day, month, leap(year));
    while (1)
    {
        int ch;
        printf("\nВыберите действие:");
        printf("\n1. Ввод даты.");
        printf("\n2. Вывод даты в форме: 1 января 2010 г.");
        printf("\n3. Вывод даты в форме: 01.01.10.");
        printf("\n4. День недели и порядковый номер в году.");
        printf("\n5. Кол-во дней от Рождества Христова");
        printf("\n6. Информация о версии и авторе программы.");
        printf("\n7. Выход из программы.");
        printf("\n\nВаш выбор: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                year = inputYear(year);
                month = inputMonth(month);
                day = inputDay(day, month, leap(year));
                break;

            case 2:
                printf("%d", day);
                convertToStrMonth(month);
                printf("%d", year);
                printf(" г.\n");
                break;

            case 3:
                printf("%d", day);
                printf(".");
                printf("%d", month);
                printf(".");
                printf("%d", year);
                printf("\n");
                break;

            case 4:
                printf("День недели: ");
                dayOfWeek(day, month, year, leap(year));
                printf("\nПозиция в году: ");
                printf("%d", pozition(day, month, leap(year)));
                printf("\n");
                break;

            case 5:
                printf("Дней от Рождества Христова: ");
                printf("%d", Jesus(pozition(day, month, leap(year)), year));
                printf("\n");
                break;

            case 6:
                printf("dev: Artyon 'relsa228' Bokun\nver: 1.0\n");
                break;

            case 7:
                return 0;

            default:
                printf("Выберите действительный вариант.\n");
                break;
        }
    }
}
