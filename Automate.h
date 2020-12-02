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

	void creerVerif(const string& codeSecret, const string& codeEssayer);

	Etat* getEtatIniatale();

	void suggestionDeMot(const string& inputDeLUtilisateur);

	void modeAuto();

	void choisirUnmotDuLexique();

	//int creerVerif(const string& codeSecret);
	
private:
	//int nbEtats_;
	Etat* etatInitial_;
	bool motChoisi_;
	bool motExistePas_;
	vector<string> motSugere_;
};

