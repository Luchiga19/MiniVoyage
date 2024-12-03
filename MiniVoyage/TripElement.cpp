#include "TripElement.h"
#include <iostream>
#include <string>

using namespace std;

const string TripElement::NON_COMPOSITE_ERROR_MESSAGE = "L'élément n'est pas un composite";
int TripElement::currentId = 0;

TripElement::TripElement(string name, string type) : name(name), id(currentId), type(type) {
	currentId++;
}

int TripElement::getId() const {
	return id;
}

string TripElement::getName() const {
	return name;
}

string TripElement::getType() const {
	return type;
}

/**
TripElement& TripElement::add(TripElement& elem) {
	cerr << NON_COMPOSITE_ERROR_MESSAGE << endl;
	return elem;
}
**/

void TripElement::add(std::unique_ptr<TripElement> elem) {
	cerr << NON_COMPOSITE_ERROR_MESSAGE << endl;
}

unique_ptr<TripElement> TripElement::remove(int id) {
	cerr << NON_COMPOSITE_ERROR_MESSAGE << endl;
	return nullptr;
}

TripElement* TripElement::getElementByName(std::string name) const {
	cerr << NON_COMPOSITE_ERROR_MESSAGE << endl;
	return nullptr;
}

void TripElement::setName(std::string name) {
	this->name = name;
}