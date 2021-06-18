﻿#include "Tour.h"

int PrintMenu()

void ListAddNecSer(ListOfNecessaryServicesList* list, char* service, int cost);
void freeMemNecList(ListOfNecessaryServicesList* list);
void freeMemList(List* list);
int CalculateProfit(List* list);

int main(void) {
	char name[TS];
	SmartPrintfChar2("Enter your name: ", name);

	int companys_profit = 0;

	List* list = readFile();
	ListOfNecessaryServicesList* listNecSer = (ListOfNecessaryServicesList*)malloc(sizeof(ListOfNecessaryServicesList));
	listNecSer->head = NULL;
	listNecSer->tail = NULL;
	ListAddNecSer(listNecSer, "Transfer", 750);
	ListAddNecSer(listNecSer, "Hotels", 610);
	ListAddNecSer(listNecSer, "Yacht cruise", 330);
	ListAddNecSer(listNecSer, "Camping on a coast", 160);
	ListAddNecSer(listNecSer, "Breakfast", 330);
	ListAddNecSer(listNecSer, "Lunch", 300);
	ListAddNecSer(listNecSer, "Dinner", 370);

	int N;
	do {
		N = PrintMenu();
		switch (N) {
		case 1:
			printf("\n");
			printf("Menu -> All tours -> \n");
			PrintTours(list);
			printf("---------------------------------------\n\n");
			break;
		case 2:
			printf("\n");
			printf("Menu -> N a tour -> \n");
			PrintTours(list);
			int N = SmartPrintfInt("Enter number of tour: ", list->toursAmount);
			Tour* current = list->head;
			int i = 1;
			while (i != N) {
				current = current->next;
				i++;
			}
			printf("You chose the %s tour!\n", current->country);
			People* new_human = (People*)malloc(sizeof(People));
			int id = current->collective->tail ? current->collective->tail->id + 1 : 1;
			AddPeople(current->collective, name, id, current->cost);
			break;
		case 3:
			printf("\n");
			printf("Menu -> Edit existing tour -> \n");
			PrintTours(list);
			int numberEdit = 1;
			Tour* tourEdit = NEditTour(list, &numberEdit);
			printf("Menu -> Edit existing tour -> %s\n", tourEdit->country);
			PrintTour(tourEdit, numberEdit);
			EditTour(tourEdit);
			printf("---------------------------------------\n\n");
			break;
		case 4:
			printf("\n");
			printf("Menu -> Add my tour -> \n");
			Tour* new_tour = CreateMyTour(listNecSer);
			AddTour(list, new_tour);
			printf("Added!");
			break;
		case 5: {
			PrintTours(list);
			int N = SmartPrintfInt("Enter number of tour: ", list->toursAmount);
			Tour* current = list->head;
			int i = 1;
			while (i != N) {
				current = current->next;
				i++;
			}
			if (!current->selfTour) {
				printf("Its not your tour!\n");
				break;
			}
			else {
				DeleteTour(list, N);
				printf("Deleted!\n");
			}
			break;
		}
		case 6:
			companys_profit = CalculateProfit(list);
			printf("Company's profit: %d\n", companys_profit);
			break;
		case 7:
			companys_profit = CalculateProfit(list);
			break;
		default:
			break;
		}

	} while (!(N == 7 || N == 2));


	SaveFile(list);
	freeMemList(list);
	freeMemNecList(listNecSer);

	return 1;
}

int PrintMenu() {
	int nextStep = 0;
	do {
		printf("---------------------------------------\n");
		printf("1. Show all tours\n");
		printf("2. N a tour\n");
		printf("3. Edit existing tour\n");
		printf("4. Create my tour\n");
		printf("5. Delete my tour\n");
		printf("6. Calculate a company's profit\n");
		printf("7. Exit and save the DB file\n");
		printf("---------------------------------------\n");
		printf("N your position: ");
	} while (!scanf("%d", &nextStep) && clearInput() || checkNumberInput(nextStep, 7));
	return nextStep;
}


void ListAddNecSer(ListOfNecessaryServicesList* list, char* service, int cost) {
	ListOfNecessaryServices* node = (ListOfNecessaryServices*)malloc(sizeof(ListOfNecessaryServices));
	strcpy(node->service, service);
	node->cost = cost;
	node->next = NULL;
	node->prev = NULL;
	if (!list->head) { list->head = node; list->tail = node; }
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
}

void freeMemNecList(ListOfNecessaryServicesList* list) {
	ListOfNecessaryServices* cur = list->head;
	while (cur) {
		ListOfNecessaryServices* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

void freeMemList(List* list) {
	Tour* cur = list->head;
	while (cur) {
		Tour* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(list);
}

int CalculateProfit(List* list) {
	int companys_profit = 0;
	Tour* tour = list->head;
	while (tour) {
		People* cur = tour->collective->head;
		while (cur) {
			companys_profit += cur->profit;
			cur = cur->next;
		}
		tour = tour->next;
	}
	return companys_profit;
}
