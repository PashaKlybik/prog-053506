//Task 2.1 Variant 10
#include <stdio.h>
#include < stdlib.h >

struct car {
	int price;
	int year;
	double engineVolume;
	int mileage;
};


void AddCar(car &myCar)
{
	printf("enter the cost of the car: ");
	scanf_s("%d", &myCar.price);

	printf("enter the year of issue: ");
	int yearOfIssue;
	scanf_s("%d", &yearOfIssue);
	myCar.year = 2021 - yearOfIssue;

	printf("enter engine displacement: ");
	scanf_s("%lf", &myCar.engineVolume);

	printf("enter mileage: ");
	scanf_s("%d", &myCar.mileage);
}

void PrintInfoAboutAuthor() {
	printf(" author: Hanna Peshko, group 053506 \n version: 1.1 \n");
}

void CalculateTheCost(car myCar) {
	int haulCost, customsClearanceCost, allCost;

	haulCost = 0.5 * myCar.mileage;

	if (myCar.year <= 3 || (myCar.year>10 && myCar.year<14) )
		customsClearanceCost = 0.6* 1000 * myCar.engineVolume;
	else if (myCar.year>3 && myCar.year<=10) 
		if(myCar.engineVolume<=2.5)
			customsClearanceCost = 0.35 * 1000 * myCar.engineVolume;
		else 
			customsClearanceCost = 0.6 * 1000 * myCar.engineVolume;
	else 
		customsClearanceCost = 2 * 1000 * myCar.engineVolume;

	allCost = customsClearanceCost + haulCost + myCar.price;

	printf("haul cost $: ");
	printf ("%d\n", haulCost);

	printf("customs clearance cost $: ");
	printf("%d\n", customsClearanceCost);

	printf("all cost $: ");
	printf("%d\n", allCost);
	
}

void Menu(car myCar) {
	system("cls");
	int choice;
	fflush(stdin);
	while (true) {
		printf(" 1.Add car\n 2.Information about author \n 3.Calculate the cost \n 4.Exit \n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: system("cls"); AddCar(myCar); system("pause");  break;
		case 2: system("cls"); PrintInfoAboutAuthor(); system("pause");  break;
		case 3: system("cls"); CalculateTheCost(myCar); system("pause"); break;
		case 4: system("cls"); exit(0); break;
		}
		system("cls");
	}
}

int main(){
	car myCar;
	AddCar(myCar);
	while (true) {
		Menu(myCar);
	
	}
}