// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "TimeSpan.h"
#include <iomanip>
#include <vector>
#include "Student.h"
#include <string>
#include <fstream>

using namespace std;


int main()
{
	TimeSpan ts(1);
	ts.print();
	int indeks;
	string imie;
	string nazwisko;
	vector<Student> bazaStudentow;
	bool dziala = 1;
	int nr;
	while (dziala) {
		cout << "co chcesz zrobic?" << endl;
		cout << "1 - dodaj studenta" << endl;
		cout << "2 - wypisz cala liste studentow" << endl;
		cout << "3 - wyszukaj po nr indeksu" << endl;
		cout << "4 - usun z bazy po nr indeksu" << endl;
		cout << "5 - zapisz baze do pliku" << endl;
		cout << "6 - wczytaj baze z pliku" << endl;
		cout << "7 - usun wszystkich studentow z bazy" << endl;
		cout << "0 - zakoncz" << endl;
		cin >> nr;
		switch (nr) {
		case 1: {
			cout << "podaj indeks, imie i nazwisko studenta" << endl;
			cin >> indeks >> imie >> nazwisko;
			Student s1(indeks, imie, nazwisko);
			bazaStudentow.push_back(s1);
			break;
		}
		case 2: {
			for each (Student s in bazaStudentow)
			{
				cout << s.imie << " " << s.nazwisko << " " << s.nr << endl;
			}
			break;
		}
		case 3: {
			cout << "podaj nr indeksu" << endl;
			cin >> nr;
			for each (Student s in bazaStudentow)
			{
				if (nr == s.nr) {
					cout << s.imie << " " << s.nazwisko << " " << s.nr << endl;
				}
			}
			break;
		}
		case 4: {
			cout << "podaj nr indeksu" << endl;
			cin >> nr;
			for (int i = 0; i < bazaStudentow.size() - 1; i++) {
				if (nr == bazaStudentow[i].nr) {
					bazaStudentow.erase(bazaStudentow.begin() + i);
				}
			}
			break;
		}
		case 5: {
			fstream dopliku;
			dopliku.open("baza.txt", ios::out, ios::trunc);
			if (dopliku.good()) {
				for (int i = 0; i < bazaStudentow.size(); i++) {
					dopliku << bazaStudentow[i].nr << " " << bazaStudentow[i].imie << " " << bazaStudentow[i].nazwisko << endl;
					//cout << bazaStudentow[i].nr << " " << bazaStudentow[i].imie << " " << bazaStudentow[i].nazwisko << endl;
				}
			}
			else cout << "blad otwarcia" << endl;
			dopliku.close();
			break;
		}
		case 6: {
			fstream zpliku;
			zpliku.open("baza.txt", ios::in);
			string napis;
			cout << "Zawartosc pliku:" << endl;
			if (zpliku.good()) {
				while (!zpliku.eof()) {
					zpliku >> nr >> imie >> nazwisko;
					//cout << nr << imie << nazwisko << endl;
					Student newStudent(nr, imie, nazwisko);
					//cout << newStudent.nr << newStudent.imie << newStudent.nazwisko << endl;
					bazaStudentow.push_back(newStudent);
				}
				cout << "baza zostala pobrana pomyslnie" << endl;
			} 
			else { cout << "blad" << endl; }
			zpliku.close();
			break;
		}
		case 7: {
			for (int i = 0; i < bazaStudentow.size() - 1; i++) {
				bazaStudentow.erase(bazaStudentow.begin() + i);
			}
			break;
		}
		case 0: {
			dziala = 0;
			break;
		}
		default: {
			dziala = 0;
			break;
		}
		}
	}
	return 0;
}













////////////////////////////////////////////////





//////////////////////////////////////