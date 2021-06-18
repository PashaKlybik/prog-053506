#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>

#define TOWN 30
#define HOTELNAME 30
#define ADDRESS 50
#define NAME 30

typedef struct RoomBase
{
    int count;
    double price;
};

typedef struct RoomMalLux
{
    int count;
    double price;
};

typedef struct RoomLux
{
    int count;
    double price;
};

typedef struct RoomVip
{
    int count;
    double price;
};

typedef struct Number
{
    RoomBase base;
    RoomMalLux malLux;
    RoomLux lux;
    RoomVip vip;
};

typedef struct Hotel
{
    char town[TOWN];
    char hotelName[HOTELNAME];
    char address[ADDRESS];
    struct Number number;
    struct Hotel* next;
    struct Hotel* prev;
};

typedef struct Person
{
    char name[NAME];
    char surname[NAME];
    char hotelname[HOTELNAME];
    int room;

};

int load(struct Hotel* t);
void Choose(struct Hotel* hotel, int count);
bool Reserve(struct Hotel* hotel, int count);
bool ToCancelReservation(struct Hotel* hotel, int countHotel);

int load(struct Hotel* t)
{
    int i = 0;
    FILE* f = fopen("DB.txt", "r");
    if (!f)
    {
        puts("Ошибка открытія файла.");
        return 0;
    }
    while (!feof(f))
    {
        fscanf_s(f, "%s\n%s\n%s\n%d\n%lf\n%d\n%lf\n%d\n%lf\n%d\n%lf\n%d\n%lf", &t[i].town, &t[i].hotelName, &t[i].address, &t[i].number.base.count,
               &t[i].number.base.price, &t[i].number.lux.count, &t[i].number.lux.price, &t[i].number.malLux.count, &t[i].number.malLux.price, &t[i].number.vip.count, &t[i].number.vip.price);
        i++;
    }
    fclose(f);
    return i - 1;
}

