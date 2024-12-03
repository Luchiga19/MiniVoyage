#pragma once

#include "ItemOffer.h"

class Flight :
    public ItemOffer
{
public:
    ~Flight() override = default;

    std::string getType() const override;
};