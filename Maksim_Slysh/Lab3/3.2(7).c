//task3.2 var7
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(){
	int  m , n ,i,j,a,cheack;
	char* array;
	int* arraycheack;
	setlocale(LC_ALL,"rus");
	printf("Введите количество строк: ");
	scanf_s("%d", &n);
	printf("Введите количество столбцов: ");
	scanf_s("%d", &m);
	array = (char*)malloc(n * m * sizeof(char));
	arraycheack = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arraycheack[i * m + j] = 0;
			}
		}
	for (;;) {
		printf("Введите через пробел i,j,Aij ");
		scanf_s("%d", &i);
		scanf_s("%d", &j);
		scanf_s("%d", &a);
		if (a == 0 && i == 0 && j == 0)
			break;
		else if (i < n && j < m && i >= 0 && j >= 0) {
			if (arraycheack[i * m + j] == 0) {
				array[i * m + j] = a+'0';
				arraycheack[i * m + j] = 1;
			}
			else if (arraycheack[i * m + j] == 1) {
				printf("\nЭта ячейка уже занята.\n");
				printf("Для перезаписи нажмите'1',Оставить предыдущий результат '2'\n");
				scanf_s("%d", &cheack);
				if (cheack == 1)
					array[i * m + j] = a+'0';
				else
					array[i * m + j] = array[i * m + j];
			}
		}
		else
			printf("\nкоординаты за пределами матрицы\n");
	}

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++)  
		{
			if (arraycheack[i * m + j] == 1)
				printf("%5c", *(array + i * m + j));
			else if (arraycheack[i * m + j] == 0) {
				array[i * m + j] = '*';
				printf("%5c", *(array + i * m + j));	
			}		
		}
		printf("\n");
	}
	free(array);
	free(arraycheack);
}

