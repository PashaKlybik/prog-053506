#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entrant{
    char* fullName;
    char* Number;
    char* school;
    char* address;
    int BelarusianorRussianlanguage;
    int mat;
    int physics;
    int SRB;
}Entrant;

typedef struct Node {
        Entrant* data;
        struct Node* prev;
        struct Node* next;
}Node;

typedef struct Listing {
    Node* head;
    int size;
    int placesForFreeTraining;
    const char* NameSpecial;
    const char* SpecialtyName;
}Listing;

void WriteToFile(Listing* faculty[], int size, const char* facul, FILE* a) {
    for (int i = 0; i < size; i++) {
        Node* tmp = faculty[i]->head;
        for (int j = 0; j < faculty[i]->size; j++) {
            fprintf(a, "%s|", facul);
            fprintf(a, "%s|", faculty[i]->SpecialtyName);
            fprintf(a, "%s|", tmp->data->fullName);
            fprintf(a, "%s|", tmp->data->Number);
            fprintf(a, "%s|", tmp->data->address);
            fprintf(a, "%s|", tmp->data->school);
            fprintf(a, "%d|", tmp->data->SRB);
            fprintf(a, "%d|", tmp->data->BelarusianorRussianlanguage);
            fprintf(a, "%d|", tmp->data->mat);
            fprintf(a, "%d\n", tmp->data->physics);
            tmp = tmp->next;
        }
    }
}

void BackPush(Listing* l, Entrant* ap) {
        Node* tmp = l->head;
        if(tmp == NULL) {
                l->head = (Node*)malloc(sizeof(Node));
                l->head->next = NULL;
                l->head->prev = NULL;
                l->head->data = (Entrant*)malloc(sizeof(Entrant));
                l->head->data->fullName = (char*)malloc(60 * sizeof(char));
                strcpy(l->head->data->fullName, ap->fullName);
                strcpy(ap->fullName, "");
                l->head->data->Number = (char*)malloc(10 * sizeof(char));
                strcpy(l->head->data->Number, ap->Number);
                strcpy(ap->Number, "");
                l->head->data->address = (char*)malloc(60 * sizeof(char));
                strcpy(l->head->data->address, ap->address);
                strcpy(ap->address, "");
                l->head->data->school = (char*)malloc(60 * sizeof(char));
                strcpy(l->head->data->school, ap->school);
                strcpy(ap->school, "");
                l->head->data->SRB = ap->SRB;
                l->head->data->BelarusianorRussianlanguage = ap->BelarusianorRussianlanguage;
                l->head->data->mat = ap->mat;
                l->head->data->physics = ap->physics;
        }

        else {
                while(tmp->next != NULL) {
                        tmp = tmp->next;
                }
                tmp->next = (Node*)malloc(sizeof(Node));
                (tmp->next)->next = NULL;
                (tmp->next)->prev = tmp;
                (tmp->next)->data = (Entrant*)malloc(sizeof(Entrant));
                (tmp->next)->data->fullName = (char*)malloc(60 * sizeof(char));
                strcpy((tmp->next)->data->fullName, ap->fullName);
                (tmp->next)->data->Number = (char*)malloc(10 * sizeof(char));
                strcpy((tmp->next)->data->Number, ap->Number);
                (tmp->next)->data->address = (char*)malloc(60 * sizeof(char));
                strcpy((tmp->next)->data->address, ap->address);
                (tmp->next)->data->school = (char*)malloc(60 * sizeof(char));
                strcpy((tmp->next)->data->school, ap->school);
                (tmp->next)->data->SRB = ap->SRB;
                (tmp->next)->data->BelarusianorRussianlanguage = ap->BelarusianorRussianlanguage;
                (tmp->next)->data->mat = ap->mat;
                (tmp->next)->data->physics = ap->physics;
        }
        l->size++;
}

void addEntrant(Entrant* c, char* faculty, char* specialty, Listing* FCSandN[4], Listing* FITandM[5], Listing* FCE[9]) {
        if(strcmp(faculty, "ФКСиС") == 0) {
                for(int i = 0; i < 4; i++) {
                        if(strcmp(specialty, FCSandN[i]->SpecialtyName) == 0) {
                                BackPush(FCSandN[i], c);
                                return;
                        }
                }
        }

        else if(strcmp(faculty, "ФИТУ") == 0) {
                for(int i = 0; i < 5; i++) {
                        if(strcmp(specialty, FITandM[i]->SpecialtyName) == 0) {
                                BackPush(FITandM[i], c);
                                return;
                        }
                }
        }     else if(strcmp(faculty, "ФКП") == 0) {
                for(int i = 0; i < 9; i++) {
                        if(strcmp(specialty, FCE[i]->SpecialtyName) == 0) {
                                BackPush(FCE[i], c);
                                return;
                        }
                }
        }
}

