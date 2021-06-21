/*
Lab 7 Variant 13

Ломбард.  База  хранимых  товаров  и  недвижимости:  наименование 
товара,  идентификатор  клиента,  оценочная  стоимость,  сумма, 
выданная  под  залог,  дата  сдачи,  срок  хранения.  Список  клиентов 
(ФИО,  паспортные  данные,  дата  регистрации,  история 
обслуживания).  Редактирование,  удаление  и  просмотр  введенной 
информации.  Функции  приема/возврата  товара,  расчет  прибыли 
ломбарда, оценочная стоимость всех хранимых вещей. 
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAXARR 150
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    struct client* client = NULL;
    struct item* item = NULL;

    //Чтение информации из файла
    read_client_file();
    read_item_file();

    write_client_file();
    write_item_file();

    i_sum_of_items();
    //Меню
    int variant;
    int int_pawnshop_profit = 0;
    int int_sum_of_items = 0;

    do
    {
        print_menu();

        //Выбранный пункт меню.
        variant = get_variant(5); 

        switch (variant)
        {
        case 1:
            do
            {
                print_menu_1();

                //Выбранный пункт меню.
                variant = get_variant(6); 

                switch (variant)
                {
                case 1:
                    read_client_list();
                    break;

                case 2:
                    client_addelement_to_list();
                    break;

                case 3:
                    delete_client_element();
                    break;

                case 4:
                    reduct_client_element();
                    break;

                case 5:
                    system("cls");
                    printf("");
                    break;
                }

            } while (variant != 6);

            break;

        case 2:
            do
            {
                print_menu_2();
                
                //Выбранный пункт меню.
                variant = get_variant(6); 

                switch (variant) {
                case 1:
                    read_item_list();
                    break;

                case 2:
                    item_addelement_to_list();
                    break;

                case 3:
                    do
                    {
                        print_menu_2_1();
                        
                        //Выбранный пункт меню.
                        variant = get_variant(4); 

                        switch (variant) {
                        case 1:
                            delete_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 2:
                            delete_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 3:
                            system("cls");
                            printf("");
                            break;
                        }

                        if (variant != 4)
                            system("pause");
                    } while (variant != 4);
                    break;

                case 4:
                    do
                    {
                        print_menu_2_2();

                        //Выбранный пункт меню.
                        variant = get_variant(5);

                        switch (variant) {
                        case 1:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 2:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 3:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 4:
                            system("cls");
                            printf("");
                            break;
                        }

                        if (variant != 5)
                            break;
                    } while (variant != 5);
                    break;

                case 5:
                    system("cls");
                    printf("");
                    break;
                }

                if (variant != 6)
                    system("pause");
            } while (variant != 6);
            break;

        case 3:
            do
            {
                print_menu_3();

                //Выбранный пункт меню.
                variant = get_variant(4);

                switch (variant) {
                case 1:
                    pawnshop_profit();
                    break;

                case 2:
                    sum_of_items();
                    break;

                case 3:
                    printf("");
                    break;
                }

                if (variant != 4)
                    system("pause");
            } while (variant != 4);
            break;

        case 4:
            system("cls");
            printf("Добро пожаловать в меню Ломбард_Вещей. Вы выбрали Помощь.\nВ первом пункте меню вы можете просмотреть список клиентов ломбарда, добавить нового клиента ломбарда, удалить клиента ломбарда и редактировать клиента ломбарда.\nВо втором пункте меню вы можете просмотреть список сданных вещей, добавить новую вещь, удалить вещь и редактировать вещь.\nВ третьем пункте меню вы можете просмотреть текущую прибыль ломбарда и оценочная стоимость всех хранимых вещей.\nВы находитесь в четвёртом пункте меню.\nПятый пункт меню предназначен для выхода из программы");//Help
            break;
        }

        if (variant != 5)
            //Задержка выполнения
            system("pause"); 
    } while (variant != 5);
}
