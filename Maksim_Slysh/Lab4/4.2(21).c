//task4.2 var21
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	char str[255], strtrue[255];
	FILE* fp = fopen("Test.txt", "r");
	fgets(str, 254, fp);
	fclose(fp);
	int size = strlen(str), count = 0;
	for (int i = 0; i < size; i++) {
		strtrue[i] = str[i];
	}
	strtrue[size] = '\0';
	char arraybig[] = { 'Ц','Ю','У','К','Е','Н','Г','Ш','Щ','З','Х','Ф','Ы','В','А','П','Р','О','Л','Д','Ж','Э','Я','Ч','С','М','И','Т','Б' };
	char arraysmall[] = { 'ц','ю','у','к','е','н','г','ш','щ','з','х','ф','ы','в','а','п','р','о','л','д','ж','э','я','ч','с','м','и','т','б' };
	for (int i = 0; i < size - 1; i++) {
		if (str[i] == '.') {
			for (int j = 0; j < 29; j++) {
				if (str[i + 1] == arraysmall[j]) {
					strtrue[i + 1] = arraybig[j];
					count++;
				}
				else if (str[0] == arraysmall[j]) {
					strtrue[0] = arraybig[j];
					count++;
				}
			}
		}
	}
	for (int cheack = 0; cheack < 5; cheack++) {
		for (int i = 0; i < size - 1; i++) {
			if (strtrue[i] == ' ' && strtrue[i + 1] == ' ') {
				for (int j = i + 1; j < size - 1; j++) {
					strtrue[j] = strtrue[j + 1];
					count++;
				}
				size--; strtrue[size] = '\0';
			}
		}
	}
	int cheack;
	if (count > 0) {
		printf("В тексте найдены ошибки:\n");
		printf("Нажмите 1 Если хотите оставить исходный вариант\n");
		printf("Нажмите 2 Если хотите исправить\n");
		scanf_s("%d", &cheack);
		if (cheack == 2) {
			FILE* fp = fopen("Test.txt", "w");
			fprintf(fp, "%s", strtrue);
		}
	}
	else
		printf("Ошибок не найдено\n");
	fclose(fp);
	printf("%s", strtrue);
}