void FromFile(Listing* FCSandN[4], Listing* FITandM[5], Listing* FCE[9], FILE* a) {
    char str[200];
    while (1) {
        char* string = fgets(str, sizeof(str), a);
        Entrant* c = (Entrant*)malloc(sizeof(Entrant));

        if (string == NULL)
            break;

        char* faculty = strtok(string, "|\n");
        char* specialty = strtok(NULL, "|\n");

        c->fullName = strtok(NULL, "|\n");
        c->Number = strtok(NULL, "|\n");
        c->address = strtok(NULL, "|\n");
        c->school = strtok(NULL, "|\n");
        char* num = strtok(NULL, "|\n");
        c->SRB = atol(num);
        num = strtok(NULL, "|\n");
        c->BelarusianorRussianlanguage = atol(num);
        num = strtok(NULL, "|\n");
        c->mat = atol(num);
        num = strtok(NULL, "|\n");
        c->physics = atol(num);

        addEntrant(c, faculty, specialty, FCSandN, FITandM, FCE);
    }
}


int entryPoint(Listing* spec) {
    if (spec->size == 0)
        return 0;
    int res;
    int* ball = (int*)malloc((spec->size) * sizeof(int));
    Node* tmp = spec->head;
    for (int i = 0; i < spec->size; i++) {
        ball[i] = tmp->data->physics + tmp->data->BelarusianorRussianlanguage + tmp->data->SRB + tmp->data->mat;
        tmp = tmp->next;
    }

    for (int i = 0; i < spec->size - 1; i++) {
        for (int j = 0; j < spec->size - i - 1; j++) {
            if (ball[j] < ball[j + 1]) {
                int temp = ball[j];
                ball[j] = ball[j + 1];
                ball[j + 1] = temp;
            }
        }
    }

    if (spec->placesForFreeTraining < spec->size)
    {
        res = ball[spec->placesForFreeTraining - 1];
    }
    else
    {
        res = ball[spec->size - 1];
    }

    free(ball);
    return res;
}

void entryPoints(Listing* faculty[], int size) {
        for(int i = 0; i < size; i++) {
                printf("\n%s: %d", faculty[i]->SpecialtyName, entryPoint(faculty[i]));
        }
}

void getInfo(Entrant* ap) {
        printf("\nФИО: %s\t\t\tБалл: %d", ap->fullName, ap->SRB + ap->mat + ap->BelarusianorRussianlanguage + ap->physics);
}

void Enrolled(Listing* faculty[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n\n%s:", faculty[i]->SpecialtyName);
        Node* tmp = faculty[i]->head;
        for (int j = 0; j < faculty[i]->size; j++) {
            int score = tmp->data->physics + tmp->data->BelarusianorRussianlanguage + tmp->data->SRB + tmp->data->mat;
            if (score >= entryPoint(faculty[i])) {
                getInfo(tmp->data);
            }
            tmp = tmp->next;
        }
    }
}

void Front(Listing* l) {
        Node* del = l->head;
        l->head = (l->head)->next;
        if(l->head != NULL) {
                (l->head)->prev = NULL;
        }
        free(del->data);
        free(del);
        l->size--;
}

void Removal(Listing* l, int index) {
        if(index == 0) {
                Front(l);
        } else if(index < l->size) {
                Node* tmp = l->head;
                for(int i = 0; i < index - 1 && tmp->next != NULL; i++) {
                        tmp = tmp->next;
                }
                Node* del = tmp->next;
                tmp->next = del->next;
                if(del->next != NULL) {
                        (del->next)->prev = tmp;
                }
                free(del->data);
                free(del);
                l->size--;
        }
}

