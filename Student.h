#pragma once


#include <iostream>

using namespace std;


class Student
{
public:
	int nr;
	string imie;
	string nazwisko;

	Student(int nr, string imie, string nazwisko) {
		this->nr = nr;
		this->imie = imie;
		this->nazwisko = nazwisko;
	}

};
