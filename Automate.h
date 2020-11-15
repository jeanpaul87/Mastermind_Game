#pragma once
#include "Etat.h"
#include <vector>
using namespace std;

class Automate
{
public:
	Automate();
	~Automate();
	Automate(const string& mot) : mot_(mot), nbEtats_(mot.size()) {};

private:
	string mot_;
	int nbEtats_;
};

