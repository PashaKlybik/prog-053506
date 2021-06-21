#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

typedef struct barcode barcode;
typedef barcode* BCode;

typedef struct barcode
{
    int key;
    char* name;
    int price;
    BCode next;
    BCode prev;
} barcode;

typedef struct creditcard creditcard;
typedef creditcard* CCard;

typedef struct creditcard
{
    int numofcard;
    int sale;
    CCard next;
    CCard prev;
} creditcard;

int ReadNumber() 
{
    int number;
    while (scanf("%d", &number) != 1 || number <= 0) 
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    return number;
}

int ReadBarCode() 
{
    int number;
    printf("Write 6-digit barcode: ");
    while (scanf("%d", &number) != 1 || number <= 99999 || number >= 1000000) 
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    return number;
}

int ReadNumProduct() 
{
    int number;
    printf("\nWrite num of product: ");
    while (scanf("%d", &number) != 1 || number < 0 || number >= 1000000) 
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    if (number == 0)
        return -1;
    return number;
}

int ReadNumOfCard() 
{
    int number;
    printf("Write 4-digit card number: ");
    while (scanf("%d", &number) != 1 || number <= 999 || number >= 10000) 
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    return number;
}

int Purchase(BCode headbarcode) 
{
    int sum = 0;
    int choiceproduct = 1;
    FILE* outputHistory = fopen("history.txt", "a");
    if (outputHistory == NULL) 
    {
        printf("File is not found");
        exit(0);
    }
    printf("Do you want to add new item? Y-1/N-0\n");
    int choice;
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0))
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    if (choice == 1)
        choiceproduct = 1;
    else
        choiceproduct = 0;
    while (choiceproduct) 
    {
        int thisbarcode;
        thisbarcode = ReadBarCode();
        BCode current = headbarcode;
        while (current != NULL) 
        {
            if (current->key == thisbarcode) 
                break;
            current = current->next;
        }
        if (current == NULL) 
            printf("\nThis item doesn't exist");
        else 
        {
            int numproduct;
            numproduct = ReadNumProduct();
            if (numproduct == -1) 
                continue;
            else 
            {
                sum += (current->price) * numproduct;
                fprintf(outputHistory, "%s x %d = %d\n", current->name, numproduct, (current->price) * numproduct);
            }
        }
        printf("\n\nDo you want to add new item? Y-1/N-0\n");
        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0))
        {
            printf("Incorrect input! Try again\n");
            while (getchar() != '\n')
                ;
        }
        if (choice == 1)
            choiceproduct = 1;
        else
            choiceproduct = 0;
    }
    fclose(outputHistory);
    return sum;
}

int UseCreditCard(int sum, CCard headcreditcard) 
{
    if (sum != 0) 
    {
        FILE* outputHistory = fopen("history.txt", "a");
        if (outputHistory == NULL) {
            printf("File is not found");
            exit(0);
        }
        printf("Have you some credit card? Y-1/N-0\n");
        int choice;
        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0))
        {
            printf("Incorrect input! Try again\n");
            while (getchar() != '\n')
                ;
        }
        if (choice == 1) 
        {
            int j = 0;
            int numofcard = ReadNumOfCard();
            printf("\n");
            CCard current = headcreditcard;
            while (current != NULL) 
            {
                if (numofcard == current->numofcard) break;
                current = current->next;
            }
            if (current == NULL) 
                printf("\nThe card with this number doesn't exist\n");
            else 
            {
                sum = (double)sum * (1 - (double)current->sale / 100.0);
                fprintf(outputHistory, "DISCOUNT %d%%\n", current->sale);
            }
        }
        fprintf(outputHistory, "FINAL SUM %d\n", sum);
        fprintf(outputHistory, "end buyer\n");
        fclose(outputHistory);
    }
    return sum;
}

BCode AddNewBarCode(BCode head)
{
    int key, price;
    char* name = (char*)malloc(sizeof(char) * 80);
    if (name == NULL) 
    {
        printf("Can't allocate memory");
        exit(0);
    }
    key = ReadBarCode();
    printf("\nName: ");
    while (scanf("%s", name) != 1) 
    {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n')
            ;
    }
    printf("Price: ");
    price = ReadNumber();
    if (head == NULL) 
    {
        head = (barcode*)malloc(sizeof(barcode));
        if (head == NULL) 
        {
            printf("Can't allocate memory");
            exit(0);
        }
        head->next = NULL;
        head->prev = NULL;
        head->key = key;
        head->name = name;
        head->price = price;
    }
    else 
    {
        BCode current = (barcode*)malloc(sizeof(barcode));
        if (current == NULL) 
        {
            printf("Can't allocate memory");
            exit(0);
        }
        current->next = head;
        current->prev = NULL;
        head->prev = current;
        head = current;
        current->key = key;
        current->name = name;
        current->price = price;
    }
    return head;
}

