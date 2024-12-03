#include "Excursion.h"
#include "OfferVisitor.h"

std::string Excursion::getType() const {
	return "excursion";
}

void Excursion::accept(OfferVisitor& visitor) {
	visitor.visitExcursion(*this);
}