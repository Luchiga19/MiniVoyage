#include "ReservationDecorator.h"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

ReservationDecorator::ReservationDecorator(Reservation& reservation) : 
    Reservation(reservation.getName(), reservation.offer),
    reservation(reservation)
{}

string ReservationDecorator::toString() const {
    string str;
    str += Reservation::toString();

    for (auto& modif : modifications) {
        str += "      Reservation " + modif.at("name") + " pour le " + modif.at("date") + " à " + modif.at("time") + "." + "\n";
    }

    for (auto& comment : comments) {
        str += "      Commentaire: " + comment + ".";
    }
    return str;
}

void ReservationDecorator::addComment(string comment) {
    comments.push_back(comment);
}

string ReservationDecorator::removeComment(size_t index) {
    if (index >= comments.size()) {
        throw out_of_range("Index du commentaire invalide.");
    }
    string removedComment = comments[index];
    comments.erase(comments.begin() + index);
    return removedComment;
}

void ReservationDecorator::addModification(const string& name, const string& time, const string& date) {
    unordered_map<string, string> data;
    data["name"] = name;
    data["time"] = time;
    data["date"] = date;
    modifications.push_back(data);
}