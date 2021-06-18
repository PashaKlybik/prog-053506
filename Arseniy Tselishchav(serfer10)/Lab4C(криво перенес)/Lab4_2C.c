#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

float Comment(char inputArr[], int length) {
	float cntCommented = 0;
	for (int ind = 0; ind < length; ind++) {
		if (inputArr[ind] == '/' && inputArr[ind + 1] == '/') {
			cntCommented += 2;
			while (inputArr[ind] != '\n') {
				cntCommented++;
				ind++;
			}
		}
		else if (  inputArr[ind] == '/' && inputArr[ind + 1] == '*') {
			ind += 2;
			cntCommented += 2;
			while (inputArr[ind] != '*' && inputArr[ind + 1] != '/') {
				if (inputArr[ind] == '\0') {
					break;
				}
				cntCommented++;
				ind++;
			}
			if(inputArr[ind] == '*' && inputArr[ind + 1] == '/')
				cntCommented += 2;
		}
	}
	return cntCommented;
}


int main() {
	FILE* File;

	char* input;
	int length;
	File=fopen("file.txt", "r");

	fseek(File, 0, SEEK_END);
	long  size = ftell(File);
	fseek(File, 0, SEEK_SET);

	input = (char*)calloc(size, sizeof(char));

	int cnt = 0;
	while (true) {
		if (feof(File)) {
			input[cnt - 1] = '\0';
			break;
		}
		input[cnt] = fgetc(File);
		cnt++;
	}
	fclose(File);

	int ind = 0;
	while (input[ind] != '\0') {
		ind++;
	}
	length = ind;

	printf("Code :\n\n");
	for (int j = 0; j < length; j++) {
		printf("%c", input[j]);
	}
	printf("\n\n");

	printf("Size Of File: %ld Bytes.\n", size);
	printf("Commented Code: %.f Bytes\n", Comment(input,length));
	printf("Commented: %.3f%%\n\n", (Comment(input, length) * 100) / size);
	free(input);
	return 0;
}