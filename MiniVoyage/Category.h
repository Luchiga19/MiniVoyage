#pragma once

#include "Offer.h"
#include "OfferIterator.h"
#include "OfferIteratorConst.h"
#include <memory>
#include <vector>
#include <string>

class OfferVisitor;

class Category :
    public Offer
{
public:
    using iterator = OfferIterator;
    using const_iterator = OfferIteratorConst;

    Category(std::string name);
    ~Category() = default;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    std::string getName() const override;
    Offer* getOfferByName(std::string name) const override;
    int getCost() const override;

    void accept(OfferVisitor& visitor) override;

    void add(std::unique_ptr<Offer> elem) override;
    std::unique_ptr<Offer> remove(const int id) override;

    void addFromFile(std::string path, std::string type) override;

private:
    std::unique_ptr<Offer> removeCategory(const int id);
    std::unique_ptr<Offer> removeItemOffer(const int id);

    std::vector<std::string> parseCsvLine(std::string line);

    std::string name;
    std::vector<std::unique_ptr<Offer>> elements;
};

