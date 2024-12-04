#pragma once

#include <string>
#include <memory>

class OfferVisitor;

class Offer
{
public:
	Offer();
	virtual ~Offer() = default;

	int getId() const;
	virtual std::string getName() const = 0;
	virtual int getCost() const = 0;
	virtual Offer* getOfferByName(std::string name) const;

	virtual std::string toString() const;

	virtual void accept(OfferVisitor& visitor) = 0;

	virtual void add(std::unique_ptr<Offer> elem);
	virtual std::unique_ptr<Offer> remove(int id);

	virtual void addFromFile(std::string path, std::string type);

private:
	static const std::string NON_COMPOSITE_ERROR_MESSAGE;
	static int currentId;
	const int id;
};