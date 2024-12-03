#include "Hotel.h"
#include "OfferVisitor.h"

std::string Hotel::getType() const {
	return "hebergement";
}

void Hotel::accept(OfferVisitor& visitor) {
	visitor.visitHotel(*this);
}