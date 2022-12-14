#include "Dogadjaj.h"
#include "Gost.h"
#include "Datum.h"

#include <memory>
#include <iostream>
#include <string>

using namespace std;

Dogadjaj::Dogadjaj() {
	strcpy(this->naziv, "Naziv");
	strcpy(this->opis, "Neki opis");
	strcpy(this->grad, "Grad");
	this->maxBrojGostiju = 100;
}

void Dogadjaj::setNaziv() {
	cout << "Unesite naziv: \n";
	cin.getline(this->naziv, 100);
}

void Dogadjaj::setOpis() {
	cout << "Unesite opis: \n";
	cin.getline(this->opis, 1000);
}

void Dogadjaj::setGrad() {
	cout << "Unesite grad: \n";
	cin.getline(this->grad, 50);
}

void Dogadjaj::setMaxBrojGostiju() {
	cout << "Unesite maksimalan broj gostiju: \n";
	cin >> this->maxBrojGostiju;
}

void Dogadjaj::setDatum() {
	cout << "Unesite datum dogadjaja: \n";
	this->datum.postaviDatum();
}

void Dogadjaj::dodajGosta() {
	if (this->dajTrenutniBrojGostiju() >= this->getMaxBrojGostiju()) {
		cout << "Nema vise dovoljno mjesta za sve goste\n";
		return;
	}

	cout << "Unos gosta \n";
	shared_ptr<Gost>gost = make_shared<Gost>();
	gost->setEmail();

	bool gostPostoji = false;
	for (int i = 0; i < this->dajGoste().size(); i++) {
		if (this->gosti[i].pretraziPoEmailu(gost->getEmail())) {
			gostPostoji = true;
			break;
		}
	}
	if (gostPostoji) {
		cout << "Gost sa " << gost->getEmail() << " vec dolazi na dogadjaj \n";
		this->dodajGosta();
	}
	else {
		gost->unesiGosta();
		this->dajGoste().push_back(*gost);
	}
}

char* Dogadjaj::getNaziv() {
	return this->naziv;
}

char* Dogadjaj::getOpis() {
	return this->opis;
}

char* Dogadjaj::getGrad() {
	return this->grad;
}

unsigned int Dogadjaj::getMaxBrojGostiju() {
	return this->maxBrojGostiju;
}

Datum Dogadjaj::getDatum() {
	return this->datum;
}

string Dogadjaj::danOdrzavanja() {
	return this->getDatum().getDatum();
}

vector<Gost>& Dogadjaj::dajGoste() {
	return this->gosti;
}

void Dogadjaj::nadjiGoste() {
	if (this->daLiImaGostiju() == false) {
		cout << "Trenutno nema gostiju za ovaj dogadjaj! \n";
	}

	else {
		char upit[50];
		cout << "Unesite ime ili prezimme ili email gosta\n";
		cin.getline(upit, 50);
		shared_ptr<Dogadjaj>dogadjaj = make_shared<Dogadjaj>();
		for (int i = 0; i < this->dajGoste().size(); i++) {
			if (this->gosti[i].pretraziGosta(upit)) {
				dogadjaj->dajGoste().push_back(this->dajGoste()[i]);
			}
		}
		if (dogadjaj->daLiImaGostiju()) {
			dogadjaj->ispisDogadjaj();
		}
		else {
			cout << "Nazalost nema gosta sa unesenim upitom!\n";
		}
	}
}

void Dogadjaj::unesiDogadjaj() {
	cout << "Unos dogadjaja\n";
	this->setNaziv();
	this->setOpis();
	this->setGrad();
	this->setMaxBrojGostiju();
	this->setDatum();
}

void Dogadjaj::ispisDogadjaj() {
	cout << "Informacije o dogadjaju: \n";
	cout << "Naziv: " << this->getNaziv() << endl;
	cout << "Opis: " << this->getOpis() << endl;
	cout << "Grad: " << this->getGrad() << endl;
	cout << "Maksimalan broj gostiju: " << this->getMaxBrojGostiju() << endl;
	if (this->daLiImaGostiju() == false) {
		cout << "Trenutno niko ne ide na ovaj dogadjaj.\n";
	}
	else {
		shared_ptr<Gost>gost = make_shared<Gost>();
		cout << "GOSTI\n";
		cout << "R. broj\tIme\t\tPrezime\t\tEmail\t\tDolazi sam\n";
		for (int i = 0; i < this->dajGoste().size(); i++) {
			*gost = this->dajGoste()[i];
			cout << i + 1 << "\t";
			cout << gost->getIme() << "\t\t";
			cout << gost->getPrezime() << "\t\t";
			cout << gost->getEmail() << "\t\t";
			cout << gost->daLiDolaziSam() << "\n";
		}
	}
}

void Dogadjaj::dodajGoste() {
	cout << "Dodavanje gostiju. Unesi 0 za izlaz ili bilo koji drugi broj za nastavak\n";
	int broj;
	cin >> broj;
	while (broj != 0) {
		this->dodajGosta();
		cout << "Zelite nastaviti! Unesite 0 za prekid, ili bilo koji drugi broj za nastavak\n";
		cin >> broj;
	}
}

bool Dogadjaj::daLiImaGostiju() {
	return this->dajGoste().size() > 0;
}

unsigned int Dogadjaj::dajTrenutniBrojGostiju() {
	unsigned int brojGostiju = 0;
	shared_ptr<Gost>gost = make_shared<Gost>();
	for (int i = 0; i < this->dodajGoste().size(); i++) {
		*gost = this->dajGoste()[i];
		if (gost->getDolaziSam()) {
			brojGostiju++;
		}

		else {
			brojGostiju += 2;
		}
	}
	return brojGostiju;
}