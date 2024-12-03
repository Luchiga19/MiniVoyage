#pragma once

#include "ItemOffer.h"
#include "string"

class Excursion :
    public ItemOffer
{
public:
    ~Excursion() override = default;

    std::string getType() const override;
};

