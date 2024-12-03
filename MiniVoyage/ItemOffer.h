#pragma once

#include "Offer.h"
#include <unordered_map>
#include <string>

class ItemOffer :
    public Offer
{
public:
    ~ItemOffer() = default;

    std::string getName() const override;
    int getCost() const;

    static void setEuroToCadFactor(double newFactor);

    void addData(std::string key, std::string value);

private:
    static double euroToCadFactor;

    void changeDataValue(std::string key, std::string value);
    std::unordered_map<std::string, std::string> data;
};