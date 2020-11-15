#include "Lexique.h"


Lexique::Lexique()
{
}

Lexique::~Lexique()
{
}

void Lexique::creerLexique(const string& lexique)
{
	ifstream fichier(lexique+".txt");
	if (fichier) { cout << "ACcess completed"; }
	else { cout << "ERREUR D'OUVERTURE DU FICHIER"; }
}