void deleteEntrant(char* name, Listing* FCSandN[4], Listing* FITandM[5], Listing* FCE[9]) {
    Node* tmp;
    for (int i = 0; i < 4; i++) {
        tmp = FCSandN[i]->head;
        for (int j = 0; j < FCSandN[i]->size && tmp != NULL; j++) {
            if (strcmp(name, tmp->data->fullName) == 0) {
                Removal(FCSandN[i], j);
                return;
            }
            tmp = tmp->next;
        }
    }
    for (int i = 0; i < 5; i++) {
        tmp = FITandM[i]->head;
        for (int j = 0; j < FITandM[i]->size && tmp != NULL; j++) {
            if (strcmp(name, tmp->data->fullName) == 0) {
                Removal(FITandM[i], j);
                return;
            }
            tmp = tmp->next;
        }
    }
    for (int i = 0; i < 9; i++) {
        tmp = FCE[i]->head;
        for (int j = 0; j < FCE[i]->size && tmp != NULL; j++) {
            if (strcmp(name, tmp->data->fullName) == 0) {
                Removal(FCE[i], j);
                return;
            }
            tmp = tmp->next;
        }
    }
}

int menu() {
    int d = 0, e = 0;
    printf("\n\nЧто вы хотите сделать у нас? Выбирайте?");
    printf("\n1 - Я хочу подать документы в БГУИР!"
        "\n2 - Я хочу забрать документы!"
        "\n3 - Я хочу узнать проходные баллы!"
        "\n4 -Я хочу увидеть списки поступивших!"
        "\n5 - Я хочу увидеть всю информацию об определенном факультете!"
        "\n6 - Я хочу выйти!\n");
    while (e != 1 && (d > 6 || d < 1)) {
        e = scanf("%d", &d);
        if (e != 1)
            fflush(stdin);
    }
    return d;
}

char* getString() {
        char* string = (char*)malloc(60 * sizeof(char));
        char symbol = 'f';
        int index = 0;
        while(symbol != '\n') {
                symbol = getc(stdin);
                if(symbol != '\n') {
                        string[index] = symbol;
                        index++;
                }
        }
        string[index] = '\0';
        return string;
}

void initialization(Listing* FCSandN[4], Listing* FITandM[5], Listing* FCE[9]) {

    for (int i = 0; i < 4; i++) {
        FCSandN[i] = (Listing*)malloc(sizeof(Listing));
        FCSandN[i]->size = 0;
        FCSandN[i]->head = NULL;
    }
    for (int i = 0; i < 5; i++) {
        FITandM[i] = (Listing*)malloc(sizeof(Listing));
        FITandM[i]->size = 0;
        FITandM[i]->head = NULL;
    }
    for (int i = 0; i < 9; i++) {
        FCE[i] = (Listing*)malloc(sizeof(Listing));
        FCE[i]->size = 0;
        FCE[i]->head = NULL;
    }
    FCE[0]->placesForFreeTraining = 25;
    FCE[1]->placesForFreeTraining = 15;
    FCE[2]->placesForFreeTraining = 20;
    FCE[3]->placesForFreeTraining = 20;
    FCE[4]->placesForFreeTraining = 25;
    FCE[5]->placesForFreeTraining = 20;
    FCE[6]->placesForFreeTraining = 20;
    FCE[7]->placesForFreeTraining = 25;
    FCE[8]->placesForFreeTraining = 20;

    FCSandN[0]->placesForFreeTraining = 65;
    FCSandN[1]->placesForFreeTraining = 60;
    FCSandN[2]->placesForFreeTraining = 75;
    FCSandN[3]->placesForFreeTraining = 25;

    FITandM[0]->placesForFreeTraining = 60;
    FITandM[1]->placesForFreeTraining = 55;
    FITandM[2]->placesForFreeTraining = 60;
    FITandM[3]->placesForFreeTraining = 25;
    FITandM[4]->placesForFreeTraining = 15;

    FCE[0]->NameSpecial = "Инженерно-психологическое обеспечение информационных технологий";
    FCE[1]->NameSpecial = "Информационные системы и технологии (в бизнес менеджменте)";
    FCE[2]->NameSpecial = "Информационные системы и технологии (в обеспечении промышленной безопасности)";
    FCE[3]->NameSpecial = "Медицинская электроника";
    FCE[4]->NameSpecial = "Моделирование и компьютерное проектирование радиоэлектронных средств";
    FCE[5]->NameSpecial = "Программируемые мобильные системы";
    FCE[6]->NameSpecial = "Программно-управляемые электронно-оптические системы";
    FCE[7]->NameSpecial = "Проектирование и производство программно-управляемых электронных средств";
    FCE[8]->NameSpecial = "Электронные системы безопасности";

    FCSandN[0]->NameSpecial = "Информатика и технологии программирования";
    FCSandN[1]->NameSpecial = "Программное обеспечение информационных технологий";
    FCSandN[2]->NameSpecial = "Вычислительные машины, системы и сети";
    FCSandN[3]->NameSpecial = "Электронные вычислительные средства";

    FITandM[0]->NameSpecial = "Автоматизированные системы обработки информации";
    FITandM[1]->NameSpecial = "Искусственный интеллект";
    FITandM[2]->NameSpecial = "Информационные технологии и управление в технических системах";
    FITandM[3]->NameSpecial = "Промышленная электроника";
    FITandM[4]->NameSpecial = "Информационные системы и технологии (в игровой индустрии)";

    FCE[0]->SpecialtyName = "ИПОИТ";
    FCE[1]->SpecialtyName = "ИСиТБМ";
    FCE[2]->SpecialtyName = "ИСиТОПБ";
    FCE[3]->SpecialtyName = "МЭ";
    FCE[4]->SpecialtyName = "МКиПРС";
    FCE[5]->SpecialtyName = "ПМС";
    FCE[6]->SpecialtyName = "ПУЭОС";
    FCE[7]->SpecialtyName = "ПиППУЭС";
    FCE[8]->SpecialtyName = "ЭСБ";

    FCSandN[0]->SpecialtyName = "ИиТП";
    FCSandN[1]->SpecialtyName = "ПОИТ";
    FCSandN[2]->SpecialtyName = "ВМСиС";
    FCSandN[3]->SpecialtyName = "ЭВС";

    FITandM[0]->SpecialtyName = "АСОИ";
    FITandM[1]->SpecialtyName = "ИИ";
    FITandM[2]->SpecialtyName = "ИТиУТС";
    FITandM[3]->SpecialtyName = "ПЭ";
    FITandM[4]->SpecialtyName = "ИСиТ";


}

