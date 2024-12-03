#include "OfferIteratorConst.h"

const Offer& OfferIteratorConst::operator*() const {
	return **it;
}

const Offer* OfferIteratorConst::operator->() const {
	return it->get();
}