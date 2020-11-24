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

	vector<Etat*> getListEtatSuivant();
	vector<string> getListlisteSigma();

	char& getNomDeEtat();

	char& getNomEtatvoisin(char& lettre);

	Etat* getEtatSuivant(const string& lettre);

	//Etat* getEtat(string& lettre);


private:
	char& nom_;
	bool estSortie_;
	int numero_;
	vector<Etat*> etatSuivant_;
	vector<string> listeSigma_;
};
