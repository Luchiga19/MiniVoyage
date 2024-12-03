#include "OfferVisitor.h"
#include "Category.h"

void OfferVisitor::visitCategory(Category& category) {
	for (auto& elem : category)
		elem.accept(*this);
}