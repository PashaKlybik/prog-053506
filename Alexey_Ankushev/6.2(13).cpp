/*
Lab 7 Variant 13

�������.  ����  ��������  �������  �  ������������:  ������������ 
������,  �������������  �������,  ���������  ���������,  �����, 
��������  ���  �����,  ����  �����,  ����  ��������.  ������  �������� 
(���,  ����������  ������,  ����  �����������,  ������� 
������������).  ��������������,  ��������  �  ��������  ��������� 
����������.  �������  ������/��������  ������,  ������  ������� 
��������, ��������� ��������� ���� �������� �����. 
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

    //������ ���������� �� �����
    read_client_file();
    read_item_file();

    write_client_file();
    write_item_file();

    i_sum_of_items();
    //����
    int variant;
    int int_pawnshop_profit = 0;
    int int_sum_of_items = 0;

    do
    {
        print_menu();

        //��������� ����� ����.
        variant = get_variant(5); 

        switch (variant)
        {
        case 1:
            do
            {
                print_menu_1();

                //��������� ����� ����.
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
                
                //��������� ����� ����.
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
                        
                        //��������� ����� ����.
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

                        //��������� ����� ����.
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

                //��������� ����� ����.
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
            printf("����� ���������� � ���� �������_�����. �� ������� ������.\n� ������ ������ ���� �� ������ ����������� ������ �������� ��������, �������� ������ ������� ��������, ������� ������� �������� � ������������� ������� ��������.\n�� ������ ������ ���� �� ������ ����������� ������ ������� �����, �������� ����� ����, ������� ���� � ������������� ����.\n� ������� ������ ���� �� ������ ����������� ������� ������� �������� � ��������� ��������� ���� �������� �����.\n�� ���������� � �������� ������ ����.\n����� ����� ���� ������������ ��� ������ �� ���������");//Help
            break;
        }

        if (variant != 5)
            //�������� ����������
            system("pause"); 
    } while (variant != 5);
}
