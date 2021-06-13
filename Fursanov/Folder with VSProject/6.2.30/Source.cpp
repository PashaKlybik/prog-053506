#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    char* brand = (char*)malloc(100 * sizeof(char));
    char* year = (char*)malloc(100 * sizeof(char));
    char* engine_capacity = (char*)malloc(100 * sizeof(char));
    char* mileage = (char*)malloc(100 * sizeof(char));
    char* condition = (char*)malloc(100 * sizeof(char));
    char* price = (char*)malloc(100 * sizeof(char));
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct Node1
{
    char* FIO = (char*)malloc(100 * sizeof(char));
    char* contacts = (char*)malloc(100 * sizeof(char));
    char* desired_brand = (char*)malloc(100 * sizeof(char));
    char* year = (char*)malloc(100 * sizeof(char));
    char* engine_capacity = (char*)malloc(100 * sizeof(char));
    char* mileage = (char*)malloc(100 * sizeof(char));
    char* condition = (char*)malloc(100 * sizeof(char));
    char* finance = (char*)malloc(100 * sizeof(char));
    struct Node1* next;
    struct Node1* previous;
} Node1;

void push(Node** head, char* brand, char* year, char* engine_capacity, char* mileage, char* condition);
void push1(Node1** head, char* FIO, char* contacts, char* desired_brand, char* year, char* engine_capacity, char* mileage, char* finance);

void printLinkedList(Node* head, int com);
void printLinkedList1(Node1* head, int com, Node* head1);

void search2(Node1* head1, Node* head, Node* headtmp);

void interfase(Node* head1, Node1* head)
{
    int a = 0;
    while (1)
    {

        {
            system("cls");
            puts("1.база клиентов");
            puts("2.база авто");
            puts("3.доход компании");
            puts("esc-выход");
        }

        a = _getch();

        if (a == 49)printLinkedList1(head, 0, head1);

        else if (a == 50)printLinkedList(head1, 0);

        else if (a == 51) { system("cls"); search2(head, head1, head1); while(_getch()!=27); }

        else if (a == 27)return;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Node1* head = NULL;

    push1(&head, (char*)"Попов Алексей Михайлович", (char*)"375-88-743-93-57", (char*)"Subaru", (char*)"2088", (char*)"5", (char*)"500", (char*)"10000");
    push1(&head, (char*)"Мармеладова Инна Васильевна", (char*)"375-29-972-01-97", (char*)"Volks Wagen", (char*)"2020", (char*)"6", (char*)"1000", (char*)"7000");
    push1(&head, (char*)"Самойлов Николай Ефимович", (char*)"375-44-666-14-88", (char*)"Jeep", (char*)"1945", (char*)"8", (char*)"3440", (char*)"8500");
    push1(&head, (char*)"Еремеенко Федосий Абдулович", (char*)"375-29-648-92-64", (char*)"Peugeot", (char*)"1960", (char*)"88", (char*)"835", (char*)"10700");

    Node* head1 = NULL;
    push(&head1, (char*)"Subaru", (char*)"2088", (char*)"5", (char*)"250", (char*)"прямо с завода");
    push(&head1, (char*)"Subaru", (char*)"2020", (char*)"6", (char*)"750", (char*)"немного побито правое крыло");
    push(&head1, (char*)"Volks Wagen", (char*)"1945", (char*)"8", (char*)"400", (char*)"облезла краска на бампере");
    push(&head1, (char*)"Volks Wagen", (char*)"1960", (char*)"88", (char*)"700", (char*)"почти новая, состояние хорошее");
    push(&head1, (char*)"Jeep", (char*)"2008", (char*)"34", (char*)"500", (char*)"скручены колёса");
    push(&head1, (char*)"Jeep", (char*)"1020", (char*)"93", (char*)"3000", (char*)"отсутствуют диски");
    push(&head1, (char*)"Peugeot", (char*)"2000", (char*)"100", (char*)"900", (char*)"разбиты фары");
    push(&head1, (char*)"Peugeot", (char*)"1960", (char*)"171", (char*)"1000", (char*)"нет видимых дефектов");

    interfase(head1, head);
    return 0;
}
