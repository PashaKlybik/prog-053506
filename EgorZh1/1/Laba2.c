#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float Sum_Dostavki(int weight, float Sum)
{
    if(weight < 5) Sum++;
        else if((weight > 5) && (weight < 20)) Sum+=3;
             else if(weight > 20)
                  {
                    Sum+=10;
                    for(int i=0;i<weight-20;i++) Sum+=2;
                  }
                  return Sum;
}

float Sum_So_skidkoy(float Summa,int Skidon)
{
    if(Summa>=100)
        {
            int x = (Skidon*Summa)/100;
            Summa=Summa-x;
            printf("dasdasda %f",Summa);
        }
    return Summa;
}

int Bucket(int weight,float Sum, int weight_mand, int weight_pers, int weight_vino)
{
    if(weight!=0)
        {
            printf("Вес мандарин = %d(кг)    Вес персиков = %d(кг)    Вес винограда = %d(кг)\n",weight_mand,weight_pers,weight_vino);
            printf("Общий вес корзины = %d\n",weight);
            printf("Цена = %f\n",Sum);
            return 0;
        }
        else
        {
            printf("Ваша корзина пуста!\n");
            return 0;
        }
}

int Rec(int flag,int a, int Skidka,int weight, int weight_mand, int weight_pers, int weight_vino, float Mand, float Pers, float Vino,float Sum, float s)
{
    printf("1.Заказ мандаринов(кг)\n");
    printf("2.Заказ персиков(кг)\n");
    printf("3.Заказ Винограда(кг)\n");
    printf("4.Корзина (с ценами)\n");
    printf("5.Расчет стоимости заказа\n");
    printf("6.Обратная связь\n");
    printf("0.Выход из программы\n");

    scanf("%d",&a);
    if(!isalpha(a))
    {
     switch(a)
     {

        case 1:
        weight_mand++;
        weight++;
        Sum+=Mand;;
        break;


        case 2:
        weight_pers++;
        weight++;
        Sum+=Pers;
        break;


        case 3:
        weight_vino++;
        weight++;
        Sum+=Vino;
        break;


        case 4:
        Bucket(weight,Sum,weight_mand,weight_pers,weight_vino);
        break;


        case 5:
        printf("\nЦена мандаринов(кг) = %f  Цена персиков(кг) =  %f  Цена винограда(кг) =  %f\n",Mand,Pers,Vino);
        s=Sum_So_skidkoy(Sum,Skidka);
        printf("Сумма заказа = %f\n",s);
        printf("Цена доставки = %f\n",Sum_Dostavki(weight,Sum)-s);
        printf("Итого: %f\n\n",Sum_Dostavki(weight,Sum));
        break;


        case 6:
        printf("\nНазвание магазина: Аметист\nНомер лицензии = 10579\nКонтакная информация = +375294584751\n\n");
        break;


        default:
        flag=0;
        break;
     }
    }
    if(flag==0) return 0;
    return Rec(flag, a, Skidka, weight, weight_mand, weight_pers, weight_vino, Mand, Pers, Vino, Sum, s);
}

int main()
{
    setlocale(0,"");

    float Mand = 1.14, Pers = 1, Vino = 1.28, Sum=0, s=0;
    int Skidka=10, weight=0, weight_mand=0, weight_pers=0, weight_vino=0;

    int a, flag=1;

    Rec(flag, a, Skidka, weight, weight_mand, weight_pers, weight_vino, Mand, Pers, Vino, Sum, s);
    printf("Вы покинули программу!\n");

    return 0;
}
