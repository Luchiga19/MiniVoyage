#include "TripIterator.h"

TripElement& TripIterator::operator*() {
	return **it;
}

TripElement* TripIterator::operator->() {
	return it->get();
}