//–еализуйте справочник столиц стран.

//Ќа вход программе поступают следующие запросы :
//
//CHANGE_CAPITAL country new_capital Ч изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше еЄ не было.
//RENAME old_country_name new_country_name Ч переименование страны из old_country_name в new_country_name.
//ABOUT country Ч вывод столицы страны country.
//DUMP Ч вывод столиц всех стран.
//‘ормат ввода
//¬ первой строке содержитс€ количество запросов Q, в следующих Q строках Ч описани€ запросов.¬се названи€ стран и столиц состо€т лишь из латинских букв, цифр и символов подчЄркивани€.
//
//‘ормат вывода
//¬ыведите результат обработки каждого запроса :
//
//¬ ответ на запрос CHANGE_CAPITAL country new_capital выведите
//
//Introduce new country country with capital new_capital, если страны country раньше не существовало;
//Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
//Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
//¬ ответ на запрос RENAME old_country_name new_country_name выведите
//
//Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
//Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.
//¬ ответ на запрос ABOUT country выведите
//
//Country country doesn't exist, если страны с названием country не существует;
//Country country has capital capital, если страна country существует и имеет столицу capital.
//¬ ответ на запрос DUMP выведите
//
//There are no countries in the world, если пока не было добавлено ни одной страны;
//разделЄнные пробелами пары country / capital, описывающие столицы всех стран и упор€доченные по названию страны, если в мире уже есть хот€ бы одна страна.

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

void ChangeCapital(map<string, string>& guide);
void Rename(map<string, string>& guide);
void About(map<string, string>& guide);
void Dump(const map<string, string>& guide);
map<string, string> Reverse(const map<string, string> guide);

int main()
{
	map<string, string> Guide;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{ /////////////////////////////////////////////////
		string operation;
		cin >> operation;
		if (operation == "CHANGE_CAPITAL") ChangeCapital(Guide);
		if (operation == "RENAME") Rename(Guide);
		if (operation == "ABOUT") About(Guide);
		if (operation == "DUMP") Dump(Guide);
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

void About(map<string, string> &guide) // нужно ли реверсировать дл€ поиска ключа?
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


