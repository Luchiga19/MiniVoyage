#include "OfferDecorator.h"
#include "Category.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


OfferDecorator::OfferDecorator(ItemOffer& offer) {
	offerId = offer.getId();
}


void OfferDecorator::addComment(std::string comment)  {
	comment = comment;
	cout << "Le commentaire " << comment << " a été ajouté à l'offre" << offerId << endl;
}


void OfferDecorator::removeComment() {
	comment = "";
	cout << "Le commentaire de l'offre " << offerId << " a été supprimé." << endl;
}

void OfferDecorator::addTemporaryDiscount(double discountPercentage) {
	if (discountPercentage <= 0 || discountPercentage > 100) {
		throw invalid_argument("Le pourcentage de rabais doit être entre 0 et 100.");
	}
	temporaryDiscount = discountPercentage;
	cout << "Rabais temporaire de " << discountPercentage << "% ajouté à l'offre ID: " << offerId << endl;
}

void OfferDecorator::removeTemporaryDiscount() {
	temporaryDiscount = 0.0;
}

double OfferDecorator::getCostWithDiscount(const ItemOffer& offer) {
	double originalCost = static_cast<double>(offer.getCost());
	if (temporaryDiscount > 0.0) {
		return originalCost * (1 - (temporaryDiscount / 100));
	}
	return originalCost;
}