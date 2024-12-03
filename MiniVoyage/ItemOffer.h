#pragma once

#include "Offer.h"
#include <unordered_map>
#include <string>

class ItemOffer :
    public Offer
{
public:
    ~ItemOffer() override = default ;

    std::string getName() const override;
    int getCost() const override;
    virtual std::string getType() const = 0;

    static void setEuroToCadFactor(double newFactor);

    void addData(std::string key, std::string value);

    void changeDataValue(std::string key, std::string value);

private:
    static double euroToCadFactor;

    std::unordered_map<std::string, std::string> data;
};