void ShowBarCode(BCode head)
{
    BCode current = head;
    if (current == NULL)
    {
        printf("List of barcodes is empty\n");
    }
    else 
    {
        while (current != NULL)
        {
            printf("%d %s price: %d\n", current->key, current->name, current->price);
            current = current->next;
        }
    }
}

BCode DeleteBarCode(BCode head) 
{
    ShowBarCode(head);
    if (head == NULL) 
        return head;
    int deletekey = ReadBarCode();
    BCode current = head;
    while (current != NULL && current->key != deletekey) 
        current = current->next;
    if (current == NULL) 
    {
        printf("\nThis code doesn't exist\n");
        return head;
    }
    else if (current == head && head->next == NULL) 
    {
        free(current->name);
        head = NULL;
    }
    else if (current == head) 
    {
        free(current->name);
        head = head->next;
        head->prev = NULL;
    }
    else 
    {
        free(current->name);
        if (current->prev != NULL) 
            current->prev->next = current->next;
        if (current->next != NULL) 
            current->next->prev = current->prev;
    }
    printf("\nOK\n");
    return head;
}

CCard AddNewCreditCard(CCard head) {
    int numofcard, sale;
    numofcard = ReadNumOfCard();
    printf("\nSale: ");
    while (scanf("%d", &sale) != 1 || sale < 0) {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n') {
        }
    }
    if (head == NULL) {
        head = (creditcard*)malloc(sizeof(creditcard));
        if (head == NULL) {
            printf("Can't allocate memory");
            exit(0);
        }
        head->next = NULL;
        head->prev = NULL;
        head->sale = sale;
        head->numofcard = numofcard;
    }
    else {
        int alreadyhave = 0;
        CCard newcurrent = head;
        while (newcurrent != NULL) {
            if (newcurrent->numofcard == numofcard) {
                alreadyhave = 1;
                break;
            }
            newcurrent = newcurrent->next;
        }
        if (alreadyhave == 0)
        {
            CCard current = (creditcard*)malloc(sizeof(creditcard));
            if (current == NULL) {
                printf("Can't allocate memory");
                exit(0);
            }
            current->next = head;
            current->prev = NULL;
            head->prev = current;
            head = current;
            current->sale = sale;
            current->numofcard = numofcard;
        }
    }
    return head;
}

void ShowCreditCard(CCard head) {
    CCard current = head;
    if (current == NULL) {
        printf("List of credit cards is empty\n");
    }
    else {
        while (current != NULL) {
            printf("Card %d, discount: %d\n", current->numofcard, current->sale);
            current = current->next;
        }
    }

}

CCard DeleteCreditCard(CCard head) {
    ShowCreditCard(head);
    if (head == NULL) {
        return head;
    }
    int deletecard = ReadNumOfCard();
    CCard current = head;
    while (current != NULL && current->numofcard != deletecard) {
        current = current->next;
    }
    if (current == NULL) {
        printf("\nThis card doesn't exist\n");
        return head;
    }
    else if (current == head && head->next == NULL) {
        head = NULL;
    }
    else if (current == head) {
        head = head->next;
        head->prev = NULL;
    }
    else {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }
    printf("\nOK\n");
    return head;
}

int main() 
{
    BCode headBC = NULL;
    CCard headCC = NULL;
    int choice, sum = 0;
    FILE* outputBarCode;
    FILE* outputCreditCard;
    do {
        system("cls");
        printf("1. Add new barcode\n");
        printf("2. Show barcode\n");
        printf("3. Delete barcode\n");
        printf("--------------------------------\n");
        printf("4. Add new credit card\n");
        printf("5. Show credit cards\n");
        printf("6. Delete credit card\n");
        printf("--------------------------------\n");
        printf("0. Exit\n\n");
        printf("Enter item: ");
        choice = ReadNumber();
        while (choice < 1 || choice > 12) 
        {
            printf("Wrong number");
            choice = ReadNumber();
        }
        system("cls");
        switch (choice) 
        {
        case 1:
            headBC = AddNewBarCode(headBC);
            break;
        case 2:
            ShowBarCode(headBC);
            break;
        case 3:
            headBC = DeleteBarCode(headBC);
            break;
        case 4:
            headCC = AddNewCreditCard(headCC);
            break;
        case 5:
            ShowCreditCard(headCC);
            break;
        case 6:
            headCC = DeleteCreditCard(headCC);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid input");
            break;
        }
    } while (1);
    return 0;
}