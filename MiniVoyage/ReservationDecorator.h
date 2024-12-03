#pragma once

#include "TripElement.h"
#include "ProxyOffer.h"
#include "Offer.h"
#include <string>
#include "Reservation.h"
#include <fstream>
#include <ctime>

class ReservationDecorator :
    public Reservation
{
public:
    ReservationDecorator(Reservation& reservation);
    ~ReservationDecorator() override = default;

    void addComment(std::string comment);
    std::string removeComment(size_t index);

    void addModification(const std::string& name, const std::string& time, const std::string& date);

private:
    const Reservation& reservation;
    std::vector<std::string> comments;
    std::vector<unordered_map<string, string>> modifications; // Modifications et coûts associés
};

