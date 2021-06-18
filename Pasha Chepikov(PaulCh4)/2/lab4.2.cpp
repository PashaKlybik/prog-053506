#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io.h>

struct Elem {
	char Data[50];
};

int main() {
	FILE* smth = fopen("dictionary.txt", "r");
	if (smth == NULL) { return 0; }
	int FileLen = _filelength(_fileno(smth));
	char* File = (char*)calloc(FileLen, 1), buff = '1';
	int j = 0;
	for (int i = 0; i < 2; ++i) fread(&buff, sizeof(char), 1, smth);
	while (!feof(smth)) {
		fread(&buff, sizeof(char), 1, smth);
		File[j] = buff;
		fread(&buff, sizeof(char), 1, smth);
		j++;
	}
	while (true) {
		int choice;
		printf("-----------Menu-------------\n");
		printf("[1] - View dictionary\n");
		printf("[2] - Check word for coincidence\n");
		printf("[3] - Exit\n");
		printf("----------------------------\n\nChoice:");
		scanf_s("%i", &choice);
		switch (choice) {
			case 1: {
				system("cls");
				printf("%s\n", File);
				system("pause");				
				system("cls");
			}
			case 2: {
				system("cls");
				int words = 0;
				for (int n = 0; n <= strlen(File); ++n) if (File[n] == ',') words++;
				Elem* massive = (Elem*)calloc(words, sizeof(Elem));
				int e = 0;
				for (int n = 0, m = 0; n <= strlen(File); ++n) {
					if (File[n] == ',') {
						e++;
						m = 0;
					}
					else if (File[n] == ' ') continue;
					else {
						massive[e].Data[m] = File[n];
						m++;
					}
				}
				for (int i = 0; i < words; ++i) {
					for (int o = 0; o < words; ++o) {
						char* buff = (char*)calloc(strlen(massive[i].Data) + strlen(massive[o].Data) + 1, 1);
						strcat(buff, massive[i].Data);
						strcat(buff, massive[o].Data);
						for (int p = 0; p < words; ++p) {
							if (strcmp(buff, massive[p].Data) == 0) printf("%s\n", buff);
						}
						free(buff);
					}
				}
				break;
			}
			case 3: return 0;
		}
	}
	fclose(smth);
}
