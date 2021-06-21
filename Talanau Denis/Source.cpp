#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct RoomDefault
{
	int count;
	double price;
};

typedef struct RoomJuniorS
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
	RoomDefault def;
	RoomJuniorS juniorLux;
	RoomLux lux;
	RoomVip vip;
};

typedef struct Hotel
{
	char town[30];
	char hotelName[30];
	char address[30];
	Number number;
	Hotel* pNext;
	Hotel* pPrev;
};
typedef struct Person
{
	char name[30];
	char surname[30];
	char hotelname[30];
	int room;

};

int load(Hotel* t);
void Choose(Hotel* hotel, int count);
bool Reserve(Hotel* hotel, int count);
bool ToCancelReservation(Hotel* hotel, int countHotel);

int main()
{
	int i, n;
	Hotel* head = NULL, * tail = NULL;
	Hotel arr[1];
	n = load(arr);

	int menu;
	while (true)
	{
		puts("Menu");
		puts("1-choose a room");
		puts("2-reserve a room");
		puts("3-to cancel reservation");
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			Choose(arr, n);
			break;
		case 2:
			if (Reserve(arr, n))
			{
				puts("Operation was successfully completed. Room booked");
				system("cls");
			}
			else
			{
				puts("No rooms of this type are available");
			}
			break;
		case 3:
			if (ToCancelReservation(arr, n))
			{
				puts("Reservation withdrawn");
			}
			else
			{
				puts("Error");
			}
			break;
		default:
			FILE* p = fopen("Info.txt", "w");
			for (int i = 0; i < n; i++)
			{
				fprintf(p, "%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", arr[i].town, arr[i].hotelName, arr[i].address, arr[i].number.def.count,
					arr[i].number.def.price, arr[i].number.lux.count, arr[i].number.lux.price, arr[i].number.juniorLux.count, arr[i].number.juniorLux.price, arr[i].number.vip.count, arr[i].number.vip.price);
			}
			return 0;
		}

	}

}


int load(Hotel* t)
{
	int i = 0;
	char town[30], hotelName[30], address[30];
	
	FILE* f = fopen("Info.txt", "r");
	if (!f)
	{
		puts("Error");
		return 0;
	}
	while (!feof(f))
	{
		fscanf(f, "%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", &t[i].town, &t[i].hotelName, &t[i].address, &t[i].number.def.count,
			&t[i].number.def.price, &t[i].number.lux.count, &t[i].number.lux.price, &t[i].number.juniorLux.count, &t[i].number.juniorLux.price, &t[i].number.vip.count, &t[i].number.vip.price);
		i++;
	}
	fclose(f);
	return i - 1;
}

