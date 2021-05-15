#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int i=0;
int Cena[] = {2,9,3,4,2,3,2};
int Disko[]={840,412,237};
char Vk[][100] = {"Apple(kg)","Meat(kg)","Rice(kg)","Oil","Cookies","CocaCola","Candies(kg)"};

typedef struct prod
{
  char Name_Of_Product[400];
  int Kol;
  int Cen;
  int shtrix_kod;

} Item;

Item Product[40];

typedef struct Card
{
  int Diskont;

} Karta;

Karta Dis[40];


int Number;
//-------------------------------------------------------------------------------
void Print(void)
{
    int sum=0,F=1;
    printf(" N  Продукт              Количество            Цена\n");
    for(i=0;i<Number;i++)
    {

        printf("%2i. %-20s %-20i %3i\n", Product[i].shtrix_kod ,Product[i].Name_Of_Product,Product[i].Kol,Product[i].Cen);
        sum+=Product[i].Kol*Product[i].Cen;
    }
    char d;
    int Disk;
    fflush(stdin);
    printf("У вас есть дисконтная карта? Да(y), Нет(n): ");
    scanf("%c",&d);
    if(d == 'n')
    {
         printf("\nОбщая стоимость покупки= %i\n",sum);
        return 0;
    }
    else if(d == 'y')
          {
            while(F)
            {
              printf("Введите номер вашей карты: ");
              scanf("%i",&Disk);
              if(Disk != 0)
                {
                  for(int j=0;j<3;j++)
                  if(Disk == Dis[j].Diskont)
                    {
                        printf("Ваша скидка 10%");
                            sum=sum*90/100;
                            F=0;
                            printf("\nОбщая стоимость покупки= %i\n",sum);
                            return 0;
                    }
                 }
            }
          }

}
int f=0;
//-------------------------------------------------------------------------------
void Add(void)
{
    int Selection,temp;
    while ((Selection = Menu_Product()) != '0' && Selection != 27)
    {
        strcpy(Product[Number].Name_Of_Product,Vk[Selection-49]);
        Product[Number].Cen = Cena[Selection-49];
        Product[Number].shtrix_kod = Selection-48;

        printf("Введите количество данного товара: ");
        if(Product[Number].Kol != 0)
        {
            temp=Product[Number].Kol;
            scanf("%i",&Product[Number].Kol);
            Product[Number].Kol = Product[Number].Kol+temp;

            Number--;
            temp=0;
        }
        else scanf("%i",&Product[Number].Kol);

        if(Product[Number].Kol==0)
        {
            return 0;
        }
        Number++;
    }
    if(Selection == '0') f=1;
    for(i=0;i<7;i++)
    {

        Dis[i].Diskont = Disko[i];
    }


}
//-------------------------------------------------------------------------------
void Save(void)
{
  FILE *F;


  if ((F = fopen("task1.txt", "wt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для записи файл 'task1.txt'\n");
    return;
  }

  fprintf(F, "%i\n", Number);
  for (i=0;i<Number;i++) fprintf(F, "%s Kol=%i  Cena=%i\n",Product[i].Name_Of_Product,Product[i].Kol,Product[i].Cen);

  fclose(F);
}
//-------------------------------------
int Menu_Product(void)
{
  int c = 0;
  while ((c < '0' || c > '7') && c != 27)
  {
    printf("    0 : Выход\n"
           "    1 : Яблоки(кг)\n"
           "    2 : Мясо(кг)\n"
           "    3 : Рис(кг)\n"
           "    4 : Масло\n"
           "    5 : Вафельки\n"
           "    6 : Кока-кола\n"
           "    7 : Конфеты(кг)\n"
           "    >");
    c = getch();
    printf("%c\n\n", c);
  }
  return c;
}
//-------------------------------------------------------------------------------
int Menu(void)
{
  int c = 0;

  while (c < '0' || c > '3')
  {
    printf("0 : Выход\n"
           "1 : Список Продуктов\n"
           "2 : Сохранить\n"
           "3 : Вывести историю покупок\n"
           ">");
    c = getch();
    printf("%c\n", c);
  }
  return c;
}
void clear (void)
    {
        while(getchar()!='\n');
    }
//-------------------------------------------------------------------------------
void main(void)
{
  setlocale(0,"");

  int Selection;

  Number = 0;
  while ((Selection = Menu()) != '0')
  {
    switch (Selection)
    {
    case '1': Add(); break;
    case '2': Save(); break;
    case '3': Print(); break;
    }
  }
}
