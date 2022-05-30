#include "klasy.h"
#include <iostream>
using namespace std;

SamochodOsobowy::~SamochodOsobowy() {
	m_kierowca->ustawAuto(nullptr);
	m_kierowca = nullptr;
}

Kierowca::~Kierowca() {
	m_auto->ustawKierowce(nullptr);
	m_auto = nullptr;
}

void SamochodOsobowy::ustawKierowce(Kierowca* kier) {
	if (kier != nullptr) {
		if (kier->getUprawnienie() == KatPJ::B) {
			if (m_kierowca == nullptr) {
				m_kierowca = kier;
				m_kierowca->ustawAuto(this);
			}
			else {
				m_kierowca->ustawAuto(nullptr);
				m_kierowca = nullptr;
				m_kierowca = kier;
				m_kierowca->ustawAuto(this);
			}
		}
		else {
			cerr << "Zle kat" << endl;
			kier->ustawAuto(nullptr);
			m_kierowca = nullptr;
		}
	}
	else {
		m_kierowca = nullptr;
	}
	cerr << "Kierowca: " << m_kierowca << endl;
}

void Kierowca::ustawAuto(SamochodOsobowy* sam) {
	if (sam != nullptr) {
		m_auto = sam;
		m_auto->ustawKierowce(this);
	}
	else {
		m_auto = nullptr;
	}
}