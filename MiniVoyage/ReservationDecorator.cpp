#include "ReservationDecorator.h"

#include <iostream>
#include <stdexcept>
#include <chrono>
#include <iomanip>

using namespace std;

ReservationDecorator::ReservationDecorator(const Reservation& reservation)
    : Reservation(reservation){
}

void ReservationDecorator::addComment(const std::string& comment) {
    comments.push_back(comment);
    cout << "Commentaire ajout� : " << comment << endl;
}

void ReservationDecorator::removeComment(size_t index) {
    if (index >= comments.size()) {
        throw out_of_range("Index du commentaire invalide.");
    }
    string removedComment = comments[index];
    comments.erase(comments.begin() + index);
    cout << "Commentaire supprim� : " << removedComment << endl;
}

void ReservationDecorator::addModification(const std::string& modification) {
    modifications.push_back(modification);
    cout << "Modification ajout�e : " << modification << endl;
}