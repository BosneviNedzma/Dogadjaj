#include <iostream>
#include <vector>
#include "Dogadjaj.h"

int glavniMeni() {
	cout << "1. Unesi dogadjaj\n";
	cout << "2. Ispisi dogadjaje\n";
	cout << "3. Rad sa dogadjajem\n";
	cout << "4. Kraj\n";

	int izbor;
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor>4);
	cin.ignore();
	return izbor;
}

int radSaDogadjajemMeni() {
	cout << "1. Unesi gosta\n";
	cout << "2. Unesi goste\n";
	cout << "3. Pretrati goste\n";
	cout << "4. Ispisi dogadjaj\n";
	cout << "5. Kraj\n";

	int izbor;
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor>5);
	cin.ignore();
	return izbor;
}

int main() {
	vector<Dogadjaj> dogadjaji;
	int izbor;
	do {
		shared_ptr<Dogadjaj>dogadjaj = make_shared<Dogadjaj>();
		izbor = glavniMeni();
		switch (izbor) {
		case 1:
			dogadjaj->unesiDogadjaj();
			dogadjaji.push_back(*dogadjaj);
			break;

		case 2:
			if (dogadjaji.size() == 0) {
				cout << "Trenutno nema dogadjaja\n";
				break;
			}
			cout << "Dogadjaji\n";
			cout << "R. broj\tNaziv\t\tMaksimalan broj gostiju\t\tTrenutno gostiju\n";
			for (int i = 0; i < dogadjaji.size(); i++) {
				*dogadjaj = dogadjaji[i];
				cout << i + 1 << "\t";
				cout << dogadjaj->getNaziv() << "\t\t";
				cout << dogadjaj->getMaxBrojGostiju() << "\t\t\t\t";
				cout << dogadjaj->dajTrenutniBrojGostiju() << endl;
			}
			break;
		case 3:
			unsigned int redniBroj;
			cout << "Unesi redni broj dogadjaja\n";
			cin >> redniBroj;

			if (redniBroj > dogadjaji.size()) {
				cout << "Ne postoji dogadjaj na tom rednom broju\n";
				break;
			}
			shared_ptr<Dogadjaj>nadjeniDogadjaj = make_shared<Dogadjaj>();
			*nadjeniDogadjaj = dogadjaji[redniBroj - 1];

			int izbor2;
			do {
				izbor2 = radSaDogadjajemMeni();
				switch (izbor2) {
				case 1:
					nadjeniDogadjaj->dodajGosta();
					break;
				case 2:
					nadjeniDogadjaj->dodajGoste();
					break;
				case 3:
					nadjeniDogadjaj->nadjiGoste();
					break;
				case 4:
					nadjeniDogadjaj->ispisDogadjaj();
					break;
				}
			} while (izbor2 != 5);
			break;
		}
	} while (izbor != 4);
}