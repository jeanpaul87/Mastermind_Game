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

	int creerVerif(const string& codeSecret);

	//int creerVerif(const string& codeSecret);
	
private:
	int nbEtats_;
	Etat* etatInitial_;
};

