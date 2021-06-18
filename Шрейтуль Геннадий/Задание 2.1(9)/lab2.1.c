//2.1(9)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[6];
	float k, time = 0;
	int menu = 0;
	do
	{
		time = -1;
		printf("Enter your units and value for length (km, m, sm, mm): ");
		scanf("%f", &k); gets(str);
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'm' && str[i + 1] == 'm')
			{
				time = k; break;
			}
			else if (str[i] == 'k' && str[i + 1] == 'm')
			{
				time = k * 1000000; break;
			}
			else if (str[i] == 'm')
			{
				time = k * 1000; break;
			}
			else if (str[i] == 's' && str[i + 1] == 'm')
			{
				time = k * 10; break;
			}
		}
		if (time >= 0)
		{
			do
			{
				printf("-----------------------------------------------------------------------------------------\n");
				printf("1. Enter new values\n2. Report output\n3. Converting length to Russian traditional units\n");
				printf("4. Converting length to English traditional units\n5. Information about the author of the program\n");
				printf("0. Exiting the program\n");
				scanf("%d", &menu);
				printf("-----------------------------------------------------------------------------------------\n");
				switch (menu)
				{
				case 1: menu = 0; break;
				case 2:
					printf("%f%s is: \n", k, str);
					printf("%f (km)\n", time / 1000000);
					printf("%f (m)\n", time / 1000);
					printf("%f (sm)\n", time / 10);
					printf("%f (mm)\n", time);
					break;
				case 3:
					printf("%f%s is: \n", k, str);
					printf("%f (verst)\n", time / (44.45 * 16 * 3 * 500));
					printf("%f (sazney)\n", time / (44.45 * 16 * 3));
					printf("%f (arshin)\n", time / (44.45 * 16));
					printf("%f (vershkov)\n", time / 44.45);
					break;
				case 4:
					printf("%f%s is: \n", k, str);
					printf("%f (miles)\n", time / (25.4 * 12 * 3 * 1760));
					printf("%f (yards)\n", time / (25.4 * 12 * 3));
					printf("%f (feet)\n", time / (25.4 * 12));
					printf("%f (inches)\n", time / 25.4);
					break;
				case 5:
					printf("Faculty: KSiS\nSpecialty: IiTP\n");
					printf("Name: Gennady Shreytul\nGroup: 053506\n");
					break;
				case 0: return 0; break;
				default: printf("\nSelect a menu item"); break;
				}
			} while (menu != 0);
		}
		else
		{
			printf("The expression is written incorrectly. Example: 10 (km)\n");
			printf("To re-enter enter the 'y' key: ");
			char again; scanf("%s", &again);
			if (again == 'y')
				time = 1;
			else
				return 0;
		}
	} while (time != -1);
	return 0;
}