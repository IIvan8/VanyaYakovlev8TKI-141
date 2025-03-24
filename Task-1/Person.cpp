#include<string>
#include<iostream>
#include "Person.h"

Person::Person()
{
	lastname = "";
	firstname = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& fn, const string& pn)
{
	lastname = ln;
	firstname = fn;
	patronymic = pn;
}

void Person::Show()
{
	cout << "LastName: " << lastname << endl;
	cout << "FirstName: " << firstname << endl << endl;
}

void Person::ShowFormal()
{
	cout << "LastName:" << lastname << endl;
	cout << "FirstName:" << firstname << endl;
	cout << "Patronymic:" << patronymic << endl << endl;
}