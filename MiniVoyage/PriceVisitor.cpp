#include "PriceVisitor.h"
#include "Hotel.h"
#include "Flight.h"
#include "Excursion.h"
#include <string>
#include <cmath>

using namespace std;

void PriceVisitor::visitHotel(Hotel& hotel) {
	double cost = hotel.getCost();
	int ceilCost = round(cost * hotelFactor);
	hotel.changeDataValue("m_prixUnitaire", to_string(ceilCost));
}

void PriceVisitor::visitExcursion(Excursion& excursion) {
	double cost = excursion.getCost();
	int ceilCost = round(cost * excursionFactor);
	excursion.changeDataValue("m_prixUnitaire", to_string(ceilCost));
}

void PriceVisitor::visitFlight(Flight& flight) {
	double cost = flight.getCost();
	int ceilCost = round(cost * flightFactor);
	flight.changeDataValue("m_prixUnitaire", to_string(ceilCost));
}