void SetInfo(Entrant* ap) {
    int e, d;
    fflush(stdin);
    printf("\nИнформация об абитуриенте:");
    printf("\nФИО: ");
    ap->fullName = getString();
    printf("Серийный номер паспорта: ");
    ap->Number = getString();
    printf("Адрес: ");
    ap->address = getString();
    printf("Учебное заведение: ");
    ap->school = getString();
    while (e != 1) {
        printf("Балл аттестата: ");
        e = scanf("%d", &d);
        if (e != 1)
            fflush(stdin);
    }
    e = 0;
    ap->SRB = d;
    while (e != 1) {
        printf("ЦТ по языку: ");
        e = scanf("%d", &d);
        if (e != 1)
            fflush(stdin);
    }
    e = 0;
    ap->BelarusianorRussianlanguage = d;
    while (e != 1) {
        printf("ЦТ по математике: ");
        d = scanf("%d", &d);
        if (e != 1)
            fflush(stdin);
    }
    e = 0;
    ap->physics = d;
    while (e != 1) {
        printf("ЦТ по физике: ");
        e = scanf("%d", &d);
        if (e != 1)
            fflush(stdin);
    }
    ap->mat = d;
}

void ListClear(Listing* l) {
    while (l->size) {
        Front(l);
    }
}

