#include "TripIteratorConst.h"

const TripElement& TripIteratorConst::operator*() const {
	return **it;
}

const TripElement* TripIteratorConst::operator->() const {
	return it->get();
}