#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Month {
        JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
        JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
} Month;

typedef struct Date {
        char day;
        Month month;
} Date;

_Bool checkDate(Date date) {
        //Check for currend month 
        if(date.month > 12) {
                return 0;
        }
        //Check for current day;
        if(
                date.month == APRIL ||
                date.month == JUNE ||
                date.month == SEPTEMBER ||
                date.month == NOVEMBER
                ) {
                if(date.day > 30) {
                        return 0;
                }
        } else if(date.month == FEBRUARY) {
                if(date.day > 29) {
                        return 0;
                }
        } else {
                if(date.day > 31) {
                        return 0;
                }
        }
        return 1;
}

Date setDate(char day, Month month) {
        Date date;
        date.day = day;
        date.month = month;
        return date;
}

char* dateToString(Date date) {
        char* output = (char*)malloc(6);
        sprintf(output, "%02d:%02d", date.day, date.month);
        return output;
}

Date dateFromString(char* input) {
        Date date = setDate(0, 0);
        date.day += input[0] * 10 - 480;
        date.day += input[1] - 48;
        date.month += input[3] * 10 - 480;
        date.month += input[4] - 48;
        if(checkDate(date) == 1) {
                return date;
        } else {
                return setDate(0, 1);
        }
}

typedef enum Zodiac {
        ARIES = 1,
        TAURUS,
        GEMINI,
        CANCER,
        LEO,
        VIRGO,
        LIBRA,
        SCORPIO,
        SAGITTARIUS,
        CAPRICORN,
        AQUARIUS,
        PISCES
} Zodiac;

Zodiac getZodiac(Date date) {
        if((date.month == MARCH && date.day >= 21) ||
                (date.month == APRIL && date.day <= 20)) {
                return ARIES;
        } else if((date.month == APRIL && date.day >= 21) ||
                (date.month == MAY && date.day <= 21)) {
                return TAURUS;
        } else if((date.month == MAY && date.day >= 22) ||
                (date.month == JUNE && date.day <= 21)) {
                return GEMINI;
        } else if((date.month == JUNE && date.day >= 21) ||
                (date.month == JULY && date.day <= 22)) {
                return CANCER;
        } else if((date.month == JULY && date.day >= 23) ||
                (date.month == AUGUST && date.day <= 21)) {
                return LEO;
        } else if((date.month == AUGUST && date.day >= 22) ||
                (date.month == SEPTEMBER && date.day <= 23)) {
                return VIRGO;
        } else if((date.month == SEPTEMBER && date.day >= 24) ||
                (date.month == OCTOBER && date.day <= 23)) {
                return LIBRA;
        } else if((date.month == OCTOBER && date.day >= 24) ||
                (date.month == NOVEMBER && date.day <= 22)) {
                return SCORPIO;
        } else if((date.month == NOVEMBER && date.day >= 23) ||
                (date.month == DECEMBER && date.day <= 22)) {
                return SAGITTARIUS;
        } else if((date.month == DECEMBER && date.day >= 23) ||
                (date.month == JANUARY && date.day <= 20)) {
                return CAPRICORN;
        } else if((date.month == JANUARY && date.day >= 21) ||
                (date.month == FEBRUARY && date.day <= 19)) {
                return AQUARIUS;
        } else if((date.month == FEBRUARY && date.day >= 20) ||
                (date.month == MARCH && date.day <= 20)) {
                return PISCES;
        } else {
                return 404;
        }
}

char* zodiacToString(Zodiac zodiac) {
        if(zodiac == ARIES) {
                return "aries";
        } else if(zodiac == TAURUS) {
                return "taurus";
        } else if(zodiac == GEMINI) {
                return "gemini";
        } else if(zodiac == CANCER) {
                return "cancer";
        } else if(zodiac == LEO) {
                return "leo";
        } else if(zodiac == VIRGO) {
                return "virgo";
        } else if(zodiac == LIBRA) {
                return "libra";
        } else if(zodiac == SCORPIO) {
                return "scorpio";
        } else if(zodiac == SAGITTARIUS) {
                return "sagittarius";
        } else if(zodiac == CAPRICORN) {
                return "capricorn";
        } else if(zodiac == AQUARIUS) {
                return "aquarius";
        } else if(zodiac == PISCES) {
                return "pisces";
        } else {
                return "zodiac error";
        }
}

typedef enum Element {
        FIRE,
        EARTH,
        AIR,
        WATER
} Element;

Element getElement(Zodiac zodiac) {
        if(
                zodiac == ARIES ||
                zodiac == LEO ||
                zodiac == SAGITTARIUS
                ) {
                return FIRE;
        } else if(
                zodiac == CAPRICORN ||
                zodiac == TAURUS ||
                zodiac == VIRGO
                ) {
                return EARTH;
        } else if(
                zodiac == LIBRA ||
                zodiac == AQUARIUS ||
                zodiac == GEMINI
                ) {
                return AIR;
        } else if(
                zodiac == CANCER ||
                zodiac == SCORPIO ||
                zodiac == PISCES
                ) {
                return WATER;
        } else {
                return 404;
        }
}

