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
    std::cout << "Hello World!\n";
    Automate automate;

    automate.creerLexique("lexique_1");
    //creerVerif()
    //modeAuto()
    //modeVersus()
    //bool EXIT = false;
    //bool estUnNumero(const string & reponse);

    /*string choixUser;
	string reponseUser = "";

    do {
		cout << "Choisissez entre l'option 1, 2 et 3: " << endl << endl
		    	<< "(1) Lire un lexique." << endl
				<< "(2) Mode Auto." << endl
				<< "(3) Mode Versus." << endl
				<< "Choix : ";

			cin >> choixUser;
		} while (!estUnNumero(choixUser) || !(choixUser == "1") || !(choixUser == "2") || !(choixUser == "3"));
*/
}

/*bool estUnNumero(const string& reponse) {
	string::const_iterator i = reponse.begin();
	while (i != reponse.end() && isdigit(*i)) ++i;
	if (!reponse.empty() && i == reponse.end())
		return true;
	else {
		cout << endl << "***Choisir une option valide***" << endl << endl;
		return false;
	}
}
*/

void modeAuto(const string& lexique){

	string motChoisiOrdinateur;

	vector<string> vecteurLexique;
    ifstream file(lexique);
    string line;

    while (getline(file, line)) vecteurLexique.push_back(line);
    
    motChoisiOrdinateur = vecteurLexique[rand() % vecteurLexique.size()];

	cout << "Entrer votre code: " << endl;
	string motUser;
	cin >> motUser;

	if(motUser == motChoisiOrdinateur){
		cout << "Felicitations! vous avez trouve le mot secret";
	} else {
		cout << "Mauvaise reponse! Voici le nombre d'erreurs: " << creerVerif(motUser) << endl;
	}
}

void modeVersus(const string& lexique){

	/*string motChoisiOrdinateur;

	vector<string> vecteurLexique;
    ifstream file(lexique);
    string line;

    while (getline(file, line)) vecteurLexique.push_back(line);

	string user1, user2;

	cout << "Choisir un code secret: ";
	cin >> user1;

	do{
		cout << "Ce mot n'existe pas dans le lexique.\n\n Suggestion(s)\n Aucune..."
			 << "Choisir un code secret: ";
			 cin >> user1;
	} while (!find(vecteurLexique.begin(), vecteurLexique.end(), user1) != vecteurLexique.end())
*/
}