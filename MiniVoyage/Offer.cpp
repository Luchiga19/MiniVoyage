#include "Offer.h"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

const string NOM_COMPOSITE_ERROR_MESSAGE = "L'élément n'est pas un composite";
int Offer::currentId = 0;

Offer::Offer() : id(currentId) {
	currentId++;
}

int Offer::getId() const {
	return id;
}

Offer* Offer::getOfferByName(std::string name) const {
	cerr << NOM_COMPOSITE_ERROR_MESSAGE << endl;
	return nullptr;
}

/**
Offer& Offer::add(Offer& elem) {
	cerr << NOM_COMPOSITE_ERROR_MESSAGE << endl;
	return elem;
}
**/

void Offer::add(unique_ptr<Offer> elem) {
	cerr << NOM_COMPOSITE_ERROR_MESSAGE << endl;
}

unique_ptr<Offer> Offer::remove(int id) {
	cerr << NOM_COMPOSITE_ERROR_MESSAGE << endl;
	return nullptr;
}

void Offer::addFromFile(string path, string type) {
	cerr << NOM_COMPOSITE_ERROR_MESSAGE << endl;
}