char* elementToString(Element element) {
        if(element == FIRE) {
                return "fire";
        } else if(element == EARTH) {
                return "earth";
        } else if(element == AIR) {
                return "air";
        } else if(element == WATER) {
                return "water";
        } else {
                return "element error";
        }
}

typedef enum Sex {
        MALE,
        FEMALE
} Sex;

Sex sexFromString(char* input) {
        if(!strcmp(input, "male")) {
                return MALE;
        } else if(!strcmp(input, "female")) {
                return FEMALE;
        } else {
                return 404;
        }
}

char* sexToString(Sex sex) {
        if(sex == MALE) {
                return "male";
        } else if(sex == FEMALE) {
                return "female";
        } else {
                return "sex error";
        }
}

typedef struct Human {
        Sex sex;
        Date birthDate;
        Zodiac zodiac;
        Element element;
} Human;

Human setHuman(Sex sex, Date birthDate) {
        Human human;
        human.sex = sex;
        human.birthDate = birthDate;
        human.zodiac = getZodiac(birthDate);
        human.element = getElement(human.zodiac);
        return human;
}

_Bool canBeFriends(Human human1, Human human2) {
        return human1.element == human2.element;
}

_Bool canBeBusinessPartners(Human human1, Human human2) {
        return (
                (human1.zodiac - human2.zodiac) <= 1 ||
                (human1.zodiac - human2.zodiac) >= -1
                );
}

_Bool canBeFamily(Human human1, Human human2) {
        return (
                (human1.sex != human2.sex) && (
                        (human1.element == AIR && human2.element == WATER) ||
                        (human2.element == AIR && human1.element == WATER) ||
                        (human1.element == FIRE && human2.element == EARTH) ||
                        (human2.element == FIRE && human1.element == EARTH)
                        )
                );
}

void enterPerson(Human* human) {
        printf("Enter birth date of person:");
        char* buff = (char*)malloc(8);
        scanf("%5s", buff);
        Date date = dateFromString(buff);
        printf("Enter sex of person:");
        scanf("%7s", buff);
        Sex sex = sexFromString(buff);
        *human = setHuman(sex, date);
        free(buff);
}

void selectionMenu() {
        Human human1 = setHuman(404, dateFromString("00:00"));
        Human human2 = setHuman(404, dateFromString("00:00"));
        int currentSelection = 8;
        do {
                printf("Please select menu item:\n");
                printf("1.Enter first person data\n");
                if(human1.sex != 404) {
                        char* buff = NULL;
                        buff = dateToString(human1.birthDate);
                        printf("  current data: date: %s, sex %s\n",
                                buff, sexToString(human1.sex));
                        free(buff);
                        //fflush(stdin);
                }
                printf("2.Enter second person data\n");
                if(human2.sex != 404) {
                        char* buff = NULL;
                        buff = dateToString(human2.birthDate);
                        printf("  current data: date: %s, sex %s\n",
                                buff, sexToString(human2.sex));
                        free(buff);
                }
                if(human1.sex != 404 && human2.sex != 404) {
                        printf("\
3.Determine sign of the zodiac of each human\n\
4.Determine if they can be friends\n\
5.Determine if they can be business partners\n\
6.Determine if they can live in marriage\n\
");
                }
                printf("7.About this program\n8.Exit\n");
                scanf("%d", &currentSelection);
                printf("\n");
                if(currentSelection == 1) {
                        enterPerson(&human1);
                } else if(currentSelection == 2) {
                        enterPerson(&human2);
                } else if(
                        human1.sex != 404 &&
                        human1.zodiac != 404 &&
                        human2.sex != 404 &&
                        human2.sex != 404
                        ) {
                        if(currentSelection == 3) {
                                printf("Zodiac of the first human is %s\nZodiac of the second human is %s\n\n",
                                        zodiacToString(human1.zodiac), zodiacToString(human2.zodiac));
                        } else if(currentSelection == 4) {
                                if(canBeFriends(human1, human2)) {
                                        printf("That humans can be friends\n\n");
                                } else {
                                        printf("That humans can't be friends\n\n");
                                }
                        } else if(currentSelection == 5) {
                                if(canBeBusinessPartners(human1, human2)) {
                                        printf("That humans can be business partners\n\n");
                                } else {
                                        printf("That humans can't be business partners\n\n");
                                }
                        } else if(currentSelection == 6) {
                                if(canBeFamily(human1, human2)) {
                                        printf("That humans can live in marriage\n\n");
                                } else {
                                        printf("That humans can't be live in marriage\n\n");
                                }
                        } else if(currentSelection == 7) {
                                printf("Info\n\n");
                        }
                } else {
                        printf("error\n");
                }
        } while(currentSelection != 8);
}

int main() {
        selectionMenu();
}