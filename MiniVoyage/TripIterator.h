#pragma once

#include "IteratorAbs.h"
#include "TripElement.h"
#include <memory>
#include <vector>

class TripIterator :
    public IteratorAbs<TripElement>
{
public:
    TripIterator(std::vector<std::unique_ptr<TripElement>>::iterator it) :
        IteratorAbs(it) {}

    TripElement& operator*() override;
    TripElement* operator->() override;
};