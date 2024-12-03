#include "CountVisitor.h"
#include "Hotel.h"
#include "Flight.h"
#include "Excursion.h"

CountVisitor::CountVisitor() {
	count = 0;
}

int CountVisitor::getCount() const{
	return count;
}

void CountVisitor::visitHotel(Hotel& hotel) {
	incrementCount();
}

void CountVisitor::visitExcursion(Excursion& excursion) {
	incrementCount();
}

void CountVisitor::visitFlight(Flight& fligh) {
	incrementCount();
}

void CountVisitor::incrementCount() {
	count++;
}