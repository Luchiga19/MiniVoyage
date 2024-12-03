#pragma once

#include <memory>
#include <vector>

template <typename T>
class IteratorAbsConst
{
public:
	using IteratorType = typename std::vector<std::unique_ptr<T>>::const_iterator;

	IteratorAbsConst(IteratorType it) :
		it(it) {}
	virtual ~IteratorAbsConst() = default;

	virtual const T& operator*() const = 0;
	virtual const T* operator->() const = 0;

	IteratorAbsConst& operator++() {
		++it;
		return *this;
	}

	bool operator==(const IteratorAbsConst& other) const {
		return it == other.it;
	}

	bool operator!=(const IteratorAbsConst& other) const {
		return !(*this == other);
	}

protected:
	IteratorType it;
};