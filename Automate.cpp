#include "Automate.h"
#include <list>
#include <queue>
#include <time.h>


Automate::Automate(): etatInitial_(new Etat(' ', false, 0,""))
{
}

Automate::~Automate()
{
}

void Automate::creerLexique(const string& lexique)
{
	Etat* etatActuelle;
	ifstream fichier(lexique + ".txt");
	if (fichier) {
		cout << "Access completed";
            

		while (!fichier.eof()) {
            
			string mot;
			string lettrePrecedantesDeEtat= "";
			etatActuelle = etatInitial_;
			getline(fichier, mot);
			if (mot == "byyyy")
				int a = 0;

			//iterer chaque lettre du mot
			for (int i = 0; i < mot.size(); i++)
			{
				char a = mot[i];
				//string s(1, a);
				
				//verifier si on a pas un voisin de la lettre 
				if (!etatActuelle->voisinTrouver(a)) {
					etatActuelle->ajouterEtat(new Etat(a, (i == (mot.size() - 1)), i + 1,mot));

						if (i > 0)
							lettrePrecedantesDeEtat = mot.substr(0, etatActuelle->getNumeroEtat());
						etatActuelle->setLettrePrecedantesDeEtat(lettrePrecedantesDeEtat );
				}

				for (int j = 0; j < etatActuelle->getListEtatSuivant().size(); j++)
				{
					if (etatActuelle->getListEtatSuivant().at(j)->getNomDeEtat() == a) {
						etatActuelle = etatActuelle->getListEtatSuivant().at(j);
					}
					
				}
				
			}

			
		}
	}
	else { cout << "ERREUR D'OUVERTURE DU FICHIER"; }

	Etat* b = etatInitial_;

}


//prendre en parametre l'automate mot a la place dun string
bool Automate::creerVerif( const string& codeSecret, const string& codeEssayer ) {//PE ETRE ON VA LE CHANGER !!
	int nbFausseLettre = 0;
	Etat* tempEtat = etatInitial_;

	for (int i = 0; i < codeSecret.size(); i++){
		tempEtat = tempEtat->getEtatSuivant(codeSecret[i]);
			if (tempEtat->getNomDeEtat() != codeEssayer[i]) {
				nbFausseLettre++;
			}
		//cout << '\n'<<tempEtat->getNomDeEtat();
		
	}
	cout << "\nVous assez " << nbFausseLettre << " lettre faux.\n";

	if (nbFausseLettre == 0) {
		return true;
	}
	else {
		return false;
	}
}

Etat* Automate::getEtatIniatale() {
	return etatInitial_;
}
void Automate::suggestionDeMot(const string& inputDeLUtilisateur) {

	queue<Etat*> queue;
	Etat* iterateur = etatInitial_;
	bool motEstValide = false;
	int compteurDeSuggetsion = 1;
	setilyAUnMot(false);
	while (!queue.empty())
	{
		queue.pop();
	}
	cout << "\n\nSuggestion(s)\n";
		for (int i = 0; i < inputDeLUtilisateur.size(); i++)
		{
			iterateur->vientDeSeVisiter();
			iterateur = iterateur->getEtatSuivant(inputDeLUtilisateur[i]);
			
		}if (iterateur->estSortie()) {
			motEstValide = true;
		}
		for (int i = 0; i < iterateur->getListEtatSuivant().size(); i++)
		{
			queue.push(iterateur->getListEtatSuivant()[i]);
		}
		if (iterateur->estSortie())
			setilyAUnMot(true);
		while (!queue.empty())
		{
			iterateur = queue.front();
			iterateur->vientDeSeVisiter();
			if (iterateur->estSortie()) {
				cout << iterateur->getLettrePrecedantesDeEtat() << "\n";
				motSugere_.push_back(iterateur->getLettrePrecedantesDeEtat());
				//cout << motSugere_.back() << "\n";
				compteurDeSuggetsion++;
				motExistePas_ = false;
			}
			queue.pop();
			for (auto i : iterateur->getListEtatSuivant()) {
				if (!i->getEstVisiter())
					queue.push(i);
			}
		}	
		/*if (!ilyAUnMot) {
			cout << "\nAucune...\n\n";
		}
		else {
			motExistePas_ = true;
		}*/
}

string Automate::modeAuto() {

			srand(time(NULL));
			bool fini = false;
			auto etat = etatInitial_;
			int randomInt;

			if (etat->getListEtatSuivant().empty())
				cout << "ITSEMPTY\n\n";
			while (!fini && !etat->getListEtatSuivant().empty()) {
				randomInt = rand() % etat->getListEtatSuivant().size();
				etat = etat->getListEtatSuivant().at(randomInt);
				if (etat->estSortie())
					if (((rand() % (2)) == 1)) {

						fini = true;
					}

			}

			return etat->getLettrePrecedantesDeEtat();
		}
bool Automate::isDansLaListeSuggere(string motAVerifier) {
	for (auto i : motSugere_)
	{
		if (i == motAVerifier) {
			return true;
		}
	}
	return false;
}
bool Automate::getilyAUnMot() {
	return ilyAUnMot_;
}
void Automate::setilyAUnMot(bool valeur) {
	ilyAUnMot_ = valeur;
}
/*void Automate::choisirUnmotDuLexique() {
	string motEtreeParUtilisateur = "";
	int reponse;

	motChoisi_ = false;
	motExistePas_ = true;
	cout << "Debut de la partie 1:\n\n";
	cout << "Le premier joueur doit définit un code secret, qui est un mot tiré d’un lexique et constitué des lettres d’un alphabet donné\n";
	cout << " Quel mot desirez-vous choisir, \n";
	
	
		cout << "\n\n\n\nTEST\n";
		cout << "\n\n> Quel code?\n";
		cout << "Reponse: ";
		cin >> motEtreeParUtilisateur;
		suggestionDeMot(motEtreeParUtilisateur);
		if (motExistePas_) {
			cout << "Ce mot n'existe pas dans le lexique\n";
			
		}
		else {
			string ser;
			cout << "Ce mot n'existe pas dans le lexique\n";
			cout << " \n\nChoisissez un des codes de la liste de suggestion\n";
			cin >> motEtreeParUtilisateur;

			//si il trouve le mot dans la liste des mot suggere
			if (std::find(motSugere_.begin(), motSugere_.end(), motEtreeParUtilisateur) != motSugere_.end())
			{
				cout << "Voulez-vous s'electionner ce code? (1:oui/0:non)\n";
				cin >> reponse;
				if (reponse == 1)
					motChoisi_ = true;
			}
			else
			{
				
			}
		}
}*/
