#include "Gost.h"
#include <iostream>
#include <string>

using namespace std;

Gost::Gost() {
	strcpy(this->ime, "Ime");
	strcpy(this->prezime, "Prezime");
	strcpy(this->emial, "Email");
	this->dolaziSam = true;
}

void Gost::setIme() {
	cout << "Unesite ime: " << endl;
	cin.getline(this->ime, 20);
}

void Gost::setPrezime() {
	cout << "Unesite prezime: \n";
	cin.getline(this->prezime, 30);
}

void Gost::setEmail() {
	cout << "Unesite email: " << endl;
	cin.getline(this->emial, 50);
}

void Gost::kakoDolazi() {
	int broj;
	cout << "Kako gost dolazi? Sam ili +1. Unesite 0 za sam ili 1 za +1\n";
	cin >> broj;
	this->dolaziSam = broj == 0;
}

char* Gost::getIme() {
	return this->ime;
}

char* Gost::getPrezime() {
	return this->prezime;
}

char* Gost::getEmail() {
	return this->emial;
}

bool Gost::getDolaziSam() {
	return this->dolaziSam;
}

string Gost::daLiDolaziSam() {
	if (this->dolaziSam) {
		return "Da";
	}

	return "+1";
}

void Gost::unesiGosta() {
	cout << "Unos gosta " << endl;
	this->setIme();
	this->setPrezime();
	this->kakoDolazi();
}

bool Gost::pretraziGosta(char* upit) {
	return strcmpi(this->ime, upit) == 0 || strcmpi(this->prezime, upit) == 0 || strcmpi(this->emial, upit) == 0;
}

bool Gost::pretraziPoEmailu(char* email) {
	return strcmpi(this->emial, emial) == 0;
}