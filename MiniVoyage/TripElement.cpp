#include "TripElement.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string TripElement::NON_COMPOSITE_ERROR_MESSAGE = "L'�l�ment n'est pas un composite";
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

void TripElement::log(string filename) const {
	ofstream outFile(filename);

	if (outFile.is_open()) {
		outFile << toString();
		outFile.close();
	}
}

void TripElement::setName(std::string name) {
	this->name = name;
}