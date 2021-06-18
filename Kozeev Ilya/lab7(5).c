-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h----------- 
#ifndef LAB_7
#define LAB_7

#include <stdlib.h>
#include <stdio.h>
#include "Date.h"




#endif
-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h-----------lab7.h----------- 
----------------------------------------------------------------------------------------------------------------------------------
-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c----------- 
#include <stdlib.h>
#include <stdio.h>
#include "Date.h"
#include "Task.h"


int main() {
    Task *new = getTask();
    printTask(new);

    deleteTask(new);

    return 0;
}
-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------lab7.c-----------
----------------------------------------------------------------------------------------------------------------------------------
-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h-----------
#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
}Month;

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

int getValidInt(int minValue, int maxValue);
int getMaxDay(Month month);
int rewriteDate(Date *toRewrite);
Date* getDate();
int difDate(Date* start, Date* end);
int compareDate(Date *first, Date *second);
int printDate(Date *date);
void deleteDate(Date *date);
#endif
-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h-----------date.h----------- 
----------------------------------------------------------------------------------------------------------------------------------
-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------
#include "Date.h"

/*These functiion can be used for day, month and year*/
int getValidInt(int minValue, int maxValue) {
    int temp;
    char goodCheck;

    while(!scanf("%d", &temp) || temp < minValue || temp > maxValue ||
          (scanf("%c", &goodCheck) && goodCheck != '\n')) {
        printf("Wrong input!\nDate must be >= %d && <= %d.\n"
               "Please, try again: ",minValue, maxValue);
        fflush(stdin);
    }

    return temp;
}

int getMaxDay(Month month) {
    if (month < 0 || month > 12) return INT_MIN;

    if (month == February) return 28;

    if (month == April || month == June || month == September ||
        month == November)
        return 30;

    return 31;
}

int rewriteDate(Date *toRewrite) {
    char temp = 0;
    
    if (!toRewrite) return 0;

    printf("\nEnter year(2021 - 3000): ");
    toRewrite->year = getValidInt(2021, 3000);

    printf("\nEnter month(1 - 12): ");
    toRewrite->month = getValidInt(1, 12);

    temp = getMaxDay(toRewrite->month);
    if (toRewrite->month == February && toRewrite->year % 4) ++temp;
    
    printf("\nEnter day(1 - %d): ", temp);
    toRewrite->day = getValidInt(1, temp);

    return 1;
}

Date* getDate() {
    Date *received = NULL;

    received = (Date*)malloc(sizeof(Date));
    if (!received) {
        printf("\nError in allocation memory in \"Date\"\n");
        exit(1);
    }

    rewriteDate(received);

    return received;
}

/*It returns days*/
int difDate(Date* start, Date* end) {
    int diff = 0;
    int i = 0;

    if (!start || !end) {
        printf("\nError, \"Date\" is missing\n");
        return INT_MIN;
    }

    if (!(start->year % 4) && start->month <= February)
        ++diff;

    for (i = start->year + 1; i < end->year; ++i) {
        if (i % 4 == 0) ++diff;
    }

    if (!(end->year % 4) &&
        (end->month > February ||
        (end->month == February && end->day == 29)))
        ++diff;
     
    diff += (end->year - end->year) * 365 +
            getMaxDay(end->month) - getMaxDay(end->month +
            end->day - start->day);
    
    return diff;
}

int compareDate(Date *first, Date *second) {
    if (first->year < second->year) return -1;
    else if (first->year > second->year)
        return 1;

    if (first->month < second->month) return -1;
    else if (first->month > second->month)
        return 1;

    if (first->day < second->day) return -1;
    else if (first->day > second->day)
        return 1;

    return 0;
}

int printDate(Date *date) {
    if (!date) return 0;

    printf("%02d.%02d.%d", date->day, date->month, date->year);

    return 1;
}

void deleteDate(Date *date) { free(date); }

