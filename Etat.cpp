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
