#include <iostream>
#include <fstream>
#include <string> 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Automate.h"

using namespace std;

int main()
{
	Automate automate;

	bool estUnNumero(const string & reponse);
	bool estValide(const string & reponse);

	bool EXIT = false;
	bool reponse = false;

	string choixUser, choixUserCase2, choixUserCase3, guessUserCase3, decisionUserCase3;
	string reponseUser = "";
	string nomLexique = "";
	int numeroPartie = 1;
	int numeroEssai = 1;

	while (!EXIT) {
		do {
			cout<< endl << "Choisissez entre l'option 1, 2, 3 et 4: " << endl << endl
				<< "(1) Lire un lexique." << endl
				<< "(2) Mode Auto." << endl
				<< "(3) Mode Versus." << endl
				<< "(4) EXIT." << endl
				<< "Choix : ";

			cin >> choixUser;
		} while (!estUnNumero(choixUser) || !estValide(choixUser));

		switch (stoi(choixUser)) {
			case 1: {

				cout << "Entrez le nom du lexique (sans le .txt):";
				cin >> nomLexique;
				automate.creerLexique(nomLexique);
				break;
			}
			case 2: {
				string motRandom = automate.modeAuto();

				do {
					do {
						cout << "Entrez un mot a deviner d'une taille de " << motRandom.size() << " caracteres:\n";
						cin >> choixUserCase2;
					} while (choixUserCase2.size() != motRandom.size());
				} while (!automate.creerVerif(motRandom, choixUserCase2));
				break;
			}
			case 3: {


				do {
					cout << endl << "Debut de la partie " << numeroPartie << endl;
					cout << "Entrez le code secret que l'usager devrait deviner: ";
					cin >> choixUserCase3;
					automate.suggestionDeMot(choixUserCase3);

					if (automate.getilyAUnMot() == true) {

						do {
							cout << "Voulez-vous selectionner ce code? (1:oui/0:non)";
							cin >> decisionUserCase3;

							if (decisionUserCase3 == "1") {
								break;
							}

							if (decisionUserCase3 == "0") {
								cout << "Entrez le code secret que l'usager devrait deviner: ";
								cin >> choixUserCase3;
								automate.suggestionDeMot(choixUserCase3);
							}

						} while (!estUnNumero(decisionUserCase3) || decisionUserCase3 == "0" || !(decisionUserCase3 == "1"));
					}

				} while (!automate.getilyAUnMot());

				do {
					cout << "Devinez le mot entre: ";
					cin >> guessUserCase3;
					if (choixUserCase3.size() == guessUserCase3.size()) {
						if (automate.creerVerif(choixUserCase3, guessUserCase3) == true) {
							reponse = true;
						}
					}
					else {
						reponse = false;
					}
					numeroEssai++;

				} while (numeroEssai < 16 && reponse == false);

				numeroPartie++;
				break;
			}
			case 4: {
				EXIT = true;
			}
		}

	}
}

bool estUnNumero(const string& reponse) {
	string::const_iterator i = reponse.begin();
	while (i != reponse.end() && isdigit(*i)) ++i;
	if (!reponse.empty() && i == reponse.end())
		return true;
	else {
		cout << endl << "***Choisir une option valide***" << endl << endl;
		return false;
	}
}

bool estValide(const string& reponse) {

	string un = "1";
	string deux = "2";
	string trois = "3";
	string quatre = "4";

	if (reponse == un || reponse == deux || reponse == trois || reponse == quatre)
		return true;
	else {
		cout << endl << "***Choisir une option valide***" << endl << endl;
		return false;
	}
}