/*typedef enum DayInMonth {
    January = 31,
    February = 28,
    March = 31,
    April = 30,
    May = 31,
    June = 30,
    July = 31,
    August = 31,
    September = 30,
    October = 31,
    November = 30,
    December = 31,
}DayInMonth;*/
-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------date.c-----------
----------------------------------------------------------------------------------------------------------------------------------
-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------
#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"

typedef struct Task{
    Date *startTaskTime;
    Date *endTaskTime;

    char *taskName;

    struct Task *nextTask;
    struct Task *prevTask; 

}Task;

char* resizeLine(char *line);
char* getWord();

Task *getTask();
void deleteTask(Task *task);
int printTask(Task *task);

#endif
-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------task.h-----------
----------------------------------------------------------------------------------------------------------------------------------
-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------
#include "Task.h"

char* resizeLine(char *line) {
    char *tempLine = NULL;
    unsigned int length = strlen(line);

    tempLine = (char*)realloc(line, (length + 1) * sizeof(char));
    if (!tempLine) return line;

    tempLine[length] = '\0';

    return tempLine;
}

char* getWord() {
    char *tempLine = (char*)malloc(256 * sizeof(char));
    if (!tempLine) return NULL;

    scanf("%[^\n]255s", tempLine);
    scanf("%*c");
    tempLine = resizeLine(tempLine);
    return tempLine;
}

Task *getTask() {
    Task *task = (Task*)malloc(sizeof(Task));
    if (!task) {
        printf("\nError in memory allocation in \"Task\"\n");
        exit(1);
    }
    
    printf("\nEnter task name: ");
    task->taskName = getWord();

    printf("\nEnter starting time: ");
    task->startTaskTime = getDate();

    printf("\nEnter ending time: ");
    task->endTaskTime = getDate();
    
    while (difDate(task->endTaskTime, task->startTaskTime) <= 0) {
        printf("\nWrong input. End date must be later then start date.\n"
               "Enter ending time again");
        rewriteDate(task->endTaskTime);
    }

    task->nextTask = task->prevTask = NULL;

    return task;
}

void deleteTask(Task *task) {
    free(task->taskName);
    deleteDate(task->startTaskTime);
    deleteDate(task->endTaskTime);
    free(task);
}

int printTask(Task *task) {
    if (!task) return 0;

    printf("\nTask name: %s", task->taskName);

    printf("\nStarting time: ");
    printDate(task->startTaskTime);

    printf("\nEnding time: ");
    printDate(task->endTaskTime);

    return 1;
}
-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------task.c-----------
----------------------------------------------------------------------------------------------------------------------------------
-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h----------
  
#ifndef LISTOFTASKS_H
#define LISTOFTASKS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"

typedef struct ListOfTasks {
    Task *head;
    Task *tail;

    unsigned int length;

}ListOfTasks;

ListOfTasks* newListOfTasks();
void addTaskEnd(ListOfTasks *list, Task *newTask);
void addTaskFront(ListOfTasks *list, Task *newTask);
void removeTaskEnd(ListOfTasks *list);
void removeTaskFront(ListOfTasks *list);
Task *deleteTaskInList(ListOfTasks *list, const char *nameToSearch);
void deleteListOfTasks(ListOfTasks *list);
int printListOfTasks(ListOfTasks *list);

#endif
-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h-----------ListOfTasks.h----------
----------------------------------------------------------------------------------------------------------------------------------
-----------ListOfTasks.c-----------ListOfTasks.c-----------ListOfTasks.c-----------ListOfTasks.c-----------ListOfTasks.c----------
#include "ListOfTasks.h"

ListOfTasks* newListOfTasks() {
    ListOfTasks *list = (ListOfTasks*)malloc(sizeof(ListOfTasks));

    if (!list) {
        printf("\nError in memory allocation in \"ListOfTasks\"\n");
        exit(1);
    }

    list->head = list->tail = NULL;
    list->length = 0;

    return list;
}

