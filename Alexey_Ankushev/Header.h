#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXARR 150
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

using namespace std;
struct client
{
    char ID[MAXARR];
    char fullname_name[MAXARR];
    char pasport_number[MAXARR];
    char registration_date[MAXARR];
    char transaction_history[MAXARR];
    struct client* next;
    struct client* prev;
};

struct item
{
    char ID[MAXARR];
    char Client_ID[MAXARR];
    char item_name[MAXARR];
    char cost[MAXARR];
    char deposit_sum[MAXARR];
    char deposit_start_date[MAXARR];
    char deposit_end_date[MAXARR];
    struct item* next;
    struct item* prev;
};

struct client* clients_first_element = NULL;
struct item* items_first_element = NULL;

void read_client_file();
void read_client_list();
void write_client_file();
void client_addelement(struct client* client);
void client_addelement_to_list();
void delete_client_element();
void reduct_client_element();

void read_item_file();
void read_item_list();
void write_item_file();
void item_addelement(struct item* item);
void item_addelement_to_list();
void delete_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items);
void reduct_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items);

void pawnshop_profit();
void sum_of_items();
void i_sum_of_items();

void print_menu();
void print_menu_1();
void print_menu_2();
void print_menu_2_1();
void print_menu_2_2();
void print_menu_3();
int get_variant(int count);


void client_addelement(struct client* client)
{
    if (clients_first_element == NULL)
        clients_first_element = client;
    else
    {
        struct client* temp = clients_first_element;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = client;
        client->prev = temp;
    }
}

void client_addelement_to_list()
{
    system("cls");

    struct client* client;
    int size = sizeof(struct client);
    client = (struct client*)malloc(sizeof(struct client));
    client->next = NULL;
    client->prev = NULL;

    struct client* temp = clients_first_element;

    printf("��������� ������ ������ ������������, � ������:\n");
    gets_s(client->ID);

    printf("������� ID �������:");
    gets_s(client->ID);

    printf("������� ��� �������:");
    gets_s(client->fullname_name);

    printf("������� ����� ��������� �������:");
    gets_s(client->pasport_number);

    printf("������� ���� ����������� �������:");
    gets_s(client->registration_date);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = client;
    client->prev = temp;

    write_client_file();
    item_addelement_to_list();
    write_item_file();
}

