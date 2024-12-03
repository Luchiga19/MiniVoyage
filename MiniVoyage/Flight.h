#pragma once

#include "ItemOffer.h"
#include "OfferVisitor.h"
#include <string>

class Flight :
    public ItemOffer
{
public:
    ~Flight() override = default;

    std::string getType() const override;
    void accept(OfferVisitor& visitor) override;
};