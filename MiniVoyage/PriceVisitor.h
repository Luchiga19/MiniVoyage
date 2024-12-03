#pragma once

#include "OfferVisitor.h"

class PriceVisitor :
    public OfferVisitor
{
public:
    PriceVisitor(double hotel, double excursion, double flight) :
        hotelFactor(hotel), excursionFactor(excursion), flightFactor(flight) 
    {}
    ~PriceVisitor() override = default;

    void visitHotel(Hotel& hotel) override;
    void visitExcursion(Excursion& excursion) override;
    void visitFlight(Flight& flight) override;

private:
    double hotelFactor;
    double excursionFactor;
    double flightFactor;
};

