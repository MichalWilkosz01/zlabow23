#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <cmath>
#include <iostream>


enum class TypTowaru { ciekly, sypki, paczkowany };
enum class KatPJ { A, B, C, D};

class Kierowca;


class SamochodOsobowy
{
private:
	//ZadanieA:
	Kierowca* m_kierowca = nullptr;



	char m_numerRej[9];
	double m_predkosc;
	int m_liczbaPasazerow;

	void setPredkosc(double i_pred) { m_predkosc = (i_pred > 160) ? i_pred : 160; }
	void setLiczbaPasazerow(int i_lp) { m_liczbaPasazerow = (i_lp > 1) ? i_lp : 1; }

public:
	//ZadanieA:
	void ustawKierowce(Kierowca* kier);
	~SamochodOsobowy();

	void setNumerRej(const char* i_num) { strncpy(m_numerRej, i_num, 8); }
	const char* getNumerRej() { return m_numerRej; }
	double getPredkosc() { return m_predkosc; }
	int getLiczbaPasazerow() { return m_liczbaPasazerow; }

	SamochodOsobowy(double i_pred, int i_lp, const char* i_num)
	{
		setPredkosc(i_pred);
		setLiczbaPasazerow(i_lp);
		setNumerRej(i_num);
	}
};


class Kierowca
{
private:
	//ZadanieA
	SamochodOsobowy* m_auto = nullptr;


	int m_staz;
	KatPJ m_uprawnienie;
public:
	void ustawAuto(SamochodOsobowy* sam);
	~Kierowca();

	void setUprawnienie(KatPJ i_upr) { m_uprawnienie = i_upr; }
	KatPJ getUprawnienie() { return m_uprawnienie; }
	int getStaz() { return m_staz; }
	void zwiekszStaz() { m_staz++; }
};

