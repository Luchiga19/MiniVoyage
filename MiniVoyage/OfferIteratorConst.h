#pragma once

#include "IteratorAbsConst.h"
#include "Offer.h"

class OfferIteratorConst :
    public IteratorAbsConst<Offer>
{
public:
    OfferIteratorConst(IteratorType it) :
        IteratorAbsConst(it) {}

    const Offer& operator*() const override;
    const Offer* operator->() const override;
};

