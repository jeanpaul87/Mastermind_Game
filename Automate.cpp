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
					etatActuelle->ajouterEtat(new Etat(a, (i == (mot.size() - 1)), i + 1,mot));//peut etre on va faire i+1
					//etatActuelle->ajouterSigma(s);
					//etatActuelle = etatActuelle->getListEtatSuivant().back();

					//ajouter le prefix du mot
					/*if (i == mot.size()) {
						etatActuelle->setLettrePrecedantesDeEtat(mot);
					}
					else {*/
						if (i > 0)
							lettrePrecedantesDeEtat = mot.substr(0, etatActuelle->getNumeroEtat());
						etatActuelle->setLettrePrecedantesDeEtat(lettrePrecedantesDeEtat );
					//}
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
	//delete etatActuelle;
	//delete b;
}


//prendre en parametre l'automate mot a la place dun string
void Automate::creerVerif( const string& codeSecret, const string& codeEssayer ) {//PE ETRE ON VA LE CHANGER !!
	int nbFausseLettre = 0;
	Etat* tempEtat = etatInitial_;

	for (int i = 0; i < codeSecret.size(); i++){
		tempEtat = tempEtat->getEtatSuivant(codeSecret[i]);
			if (tempEtat->getNomDeEtat() != codeEssayer[i]) {
				nbFausseLettre++;
			}
		cout << '\n'<<tempEtat->getNomDeEtat();
		
	}
	cout << "\nVous azez " << nbFausseLettre << " Lettre faux.\n";

	/*for (int i = 0; i < codeSecret.size(); i++)
	{
		std::string s(1, codeSecret[i]);
		if (tempEtat->getNomEtatvoisin((char&)codeSecret[i]) != codeSecret[i]) {
			nbFausseLettre++;
		}
		tempEtat = tempEtat->getEtatSuivant(s);
	}
	cout<< nbFausseLettre;*/
}

Etat* Automate::getEtatIniatale() {
	return etatInitial_;
}
void Automate::suggestionDeMot(const string& inputDeLUtilisateur) {
	

	queue<Etat*> queue;

	Etat* iterateur = etatInitial_;
	for (int i = 0; i < inputDeLUtilisateur.size(); i++)
	{
		iterateur = iterateur->getEtatSuivant(inputDeLUtilisateur[i]);
		iterateur->vientDeSeVisiter();
		//queue.push(iterateur);
		cout << '\n'<<iterateur->getNomDeEtat();
	}
	for (auto i : iterateur->getListEtatSuivant()) {
		queue.push(i);
	}
	while (!queue.empty())
	{
		iterateur = queue.front();
		iterateur->vientDeSeVisiter();
		queue.pop();
		for (auto i : iterateur->getListEtatSuivant()) {
			if(!i->getEstVisiter())
			queue.push(i);

		}
		if (!queue.empty()) {
			//cout << "HIHI";
			cout << '\n'<<"JJJJ"<<queue.front()->getNomDeEtat();
		}
			//queue.pop();
	}
	//iterateur = etatInitial_->getEtatSuivant(inputDeLUtilisateur.at(0));
	//
	//queue.push(iterateur);
	//iterateur->vientDeSeVisiter();


	//while (!queue.empty()) {

	//	for (auto i : iterateur->getListEtatSuivant()) {
	//		queue.push(i);
	//		name.push(i->getNomDeEtat());

	//	}
	//	
	//	iterateur = queue.front();
	//	if (queue.front()->estSortie())
	//		cout << name.front();
	//	queue.pop();
	//}

}

void Automate::modeAuto() {

	srand(time(NULL));
	bool fini = false;
	auto etat = etatInitial_;
	int randomInt;

	if (etat->getListEtatSuivant().empty())
		cout << "ITSEMPTY\n\n";
	while (!fini && !etat->getListEtatSuivant().empty()) {
		randomInt = rand() % etat->getListEtatSuivant().size();
		cout << "HOP\n";
		cout << randomInt<<'\n';
		etat = etat->getListEtatSuivant().at(randomInt);
		if(etat->estSortie())
			if (((rand() % (2)) == 1)) {
				cout<<"\n"<< etat->getLettrePrecedantesDeEtat();
				fini = true;
			}

	}
	cout<<"\n"<<etat->getLettrePrecedantesDeEtat();
	
}
