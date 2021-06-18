//task 6.2 Var 2




//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Name1;
	TEdit *Passport1;
	TEdit *Insurance1;
	TEdit *Education1;
	TEdit *Post1;
	TEdit *Salary1;
	TEdit *Notes1;
	TDateTimePicker *Birthday1;
	TDateTimePicker *Hiring1;
	TLabel *Name;
	TLabel *Label2;
	TLabel *Passport;
	TLabel *Insurance;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TMemo *Memo1;
	TComboBox *ComboBox1;
	TButton *Add;
	TButton *Elder;
	TStaticText *StaticText1;
	TButton *Delete;
	TButton *DeleteFills;
	TButton *Display;
	TComboBox *ComboBox2;
	TEdit *FindAll;
	TButton *Button1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TComboBox *ComboBox3;
	TStaticText *StaticText4;
	TButton *DelEmp;
	void __fastcall DeleteFillsClick(TObject *Sender);
	void __fastcall DisplayClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall ElderClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DelEmpClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Main.h"
#include "Employee.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

list List;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
	Form1->ComboBox2->Items->Add("Имя");
	Form1->ComboBox2->Items->Add("Дата рождения");
	Form1->ComboBox2->Items->Add("Паспорт");
	Form1->ComboBox2->Items->Add("Страховка");
	Form1->ComboBox2->Items->Add("Обрпзование");
	Form1->ComboBox2->Items->Add("Должность");
	Form1->ComboBox2->Items->Add("Зарплата");
	Form1->ComboBox2->Items->Add("Прием");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
	emp New(Name1->Text, DateToStr(Birthday1->Date), Passport1->Text, Insurance1->Text, Education1->Text, Post1->Text, StrToInt(Salary1->Text), DateToStr(Hiring1->Date), Notes1->Text);
	List.AddNode(New);
	Memo1->Lines->Add("Имя: " + Name1->Text);
	Memo1->Lines->Add("Дата рождения: " + DateToStr(Birthday1->Date));
	Memo1->Lines->Add("Паспорт: " + Passport1->Text);
	Memo1->Lines->Add("Страховка: " + Insurance1->Text);
	Memo1->Lines->Add("Образование: " + Education1->Text);
	Memo1->Lines->Add("Должность: " + Post1->Text);
	Memo1->Lines->Add("Зарплата: " + Salary1->Text);
	Memo1->Lines->Add("Прием: " + DateToStr(Hiring1->Date));
	Memo1->Lines->Add("Комментарий: " + Notes1->Text);
	Memo1->Lines->Add("");
	ComboBox3->Items->Add(Name1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteFillsClick(TObject *Sender)
{
	Name1->Clear();
	Passport1->Clear();
	Insurance1->Clear();
	Education1->Clear();
	Post1->Clear();
	Salary1->Clear();
	Notes1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayClick(TObject *Sender)
{
	List.GetNode(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ElderClick(TObject *Sender)
{
    List.Elder(ComboBox1, Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	int x = ComboBox2->ItemIndex;

	switch(x)
	{
		case 0: List.FindName(FindAll, Memo1); break;
		case 1: List.FindBirthday(FindAll, Memo1); break;
		case 2: List.FindPassport(FindAll, Memo1); break;
		case 3: List.FindInsurance(FindAll, Memo1); break;
		case 4: List.FindEducation(FindAll, Memo1); break;
		case 5: List.FindPost(FindAll, Memo1); break;
		case 6: List.FindSalary(FindAll, Memo1); break;
		case 7: List.FindHiring(FindAll, Memo1); break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DelEmpClick(TObject *Sender)
{
	List.DeleteElement(ComboBox3, Memo1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DeleteClick(TObject *Sender)
{
	List.DeleteElement(ComboBox1, Memo1);
}
//---------------------------------------------------------------------------

-----------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop
#include<Dateutils.hpp>

#include "Employee.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void list :: AddNode(emp value)
{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if(head == NULL)
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
}

void list :: GetNode(TMemo*Memo)
{
	Memo->Lines->Clear();
	node *temp;
	temp = head;
	while(temp != NULL)
	{
		Memo->Lines->Add("Имя: " + temp->data.Name);
		Memo->Lines->Add("Дата рождения: " + temp->data.Birthday);
		Memo->Lines->Add("Паспорт: " + temp->data.Passport);
		Memo->Lines->Add("Страховка: " + temp->data.Insurance);
		Memo->Lines->Add("Образование: " + temp->data.Education);
		Memo->Lines->Add("Должность: " + temp->data.Post);
		Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
		Memo->Lines->Add("Дата приема: " + temp->data.Hiring);
		Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		Memo->Lines->Add("");
		temp = temp->next;
	}
}

void list :: DeleteElement(TComboBox*ComboBox, TMemo*Memo)
{
	bool c = false;
	if(ComboBox->ItemIndex == 0)
	{
		node *temp;
		temp = head;
		head = head->next;
		ComboBox->Items->Delete(0);
		Memo->Lines->Add("Модель уволена.");
		delete temp;
	}
	else{
		node *current;
		node *previous;
		current = head;

		if (current != NULL && !current->data.Name.Compare(ComboBox->Text))
		{
			current = current->next;
		}
		else
		{
			while (current != NULL && current->data.Name.Compare(ComboBox->Text)){
				previous = current;
				current = current->next;
				c = true;
			}
		}

		if(c)
		{
			Memo->Lines->Add("Модель уволена.");
			ComboBox->Items->Delete(ComboBox->ItemIndex);
		}

		previous->next = current->next;
	}
}

void list :: Elder(TComboBox*ComboBox, TMemo*Memo)
{
	node *temp = head;
	while(temp != NULL)
	{
		if(21 - (10*(temp->data.Birthday[8] - 48) + temp->data.Birthday[9] - 48) <= -29 )
		{
			ComboBox->Items->Add(temp->data.Name);
		}
		temp = temp->next;
	}
}

void list :: FindName(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Name)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindBirthday(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Birthday)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindPassport(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Passport)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindInsurance(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Insurance)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindEducation(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Education)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindPost(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Post)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindSalary(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Salary)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

void list :: FindHiring(TEdit*Edit, TMemo*Memo)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = head;
	while(temp != NULL)
	{
		if(!(Edit->Text.Compare(temp->data.Hiring)))
		{
			c = true;
			Memo->Lines->Add("Имя: " + temp->data.Name);
			Memo->Lines->Add("Дата: " + temp->data.Birthday);
			Memo->Lines->Add("Паспорт: " + temp->data.Passport);
			Memo->Lines->Add("Страховка: " + temp->data.Insurance);
			Memo->Lines->Add("Обрзование: " + temp->data.Education);
			Memo->Lines->Add("Должность: " + temp->data.Post);
			Memo->Lines->Add("Зарплата: " + IntToStr(temp->data.Salary));
			Memo->Lines->Add("Прием: " + temp->data.Hiring);
			Memo->Lines->Add("Комментарий: " + temp->data.Notes);
		}
		temp = temp->next;
	}

	if(temp == NULL && !c)
		Memo->Lines->Add("Модель не найдена.");
}

--------------------------------------
//---------------------------------------------------------------------------

#ifndef EmployeeH
#define EmployeeH
//---------------------------------------------------------------------------
#endif

class emp
{
	public:

	UnicodeString Name;
	UnicodeString Birthday;
	UnicodeString Passport;
	UnicodeString Insurance;
	UnicodeString Education;
	UnicodeString Post;
	int Salary;
	UnicodeString Hiring;
	UnicodeString Notes;

	emp(UnicodeString a, UnicodeString c, UnicodeString d, UnicodeString e, UnicodeString f, UnicodeString g, int h, UnicodeString i, UnicodeString j)
	{
		Name = a;
		Birthday = c;
		Passport = d;
		Insurance = e;
		Education = f;
		Post = g;
		Salary = h;
		Hiring = i;
		Notes = j;
	}

	emp(){ }

};

class list
	{

		private:

		struct node{

			emp data;
			node *next;

		};

		node *head, *tail;

		public:
		list(){
			head = NULL;
			tail = NULL;
		}

		void AddNode(emp value);

		void GetNode(TMemo*Memo);

		void DeleteElement(TComboBox*ComboBox, TMemo*Memo);

		void Elder(TComboBox*ComboBox, TMemo*Memo);

		void FindName(TEdit*Edit, TMemo*Memo);

		void FindBirthday(TEdit*Edit, TMemo*Memo);

		void FindPassport(TEdit*Edit, TMemo*Memo);

		void FindInsurance(TEdit*Edit, TMemo*Memo);

		void FindEducation(TEdit*Edit, TMemo*Memo);

		void FindPost(TEdit*Edit, TMemo*Memo);

		void FindSalary(TEdit*Edit, TMemo*Memo);

		void FindHiring(TEdit*Edit, TMemo*Memo);
	};
-----------------------
#include <vcl.h>
#include <tchar.h>
#include<cmath>
#include<math.h>
---------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Main.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Light");
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------



