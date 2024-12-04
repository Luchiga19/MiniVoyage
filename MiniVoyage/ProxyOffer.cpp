#include "ProxyOffer.h"
#include <string>

using namespace std;

ProxyOffer::ProxyOffer(const ProxyOffer& other) :
	bdor(other.bdor),
	name(other.name),
	access(other.access)
{}

string ProxyOffer::toString() const {
	return bdor->getOfferByName(name)->toString();
}

string ProxyOffer::getName() const {
	return name;
}

int ProxyOffer::getCost() const {
	return bdor->getOfferByName(name)->getCost();
}

void ProxyOffer::addData(string key, string value) {
	if (access)
		dynamic_cast<ItemOffer*>(bdor->getOfferByName(name))->addData(key, value);
}