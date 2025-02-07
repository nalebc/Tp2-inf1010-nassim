/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/
#pragma once

#include <string>
#include <vector>
#include <map>

#include "coupon.h"
#include "membrePremium.h"

class AjouterCoupon
{
public:
	AjouterCoupon(vector<Coupon*>& conteneur) : conteneur_(conteneur) {};
	vector<Coupon*> operator()(Coupon* coupon) {
		bool condition = true;
		for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it) {
			if (*it == coupon)
				condition = false;
		}
		if (condition)
			conteneur_.push_back(coupon);
		return conteneur_;
	}

private:
	vector<Coupon*>& conteneur_;

};


class AjouterMembre
{
public:
	AjouterMembre(map<string, Membre*>& conteneur): conteneur_(conteneur) {}
	map<string, Membre*> operator()(pair<string, Membre*> membre) {
		conteneur_.insert(conteneur_.end(), membre);
		return conteneur_;
	}

private:
	map<string, Membre*> &conteneur_;
//TODO
};

class IntervallePrixBillet

{
public:
	IntervallePrixBillet(double borneInf, double borneSup): borneSup_(borneSup), borneInf_(borneInf){}
	bool operator()(Billet* billet) {
		return (billet->getPrix() >= borneInf_ && billet->getPrix() <= borneSup_);
	}
private:
	double borneInf_;
	double borneSup_;
//  TODO
};