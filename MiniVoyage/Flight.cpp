#include "Flight.h"
#include "OfferVisitor.h"

std::string Flight::getType() const {
	return "transport";
}

void Flight::accept(OfferVisitor& visitor) {
	visitor.visitFlight(*this);
}