#pragma once

#include "Offer.h"
#include "OfferIterator.h"
#include "OfferIteratorConst.h"
#include <memory>
#include <vector>
#include <string>

class CommentOffer: 
    public Offer
{
public:

    CommentOffer(Offer& offer);
    ~CommentOffer() = default;

    std::string getName() const override;

    void addComment(std::string comment);
    void removeComment();


private:
    int offerId;
    std::string comment;
};

