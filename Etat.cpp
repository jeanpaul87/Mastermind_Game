#include "Etat.h"


Etat::Etat(char nom, bool estSortie, int numero, string nomEtatPrecedant) :
	nom_(nom),
	estSortie_(estSortie),
	numero_(numero),
	LettrePrecedantesDeEtat_(nomEtatPrecedant),
	estVisiter_(false)
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
{
	bool estTrouver = false;
	for (auto it : listeSigma_) {
		if (sigma == it) {
			estTrouver = true;
		}
	}
	if (!estTrouver)listeSigma_.push_back(sigma);
}
void Etat::setLettrePrecedantesDeEtat(string mot) {
	LettrePrecedantesDeEtat_ = mot;
}
string Etat::getLettrePrecedantesDeEtat()
{
	return LettrePrecedantesDeEtat_;
}
bool Etat::voisinTrouver(char& lettre)
{
	for (int i = 0; i < getListEtatSuivant().size(); i++) {

		if (getListEtatSuivant().at(i)->getNomDeEtat() == lettre)
			return true;
	}
	return false;
}
void Etat::vientDeSeVisiter() {
	estVisiter_ = true;
}
vector<Etat*> Etat::getListEtatSuivant()
{
	return etatSuivant_;
}
bool Etat::getEstVisiter() {
	return estVisiter_;
}
void Etat::setSorti() {
	estSortie_ = true;
}
bool Etat::estSortie() {
	return estSortie_;
}
int Etat::getNumeroEtat() {
	return numero_;
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
	for (int i = 0; i < etatSuivant_.size(); i++)
	{
		if (etatSuivant_[i]->getNomDeEtat() == lettre) return etatSuivant_[i]->getNomDeEtat();
		return returning;
	}
}

Etat* Etat::getEtatSuivant(const char& lettre)
{
	Etat* etatChercher = new Etat('&', false, 0, "");
	for (int i = 0; i < getListEtatSuivant().size(); i++)
	{
		if (getListEtatSuivant().at(i)->getNomDeEtat() == lettre)
			etatChercher = getListEtatSuivant().at(i);
	}
	return etatChercher;
}