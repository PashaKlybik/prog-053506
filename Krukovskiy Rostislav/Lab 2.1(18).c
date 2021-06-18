//task 2.1 Var 18

#ifndef PROG_H
#define PROG_H
#define MAX 2147483647
// структура тарифов
struct Parameters
{
  int minutes_in_the_network;
  int minutes_outside_the_network;
  int internet;
  char name[20];
};

// инициализация тарифов сервиса
const struct Parameters ComfortS = {120, 60, 1, "Comfort S"};
const struct Parameters ComfortM = {300, 120, 10, "Comfort M"};
const struct Parameters ComfortL = {500, 300, 25, "Comfort L"};
const struct Parameters ComfortXL = {1000, 1000, 50, "Comfort Xl"};
const struct Parameters NoLimit = {2000, 500, MAX, "No Limit"};

struct Parameters user_parameters;
// создание массива тарифов, для удобной работы с ними
struct Parameters tariffs[5] = {ComfortS, ComfortM, ComfortL, ComfortXL, NoLimit};

// ввод пользователем номера желаемой функции
void Input();
// расчет подходящих таривоф
char *Calculation(struct Parameters usr_parameters);
// вывод существующих тарифов с описанием
void Information();
// контактная информация компании
void Contacts();
// пользовательское меню выбора
void Menu();
void Repeater();
void Start();

// ввод пользователем номера желаемой функции
void Input()
{
  printf("Enter the tariff parameters:\n");
  printf("Number of minutes inside the network\n");
  scanf("%d", &user_parameters.minutes_in_the_network);
  printf("Number of minutes outside the network\n");
  scanf("%d", &user_parameters.minutes_outside_the_network);
  printf("Number of GB of Internet\n");
  scanf("%d", &user_parameters.internet);
}

// расчет подходящих таривоф
char *Calculation(struct Parameters usr_parameters)
{
  if (usr_parameters.internet == 0 && usr_parameters.minutes_in_the_network == 0 && usr_parameters.minutes_outside_the_network == 0)
  {
    Input();
  }
  for (size_t i = 0; i < 5; ++i)
  {
    if (usr_parameters.minutes_in_the_network <= tariffs[i].minutes_in_the_network &&
        usr_parameters.minutes_outside_the_network <= tariffs[i].minutes_outside_the_network &&
        usr_parameters.internet <= tariffs[i].internet)
      return tariffs[i].name;
  }
  return tariffs[4].name;
}

// вывод существующих тарифов с описанием
void Information()
{
  for (size_t i = 0; i < 5; ++i)
  {
    printf("%s\n", tariffs[i].name);
    printf("Number of minutes within the network:%d\n", tariffs[i].minutes_in_the_network);
    printf("Number of minutes offline:%d\n", tariffs[i].minutes_outside_the_network);
    printf("Number of GB of Internet:%d\n\n", tariffs[i].internet);
  }
}

// контактная информация компании
void Contacts()
{
  printf("\ncontact information:\n\n"
         "150 single contact center number (free call from all networks of operators in Belarus)\n"
         "7100 - (from mobile A1 - 0.03 rubles.)\n"
         "Roaming by phone +375 29 6 000 150 (payment according to roaming rates)\n"
         "E-mail address for servicing individuals: 150@A1.by\n"
         "E-mail address for processing applications of legal entities : legal@A1.by\n"
         "E-mail address for consultations on servicing legal entities : corp@A1.by\n"
         "E-mail address of the office : info@A1.by\n\n");
}

// пользовательское меню выбора
void Menu()
{
  printf("To select an operation, enter a number:\n\n"
         "1: Input parameters\n"
         "2: Calculation of the optimal tariff \n"
         "3: Information about all tariffs \n"
         "4: Feedback\n"
         "5: Exit the program\n");
}

void Start()
{
  Menu();
  int value;
  if (!scanf("%d", &value))
  {
    printf("error\n");
    exit(1);
  };
  switch (value)
  {
  case 1:
    Input();
    break;
  case 2:
    printf("%s", Calculation(user_parameters));
    printf("\n");
    break;
  case 3:
    Information();
    break;
  case 4:
    Contacts();
    break;
  case 5:
    exit(1);
    break;
  default:
    printf("Option not selected\n");
  }
  Repeater();
}

void Repeater()
{
  printf("Would you like to continue?: yes:1/no:2 \n");
  int ans;
  if (!scanf("%d", &ans))
  {
    printf("error\n");
    exit(1);
  }
  if (ans == 1)
  {
    Start();
  }
  else 
  {
    exit(0);
  }
}

#endif

------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "program.h"

int main()
{
  Start();
  return   0;
}