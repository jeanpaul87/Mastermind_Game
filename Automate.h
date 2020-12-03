#pragma once
#include "Etat.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Automate
{
public:
	Automate();
	~Automate();

	void creerLexique(const string& lexique);

	bool creerVerif(const string& codeSecret, const string& codeEssayer);

	Etat* getEtatIniatale();

	void suggestionDeMot(const string& inputDeLUtilisateur);

	string modeAuto();

	void choisirUnmotDuLexique();
	
private:
	//int nbEtats_;
	Etat* etatInitial_;
	bool motChoisi_;
	bool motExistePas_;
	vector<string> motSugere_;
};

