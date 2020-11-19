#pragma once
#include <string>
#include <vector>
using namespace std;

class Etat
{
public:
	Etat();
	Etat(const string& nom, bool estSortie, int numero);
	~Etat();

	void ajouterEtat(Etat* sortant);
	void ajouterSigma(string& sigma);
	bool voisinTrouver(string& lettre);

private:
	string nom_;
	bool estSortie_;
	int numero_;
	vector<Etat*> etatSuivant_;
	vector<string> listeSigma_;
};
