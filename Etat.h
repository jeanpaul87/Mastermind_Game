#pragma once
#include <string>
using namespace std;

class Etat
{
public:
	Etat();
	Etat(const string& nom);
	~Etat();

	void ajouterEtat(Etat* etat);

private:
	string nom_;

};


