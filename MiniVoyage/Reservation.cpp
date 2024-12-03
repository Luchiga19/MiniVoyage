#include "Reservation.h"
#include "Offer.h"
#include "ProxyOffer.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Reservation::Reservation(string name) :
	TripElement(name, "Reservation"),
	date(""), trip("") 
{}

Reservation::Reservation(string name, Offer* bdor, string date, string trip) : 
	TripElement(name, "Reservation"),
	offer(*dynamic_cast<ItemOffer*>(bdor->getOfferByName(name)), false),
	date(date),
	trip(trip)
{
	cout << "      " << getType() << " creee : " << trip << "/" << date << "/" << getName() << endl;
}

Reservation::Reservation(const Reservation& other) :
	TripElement(other.getName(), other.getType()),
	offer(other.offer)
{}

int Reservation::calculateCost() const {
	return offer.getCost();
}

unique_ptr<TripElement> Reservation::clone() const {
	return make_unique<Reservation>(*this);
}