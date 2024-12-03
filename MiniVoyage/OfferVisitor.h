#pragma once

#include "Category.h"

class Flight;
class Excursion;
class Hotel;

class OfferVisitor
{
public:
	virtual ~OfferVisitor() = default;

	virtual void visitHotel(Hotel& hotel) = 0;
	virtual void visitExcursion(Excursion& excursion) = 0;
	virtual void visitFlight(Flight& flight) = 0;

	virtual void visitCategory(Category& caegory);
};

