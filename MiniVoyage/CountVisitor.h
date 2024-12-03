#pragma once

#include "OfferVisitor.h"

class CountVisitor :
    public OfferVisitor
{
public:
    CountVisitor();
    ~CountVisitor() override = default;

    int getCount() const;

    void visitHotel(Hotel& hotel) override;
    void visitExcursion(Excursion& excursion) override;
    void visitFlight(Flight& flight) override;

    void incrementCount();

private:
    int count;
};

