#pragma once

#include "TripElement.h"
#include "ProxyOffer.h"
#include "Offer.h"
#include "Reservation.h"
#include <string>
#include <unordered_map>
#include <fstream>
#include <ctime>

class ReservationDecorator :
    public Reservation
{
public:
    ReservationDecorator(Reservation& reservation);
    ~ReservationDecorator() override = default;

    std::string toString() const override;

    int calculateCost() const override;

    void addComment(std::string comment);
    std::string removeComment(size_t index);

    void addModification(const std::string& name, const std::string& time, const std::string& date, int cost);
    void removeModifications();

private:
    const Reservation& reservation;
    std::vector<std::string> comments;
    std::vector<std::unordered_map<std::string, std::string>> modifications; // Modifications et coûts associés
};

