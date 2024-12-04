#pragma once

#include "ItemOffer.h"
#include "OfferIterator.h"
#include "OfferIteratorConst.h"
#include "OfferVisitor.h"
#include <memory>
#include <vector>
#include <string>

class OfferDecorator: 
    public ItemOffer
{
public:

    OfferDecorator(std::unique_ptr<ItemOffer> offer);
    ~OfferDecorator() = default;

    void addComment(std::string comment);
    std::string removeComment(size_t index);

    void addFlatDiscount(int flatDiscount);
    void removeTemporaryDiscount();

    void accept(OfferVisitor& visitor);

    std::string toString() const override;

    std::string getName() const override;
    int getCost() const override;

    std::string getType() const override;

    std::unique_ptr<ItemOffer> offer;
    
private:
    std::vector<std::string> comments;
    int temporaryDiscount = 0;
};

