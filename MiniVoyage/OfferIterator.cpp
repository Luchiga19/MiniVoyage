#include "OfferIterator.h"

Offer& OfferIterator::operator*() {
	return **it;
}

Offer* OfferIterator::operator->() {
	return it->get();
}