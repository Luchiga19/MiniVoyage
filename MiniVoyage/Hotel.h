#pragma once
#include "ItemOffer.h"
class Hotel :
    public ItemOffer
{
public:
    ~Hotel() override = default;

    std::string getType() const override;
};