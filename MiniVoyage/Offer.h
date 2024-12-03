#pragma once

#include <string>
#include <memory>

class Offer
{
public:
	Offer();
	virtual ~Offer() = default;

	int getId() const;
	virtual std::string getName() const = 0;
	virtual Offer* getOfferByName(std::string name) const;

	// virtual Offer& add(Offer& elem);
	virtual void add(std::unique_ptr<Offer> elem);
	virtual std::unique_ptr<Offer> remove(int id);

	virtual void addFromFile(std::string path);

private:
	static const std::string NON_COMPOSITE_ERROR_MESSAGE;
	static int currentId;
	const int id;
};