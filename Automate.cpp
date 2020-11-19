#include "Automate.h"


Automate::Automate(): nbEtats_(0), etatInitial_(new Etat("INIT", false, 0))
{
}

Automate::~Automate()
{
}

void Automate::creerLexique(const string& lexique)
{
	ifstream fichier(lexique + ".txt");
	if (fichier) {
		cout << "Access completed";
            
		while (!fichier.eof()) {
            
			string mot;
			cout << "\n\n";
			getline(fichier, mot);
			Etat* etatActuelle = etatInitial_;
			//iterer chaque lettre du mot
			for (int i = 0; i < mot.size(); i++)
			{
				char& a = mot[i];
				string s(1, a);
				if (!etatActuelle->voisinTrouver(s)) {
					etatActuelle->ajouterEtat(new Etat(s, (i==(mot.size()-1)), i));
					etatActuelle->ajouterSigma(s);
				}//On est aarriveee ici !!!
			}
			for (int i = 0; i < mot.size(); i++) {
				//cout<< 
			}
			
		}
	}
	else { cout << "ERREUR D'OUVERTURE DU FICHIER"; }
}