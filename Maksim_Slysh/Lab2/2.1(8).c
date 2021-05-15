//task2.1 var8
#include<stdio.h>
#include <locale.h>

thechoicerate() {
	int minsuper = 200, minsuper10 = 400, minultra = 1000,minmts,minother,minhome,minallnetwork;
	int  minarray[] = { 200,400,1000,};
	printf("Введите колличество минут:");
	printf("\nВнутри сети:\n");
	scanf_s("%d", &minmts);
	printf("В другие сети:\n");
	scanf_s("%d", &minother);
	printf("На домашний телефон :\n");
	scanf_s("%d", &minhome);
	minallnetwork = minhome + minother;
	if (minallnetwork == 0&&minmts<=200){
		printf("Вам подходит тариф :Супер-200 минут внутри сети МТС,Цена 11рублей/месяц\n");
	}
	else if (minmts + minallnetwork <= 400) {
		printf("Вам подходит тариф :Супер10-400 во все сети,Цена 21рубль/месяц\n");
	}
	else if (minmts + minallnetwork <= 1000) {
		printf("Вам подходит тариф :Ультра-,1000 во все сети,Цена 35рублей/месяц\n");
	}
	else
		printf("Вам подходит тариф :Супер25-,безлимит во все сети,Цена 55рубль/месяц\n");
}
void showrate() {
	printf("Тарифы для звонков:\n");
	printf("1:Супер-200 минут внутри сети МТС,Цена 11рублей/месяц\n");
	printf("2:Супер10-400 во все сети,Цена 21рубль/месяц\n");
	printf("3:Ультра-,1000 во все сети,Цена 35рублей/месяц\n");
	printf("4:Супер25-,безлимит во все сети,Цена 55рубль/месяц\n");
}
void shownumberphone(){
	int arraynumber[] = {0,0,0,0,0,0,0};
	char mailarray[] = {'a','a','a','a','a','a','a'};
	for (int i = 0; i < 7; i++) {
		arraynumber[i] = rand() % 10;
		mailarray[i] = rand() % 26 + 65;
	}
    printf("Ваш номер телефона:\t+37529");
	for (int i = 0; i < 7; i++) {
		printf("%d", arraynumber[i]);
	}
	printf("\n");
	printf("Ваша почта :\t");
	for (int i = 0; i < 7; i++) {
		printf("%c", mailarray[i]);
	}
	printf("@mail.ru\n");
	printf("Ваш тариф :\t");
	int a = rand() % 4;
	if(a == 0)
		printf(" Супер\n");
	else if (a == 1)
		printf(" Супер10\n");
	else if (a == 2)
		printf(" Супер25\n");
	else if (a == 3)
		printf(" Ультра\n");

}
int main() {
	int n, cheack=0;
	setlocale(LC_ALL, "rus");
	for (;;) {
		printf("-------------------");
		printf("\nВыберите действие:\n1:Подбор тарифа\n2:Все тарифы\n3:Ваши данные\n4:Завершить программу\n");
		printf("-------------------\n");		
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			thechoicerate();
			break;
		case 2:
			showrate();
			break;
		case 3:
			shownumberphone();
			break;
		case 4:return 0; 
			break;
		}
	}
}