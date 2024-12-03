#pragma once

#include "TripElement.h"
#include "ProxyOffer.h"
#include "Offer.h"
#include <string>
#include "Reservation.h"
#include <fstream>
#include <ctime>

class ReservationDecorator : public Reservation
{
public:
    ReservationDecorator(const Reservation& reservation);
    ~ReservationDecorator() override = default;

    void addComment(const std::string& comment);
    void removeComment(size_t index);

    void addModification(const std::string& modification);


private:
    std::vector<std::string> comments;
    std::vector<std::string> modifications; // Modifications et coûts associés

    std::string getCurrentTimestamp() const;
};

