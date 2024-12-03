#pragma once

#include "TripElement.h"
#include "ProxyOffer.h"
#include "Offer.h"
#include <string>

class Reservation :
    public TripElement
{
public:
    Reservation(std::string name, Offer* bdor, std::string date, std::string trip);
    Reservation(const Reservation& other);
    ~Reservation() override = default;

    int calculateCost() const override;

    std::unique_ptr<TripElement> clone() const override;

    ProxyOffer offer;

private:
    std::string date;
    std::string trip;
};