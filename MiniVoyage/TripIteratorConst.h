#pragma once

#include "IteratorAbsConst.h"
#include "TripElement.h"
#include <memory>
#include <vector>

class TripIteratorConst :
    public IteratorAbsConst<TripElement>
{
public:
    TripIteratorConst(IteratorType it) :
        IteratorAbsConst(it) {}

    const TripElement& operator*() const override;
    const TripElement* operator->() const override;
};