void Choose(struct Hotel* hotel, int count)
{
    char town[TOWN];
    int type;
    double maxPrice;
    while (getchar() != '\n');
    system("cls");
    puts("Выберите городъ:");
    gets_s(town);
    puts("Выберите типъ комнаты:");
    puts("1. Обычная");
    puts("2. Люксъ");
    puts("3. Большой люксъ");
    puts("4. Императорскія хоромы");
    puts("5. Не имѣетъ значеніе");
    scanf_s("%d", &type);
    puts("Введите -1, если стоимость не имѣетъ значенія");
    puts("Введите максимальную стоимость: ");
    scanf_s("%lf", &maxPrice);
    system("cls");

    for (int i = 0; i < count; i++)
    {
        if (strcmp(hotel[i].town, town) != 0)
            continue;

        if (type == 1 && hotel[i].number.base.count > 0 && maxPrice != -1 && hotel[i].number.base.price < maxPrice)
            printf("%s\n%s\nтипъ комнаты: обычная\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.base.price);
        if (type == 2 && hotel[i].number.lux.count > 0 && maxPrice != -1 && hotel[i].number.lux.price < maxPrice)
            printf("%s\n%s\nтипъ комнаты: люксъ\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.lux.price);
        if (type == 3 && hotel[i].number.malLux.count > 0 && maxPrice != -1 && hotel[i].number.malLux.price < maxPrice)
            printf("%s\n%s\nтипъ комнаты: большой люксъ\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.malLux.price);
        if (type == 4 && hotel[i].number.vip.count > 0 && maxPrice != -1 && hotel[i].number.vip.price < maxPrice)
            printf("%s\n%s\nтипъ комнаты: императорскія хоромы\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.vip.price);

        if (type == 1 && hotel[i].number.base.count > 0 && maxPrice == -1)
            printf("%s\n%s\nтипъ комнаты: обычная\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.base.price);
        if (type == 2 && hotel[i].number.lux.count > 0 && maxPrice == -1)
            printf("%s\n%s\nтипъ комнаты: люксъ\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.lux.price);
        if (type == 3 && hotel[i].number.malLux.count > 0 && maxPrice == -1)
            printf("%s\n%s\nтипъ комнаты: большой люксъ\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.malLux.price);
        if (type == 4 && hotel[i].number.vip.count > 0 && maxPrice == -1)
            printf("%s\n%s\nтипъ комнаты: императорскія хоромы\n%f\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.vip.price);

        if (type == 5 && maxPrice != -1)
        {
            if (hotel[i].number.base.price < maxPrice)
                printf("%s\n%s\n", hotel[i].town, hotel[i].hotelName);
            printf("типъ комнаты: обычная\n%f\n", hotel[i].number.base.price);
            if (hotel[i].number.lux.price < maxPrice)
                printf("типъ комнаты: люксъ\n%f\n", hotel[i].number.lux.price);
            if (hotel[i].number.malLux.price < maxPrice)
                printf("типъ комнаты: большой люксъ\n%f\n", hotel[i].number.malLux.price);
            if (hotel[i].number.vip.price < maxPrice)
                printf("типъ комнаты: императорскія хоромы\n%f\n", hotel[i].number.vip.price);
        }
        if (type == 5 && maxPrice == -1)
        {
            printf("%s\n%s\n", hotel[i].town, hotel[i].hotelName);
            printf("типъ комнаты: обычная\n%f\n", hotel[i].number.base.price);
            printf("типъ комнаты: люксъ\n%f\n", hotel[i].number.lux.price);
            printf("типъ комнаты: большой люксъ\n%f\n", hotel[i].number.malLux.price);
            printf("типъ комнаты: императорскія хоромы\n%f\n", hotel[i].number.vip.price);
        }
    }

}

bool Reserve(struct Hotel* hotel, int count)
{
    system("cls");
    char name[HOTELNAME];
    int type;
    while (getchar() != '\n');
    puts("Введите названіе гостиницы: ");
    gets_s(name);
    puts("Выберите типъ комнаты:");
    puts("1. Обычная");
    puts("2. Люксъ");
    puts("3. Большой люксъ");
    puts("4. Императорскія хоромы");
    scanf_s("%d", &type);
    if (type != 1 && type != 2 && type != 3 && type != 4)
        return false;

    int flag = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(hotel[i].hotelName, name) != 0)
            continue;

        switch (type)
        {
            case 1:
                if (hotel[i].number.base.count > 0)
                {
                    hotel[i].number.base.count--;
                    flag = 1;
                }
                break;
            case 2:
                if (hotel[i].number.lux.count > 0)
                {
                    hotel[i].number.lux.count--;
                    flag = 2;
                }
                break;
            case 3:
                if (hotel[i].number.malLux.count > 0)
                {
                    hotel[i].number.malLux.count--;
                    flag = 3;
                }
                break;
            case 4:
                if (hotel[i].number.vip.count > 0)
                {
                    hotel[i].number.vip.count--;
                    flag = 4;
                }
                break;
        }

        if (flag != 0)
        {
            Person person{};
            char name[NAME], surname[NAME];
            while (getchar() != '\n');
            puts("Введите имя: ");
            gets_s(name);
            while (getchar() != '\n');
            puts("Введите фамилію: ");
            gets_s(surname);
            while (getchar() != '\n');

            strcpy(person.name, name);
            strcpy(person.surname, surname);
            strcpy(person.hotelname, hotel[i].hotelName);
            person.room = flag;


            FILE* p = fopen("reserve.txt", "a");
            if (!p)
            {
                puts("Ошибка открытія файла.");
                return 0;
            }
            fprintf(p, "%s\n%s\n%s\n%d\n", person.name, person.surname, person.hotelname, person.room);
            fclose(p);


            return true;
        }
    }
    return false;
}

bool ToCancelReservation(struct Hotel* hotel, int countHotel)
{
    system("cls");
    char name[NAME], surname[NAME];
    while (getchar() != '\n');
    puts("Введите имя: ");
    gets_s(name);
    while (getchar() != '\n');
    puts("Введите фамилію: ");
    gets_s(surname);
    while (getchar() != '\n');
    Person t1{};
    int i = 0;

    FILE* f = fopen("reserve.txt", "r");
    if (!f)
    {
        puts("Ошибка открытія файла.");
        return false;
    }

    while (!feof(f))
    {
        fscanf_s(f, "%s\n%s\n%s\n%d", &t1.name, &t1.surname, &t1.hotelname, &t1.room);
        i++;
        if (strcmp(t1.name, name) != 0)
            continue;
        if (strcmp(t1.surname, surname) != 0)
            continue;
        for (int i = 0; i < countHotel; i++)
        {
            if (strcmp(t1.hotelname, hotel[i].hotelName) != 0)
                continue;
            switch (t1.room)
            {
                case 1:
                    hotel->number.base.count++;
                    fclose(f);
                    return true;
                case 2:
                    hotel->number.lux.count++;
                    fclose(f);
                    return true;
                case 3:
                    hotel->number.malLux.count++;
                    fclose(f);
                    return true;
                case 4:
                    hotel->number.vip.count++;
                    fclose(f);
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int n, menu;
    Hotel arr[10];
    n = load(arr);

    puts("Васъ привѣтствуетъ Императорская система выбора гостиницъ. Слѣдуйте инструкціямъ и мы подберемъ для "
         "васъ идеальное мѣсто пребыванія.");

    while (true)
    {
        puts("\nВыберите дѣйствіе:");
        puts("1. Выборъ комнаты ");
        puts("2. Бронированіе комнаты ");
        puts("3. Отмѣна регистраціи");
        scanf_s("%d", &menu);

        switch (menu)
        {
            case 1:
                Choose(arr, n);
                break;

            case 2:
                if (Reserve(arr, n))
                {
                    puts("Комната забронирована.");
                    system("cls");
                }
                else
                    puts("Комнаты, соотвѣтствующія запросу, отсутствуютъ.");
                break;

            case 3:
                if (ToCancelReservation(arr, n))
                    puts("Бронь отмѣнена.");
                else
                    puts("Ошибка.");
                break;

            default:
                FILE* p = fopen("DB.txt", "w");
                for (int i = 0; i < n; i++)
                    fprintf(p, "%s\n%s\n%s\n%d\n%lf\n%d\n%lf\n%d\n%lf\n%d\n%lf\n", arr[i].town, arr[i].hotelName, arr[i].address, arr[i].number.base.count,
                            arr[i].number.base.price, arr[i].number.lux.count, arr[i].number.lux.price, arr[i].number.malLux.count, arr[i].number.malLux.price, arr[i].number.vip.count, arr[i].number.vip.price);
                return 0;
        }
    }
}
