#include <iostream>

void Show(int chis, int znam);
void Socr(int chis, int znam);
void Sum(int a, int b, int c, int d);
void Sub(int a, int b, int c, int d);
void Mul(int a, int b, int c, int d);
void Div(int a, int b, int c, int d);
void SrGarm(int a, int b, int c, int d);
void Clear();
void Input(int& a, int& b, int& c, int& d);
void Otput(int a, int b, int c, int d);
void Autor();

int main(void)
{
	int a, b, c, d;
	int N = 0;
	bool Start = 0;

	while (true)
	{
		printf_s("1.Input\n2.Output\n3.Sum\n4.Subtraction\n5.Multiplication\n6.Division\n7.Harmonic Value\n8.Program Information\n9.End");
		printf_s("\n\nselect an item and press ENTER:");
		scanf_s("%d", &N);

		if (N == 1)Start = 1;
		if (Start == 0)
		{
			printf_s("\n\n(!)You haven't entered numbers yet");
			Clear();
			continue;
		}

		switch (N)
		{
			case 1:
				Input(a, b, c, d);
				break;
			case 2:
				Otput(a, b, c, d);
				break;
			case 3:
				Sum(a, b, c, d);
				break;
			case 4:
				Sub(a, b, c, d);
				break;
			case 5:
				Mul(a, b, c, d);
				break;
			case 6:
				Div(a, b, c, d);
				break;
			case 7:
				SrGarm(a, b, c, d);
				break;
			case 8:
				Autor();
				break;
			case 9:
				return 0;
			default:
				break;
		}
		Clear();
	}

	return 0;
}

void Show(int chis, int znam)
{
	printf_s("\n%d/%d", chis, znam);
}

void Socr(int chis, int znam)
{
	int zn = 1;
	if (chis < 0)
		zn = -1;
	for (int i = 2; i <= zn * chis; i++)
		if (!(chis % i) && !(znam % i))
		{
			chis /= i;
			znam /= i;
			return Socr(chis, znam);
		}
	Show(chis, znam);
}
void Sum(int a, int b, int c, int d)
{
	int chis = a * d + c * b;
	int znam = b * d;

	Socr(chis, znam);
}
void Sub(int a, int b, int c, int d)
{
	int chis = a * d - c * b;
	int znam = b * d;

	Socr(chis, znam);
}
void Mul(int a, int b, int c, int d)
{
	int chis = a * c;
	int znam = b * d;

	Socr(chis, znam);
}
void Div(int a, int b, int c, int d)
{
	int chis = a * d;
	int znam = b * c;

	Socr(chis, znam);
}
void SrGarm(int a, int b, int c, int d)
{
	int chis = a * d + c * b;
	int znam = a * c;
	znam *= 2;

	Socr(znam, chis);
}
void Clear()
{
	printf_s("\n............................................\n");
}
void Input(int& a, int& b, int& c, int& d)
{
	while (true)
	{
		printf_s("Enter a: ");
		scanf_s("%d", &a);
		printf_s("Enter b: ");
		scanf_s("%d", &b);

		printf_s("_________________\nEnter c: ");
		scanf_s("%d", &c);
		printf_s("Enter d: ");
		scanf_s("%d", &d);

		if (b == 0 || d == 0)
		{
			printf_s("\nCannot be divisible by 0, try again\n");
			continue;
		}
		else break;
	}
}
void Otput(int a, int b, int c, int d)
{
	Show(a, b);
	Show(c, d);
}

void Autor()
{
	printf_s("\n-------Something about the author-------\n");
}
