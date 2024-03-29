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

	bool isDansLaListeSuggere(string motAVerifier);

	bool getilyAUnMot();

	void setilyAUnMot(bool valeur);


private:
	Etat* etatInitial_;
	bool motChoisi_;
	bool motExistePas_;
	bool ilyAUnMot_;
	vector<string> motSugere_;
};