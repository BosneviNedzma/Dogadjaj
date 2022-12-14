#pragma once
#include <cstring>
using namespace std;

class Gost {
private:
	char ime[20], prezime[30], emial[50];
	bool dolaziSam;

public:
	Gost();
	void setIme();
	void setPrezime();
	void setEmail();
	void kakoDolazi();
	char* getIme();
	char* getPrezime();
	char* getEmail();
	bool getDolaziSam();
	string daLiDolaziSam();
	void unesiGosta();
	bool pretraziGosta(char* upit);
	bool pretraziPoEmailu(char* email);
	~Gost(){}
};
