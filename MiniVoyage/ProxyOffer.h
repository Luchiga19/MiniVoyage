#pragma once

#include "Offer.h"
#include "ItemOffer.h"
#include "OfferVisitor.h"
#include <string>

class ProxyOffer :
    public Offer
{
public:
    ProxyOffer(Offer* bdor, std::string name, bool access) : 
        bdor(bdor), 
        name(name), 
        access(access) 
    {}
    ProxyOffer(const ProxyOffer& other);
    ~ProxyOffer() = default;
    
    std::string toString() const override;

    std::string getName() const override;
    int getCost() const;

    void accept(OfferVisitor& visitor) override {}

    void addData(std::string key, std::string value);

private:
    std::string name;
    Offer* bdor;
    const bool access;
};