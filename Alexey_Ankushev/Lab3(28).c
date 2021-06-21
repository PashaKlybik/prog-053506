/*
3.2 (Variant 28)
��������  �������  a(n,m)  ����  �������  ���������  �����  ����.
����  �  ��  �������  ���������  �������  ���������  ���.  ������  �
�������  ���������  �������  ����������.  �������������  �����  �
�������� ������������ �������� ������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void SortRows(int** matrix, int ColumnsCount, int firstRow, int secondRow) {

	//��������� ������
	int* temp = malloc(ColumnsCount * sizeof(int));
	for (int i = 0; i < ColumnsCount; i++)
	{
		temp[i] = matrix[firstRow][i];
		matrix[firstRow][i] = matrix[secondRow][i];
		matrix[secondRow][i] = temp[i];
	}
	free(temp);
}

void SortColumns(int** matrix, int RowsCount, int firstColumn, int secondColumn)
{
	//��������� �������
	int* temp = malloc(RowsCount * sizeof(int));
	for (int i = 0; i < RowsCount; i++)
	{
		temp[i] = matrix[i][firstColumn];
		matrix[i][firstColumn] = matrix[i][secondColumn];
		matrix[i][secondColumn] = temp[i];
	}
	free(temp);
}

void ShowMatrix(int** Matrix, int Rows, int Columns) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Columns; j++) {
			printf("%d\t", Matrix[i][j]);
		}
		printf("\n");
	}
}

void MatrixBackup(int** Matrix, int** MatrixTemplate, int Rows, int Columns) {
	
	for (int i = 0; i < Rows; i++)
	{
		int Count = 0;
		for (int j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] == 0)
			{
				if (j > Count)
				{
					SortColumns(Matrix, Rows, j, Count);
					printf("\n������ %d�� � %d�� ��������\n\n", j, Count);
					ShowMatrix(Matrix, Rows, Columns);
				}
				Count++;
			}
		}

		if (i > Count && Count != Columns)
		{
			SortRows(Matrix, Columns, i, Count);
			printf("\n������ %d� � %d� �����\n\n", i, Count);
			ShowMatrix(Matrix, Rows, Columns);
			printf("\n");
			i--;
		}
	}

	for (int i = 0; i < Rows; i++)
	{
		free(Matrix[i]);
		free(MatrixTemplate[i]);
	}
	free(Matrix);
	free(MatrixTemplate);

}

int** EnterMatrixTemplate(int** Matrix, int* Rows, int* Columns) {
	int** MatrixTemplate;

	MatrixTemplate = (int**)malloc(*Rows * sizeof(int*));
	for (int i = 0; i < *Rows; i++) {
		MatrixTemplate[i] = (int*)malloc(*Columns * sizeof(int));
	}

	for (int i = 0; i < *Rows; i++) {
		for (int j = 0; j < *Columns; j++) {
			MatrixTemplate[i][j] = Matrix[i][j];		
		}
	}

	return MatrixTemplate;
}

int** EnterMatrix(int *Rows, int *Columns) {
	int temp = 0;
	int** Matrix;

	//�������� ���������� ������������� ������� (�������)
	Matrix = (int**)malloc(*Rows * sizeof(int*));
	for (int i = 0; i < *Rows; i++) {
		Matrix[i] = (int*)malloc(*Columns * sizeof(int));
	}

	//������������� �������
	for (int i = 0; i < *Rows; i++) {
		for (int j = 0; j < *Columns; j++) {
			printf("[%d][%d] = ", i, j);
			scanf("%d", &temp);
			Matrix[i][j] = temp;
			if (i > j) {
				if (Matrix[i][j]) {
					Matrix[i][j] = 0;
				}
			}
		}
		printf("\n");
	}

	return Matrix;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	int** matrix;
	int** matrixTemplate;
	int Rows = 0, Columns = 0;
	printf("������� ���������� ����� � ��������: ");
	scanf("%d %d", &Rows, &Columns);
	system("cls");

	//�������� ������� + �������� �������
	matrix = EnterMatrix(&Rows, &Columns);
	system("cls");
	matrixTemplate = EnterMatrixTemplate(matrix, &Rows, &Columns);

	//����� �������
	printf("�������� �������: \n");
	ShowMatrix(matrix,Rows,Columns);

	//��������� ����� � ��������
	printf("\n���������� ������� � ������ �������. ���������: \n");
	for (int i = 0; i < rand() % 100 + 200; i++) {
		SortColumns(matrix, Rows, rand() % Columns, rand() % Columns);
		SortRows(matrix, Columns, rand() % Rows, rand() % Rows);
	}
	ShowMatrix(matrix, Rows, Columns);

	//�������������� �������
	printf("\n�������������� �������.\n");
	MatrixBackup(matrix,matrixTemplate,Rows,Columns);
	
	return 0;
}