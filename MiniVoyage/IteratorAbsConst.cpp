/**
#include "IteratorAbsConst.h"

template <typename T>
bool IteratorAbsConst<T>::operator==(const IteratorAbsConst<T>& other) const {
	return it == other.it;
}

template <typename T>
bool IteratorAbsConst<T>::operator!=(const IteratorAbsConst<T>& other) const {
	return !(*this == other);
}

template <typename T>
IteratorAbsConst<T>& IteratorAbsConst<T>::operator++() {
	
}
**/