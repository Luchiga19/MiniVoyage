#pragma once

#include "IteratorAbs.h"
#include "Offer.h"
#include <memory>
#include <vector>

class OfferIterator :
    public IteratorAbs<Offer>
{
public:
    OfferIterator(std::vector<std::unique_ptr<Offer>>::iterator it) :
        IteratorAbs(it) {}

    Offer& operator*() override;
    Offer* operator->() override;
};