void read_client_file()
{
    FILE* fclients;
    char buffer[MAXARR];

    fclients = fopen("D:\\Clients.txt", "r");
    if (!fclients)
    {
        printf("���� �� ������. ����� �� ���������");
        return;
    }
    while (fgets(buffer, MAXARR, fclients) != NULL)
    {
        struct client* client;
        int size = sizeof(struct client);
        client = (struct client*)malloc(sizeof(struct client));
        client->next = NULL;
        client->prev = NULL;

        int i = 0;
        int j = 0;

        while (buffer[i] != '\n')
        {
            while (buffer[i] != ';')
            {
                client->ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->fullname_name[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->fullname_name[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->pasport_number[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->pasport_number[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->registration_date[j] = buffer[i];
                if (buffer[i + 1] == ';' || buffer[i + 1] == '\n' || buffer[i + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j++;
            client->registration_date[j] = '\0';

            if (buffer[i] == '\0')
            {
                break;
            }
        }
        client_addelement(client);

    }
    fclose(fclients);
}

void write_client_file()
{
    FILE* fclients;
    char fbuffer[MAXARR];

    fclients = fopen("Clients.txt", "w");
    if (!fclients)
    {
        printf("���� �� ������. ����� �� ���������");
        return;
    }

    int i = 0;
    int j = 0;

    struct client* temp = clients_first_element;

    while (temp != NULL)
    {
        while (fbuffer[i] != '\n')
        {
            while (temp->ID[j] != '\0')
            {
                fbuffer[i] = temp->ID[j];
                if (temp->ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->fullname_name[j] != '\0')
            {
                fbuffer[i] = temp->fullname_name[j];
                if (temp->fullname_name[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->pasport_number[j] != '\0')
            {
                fbuffer[i] = temp->pasport_number[j];
                if (temp->pasport_number[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->registration_date[j] != '\0')
            {
                fbuffer[i] = temp->registration_date[j];
                if (temp->registration_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j = 0;
            fbuffer[i] = '\n';
        }
        temp = temp->next;
        i++;
    }
    i--;
    fbuffer[i] = '\0';
    fputs(fbuffer, fclients);
    fclose(fclients);
}

void read_client_list()
{
    system("cls");
    struct client* temp = clients_first_element;
    while (temp != NULL)
    {
        printf("%s\n", temp->ID);
        printf("%s\n", temp->fullname_name);
        printf("%s\n", temp->pasport_number);
        printf("%s\n\n", temp->registration_date);
        temp = temp->next;
    }
    system("pause");
}

void delete_client_element()
{
    int check = 0;

    struct client* prev = nullptr, * next = nullptr;
    struct client* temp = clients_first_element;

    printf("������� ID �������, �������� ���� �������\n");
    scanf("%d", &check);


    while (temp != NULL)
    {
        int ID = atoi(temp->ID);
        if (ID == check)
        {
            prev = temp->prev; // ����, �������������� lst
            next = temp->next; // ����, ��������� �� lst
            if (prev != NULL)
                prev->next = temp->next; // ������������ ���������
            if (next != NULL)
                next->prev = temp->prev; // ������������ ���������
            free(temp); // ����������� ������ ���������� ��������
            break;
        }
        temp = temp->next;
    }

    write_client_file();
}

void item_addelement(struct item* item)
{
    if (items_first_element == NULL)
        items_first_element = item;
    else
    {
        struct item* temp = items_first_element;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = item;
        item->prev = temp;
    }
}

void item_addelement_to_list()
{
    system("cls");

    struct item* item;
    int size = sizeof(struct item);
    item = (struct item*)malloc(sizeof(struct item));
    item->next = NULL;
    item->prev = NULL;

    struct item* temp = items_first_element;

    printf("��������� ������ ������ ������������, � ������:\n");
    gets_s(item->ID);

    printf("������� ID ����:");
    gets_s(item->ID);

    printf("������� ID ������� ����:");
    gets_s(item->Client_ID);

    printf("������� �������� ����:");
    gets_s(item->item_name);

    printf("������� ��������� ��������� ����:");
    gets_s(item->cost);

    printf("������� �����, �������� ��� �����:");
    gets_s(item->deposit_sum);

    printf("������� ���� ����������� ����:");
    gets_s(item->deposit_start_date);

    printf("������� ���� ��������� �������� ����:");
    gets_s(item->deposit_end_date);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = item;
    item->prev = temp;

    write_item_file();
}

void read_item_file()
{
    FILE* fitems;
    char buffer[MAXARR];

    fitems = fopen("Items.txt", "r");
    if (!fitems)
    {
        printf("���� �� ������. ����� �� ���������");
        return;
    }
    while (fgets(buffer, MAXARR, fitems) != NULL)
    {
        struct item* item;
        int size = sizeof(struct item);
        item = (struct item*)malloc(sizeof(struct item));
        item->next = NULL;
        item->prev = NULL;

        int i = 0;
        int j = 0;

        while (buffer[i] != '\n')
        {
            while (buffer[i] != ';')
            {
                item->ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->Client_ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->Client_ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->item_name[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->item_name[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->cost[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->cost[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->deposit_sum[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->deposit_sum[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->deposit_start_date[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->deposit_start_date[j] = '\0';
            j = 0;

            while (buffer[i] != '\0')
            {
                item->deposit_end_date[j] = buffer[i];
                if (buffer[i + 1] == '\0' || buffer[i + 1] == '\n')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j++;
            item->deposit_end_date[j] = '\0';

            if (buffer[i] == '\0')
            {
                break;
            }
        }

        item_addelement(item);
    }
    fclose(fitems);
}

void write_item_file()
{
    FILE* fitems;
    char fbuffer[MAXARR];

    fitems = fopen("Items.txt", "w");
    if (!fitems)
    {
        printf("���� �� ������. ����� �� ���������");
        return;
    }

    int i = 0;
    int j = 0;

    struct item* temp = items_first_element;

    while (temp != NULL)
    {
        while (fbuffer[i] != '\n')
        {
            while (temp->ID[j] != '\0')
            {
                fbuffer[i] = temp->ID[j];
                if (temp->ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->Client_ID[j] != '\0')
            {
                fbuffer[i] = temp->Client_ID[j];
                if (temp->Client_ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->item_name[j] != '\0')
            {
                fbuffer[i] = temp->item_name[j];
                if (temp->item_name[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->cost[j] != '\0')
            {
                fbuffer[i] = temp->cost[j];
                if (temp->cost[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_sum[j] != '\0')
            {
                fbuffer[i] = temp->deposit_sum[j];
                if (temp->deposit_sum[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_start_date[j] != '\0')
            {
                fbuffer[i] = temp->deposit_start_date[j];
                if (temp->deposit_start_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_end_date[j] != '\0')
            {
                fbuffer[i] = temp->deposit_end_date[j];
                if (temp->deposit_end_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j = 0;
            fbuffer[i] = '\n';
        }
        temp = temp->next;
        i++;
    }
    i--;
    fbuffer[i] = '\0';
    fputs(fbuffer, fitems);
    fclose(fitems);
}

void read_item_list()
{
    system("cls");
    struct item* temp = items_first_element;
    while (temp != NULL)
    {
        printf("%s\n", temp->ID);
        printf("%s\n", temp->Client_ID);
        printf("%s\n", temp->item_name);
        printf("%s\n", temp->cost);
        printf("%s\n", temp->deposit_sum);
        printf("%s\n", temp->deposit_start_date);
        printf("%s\n\n", temp->deposit_end_date);
        temp = temp->next;
    }
    system("pause");
}

void delete_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items)
{
    int check = 0;

    struct item* prev = nullptr, * next = nullptr;
    struct item* temp = items_first_element;
    if (variant == 1)
    {
        printf("������� ID ����, ������� ���� �������\n");
        scanf("%d", &check);

        while (temp != NULL)
        {
            int ID = atoi(temp->ID);
            if (ID == check)
            {
                int_pawnshop_profit += atoi(temp->deposit_sum);
                prev = temp->prev; // ����, �������������� lst
                next = temp->next; // ����, ��������� �� lst
                if (prev != NULL)
                    prev->next = temp->next; // ������������ ���������
                if (next != NULL)
                    next->prev = temp->prev; // ������������ ���������
                free(temp); // ����������� ������ ���������� ��������
                break;
            }
            temp = temp->next;
        }

        write_item_file();
    }
    else
    {
        printf("������� ID ����, ������� ���� �������\n");
        scanf("%d", &check);

        while (temp != NULL)
        {
            int ID = atoi(temp->ID);
            if (ID == check)
            {
                int_pawnshop_profit += atoi(temp->cost);
                int_sum_of_items -= atoi(temp->cost);
                prev = temp->prev; // ����, �������������� lst
                next = temp->next; // ����, ��������� �� lst
                if (prev != NULL)
                    prev->next = temp->next; // ������������ ���������
                if (next != NULL)
                    next->prev = temp->prev; // ������������ ���������
                free(temp); // ����������� ������ ���������� ��������
                break;
            }
            temp = temp->next;
        }

        write_item_file();
    }
}

void reduct_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items)
{
    int check = 0;
    struct item* temp = items_first_element;
    int ID = atoi(temp->ID);

    printf("������� ID �������, �������� ���� �������������\n");
    scanf("%d", &check);

    if (variant == 1)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("������� ��������� ��������� ���������:");
                scanf("%s", temp->cost);
                int_sum_of_items += atoi(temp->cost);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }

    if (variant == 2)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("������� ���� ��������� �������� ����:");
                scanf("%s", temp->deposit_end_date);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }

    if (variant == 3)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("������� ��������� ����� ������:");
                scanf("%s", temp->deposit_sum);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }
}



void pawnshop_profit()
{
    system("cls");

    struct item* temp = items_first_element;

    int int_pawnshop_profit = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->deposit_sum);
        int_pawnshop_profit += cost;
        temp = temp->next;
    }

    printf("������� �������� ����� %d ������.\n", int_pawnshop_profit);
    system("pause");
}

void i_sum_of_items()
{
    struct item* temp = items_first_element;

    int sum_of_items = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->cost);
        sum_of_items += cost;
        temp = temp->next;
    }
}

void sum_of_items()
{
    system("cls");

    struct item* temp = items_first_element;

    int sum_of_items = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->cost);
        sum_of_items += cost;
        temp = temp->next;
    }

    printf("��������� ��������� ���� �������� ����� ����� %d ������.\n", sum_of_items);
    system("pause");
}

void print_menu()
{
    system("cls");  // ������� �����
    printf("������������.\n�� ���������� � ���� �������_�����.\n����������, �������� ��������� ������ ����:\n\n");
    printf("1. ���������� ����.\n");
    printf("2. ������ �������� �����.\n");
    printf("3. �������� ������� ��������.\n");
    printf("4. ������.\n");
    printf("5. ����� �� ���������.\n");
    printf(">");
}

void print_menu_1()
{
    system("cls");  // ������� �����
    printf("������ ����� ���� 1:\n");
    printf("1. �������� ��������.\n");
    printf("2. ���������� ������ �������.\n");
    printf("3. �������� �������.\n");
    printf("4. �������������� �������.\n");
    printf("5. ������.\n");
    printf("6. ��������� � ����.\n");
    printf(">");
}

void print_menu_2()
{
    system("cls");  // ������� �����
    printf("������ ����� ���� 2:\n");
    printf("1. �������� ������ �����.\n");
    printf("2. ���������� ����.\n");
    printf("3. �������� ����.\n");
    printf("4. �������������� ����.\n");
    printf("5. ������.\n");
    printf("6. ��������� � ����.\n");
    printf(">");
}

void print_menu_2_1()
{
    system("cls");  // ������� �����
    printf("������ �������� ���� 2.1:\n");
    printf("1. ���� ����������.\n");
    printf("2. � ���� ���� ���� �������� � �� �������� �������.\n");
    printf("3. ������.\n");
    printf("4. ���������.\n");
    printf(">");
}

void print_menu_2_2()
{
    system("cls");  // ������� �����
    printf("������ �������� ���� 2.2:\n");
    printf("1. �������������� ����.\n");
    printf("2. �������������� ����� ��������.\n");
    printf("3. �������������� ������.\n");
    printf("4. ������.\n");
    printf("5. ���������.\n");
    printf(">");
}

void print_menu_3()
{
    system("cls");  // ������� �����
    printf("������ ����� ���� 4:\n");
    printf("1. ������� ��������.\n");
    printf("2. ������� ����� ���� ����� ��������.\n");
    printf("3. ������.\n");
    printf("4. ��������� � ����.\n");
    printf(">");
}

int get_variant(int count)
{
    int variant;
    char s[100]; // ������ ��� ���������� �������� ������
    scanf("%s", s); // ��������� ������

    // ���� ���� �����������, �������� �� ���� � ������ ��������� ���
    while (scanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        printf("������� ��������� ����� ����. ��������� ����: "); // ������� ��������� �� ������
        scanf("%s", s); // ��������� ������ ��������
    }

    return variant;
}