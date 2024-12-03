#pragma once

#include <memory>
#include <vector>

template <typename T>
class IteratorAbs
{
public:
	using IteratorType = typename std::vector<std::unique_ptr<T>>::iterator;

	IteratorAbs(IteratorType it) :
		it(it) {}
	virtual ~IteratorAbs() = default;

	virtual T& operator*() = 0;
	virtual T* operator->() = 0;

	IteratorAbs& operator++() {
		++it;
		return *this;
	}
	
	bool operator==(const IteratorAbs& other) const {
		return it == other.it;
	}

	bool operator!=(const IteratorAbs& other) const {
		return !(*this == other);
	}

protected:
	IteratorType it;
};

