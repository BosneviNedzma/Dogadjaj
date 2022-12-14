#pragma once
#include "Gost.h"
#include "Datum.h"
#include <vector>
#include <string>

using namespace std;

class Dogadjaj {
private:
	char naziv[100], grad[50], opis[1000];
	unsigned int maxBrojGostiju;
	Datum datum;
	vector<Gost>gosti;


public:
	Dogadjaj();
	void setNaziv();
	void setOpis();
	void setGrad();
	void setMaxBrojGostiju();
	void setDatum();
	void dodajGosta();
	char* getNaziv();
	char* getOpis();
	char* getGrad();
	unsigned int getMaxBrojGostiju();
	Datum getDatum();
	string danOdrzavanja();
	vector<Gost>& dajGoste();
	void nadjiGoste();
	void unesiDogadjaj();
	void ispisDogadjaj();
	void dodajGoste();
	bool daLiImaGostiju();
	unsigned int dajTrenutniBrojGostiju();
	~Dogafjaj() = default;
};