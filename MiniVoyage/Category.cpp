#include "Category.h"
#include "Flight.h"
#include "Hotel.h"
#include "Excursion.h"
#include "ItemOffer.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


Category::Category(string name) {
	this->name = name;
}

Category::iterator Category::begin() {
	return iterator(elements.begin());
}

Category::iterator Category::end() {
	return iterator(elements.end());
}

Category::const_iterator Category::begin() const {
	return const_iterator(elements.cbegin());
}

Category::const_iterator Category::end() const {
	return const_iterator(elements.cend());
}

string Category::getName() const {
	return name;
}

Offer* Category::getOfferByName(string name) const {
	Offer* offer = nullptr;
	if (auto ptr = dynamic_cast<Category*>(elements[0].get())) {
		for (auto& elem : elements) {
			offer = elem->getOfferByName(name);

			if (offer != nullptr)
				return offer;
		}
	}

	for (auto& elem : elements) {
		if (elem->getName() == name)
			return elem.get();
	}

	return nullptr;
}

int Category::getCost() const {
	cerr << "Not an itemOffer" << endl;
	return -1;
}

void Category::accept(OfferVisitor& visitor) {
	visitor.visitCategory(*this);
}

void Category::add(unique_ptr<Offer> elem) {
	elements.push_back(move(elem));
}

unique_ptr<Offer> Category::remove(const int id) {
	if (getId() == id) {
		cerr << "Cannot remove self" << endl;
		return nullptr;
	}

	if (elements.empty())
		return nullptr;

	if (dynamic_cast<Category*>(elements[0].get()) != nullptr)
		return removeCategory(id);

	return removeItemOffer(id);
}

void Category::addFromFile(string path, string type) {
	ifstream file(path);
	if (!file.is_open()) {
		cerr << "Could not open the file" << endl;
		return;
	}

	string line;
	if (getline(file, line)) {
		vector<string> headers = parseCsvLine(line);

		while (getline(file, line)) {
			vector<string> row = parseCsvLine(line);

			unique_ptr<ItemOffer> item;
			if (type == "transport")
				item = make_unique<Flight>();
			else if (type == "hebergement")
				item = make_unique<Hotel>();
			else if (type == "excursion")
				item = make_unique<Excursion>();

			for (size_t i = 0; i < headers.size(); i++)
				item->addData(headers[i], row[i]);

			cout << "Entree " << item->getName() << " rattachee a la categorie " << getName() << " creee!" << endl;
			add(move(item));
		}
	}
}

unique_ptr<Offer> Category::removeCategory(const int id) {
	unique_ptr<Offer> removedElem = nullptr;

	for (auto& elem : elements) {
		removedElem = elem->remove(id);
		if (removedElem != nullptr)
			return removedElem;
	}

	return removedElem;
}

unique_ptr<Offer> Category::removeItemOffer(const int id) {
	auto it = find_if(
		elements.begin(),
		elements.end(),
		[id](const unique_ptr<Offer>& elem) {
			return elem->getId() == id;
		}
	);

	if (it != elements.end()) {
		unique_ptr<Offer> removedElem = move(*it);
		elements.erase(it);
		return removedElem;
	}

	return nullptr;
}

vector<string> Category::parseCsvLine(string line) {
	stringstream ss(line);
	string value;
	vector<string> fields;

	while (getline(ss, value, ','))
		fields.push_back(value);

	return fields;
}