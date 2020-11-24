#include "Automate.h"


Automate::Automate(): nbEtats_(0), etatInitial_(new Etat("INIT", false, 0))
{
}

Automate::~Automate()
{
}

void Automate::creerLexique(const string& lexique)
{
	Etat* etatActuelle = NULL;
	ifstream fichier(lexique + ".txt");
	if (fichier) {
		cout << "Access completed";
            

		while (!fichier.eof()) {
            
			string mot;
			etatActuelle = etatInitial_;
			getline(fichier, mot);
			if (mot == "bkbbr")
			{
				int f = 8;
			}
			//iterer chaque lettre du mot
			for (int i = 0; i < mot.size(); i++)
			{
				char& a = mot[i];
				string s(1, a);
				//verifier si on a pas un voisin de la lettre 
				if (!etatActuelle->voisinTrouver(s)) {
					etatActuelle->ajouterEtat(new Etat(s, (i==(mot.size()-1)), i+1));//peut etre on va faire i+1
					etatActuelle->ajouterSigma(s);
					etatActuelle = etatActuelle->getListEtatSuivant().back();
				}

				else {
						for (int j = 0; j < etatActuelle->getListEtatSuivant().size(); j++)
						{
							if (etatActuelle->getListEtatSuivant().at(j))
							{
								etatActuelle = etatActuelle->getListEtatSuivant().at(j);
								break;
							}
						}
				}
			}
			/*for (int i = 0; i < etatInitial_->getListEtatSuivant().size(); i++) {
				cout << etatInitial_->getListEtatSuivant().at(i);
			}
			*/
			
		}
	}
	else { cout << "ERREUR D'OUVERTURE DU FICHIER"; }

	Etat* b = etatInitial_;
}
int Automate::creerVerif( const string& codeSecret) {//bbbbb
	int nbFausseLettre = 0;
	Etat* tempEtat = etatInitial_;

	for (int i = 0; i < codeSecret.size(); i++)
	{
		std::string s(1, codeSecret[i]);
		if (tempEtat->getNomEtatvoisin((char&)codeSecret[i]) != codeSecret[i]) {
			nbFausseLettre++;
		}
		tempEtat = tempEtat->getEtatSuivant(s);
	}
	return nbFausseLettre;
}