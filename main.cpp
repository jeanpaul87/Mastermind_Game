#include <iostream>
#include <fstream>
#include <string> 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Automate.h"

int main()
{
    Automate automate;

    bool estUnNumero(const string & reponse);
	bool estValide(const string & reponse);

	bool EXIT = false;

    string choixUser, choixUserCase2, choixUserCase3, guessUserCase3;
	string reponseUser = "";
	string nomLexique = "";

while(!EXIT){
    do {
		cout<< endl << "Choisissez entre l'option 1, 2 et 3: " << endl << endl
		    << "(1) Lire un lexique." << endl
			<< "(2) Mode Auto." << endl
			<< "(3) Mode Versus." << endl
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

				cout << motRandom;

				do {
					cout << "Entrez un mot a deviner d'une taille de " << motRandom.size() << " caracteres:\n";
					cin >> choixUserCase2;

				} while (!automate.creerVerif(motRandom, choixUserCase2));
				break;
			}
			case 3: {

				do{
				cout << "Entrez le code secret que l'usager devrait deviner: ";
				cin >> choixUserCase3;
				automate.suggestionDeMot(choixUserCase3);
				} while(!automate.getilyAUnMot());
				
				//cout<<'\n'<<boolalpha<<automate.isDansLaListeSuggere(choixUserCase3);

				cout << "Devinez le mot entre: ";
				cin >> guessUserCase3;

				automate.creerVerif(choixUserCase3, guessUserCase3);

				EXIT = true;
				break;
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

	if (reponse == un || reponse == deux || reponse == trois)
		return true;
	else {
		cout << endl << "***Choisir une option valide***" << endl << endl;
		return false;
	}
}




/*void modeVersus(const string& lexique){

	string motChoisiOrdinateur;

	vector<string> vecteurLexique;
    ifstream file(lexique);
    string line;

    while (getline(file, line)) vecteurLexique.push_back(line);

	string user1, user2;

	cout << "Choisir un code secret: ";
	cin >> user1;

	do{
		cout << "Ce mot n'existe pas dans le lexique.\n\n Suggestion(s)\n 
		..."
			 << "Choisir un code secret: ";
			 cin >> user1;
	} while (!find(vecteurLexique.begin(), vecteurLexique.end(), user1) != vecteurLexique.end())


}*/