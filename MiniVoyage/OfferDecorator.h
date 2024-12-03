#pragma once

#include "ItemOffer.h"
#include "OfferIterator.h"
#include "OfferIteratorConst.h"
#include <memory>
#include <vector>
#include <string>

class OfferDecorator: 
    public ItemOffer
{
public:

    OfferDecorator(ItemOffer& offer);
    ~OfferDecorator() = default;

    void addComment(std::string comment);
    void removeComment();

    void addTemporaryDiscount(double discountPourcentage);
    void removeTemporaryDiscount();

    double getCostWithDiscount(const ItemOffer& offer);


private:
    int offerId;
    std::string comment;
    double temporaryDiscount = 0.0;
};