void Choose(Hotel* hotel, int count)
{
	char town[30];
	int type;
	int maxPrice;
	while (getchar() != '\n');
	system("cls");
	puts("Enter town:");
	gets_s(town);
	puts("Enter number type");
	puts("1-Base");
	puts("2-Lux");
	puts("3-Junior Suite");
	puts("4-Vip");
	puts("5-doesn't matter");
	scanf_s("%d", &type);
	puts("Enter max price:");
	puts("Enter -1 to say that the price does not matter");
	scanf_s("%d", &maxPrice);
	system("cls");

	for (int i = 0; i < count; i++)
	{
		if (strcmp(hotel[i].town, town) != 0)
			continue;

		if (type == 1 && hotel[i].number.def.count > 0 && maxPrice != -1 && hotel[i].number.def.price < maxPrice)
			printf("%s\n%s\ntype room:base\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.def.price);
		if (type == 2 && hotel[i].number.lux.count > 0 && maxPrice != -1 && hotel[i].number.lux.price < maxPrice)
			printf("%s\n%s\ntype room:lux\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.lux.price);
		if (type == 3 && hotel[i].number.juniorLux.count > 0 && maxPrice != -1 && hotel[i].number.juniorLux.price < maxPrice)
			printf("%s\n%s\ntype room:malflux\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.juniorLux.price);
		if (type == 4 && hotel[i].number.vip.count > 0 && maxPrice != -1 && hotel[i].number.vip.price < maxPrice)
			printf("%s\n%s\ntype room:vip\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.vip.price);

		if (type == 1 && hotel[i].number.def.count > 0 && maxPrice == -1)
			printf("%s\n%s\ntype room:base\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.def.price);
		if (type == 2 && hotel[i].number.lux.count > 0 && maxPrice == -1)
			printf("%s\n%s\ntype room:lux\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.lux.price);
		if (type == 3 && hotel[i].number.juniorLux.count > 0 && maxPrice == -1)
			printf("%s\n%s\ntype room:malflux\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.juniorLux.price);
		if (type == 4 && hotel[i].number.vip.count > 0 && maxPrice == -1)
			printf("%s\n%s\ntype room:vip\n%d\n\n", hotel[i].town, hotel[i].hotelName, hotel[i].number.vip.price);

		if (type == 5 && maxPrice != -1)
		{
			if (hotel[i].number.def.price < maxPrice)
				printf("%s\n%s\n", hotel[i].town, hotel[i].hotelName);
			printf("type room:base\n%d\n", hotel[i].number.def.price);
			if (hotel[i].number.lux.price < maxPrice)
				printf("type room:lux\n%d\n", hotel[i].number.lux.price);
			if (hotel[i].number.juniorLux.price < maxPrice)
				printf("type room:malflux\n%d\n", hotel[i].number.juniorLux.price);
			if (hotel[i].number.vip.price < maxPrice)
				printf("type room:vip\n%d\n", hotel[i].number.vip.price);
		}
		if (type == 5 && maxPrice == -1)
		{
			printf("%s\n%s\n", hotel[i].town, hotel[i].hotelName);
			printf("type room:base\n%d\n", hotel[i].number.def.price);
			printf("type room:lux\n%d\n", hotel[i].number.lux.price);
			printf("type room:malflux\n%d\n", hotel[i].number.juniorLux.price);
			printf("type room:vip\n%d\n", hotel[i].number.vip.price);
		}
	}

}

bool Reserve(Hotel* hotel, int count)
{
	system("cls");
	char name[30];
	int type;
	while (getchar() != '\n');
	puts("Enter Hotels name:");
	gets_s(name);
	puts("Enter number type");
	puts("1-Base");
	puts("2-Lux");
	puts("3-Junior Suite");
	puts("4-Vip");
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
			if (hotel[i].number.def.count > 0)
			{
				hotel[i].number.def.count--;
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
			if (hotel[i].number.juniorLux.count > 0)
			{
				hotel[i].number.juniorLux.count--;
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
			Person person;
			char name[30], surname[30];
			while (getchar() != '\n');
			puts("Enter Name:");
			gets_s(name);
			while (getchar() != '\n');
			puts("Enter Surame:");
			gets_s(surname);
			while (getchar() != '\n');

			strcpy(person.name, name);
			strcpy(person.surname, surname);
			strcpy(person.hotelname, hotel[i].hotelName);
			person.room = flag;


			FILE* p = fopen("reserve.txt", "a");
			if (!p)
			{
				puts("Error");
				return 0;
			}
			fprintf(p, "%s\n%s\n%s\n%d\n", person.name, person.surname, person.hotelname, person.room);
			fclose(p);


			return true;
		}
	}
	return false;
}

bool ToCancelReservation(Hotel* hotel, int countHotel)
{
	system("cls");
	char name[30], surname[30];
	while (getchar() != '\n');
	puts("Enter Name:");
	gets_s(name);
	while (getchar() != '\n');
	puts("Enter Surame:");
	gets_s(surname);
	while (getchar() != '\n');
	Person t1;
	int i = 0;

	FILE* f = fopen("reserve.txt", "r");
	if (!f)
	{
		puts("Error");
		return 0;
	}
	int flag = 0;
	while (!feof(f))
	{
		fscanf(f, "%s\n%s\n%s\n%d", &t1.name, &t1.surname, &t1.hotelname, &t1.room);
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
				hotel->number.def.count++;
				flag = 1;
				fclose(f);
				return true;
			case 2:
				hotel->number.lux.count++;
				flag = 1;
				fclose(f);
				return true;
			case 3:
				hotel->number.juniorLux.count++;
				flag = 1;
				fclose(f);
				return true;
			case 4:
				hotel->number.vip.count++;
				flag = 1;
				fclose(f);
				return true;
			}
		}
	}
	return false;
}