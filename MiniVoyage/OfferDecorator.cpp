#include "OfferDecorator.h"
#include "Category.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

OfferDecorator::OfferDecorator(unique_ptr<ItemOffer> offer) : offer(move(offer)) {}

void OfferDecorator::addComment(std::string comment)  {
	comments.push_back(comment);
}

string OfferDecorator::removeComment(size_t index) {
	if (index >= comments.size()) {
		throw out_of_range("Index du commentaire invalide.");
	}
	string removedComment = comments[index];
	comments.erase(comments.begin() + index);
	return removedComment;
}

void OfferDecorator::addFlatDiscount(int flatDiscount) {
	if (flatDiscount > 0)
		temporaryDiscount = flatDiscount;
}

void OfferDecorator::removeTemporaryDiscount() {
	temporaryDiscount = 0;
}

void OfferDecorator::accept(OfferVisitor& visitor) {
	offer->accept(visitor);
}

string OfferDecorator::toString() const {
	string str;

	for (auto& comment : comments)
		str += "      Commentaire: " + comment + "\n";
	return str;
}

string OfferDecorator::getName() const {
	return offer->getName();
}

int OfferDecorator::getCost() const {
	int cost = offer->getCost();
	return cost - temporaryDiscount;
}

string OfferDecorator::getType() const {
	return offer->getType();
}