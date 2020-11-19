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
	
private:
	int nbEtats_;
	Etat* etatInitial_;
};