void addTask(ListOfTasks *list, Task *newTask) {
    Task *temp = NULL;

    if (!list || !newTask) return;

    temp = list->head;

    if (compareDate(newTask->startTaskTime, temp->endTaskTime) == -1) {
        addTaskFront(list, newTask);
    }

    while (temp) {
        if (compareDate(newTask->startTaskTime, temp->endTaskTime) != -1) {
            if (temp == list->head) {
                addTaskFront(list, newTask);
            } else if (temp == list->tail) {
                addTaskEnd(list, newTask);
            } else {
                newTask->nextTask = temp->nextTask;
                newTask->prevTask = temp;
                temp->nextTask->prevTask = newTask;
                temp->nextTask = newTask;
            }
            return;
        }

        temp = temp->nextTask;
    }      
}

void addTaskEnd(ListOfTasks *list, Task *newTask) {
    if (!list || !newTask) return;

    if (!list->head) {
        list->head = newTask;
    } else {
        newTask->prevTask = list->tail;
        list->tail->nextTask = newTask;
    }

    ++list->length;
    list->tail = newTask;
}

void addTaskFront(ListOfTasks *list, Task *newTask) {
    if (!list || !newTask) return;

    if (!list->head) {
        list->tail = newTask;
    } else {
        newTask->nextTask = list->head;
        list->head->prevTask = newTask;
    }


    ++list->length;
    list->head = newTask;
}

void removeTaskEnd(ListOfTasks *list) {
    Task *oldTail = NULL;
    
    if (!list || !list->tail) return;

    oldTail = list->tail;
    list->tail = list->tail->prevTask; 

    if (!list->tail) list->head = NULL;
    else
        list->tail->nextTask = oldTail->nextTask;

    --list->length;
    free(oldTail);
}

void removeTaskFront(ListOfTasks *list) {
    Task *oldHead = NULL;

    if (!list || !list->head) return;

    oldHead = list->head;
    list->head = list->head->nextTask;

    if (!list->head) list->tail = NULL;
    else
        list->head->prevTask = oldHead->prevTask;

    --list->length;
    free(oldHead);
}

int searchTask(ListOfTasks *list, const char *nameToSearch) {
    Task *temp = NULL;
    if (!list || !nameToSearch) return 0;

    temp = list->head;

    while (temp) {
        if (!strcmp(temp->taskName, nameToSearch)) {
            printTask(temp);
            return 1;
        }
        temp = temp->nextTask;
    }

    return 0;
}

Task *deleteTaskInList(ListOfTasks *list, const char *nameToSearch) {
    Task *temp = NULL;

    if (!list || !list->head || !nameToSearch) return NULL;

    temp = list->head;

    while (temp) {
        if (!strcmp(temp->taskName, nameToSearch)) {
            printTask(temp);
            
            if (temp == list->head) {
                list->head = list->head->nextTask;
                list->head->prevTask = temp->prevTask;
            } else if (temp == list->tail) {
                list->tail = list->tail->prevTask;
                list->tail->nextTask = temp->nextTask;
            } else {
                temp->prevTask->nextTask = temp->nextTask;
                temp->nextTask->prevTask = temp->prevTask; 
            }
            
            temp->nextTask = temp->prevTask = NULL;
            return temp;
        }
        temp = temp->nextTask;
    }
    return NULL;
}

void deleteListOfTasks(ListOfTasks *list) {
    Task *temp = NULL;

    if (!list) return;

    temp = list->head;

    while (list->head) {
        temp = list->head->nextTask;
        deleteTask(list->head);
        list->head = temp;
    }

    free(list);
}

int printListOfTasks(ListOfTasks *list) {
    Task *temp = NULL;

    if (!list) return 0;

    temp = list->head;
    
    printf("\nCurrent tasks");
    while (temp) {
        printTask(list->head);
        temp = temp->nextTask;
    } 

    return 1;
}