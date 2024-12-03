#include "ItemOffer.h"
#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;

double ItemOffer::euroToCadFactor = 1.5;

string ItemOffer::getName() const {
	try {
		return data.at("m_nom");
	}
	catch (const out_of_range& e) {
		throw ("Pas de nom associé à cette offre");
	}
}

int ItemOffer::getCost() const {
	try {
		if (data.at("m_devise") == "EURO")
			return stoi(data.at("m_prixUnitaire")) * euroToCadFactor;
		return stoi(data.at("m_prixUnitaire"));
	}
	catch (const out_of_range& e) {
		throw ("Pas de coût associé à cette offre");
	}
	catch (const invalid_argument& e) {
		throw ("La valeur associée au cout n'est pas conversible à un entier");
	}
}

void ItemOffer::setEuroToCadFactor(double newFactor) {
	euroToCadFactor = newFactor;
}

void ItemOffer::addData(string key, string value) {
	if(!(data.find(key) != data.end()))
		data[key] = value;
}

void ItemOffer::changeDataValue(string key, string value) {
	data[key] = value;
}