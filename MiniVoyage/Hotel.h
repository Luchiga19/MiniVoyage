#pragma once

#include "ItemOffer.h"
#include <string>

class Hotel :
    public ItemOffer
{
public:
    ~Hotel() override = default;

    std::string getType() const override;
    void accept(OfferVisitor& visitor) override;
};