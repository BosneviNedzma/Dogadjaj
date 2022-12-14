#pragma once
#include <string>
using namespace std;

class Datum {
private:
	int dan, mjesec, godina;
	void postaviDan(int min, int max);
	int zellerAlgoritam(int dan, int mjesec, int zadnjeDvijeCifre, int prveDvijeCifre);

public:
	Datum();
	void setDan();
	void setMjesec();
	void setGodina();
	int getDan();
	int getMjesec();
	int getGodina();

	void postaviDatum();
	void ispisDatum();
	string getDatum();
	string nazivDana();

	~Datum() {};
};