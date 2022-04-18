//Реализуйте справочник столиц стран.

//На вход программе поступают следующие запросы :
//
//CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
//RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
//ABOUT country — вывод столицы страны country.
//DUMP — вывод столиц всех стран.
//Формат ввода
//В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов.Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода
//Выведите результат обработки каждого запроса :
//
//В ответ на запрос CHANGE_CAPITAL country new_capital выведите
//
//Introduce new country country with capital new_capital, если страны country раньше не существовало;
//Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
//Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
//В ответ на запрос RENAME old_country_name new_country_name выведите
//
//Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
//Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.
//В ответ на запрос ABOUT country выведите
//
//Country country doesn't exist, если страны с названием country не существует;
//Country country has capital capital, если страна country существует и имеет столицу capital.
//В ответ на запрос DUMP выведите
//
//There are no countries in the world, если пока не было добавлено ни одной страны;
//разделённые пробелами пары country / capital, описывающие столицы всех стран и упорядоченные по названию страны, если в мире уже есть хотя бы одна страна.

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

void ChangeCapital(map<string, string>& guide);
void Rename(map<string, string>& guide);
void About(map<string, string>& guide);
void Dump(const map<string, string>& guide);
void Info();
map<string, string> Reverse(const map<string, string> guide);


int main()
{
	map<string, string> Guide;
	bool Exit = false;
	Info();
	while (!Exit)
	{ 
		string operation;
		cin >> operation;
		if (operation == "1") ChangeCapital(Guide);
		if (operation == "2") Rename(Guide);
		if (operation == "3") About(Guide);
		if (operation == "4") Dump(Guide);
		if (operation == "5") Info();
		if (operation == "6") Exit = true;
	}
	return 0;
}


map<string, string> Reverse(const map<string, string> guide)
{
	map<string, string> reversed;
	for (auto item : guide)
	{
		reversed[item.second] = item.first;
	}
	return reversed;
}

void ChangeCapital(map<string, string> &guide)
{
	string newCapital, oldCapital, country;
	bool isExist = false;
	bool isSame = false;
	cin >> country >> newCapital;

	if (guide.count(country)) isExist = true;
	oldCapital = guide[country];
	guide[country] = newCapital;
	if (newCapital == oldCapital) isSame = true;
	if (isExist)
	{
		if (isSame) cout << "Country " << country << " hasn't changed its capital" << endl;
		else cout << "Country " << country << " has changed its capital from " << oldCapital << " to " << newCapital << endl;
	}
	else
	{
		cout << "Introduce new country " << country << " with capital " << newCapital << endl;
	}
}

void Rename(map<string, string> &guide)
{
	string oldCountry, newCountry, capital;
	//map<string, string> reverseGuide = Reverse(guide);
	bool isSame = false; // false
	bool isExistOld = false; // true
	bool isExistNew = false; // false

	cin >> oldCountry >> newCountry;
	if (oldCountry == newCountry) isSame = true;
	if (guide.count(newCountry)) isExistNew = true;
	if (guide.count(oldCountry)) isExistOld = true;
	if (isSame || isExistNew || !isExistOld)
		cout << "Incorrect rename, skip" << endl;
	else
	{
		capital = guide[oldCountry];
		guide[newCountry] = capital;
		guide.erase(oldCountry);
		cout << "Country " << oldCountry << " with capital " << capital << " has been renamed to " << newCountry << endl;
	}
}

void About(map<string, string> &guide) // нужно ли реверсировать для поиска ключа?
{
	string country;
	bool isExist = false;

	cin >> country;
	if (guide.count(country)) isExist = true;
	if (isExist) cout << "Country " << country << " has capital " << guide[country] << endl;
	else cout << "Country " << country << " doesn't exist" << endl;

}

void Dump(const map<string, string> &guide)
{
	if (!guide.size()) cout << "There are no countries in the world" << endl;
	else
	{
		for (auto item : guide) cout << item.first << "/" << item.second << " ";
	}
}

void Info() {
	cout << "Для выбора действия введите:" << endl;
	cout << "Изменить столицу или создать новую страну - 1" << endl;
	cout << "Переименовать страну - 2" << endl;
	cout << "Узнать столицу страны - 3" << endl;
	cout << "Вывести всю информацию о странах и столицах - 4" << endl;
	cout << "Помощь - 5" << endl;
	cout << "Завершение работы - 6" << endl;
}
