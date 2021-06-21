#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "laba7.h"

int main() {
	catalog = (List*)malloc(sizeof(List));
	create(catalog);
	FILE* mycatalog;
	errno_t err = fopen_s(&mycatalog, "catalogS.txt", "r+");
	if (err != 0) {
		err = fopen_s(&mycatalog, "catalog.txt", "r+");
		if (err != 0) {
			printf_s("File error");
			return -1;
		}
	}
	while (!feof(mycatalog))
		push(managerRead(mycatalog));
	fclose(mycatalog);
	while (1) {
		int n = 0;
		printf_s("\n\tMenu\n");
		printf_s("1.Catalog\n");
		printf_s("2.Add a comment\n");
		printf_s("3.Edit comment\n");
		printf_s("4.View source\n");
		printf_s("5.Save\n");
		printf_s("6.View article\n");
		printf_s("7.View code\n");
		printf_s("8.Exit\n\n");

		while (!scanf_s("%d", &n) || n <= 0 || n > 8) {
			printf_s("Incorrect input\n");
			while (getchar() != '\n');
		}
		switch (n) {
		case 1: {
			system("cls");
			printf_s("1.Programming languages\n");
			printf_s("2.Articles\n");
			printf_s("3.Subjects\n");
			int choice;
			while (!scanf_s("%d", &choice) || choice <= 0 || choice > 3) {
				printf_s("Incorrect input \n");
				while (getchar() != '\n');
			}

			showList(choice);
			break;
		}

		case 2: {
			char code[20];
			printf_s("Code to comment\n");
			scanf_s("%s", code, 20);
			Manager* search = Search(catalog->head, code);
			if (search == NULL) {
				printf("Incorrect code\n");
			}
			else {
				char string[256];
				printf_s("Enter comment (max. 256):\n");
				scanf_s("%s", string, 256);
				addComment(search, string);
				system("cls");
				printf_s("comment added");
			}
			break;
		}

		case 3: {
			char buf[100];
			char code[20];
			printf_s("Code to comment\n");
			scanf_s("%s", code, 20);
			printf_s("Enter new comment\n");
			scanf_s("%s", buf, 100);
			Manager* search = Search(catalog->head, code);
			if (search == NULL) {
				printf_s("Incorrect code\n");
			}
			else {
				free(search->comment);
				search->comment = (char*)calloc(strlen(buf), sizeof(char));
				memset(search->comment, 0, strlen(buf));
				for (int i = 0; i < strlen(buf); i++)
					search->comment[i] = buf[i];
			}
			break;
		}

		case 4: {
			system("cls");
			Catalog(catalog->head);
			break;
		}
		case 5: {
			int flag = 0;
			FILE* save;
			errno_t err = fopen_s(&save, "catalogS.txt", "w+");
			if (err != 0) {
				printf("File error");
				exit(-1);
			}
			Node* temp = catalog->head;
			while (temp) {
				if (flag++ != 0) {
					fprintf(save, "\n");
				}
				fprintf(save, "%s\n", temp->manager->language);
				fprintf(save, "%s\n", temp->manager->subjects);
				fprintf(save, "%s\n", temp->manager->code);
				fprintf(save, "%s\n", temp->manager->article);
				fprintf(save, "%s\n", temp->manager->comment);
				fprintf(save, "%d", temp->manager->dateAdded);
				temp = temp->next;
			}
			printf("Saved\n");
			fclose(save);
			break;
		}
		case 6: {
			system("cls");
			FILE* article;
			int count = 0, choice;
			Node* temp = catalog->head;
			while (temp) {
				printf("%d.", ++count);
				printf("%s\n", temp->manager->article);
				temp = temp->next;
			}
			while (!scanf_s("%d", &choice) || choice <= 0 || choice > count) {
				printf("Incorrect input \n");
				while (getchar() != '\n');
			}
			count = 1;
			temp = catalog->head;
			while (choice != count) {
				temp = temp->next;
				count++;
			}
			char path[256];
			sprintf_s(path, "%s%s", "Article/", temp->manager->article);
			errno_t err = fopen_s(&article, path, "rt");
			if (err != 0) {
				printf("Error");
				return 0;
			}
			char line[256];
			while (fgets(line, 256, article) != NULL) {
				printf("%s", line);
			}
			fclose(article);
			break;
		}
		case 7: {
			system("cls");
			FILE* code;
			int count = 0, choice;
			Node* temp = catalog->head;
			while (temp) {
				printf("%d.", ++count);
				printf("%s\n", temp->manager->code);
				temp = temp->next;
			}
			while (!scanf_s("%d", &choice) || choice <= 0 || choice > count) {
				printf("Incorrect input \n");
				while (getchar() != '\n');
			}
			count = 1;
			temp = catalog->head;
			while (choice != count) {
				temp = temp->next;
				count++;
			}
			char path[256];
			sprintf_s(path, "%s%s", "Source/", temp->manager->code);
			errno_t err = fopen_s(&code, path, "rt");
			if (err != 0) {
				printf("Error");
				return 0;
			}
			char line[256];
			while (fgets(line, 256, code) != NULL) {
				printf("%s", line);
			}
			fclose(code);
			break;
		}

		case 8: {
			del(catalog->head);
			free(catalog);
			system("cls");
			exit(1);
			break;
		}
		}
	}
}