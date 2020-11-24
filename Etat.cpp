#include "Etat.h"

Etat::Etat()
{
}

Etat::Etat(const string& nom,bool estSortie, int numero):
	nom_(nom),
	estSortie_(estSortie),
	numero_(numero) 
{
}

Etat::~Etat()
{
}

void Etat::ajouterEtat(Etat* sortant)
{
    etatSuivant_.push_back(sortant);
}

void Etat::ajouterSigma(string& sigma)
{//POTENTIAL ERROR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <---- q(0_0)p
	bool estTrouver = false;
	for (auto it : listeSigma_) {
		if (sigma == it) {
			estTrouver = true;
		}
	}
	if(!estTrouver)listeSigma_.push_back(sigma);
}

bool Etat::voisinTrouver(string& lettre)
{
	for(auto var : listeSigma_)
	{
		if(var == lettre)
			return true;
	}
	return false;
}

vector<Etat*> Etat::getListEtatSuivant()
{
	return etatSuivant_;
}

vector<string> Etat::getListlisteSigma()
{
	return listeSigma_;
}

char& Etat::getNomDeEtat() {
	return nom_;
}

char& Etat::getNomEtatvoisin(char& lettre) {
	char returning = '&';
	for (int i = 0; i < etatSuivant_.size() ; i++)
	{
		if (etatSuivant_[i]->getNomDeEtat() == lettre) return etatSuivant_[i]->getNomDeEtat();
		return returning;
	}
}

Etat* Etat::()