#include "Reservation.h"
#include "Offer.h"
#include "ProxyOffer.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Reservation::Reservation(string name, Offer* bdor, string date, string trip) : 
	TripElement(name, "Reservation"),
	offer(bdor, name, false),
	date(date),
	trip(trip)
{
	cout << "      " << getType() << " creee : " << trip << "/" << date << "/" << getName() << endl;
}

Reservation::Reservation(const Reservation& other) :
	TripElement(other.getName(), other.getType()),
	offer(other.offer)
{}

string Reservation::toString() const {
	return "    " + getType() + " " + getName() + ", prix total ($ CA): " + to_string(calculateCost()) + ".\n" + offer.toString();

}

int Reservation::calculateCost() const {
	return offer.getCost();
}

unique_ptr<TripElement> Reservation::clone() const {
	return make_unique<Reservation>(*this);
}