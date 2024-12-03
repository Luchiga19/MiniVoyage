#include "Segment.h"
#include "Reservation.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Segment::Segment(string name, string type) : TripElement(name, type), inSegment("") {
	cout << name << "cree!" << endl;
}

Segment::Segment(string name, string type, string inSegment) : TripElement(name, type), inSegment(inSegment) {
	if (type == "Journee")
		cout << "    " << type << " " << name << " creee dans le segment " << inSegment << "!" << endl;
	else if (type == "Segment")
		cout << "  " << type << " " << name << " creee dans le " << inSegment << "!" << endl;
}

Segment::Segment(const Segment& other) : TripElement(other.getName(), other.getType()) {
	type = other.type;

	for (const auto& elem : other)
		elements.push_back(elem.clone());
}

Segment::iterator Segment::begin() {
	return iterator(elements.begin());
}

Segment::iterator Segment::end() {
	return iterator(elements.end());
}

Segment::const_iterator Segment::begin() const {
	return const_iterator(elements.cbegin());
}

Segment::const_iterator Segment::end() const {
	return const_iterator(elements.cend());
}

string Segment::toString() const {
	string str;
	if (getType() == "Voyage")
		str = getName() + ":\n";
	else if (getType() == "Journee")
		str = "  " + getType() + " " + getName() + ":\n";

	for (auto& elem : elements)
		str += elem->toString();
	return str;

	return "";
}

int Segment::calculateCost() const {
	int cost = 0;

	for (auto& elem : *this) {
		cost += elem.calculateCost();
	}

	return cost;
}

TripElement* Segment::getElementByName(std::string name) const {
	TripElement* tripElem = nullptr;
	if (!elements.empty() && dynamic_cast<Segment*>(elements[0].get()) != nullptr) {
		for (auto& elem : elements) {
			tripElem = elem->getElementByName(name);

			if (tripElem != nullptr)
				return tripElem;
		}
	}

	for (auto& elem : elements) {
		if (elem->getName() == name)
			return elem.get();
	}

	return nullptr;
}

/**
TripElement& Segment::add(TripElement& elem) {
	add(unique_ptr<TripElement>(&elem));
	return elem;
}
**/

void Segment::add(std::unique_ptr<TripElement> elem) {
	elements.push_back(move(elem));
}

unique_ptr<TripElement> Segment::remove(const int id) {
	if (getId() == id) {
		cerr << "Cannot remove self" << endl;
		return nullptr;
	}

	if (elements.empty())
		return nullptr;

	unique_ptr<TripElement> removedPtr = removeElement(id);

	if (removedPtr != nullptr)
		return removedPtr;

	else if (dynamic_cast<Segment*>(elements[0].get()) != nullptr)
		return removeChildSegment(id);

	return nullptr;
}

unique_ptr<TripElement> Segment::removeChildSegment(const int id) {
	unique_ptr<TripElement> removedElem = nullptr;

	for (auto& elem : elements) {
		removedElem = elem->remove(id);
		if (removedElem != nullptr)
			return removedElem;
	}

	return removedElem;
}

unique_ptr<TripElement> Segment::removeElement(const int id) {
	auto it = find_if(
		elements.begin(),
		elements.end(),
		[id](const unique_ptr<TripElement>& elem) {
			return elem->getId() == id;
		}
	);

	if (it != elements.end()) {
		unique_ptr<TripElement> removedElem = move(*it);
		elements.erase(it);
		return removedElem;
	}

	return nullptr;
}

unique_ptr<TripElement> Segment::clone() const {
	return make_unique<Segment>(*this);
}

unique_ptr<Segment> Segment::clone(string newName) const {
	auto copied = make_unique<Segment>(*this);
	copied->setName(newName);
	cout << copied->getName() << " copie a partir du " << getName() << endl;
	return copied;
}