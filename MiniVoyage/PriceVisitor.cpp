#include "PriceVisitor.h"
#include "Hotel.h"
#include "Flight.h"
#include "Excursion.h"
#include <string>

using namespace std;

void PriceVisitor::visitHotel(Hotel& hotel) {
	int cost = hotel.getCost();
	cost *= hotelFactor;
	hotel.changeDataValue("m_prixUnitaire", to_string(cost));
}

void PriceVisitor::visitExcursion(Excursion& excursion) {
	int cost = excursion.getCost();
	cost *= excursionFactor;
	excursion.changeDataValue("m_prixUnitaire", to_string(cost));
}

void PriceVisitor::visitFlight(Flight& flight) {
	int cost = flight.getCost();
	cost *= flightFactor;
	flight.changeDataValue("m_prixUnitaire", to_string(cost));
}