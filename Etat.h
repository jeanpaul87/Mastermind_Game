#pragma once
#include <string>
#include <vector>
using namespace std;

class Etat
{
public:
	Etat(char nom, bool estSortie, int numero,string nomEtatPrecedant);
	~Etat();

	void ajouterEtat(Etat* sortant);
	void ajouterSigma(string& sigma);
	void setLettrePrecedantesDeEtat(string mot);
	string getLettrePrecedantesDeEtat();
	//bool voisinTrouver(const lettre);
	bool estSortie();

	int getNumeroEtat();

	bool voisinTrouver(char& lettre);

	void vientDeSeVisiter();

	vector<Etat*> getListEtatSuivant();
	bool getEstVisiter();
	void setSorti();
	vector<string> getListlisteSigma();

	char& getNomDeEtat();

	char& getNomEtatvoisin(char& lettre);

	Etat* getEtatSuivant(const char& lettre);

	//Etat* getEtat(string& lettre);


private:
	char nom_;
	bool estSortie_;
	bool estVisiter_;
	int numero_;
	string LettrePrecedantesDeEtat_;
	vector<Etat*> etatSuivant_;
	vector<string> listeSigma_;
};
