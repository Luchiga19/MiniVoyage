#include "Category.h"
#include "ItemOffer.h"
#include "Segment.h"
#include "Reservation.h"
#include "Flight.h"
#include "Hotel.h"
#include "Excursion.h"
#include "PriceVisitor.h"
#include "CountVisitor.h"
#include "ReservationDecorator.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	Category bdor("BDOR");
	cout << "Objet BDOR cree!" << endl;

	vector<string> categories = {"transport", "hebergement", "excursion"};

	for (auto& name : categories) {
		auto category = make_unique<Category>(name);
		bdor.add(move(category));
		cout << "Categorie " << name << " creee!" << endl;
	}

	for (auto& category : bdor) {
		category.addFromFile("../assets/" + category.getName() + ".csv", category.getName());
	}

	cout << endl;

	unique_ptr<Segment> tripDora = make_unique<Segment>("Voyage de Dora", "Voyage");
	
	unique_ptr<Segment> f1 = make_unique<Segment>("France 1ere partie", "Segment", tripDora->getName());

	unique_ptr<Segment> f1j1 = make_unique<Segment>("2024-10-26", "Journee", f1->getName());

	unique_ptr<Reservation> f1j1a1 = make_unique<Reservation>("Air Canada AC 870 2024-10-26", &bdor, f1j1->getName(), tripDora->getName());

	unique_ptr<Segment> f1j2 = make_unique<Segment>("2024-10-27", "Journee", f1->getName());

	unique_ptr<Reservation> f1j2a1 = make_unique<Reservation>("Hotel Stella", &bdor, f1j2->getName(), tripDora->getName());

	unique_ptr<Segment> f1j3 = make_unique<Segment>("2024-10-28", "Journee", f1->getName());

	unique_ptr<Reservation> f1j3a1 = make_unique<Reservation>("Paris Dîner-croisière sur la Seine by Bateaux Mouches", &bdor, f1j3->getName(), tripDora->getName());

	unique_ptr<Reservation> f1j3a2 = make_unique<Reservation>("Hotel Stella", &bdor, f1j3->getName(), tripDora->getName());
	
	f1j1->add(move(f1j1a1));
	f1j2->add(move(f1j2a1));
	f1j3->add(move(f1j3a2));
	f1j3->add(move(f1j3a1));

	f1->add(move(f1j1));
	f1->add(move(f1j2));
	f1->add(move(f1j3));

	tripDora->add(move(f1));

	unique_ptr<Segment> p = make_unique<Segment>("Portugal", "Segment", tripDora->getName());

	unique_ptr<Segment> pj1 = make_unique<Segment>("2024-10-29", "Journee", p->getName());

	unique_ptr<Reservation> pj1a1 = make_unique<Reservation>("TAP Air Portugal TP 0441 2024-10-29", &bdor, pj1->getName(), tripDora->getName());

	unique_ptr<Reservation> pj1a2 = make_unique<Reservation>("Hôtel Roma", &bdor, pj1->getName(), tripDora->getName());

	unique_ptr<Segment> pj2 = make_unique<Segment>("2024-10-30", "Journee", p->getName());

	unique_ptr<Reservation> pj2a1 = make_unique<Reservation>("Visite du Musée Calouste-Gulbenkian", &bdor, pj2->getName(), tripDora->getName());

	unique_ptr<Reservation> pj2a2 = make_unique<Reservation>("Hôtel Roma", &bdor, pj2->getName(), tripDora->getName());

	unique_ptr<Segment> pj3 = make_unique<Segment>("2024-10-31", "Journee", p->getName());

	unique_ptr<Reservation> pj3a1 = make_unique<Reservation>("easyJet 4592 2024-10-31", &bdor, pj3->getName(), tripDora->getName());

	pj1->add(move(pj1a1));
	pj1->add(move(pj1a2));
	pj2->add(move(pj2a1));
	pj2->add(move(pj2a2));
	pj3->add(move(pj3a1));

	p->add(move(pj1));
	p->add(move(pj2));
	p->add(move(pj3));

	tripDora->add(move(p));

	unique_ptr<Segment> f2 = make_unique<Segment>("France 2e partie", "Segment", tripDora->getName());

	unique_ptr<Segment> f2j1 = make_unique<Segment>("2024-10-31", "Journee", f2->getName());

	unique_ptr<Reservation> f2j1a1 = make_unique<Reservation>("Hotel Stella", &bdor, f2j1->getName(), tripDora->getName());

	unique_ptr<Segment> f2j2 = make_unique<Segment>("2024-11-01", "Journee", f2->getName());

	unique_ptr<Reservation> f2j2a1 = make_unique<Reservation>("Visite guidée pour voir les chefs-d'œuvre du musée du Louvre", &bdor, f2j2->getName(), tripDora->getName());

	unique_ptr<Reservation> f2j2a2 = make_unique<Reservation>("Hotel Stella", &bdor, f2j2->getName(), tripDora->getName());

	unique_ptr<Segment> f2j3 = make_unique<Segment>("2024-11-02", "Journee", f2->getName());

	unique_ptr<Reservation> f2j3a1 = make_unique<Reservation>("Visite guidée à Versailles et accès prioritaire avec transfert depuis l'hôtel au départ de Paris", &bdor, f2j3->getName(), tripDora->getName());

	unique_ptr<Reservation> f2j3a2 = make_unique<Reservation>("Hotel Stella", &bdor, f2j3->getName(), tripDora->getName());

	unique_ptr<Segment> f2j4 = make_unique<Segment>("2024-11-03", "Journee", f2->getName());

	unique_ptr<Reservation> f2j4a1 = make_unique<Reservation>("Air Transat 111 2024-11-03", &bdor, f2j4->getName(), tripDora->getName());

	f2j1->add(move(f2j1a1));
	f2j2->add(move(f2j2a1));
	f2j2->add(move(f2j2a2));
	f2j3->add(move(f2j3a1));
	f2j3->add(move(f2j3a2));
	f2j4->add(move(f2j4a1));

	f2->add(move(f2j1));
	f2->add(move(f2j2));
	f2->add(move(f2j3));
	f2->add(move(f2j4));

	tripDora->add(move(f2));

	cout << endl;

	unique_ptr<Segment> tripDiego = tripDora->clone("Voyage de Diego");
	
	unique_ptr<TripElement> removedElem = tripDiego->remove(tripDiego->getElementByName("Portugal")->getId());
	cout << removedElem->getType() << " " << removedElem->getName() << " efface!" << endl;


	unique_ptr<Segment> e = make_unique<Segment>("Espagne", "Segment", tripDiego->getName());

	unique_ptr<Segment> ej1 = make_unique<Segment>("2024-10-29", "Journee", e->getName());

	unique_ptr<Reservation> ej1a1 = make_unique<Reservation>("Air Europa 1026", &bdor, ej1->getName(), tripDiego->getName());
	
	unique_ptr<Reservation> ej1a2 = make_unique<Reservation>("Far Home Atocha", &bdor, ej1->getName(), tripDiego->getName());

	unique_ptr<Segment> ej2 = make_unique<Segment>("2024-10-30", "Journee", e->getName());

	unique_ptr<Reservation> ej2a1 = make_unique<Reservation>("Excursion d'une journée à Tolède (de Madrid)", &bdor, ej2->getName(), tripDiego->getName());

	unique_ptr<Reservation> ej2a2 = make_unique<Reservation>("Far Home Atocha", &bdor, ej2->getName(), tripDiego->getName());

	unique_ptr<Segment> ej3 = make_unique<Segment>("2024-10-31", "Journee", e->getName());

	unique_ptr<Reservation> ej3a1 = make_unique<Reservation>("Air Europa 1025", &bdor, ej3->getName(), tripDiego->getName());

	ej1->add(move(ej1a1));
	ej1->add(move(ej1a2));
	ej2->add(move(ej2a1));
	ej2->add(move(ej2a2));
	ej3->add(move(ej3a1));

	e->add(move(ej1));
	e->add(move(ej2));
	e->add(move(ej3));

	unique_ptr<TripElement> removedElem2 = tripDiego->remove(tripDiego->getElementByName("France 2e partie")->getId());

	tripDiego->add(move(e));

	tripDiego->add(move(removedElem2));

	cout << endl;

	unique_ptr<TripElement> moved = tripDiego->remove(tripDiego->getElementByName("Air Europa 1025")->getId());
	tripDiego->remove(tripDiego->getElementByName("2024-10-31")->getId());
	tripDiego->getElementByName("2024-10-31")->add(move(moved));

	moved = tripDora->remove(tripDora->getElementByName("easyJet 4592 2024-10-31")->getId());
	tripDora->remove(tripDora->getElementByName("2024-10-31")->getId());
	tripDora->getElementByName("2024-10-31")->add(move(moved));

	unique_ptr<Segment> tripAlicia = tripDiego->clone("Voyage d\'Alicia");

	cout << endl;

	cout << "Total des frais pour " << tripDora->getName() << " ($ CA): " << tripDora->calculateCost() << endl;
	cout << "Total des frais pour " << tripDiego->getName() << " ($ CA): " << tripDiego->calculateCost() << endl;
	cout << "Total des frais pour " << tripAlicia->getName() << " ($ CA): " << tripAlicia->calculateCost() << endl;

	cout << endl;

	cout << "--- Debut de la sortie du TP5" << endl;

	cout << endl;


	for (auto& trip : { tripDora.get(), tripDiego.get(), tripAlicia.get() }) {
		TripElement* jourReservation = trip->getElementByName("2024-10-27");
		TripElement* hotelReservation = jourReservation->getElementByName("Hotel Stella");

		unique_ptr<ReservationDecorator> decoratedRes = make_unique<ReservationDecorator>(*dynamic_cast<Reservation*>(trip->remove(hotelReservation->getId()).get()));
		decoratedRes->addModification("Restaurant de l'hôtel Stella", "19h", "27 octobre 2024", 0);
		jourReservation->add(move(decoratedRes));
	}

	for (auto& trip : { tripDora.get(), tripDiego.get(), tripAlicia.get() }) {
		TripElement* jourReservation = trip->getElementByName("2024-10-31");
		TripElement* hotelReservation = jourReservation->getElementByName("Hotel Stella");

		unique_ptr<ReservationDecorator> decoratedRes = make_unique<ReservationDecorator>(*dynamic_cast<Reservation*>(trip->remove(hotelReservation->getId()).get()));
		decoratedRes->addModification("Restaurant de l'hôtel Stella", "19h", "27 octobre 2024", 0);
		decoratedRes->addComment("Excellent service!");
		jourReservation->add(move(decoratedRes));
	}

	for (auto& trip : { tripDora.get(), tripDiego.get(), tripAlicia.get() }) {
		TripElement* jourReservation = trip->getElementByName("2024-10-31");
		ReservationDecorator* hotelReservation = dynamic_cast<ReservationDecorator*>(jourReservation->getElementByName("Hotel Stella"));

		hotelReservation->removeModifications();
	}

	PriceVisitor priceVisitor(1.03, 1.02, 1.02);
	bdor.accept(priceVisitor);

	cout << tripDora->toString() << endl;
	cout << tripDiego->toString() << endl;
	cout << tripAlicia->toString() << endl;

	CountVisitor countVisitor;
	bdor.accept(countVisitor);
	int tor = countVisitor.getCount();

	cout << endl;

	cout << "Total du nombre d'offres de réservations dans la BDOR: " << tor << "," << endl;
}