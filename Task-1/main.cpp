#include<string>
#include<iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person person("Yakovlev", "Ivan", "Mihailovich");
	person.Show();
	person.ShowFormal();

	return 0;
}