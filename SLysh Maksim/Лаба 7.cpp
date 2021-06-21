

#include<iostream>

using namespace std;

struct Student
{
	string name;
	string surname;
	string speciality;
	string course;
	int violations = 0;
	Student* next = NULL;
};

class Studentlist
{
private:
	Student* head, * tail;
	int check;

public:
	int size;
	Studentlist()
	{
		head = NULL;
		tail = NULL;
		size = 0;
		check = 0;
	}

	int Add(string name, string surname, string speciality, string course, int violations)
	{
		Student* temp = new Student;
		temp->name = name;
		temp->surname = surname;
		temp->speciality = speciality;
		temp->course = course;
		temp->violations = violations;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		size++;
		return size;
	}

	int Show()
	{
		Student* temp = new Student;
		temp = head;
		check = 0;

		while (temp != NULL)
		{
			cout << "\nИмя: " << temp->name;
			cout << "\nФамилия: " << temp->surname;
			cout << "\nСпециальность: " << temp->speciality;
			cout << "\nКурс: " << temp->course;
			cout << "\nКоличество нарушений: " << temp->violations;
			temp = temp->next;
			check = 1;
		}
		return check;
	}

	int Search(string value)
	{
		check = 0;
		if (head != NULL)
		{
			Student* temp = new Student;
			temp = head;

			while (temp != NULL)
			{
				if (temp->surname == value)
				{
					cout << "\nИмя: " << temp->name;
					cout << "\nФамилия: " << temp->surname;
					cout << "\Специальность: " << temp->speciality;
					cout << "\nкурс: " << temp->course;
					cout << "\nКоличество нарушений: " << temp->violations;
					check = 1;
				}
				temp = temp->next;
			}
		}
		return check;
	}

	int CheckViolations()
	{
		check = 0;
		if (head != NULL)
		{
			Student* temp = new Student;
			temp = head;

			while (temp != NULL)
			{
				if (temp->violations > 2)
				{
					cout << "\nРекомендовано к нарушению: " << temp->name << "  " << temp->surname;
					check = 1;
				}
				temp = temp->next;
			}
		}
		return check;
	}

	int Delete(string name, string surname)
	{
		Student* temp = new Student;
		temp = head;
		int pos = 1;

		for (; temp != NULL && temp->surname != surname && temp->name != name; pos++)
		{
			temp = temp->next;
		}

		if (pos == 1)
		{
			Student* current = new Student;
			current = head;
			head = head->next;
			delete current;
		}
		else if (pos == size)
		{
			Student* current = new Student;
			Student* previous = new Student;

			current = head;
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			delete current;
		}
		else
		{
			Student* current = new Student;
			Student* previous = new Student;
			current = head;

			for (int i = 1; i < pos; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
		size--;
		return 1;
	}
};


struct Workers
{
	string function;
	string name;
	string surname;
	string patronymic;
	long int number = 0;
	Workers* next = NULL;
};

class Workerslist
{
private:
	Workers* head, * tail;
	int size, check;

public:
	Workerslist()
	{
		head = NULL;
		tail = NULL;
		size = 0;
		check = 0;
	}

	int Add(string function, string name, string surname, string patronymic, int number)
	{
		Workers* temp = new Workers;
		temp->name = name;
		temp->surname = surname;
		temp->function = function;
		temp->patronymic = patronymic;
		temp->number = number;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		size++;
		return size;
	}

	int Show()
	{
		Workers* temp = new Workers;
		temp = head;
		check = 0;

		while (temp != NULL)
		{
			cout << "\n\nДолжность: " << temp->function;
			cout << "\nФамилия: " << temp->surname;
			cout << "\nИмя: " << temp->name;
			cout << "\nОтчество: " << temp->patronymic;
			cout << "\nНомер телефона: +37517" << temp->number;
			temp = temp->next;
			check = 1;
		}
		return check;
	}

};
int Menu(Studentlist* slist, Workerslist* wlist, int choice);
int Question(Studentlist* slist, Workerslist* wlist);

int Question(Studentlist* slist, Workerslist* wlist)
{
	cout << "\n\nВыберите действие: \nПоказать рабочих 1, \nПоказать студентов 2, \nРекомендуется для выселения 3, \nДобавить студента 4, \nУдалить студента 5, \nПоиск 6, \nВыход 7 \n";
	cout << "Ввод: ";
	int choice;
	cin >> choice;
	Menu(slist, wlist, choice);
	return 1;
}

int Menu(Studentlist* slist, Workerslist* wlist, int choice)
{
	int violations = 0;
	string temp, name, surname, speciality, course;

	switch (choice)
	{
	case 1:
		wlist->Show();
		Question(slist, wlist);
		break;
	case 2:
		if (slist->Show() == 0)
		{
			cout << "Вы не добавили ни одного ученика!";
		}
		Question(slist, wlist);
		break;
	case 3:
		if (slist->CheckViolations() == 0)
		{
			cout << "Никаких нарушителей!";
		}
		Question(slist, wlist);
		break;
	case 4:
		cout << "\nУкажите свое имя, фамилию, специальность, курс и количество нарушений.: ";
		cin >> name >> surname >> speciality >> course >> violations;
		cout << "Кол-во свободных комнат: " << 1000 - slist->Add(name, surname, speciality, course, violations) << "\n";
		Question(slist, wlist);
		break;
	case 5:
		cout << "\nВведите ФИ";
		cin >> name >> surname;
		if (slist->Delete(name, surname) == 0)
		{
			cout << "С такой фамилией нет людей";
		}
		Question(slist, wlist);
		break;
	case 6:
		cout << "\nВведите фамилию: ";
		cin >> temp;
		if (slist->Search(temp) == 0)
		{
			cout << "С такой фамилией нет людей";
		}
		Question(slist, wlist);
		break;
	case 7:
		break;
	default:
		cout << "\nНеправильный ввод";
		Question(slist, wlist);
		break;
	}
	return choice;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Studentlist slist;
	Workerslist wlist;

	wlist.Add("Заведующая", "Валентина", "Иванова", "Ивановна", 27763);
	wlist.Add("Коменда", "Светлана", "Петрова", "Петровна", 392924);
	wlist.Add("Воспетка", "Ирина", "Аыаыфаыф", "Валентиновна", 392935);
	wlist.Add("Психолог", "Наталья", "Авывыфвф", "Леонидовна", 39241);
	wlist.Add("Паспортистка", "Ирина", "ВАавафыаф", "Васильевна", 27763);

	if (Question(&slist, &wlist))
	{
		cout << "\nЗавершить";
	}
	return 0;
}






