/********************************************
* Titre: Travail pratique #5 - billetRegulierSolde.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/

#include "billetRegulierSolde.h"

BilletRegulierSolde::BilletRegulierSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde) :
	BilletRegulier(pnr, prix, od, tarif, dateVol), Solde(pourcentageSolde)
{
}

double BilletRegulierSolde::getPrix() const
{
	return prix_ * (1 - pourcentageSolde_);
}

double BilletRegulierSolde::getPrixBase() const
{
	return prix_;
}

BilletRegulierSolde* BilletRegulierSolde::clone() const
{
	return new BilletRegulierSolde(*this);
}

void BilletRegulierSolde::afficher(ostream& o) const
{
	BilletRegulier::afficher(o);
	o << "\t\t\t" << setw(11) << "- Pourcentage solde" << ": " << pourcentageSolde_ << "%" << endl;
}