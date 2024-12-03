#pragma once

#include "TripElement.h"
#include "TripIterator.h"
#include "TripIteratorConst.h"
#include <memory>
#include <vector>
#include <string>

class Segment :
    public TripElement
{
public:
    using iterator = TripIterator;
    using const_iterator = TripIteratorConst;

    Segment(std::string name, std::string type);
    Segment(std::string name, std::string type, std::string inSegment);    
    Segment(const Segment& other);
    ~Segment() override = default;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
    
    TripElement* getElementByName(std::string name) const override;

    int calculateCost() const override;

    // TripElement& add(TripElement& elem) override;
    void add(std::unique_ptr<TripElement> elem) override;
    std::unique_ptr<TripElement> remove(const int id) override;
    std::unique_ptr<TripElement> clone() const override;
    virtual std::unique_ptr<Segment> clone(std::string newName) const;

private:
    std::unique_ptr<TripElement> removeChildSegment(const int id);
    std::unique_ptr<TripElement> removeElement(const int id);

    std::string inSegment;
    std::string type;
    std::vector<std::unique_ptr<TripElement>> elements;
};