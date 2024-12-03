#include "ProxyOffer.h"
#include <string>

using namespace std;

ProxyOffer::ProxyOffer(const ProxyOffer& other) :
	offer(other.offer),
	access(other.access)
{}

string ProxyOffer::getName() const {
	return offer.getName();
}

int ProxyOffer::getCost() const {
	return offer.getCost();
}

void ProxyOffer::addData(string key, string value) {
	if (access)
		offer.addData(key, value);
}