//���������� ���������� ������ �����.

//�� ���� ��������� ��������� ��������� ������� :
//
//CHANGE_CAPITAL country new_capital � ��������� ������� ������ country �� new_capital, ���� ���������� ����� ������ � ����� ��������, ���� ������ � �� ����.
//RENAME old_country_name new_country_name � �������������� ������ �� old_country_name � new_country_name.
//ABOUT country � ����� ������� ������ country.
//DUMP � ����� ������ ���� �����.
//������ �����
//� ������ ������ ���������� ���������� �������� Q, � ��������� Q ������� � �������� ��������.��� �������� ����� � ������ ������� ���� �� ��������� ����, ���� � �������� �������������.
//
//������ ������
//�������� ��������� ��������� ������� ������� :
//
//� ����� �� ������ CHANGE_CAPITAL country new_capital ��������
//
//Introduce new country country with capital new_capital, ���� ������ country ������ �� ������������;
//Country country hasn't changed its capital, ���� ������ country �� �������� ������� ����� ������� new_capital;
//Country country has changed its capital from old_capital to new_capital, ���� ������ country �� �������� ������� ����� ������� old_capital, �������� ������� �� ��������� � ��������� new_capital.
//� ����� �� ������ RENAME old_country_name new_country_name ��������
//
//Incorrect rename, skip, ���� ����� �������� ������ ��������� �� ������, ������ old_country_name �� ���������� ��� ������ new_country_name ��� ����������;
//Country old_country_name with capital capital has been renamed to new_country_name, ���� ������ ��������� � ������ ����� ������� capital.
//� ����� �� ������ ABOUT country ��������
//
//Country country doesn't exist, ���� ������ � ��������� country �� ����������;
//Country country has capital capital, ���� ������ country ���������� � ����� ������� capital.
//� ����� �� ������ DUMP ��������
//
//There are no countries in the world, ���� ���� �� ���� ��������� �� ����� ������;
//���������� ��������� ���� country / capital, ����������� ������� ���� ����� � ������������� �� �������� ������, ���� � ���� ��� ���� ���� �� ���� ������.

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

void About(map<string, string> &guide) // ����� �� ������������� ��� ������ �����?
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
	cout << "��� ������ �������� �������:" << endl;
	cout << "�������� ������� ��� ������� ����� ������ - 1" << endl;
	cout << "������������� ������ - 2" << endl;
	cout << "������ ������� ������ - 3" << endl;
	cout << "������� ��� ���������� � ������� � �������� - 4" << endl;
	cout << "������ - 5" << endl;
	cout << "���������� ������ - 6" << endl;
}
