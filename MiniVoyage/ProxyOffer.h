#pragma once

#include "Offer.h"
#include "ItemOffer.h"
#include "OfferVisitor.h"
#include <string>

class ProxyOffer :
    public Offer
{
public:
    ProxyOffer(ItemOffer& offer, bool access) : offer(offer), access(access) {}
    ProxyOffer(const ProxyOffer& other);
    ~ProxyOffer() = default;
    
    std::string getName() const override;
    int getCost() const;

    void accept(OfferVisitor& visitor) override {}

    void addData(std::string key, std::string value);

private:
    ItemOffer& offer;
    const bool access;
};