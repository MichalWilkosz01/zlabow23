#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*
*/
using namespace std;

#define ZadanieA 

#ifdef ZadanieD

class Osoba {

};

class ZamekCyfrowy {
private:
	mutable int klucz;
public:
	ZamekCyfrowy(int a) {
		klucz = a;
	}
	bool czyPoprawny(int x);
};

bool ZamekCyfrowy::czyPoprawny(int x) {
	if (x == klucz)
		return true;
	return false;
}

class Sejf {
private:
	int dane[5]{};
	Osoba* osoby[3] = { nullptr };
	ZamekCyfrowy m_zamek;
public:
	Sejf(int x); 
	void zapisDanych(Osoba* o, int klucz);
	void odczytDanych(Osoba* o, int klucz);
	void dodajOsobe(Osoba* o);
	void usunOsobe(int index);
};

Sejf::Sejf(int x)
	:m_zamek(x) 
{
	
}

void Sejf::zapisDanych(Osoba* o, int klucz) {
	for (int i = 0; i < 3; i++) {
		if (osoby[i] == o && m_zamek.czyPoprawny(klucz)) {
			cout << "Osoba uprawniona, zapis sie powiodl " << endl;		//Funkcjonalnosc metody do prezentacji w programie glownym
			for (int j = 0; j < 5; j++) {
				dane[j] = i;
			}
			return;
		}
	}
	cout << "Osoba nieuprawniona" << endl;
}

void Sejf::odczytDanych(Osoba* o, int klucz) {
	for (int i = 0; i < 3; i++) {
		if (osoby[i] == o && m_zamek.czyPoprawny(klucz)) {
			cout << "Osoba uprawniona " << endl;		//Funkcjonalnosc metody do prezentacji w programie glownym
			for (int j = 0; j < 5; j++) {
				cout << dane[j] << " ";
			}
			cout << endl;
			return;
		}
	}
	cout << "Osoba nieuprawniona" << endl;
}

void Sejf::dodajOsobe(Osoba* o) {
	int licznik = 0;
	for (int i = 0; i < 3; i++) {
		if (osoby[i] == nullptr) {
			osoby[i] = o;
			cout << "Dodano osobe do tablicy o indeksie " << i << endl; //Funkcjonalnosc metody do prezentacji w programie glownym
			return;
		}
		licznik++;
	}
	if (licznik == 3) {
		cout << "Blad, nalezy usunac osobe" << endl;
	}
}

void Sejf::usunOsobe(int index) {
	if (0 < index && index < 3) {
		osoby[index] = nullptr;
		cout << "Usunieto osobe z tablicy o indeksie " << index << endl; //Funkcjonalnosc metody do prezentacji w programie glownym
	}
}

int main()
{
	Sejf s01(15);
	Osoba os1, os2, os3, os4;
	s01.dodajOsobe(&os1);
	s01.dodajOsobe(&os2);
	s01.dodajOsobe(&os3);
	s01.dodajOsobe(&os4);
	s01.usunOsobe(1);
	s01.dodajOsobe(&os4);

	cout << endl << "Test zapisu i odczytu dla osoby uprawnionej: " << endl;
	s01.zapisDanych(&os3, 15);
	s01.odczytDanych(&os1, 15);

	cout << endl << "Test zapisu i odczytu dla osoby nieuprawnionej: " << endl;
	cout << "Zapis:" << endl;
	s01.zapisDanych(&os2, 15);
	cout << "Odczyt:" << endl;
	s01.odczytDanych(&os2, 15);
}

#endif

#ifdef ZadanieP

enum class TypTowaru { ciekly, sypki, paczkowany };

class SamochodCiezarowy
{
private:
	double m_predkosc;
	char m_numerRej[9];
	double m_pojemnosc;
	TypTowaru m_typ;

	void setPojemnosc(double i_poj) { m_pojemnosc = (i_poj > 1000) ? i_poj : 1000; }
	void setPredkosc(double i_pred) { m_predkosc = (i_pred > 160) ? i_pred : 160; }

public:
	void setTyp(TypTowaru i_typ) { m_typ = i_typ; }
	void setNumerRej(const char* i_num) { strncpy(m_numerRej, i_num, 8); }

	TypTowaru getTyp() { return m_typ; }
	const char* getNumerRej() { return m_numerRej; }
	double getPredkosc() { return m_predkosc; }
	double getPojemnosc() { return m_pojemnosc; }

	SamochodCiezarowy(double i_pred, double i_poj, TypTowaru i_typ, const char* i_num)
	{
		setPredkosc(i_pred);
		setPojemnosc(i_poj);
		setNumerRej(i_num);
		setNumerRej(i_num);
	}
};

class Flota {
private:
	SamochodCiezarowy* m_auta[20] = { nullptr };
	int licznik;
public:
	Flota();
	void dodajAuto(SamochodCiezarowy& s);
	void usunAuto(SamochodCiezarowy& s);
	int ileAut();
};

Flota::Flota() {
	licznik = 0;
}

void Flota::dodajAuto(SamochodCiezarowy& s) {
	int czyByl = 0;
	for (int i = 0; i < 20; i++) {
		if (m_auta[i] == &s) {
			czyByl = 1;
			return;
		}
	}
	if (czyByl != 1) {
		for (int i = 0; i < 20; i++) {
			if (m_auta[i] == nullptr) {
				m_auta[i] = &s;
				licznik++;
				return;
			}		
		}

	}
}

void Flota::usunAuto(SamochodCiezarowy& s) {
	if (licznik != 0) {
		for (int i = 0; i < licznik; i++) {
			if (m_auta[i] == &s) {
				m_auta[i] = nullptr;
				swap(m_auta[i], m_auta[licznik - 1]);
				licznik--;
			}
		}
	}
}

int Flota::ileAut() {
	return licznik;
}

int main()
{
	SamochodCiezarowy s01(1, 250, TypTowaru::ciekly, "MAN");
	SamochodCiezarowy s02(1, 250, TypTowaru::ciekly, "MAN");
	Flota f01;
	f01.dodajAuto(s01);
	f01.dodajAuto(s01);
	f01.dodajAuto(s02);
	cout << f01.ileAut() << endl;
	f01.usunAuto(s02);
	cout << f01.ileAut() << endl;
}

#endif

#ifdef ZadanieA

#include "klasy.h"

int main()
{
	Kierowca k01, k02, k03;
	k01.setUprawnienie(KatPJ::B);
	k02.setUprawnienie(KatPJ::C);
	k03.setUprawnienie(KatPJ::B);
	
	SamochodOsobowy s01(1, 3, "Opel Coersa C");
	s01.ustawKierowce(&k01);
}

#endif