int main() {

    int b;
    Listing* FCSandN[4];
    Listing* FITandM[5];
    Listing* FCE[9];

    initialization(FCSandN, FITandM, FCE);

    FILE* a;
    a = fopen("C:/Users/User/Desktop/Новый текстовый документ (4).txt", "q");
    FromFile(FCSandN, FITandM, FCE, a);
    fclose(a);

    b = menu();
    while (b != 6) {
        switch (b) {
        case 1: {
            char* faculty;
            char* specialty;
            Entrant* c = (Entrant*)malloc(sizeof(Entrant));
            SetInfo(c);
            fflush(stdin);
            printf("Наш факультет: ");
            faculty = getString();
            printf("Наша специальность: ");
            specialty = getString();
            b = menu();
            addEntrant(c, faculty, specialty, FCSandN, FITandM, FCE);
            break;
        }
        case 2: {
            fflush(stdin);
            printf("\n Фамилия Имя Отчество абитуриента\n");
            char* name = getString();
            deleteEntrant(name, FCSandN, FITandM, FCE);
            b = menu();
            break;
        }
        case 3: {
            fflush(stdin);
            printf("\nФакультет компьютерных систем и сетей:");
            entryPoints(FCSandN, 4);
            printf("\n\nФакультет информационных технологий и управления:");
            entryPoints(FITandM, 5);
            printf("\n\nФакультет компьютерного проектирования:");
            entryPoints(FCE, 9);
            b = menu();
            break;
        }
        case 4: {
            fflush(stdin);
            printf("\nСписки поступивших: ");
            printf("\nФакультет компьютерных систем и сетей:");
            Enrolled(FCSandN, 4);
            printf("\nФакультет информационных технологий и управления:");
            Enrolled(FITandM, 5);
            printf("\nИнженерно-экономический факультет:");
            Enrolled(FCE, 9);
            b = menu();
            break;
        }
        case 5: {
            fflush(stdin);
            int opt;
            printf("\nВыберите факультет, о котором хотите увидеть информацию"
                "\n1 - ФКСиС"
                "\n2 - ФИТУ"
                "\n3 - ФКП\n");
            scanf("%d", &opt);
            switch (opt) {
            case 1: {
                printf("\nКоличество поданных заявлений:");
                printf("\n%s: %d", FCSandN[0]->SpecialtyName, FCSandN[0]->size);
                printf("\t%s: %d", FCSandN[1]->SpecialtyName, FCSandN[1]->size);
                printf("\t%s: %d", FCSandN[2]->SpecialtyName, FCSandN[2]->size);
                printf("\t%s: %d", FCSandN[3]->SpecialtyName, FCSandN[3]->size);
                printf("\n\nПроходные баллы:");
                entryPoints(FCSandN, 4);
                printf("\n\nСписки поступивших: ");
                Enrolled(FCSandN, 4);
                break;
            }
            case 2: {
                printf("\nКоличество поданных заявлений:");
                printf("\n%s: %d", FITandM[0]->SpecialtyName, FITandM[0]->size);
                printf("\t%s: %d", FITandM[1]->SpecialtyName, FITandM[1]->size);
                printf("\t%s: %d", FITandM[2]->SpecialtyName, FITandM[2]->size);
                printf("\t%s: %d", FITandM[3]->SpecialtyName, FITandM[3]->size);
                printf("\t%s: %d", FITandM[4]->SpecialtyName, FITandM[4]->size);
                printf("\n\nПроходные баллы:");
                entryPoints(FITandM, 5);
                printf("\n\nСписки поступивших: ");
                Enrolled(FITandM, 5);
                break;
            }
            case 3: {
                printf("\nКоличество поданных заявлений:");
                printf("\n%s: %d", FCE[0]->SpecialtyName, FCE[0]->size);
                printf("\t%s: %d", FCE[1]->SpecialtyName, FCE[1]->size);
                printf("\t%s: %d", FCE[2]->SpecialtyName, FCE[2]->size);
                printf("\t%s: %d", FCE[3]->SpecialtyName, FCE[3]->size);
                printf("\n%s: %d", FCE[4]->SpecialtyName, FCE[0]->size);
                printf("\t%s: %d", FCE[5]->SpecialtyName, FCE[1]->size);
                printf("\t%s: %d", FCE[6]->SpecialtyName, FCE[2]->size);
                printf("\t%s: %d", FCE[7]->SpecialtyName, FCE[3]->size);
                printf("\n\nПроходные баллы:");
                entryPoints(FCE, 9);
                printf("\n\nСписки поступивших: ");
                Enrolled(FCE, 9);
                break;
            }
            default: {
                printf("\nВы не выбрали факультет, попробуйте снова.");
                break;
            }
            }
            b = menu();
        }
        default: break;
        }
    }

    a = fopen("C:/Users/User/Desktop/Новый текстовый документ (4).txt", "q");
    WriteToFile(FCSandN, 4, "ФКСиС", a);
    WriteToFile(FITandM, 5, "ФИТУ", a);
    WriteToFile(FCE, 9, "ФКП", a);
    fclose(a);

    for (int i = 0; i < 4; i++) {
        ListClear(FCSandN[i]);
        free(FCSandN[i]);
    }
    for (int i = 0; i < 5; i++) {
        ListClear(FITandM[i]);
        free(FITandM[i]);
    }
    for (int i = 0; i < 9; i++) {
        ListClear(FCE[i]);
        free(FCE[i]);
    }

    return 0;
}
