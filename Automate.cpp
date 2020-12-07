#include "Automate.h"
#include <list>
#include <queue>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Automate::Automate() : etatInitial_(new Etat(' ', false, 0, ""))
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
			string lettrePrecedantesDeEtat = "";
			etatActuelle = etatInitial_;
			getline(fichier, mot);

			//iterer chaque lettre du mot
			for (int i = 0; i < mot.size(); i++)
			{
				char a = mot[i];

				//verifier si on a pas un voisin de la lettre 
				if (!etatActuelle->voisinTrouver(a)) {
					etatActuelle->ajouterEtat(new Etat(a, (i == (mot.size() - 1)), i + 1, mot));

					if (i > 0)
						lettrePrecedantesDeEtat = mot.substr(0, etatActuelle->getNumeroEtat());
					etatActuelle->setLettrePrecedantesDeEtat(lettrePrecedantesDeEtat);
				}

				for (int j = 0; j < etatActuelle->getListEtatSuivant().size(); j++)
				{
					if (etatActuelle->getListEtatSuivant().at(j)->getNomDeEtat() == a) {
						etatActuelle = etatActuelle->getListEtatSuivant().at(j);
						break;
					}
				}
				if (i == mot.size() - 1) {
					etatActuelle->setSorti();
				}

			}


		}
	}
	else { cout << "ERREUR D'OUVERTURE DU FICHIER"; }
}


//prendre en parametre l'automate mot a la place dun string
bool Automate::creerVerif(const string& codeSecret, const string& codeEssayer) {//PE ETRE ON VA LE CHANGER !!
	int nbFausseLettre = 0;
	Etat* tempEtat = etatInitial_;

	for (int i = 0; i < codeSecret.size(); i++) {
		tempEtat = tempEtat->getEtatSuivant(codeSecret[i]);
		if (tempEtat->getNomDeEtat() != codeEssayer[i]) {
			nbFausseLettre++;
		}

	}
	if(nbFausseLettre != 0)
	cout << "\nVous assez " << nbFausseLettre << " lettre faux.\n";

	if (nbFausseLettre == 0) {
		cout << "\n\nBravo ! vous avez gagne ! \n\nAttendez quelque seconds pour reclamez votre cadeaux \n";
		cout << " \n\nAttendez ";
		for (int i = 0; i < 3; i++)
		{
			Sleep(1500);
			cout << " .";
		}
		Sleep(1000);
		cout << "\n\nMalheuresement le generateur de cadeaux est vide. :/  \n";

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
			
			compteurDeSuggetsion++;
			motExistePas_ = false;
		}
		queue.pop();
		for (auto i : iterateur->getListEtatSuivant()) {
			if (!i->getEstVisiter())
				queue.push(i);
		}
	}
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