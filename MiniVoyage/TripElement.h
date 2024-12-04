#pragma once

#include <memory>
#include <string>

class TripElement
{
public:
	TripElement(std::string name, std::string type);
	virtual ~TripElement() = default;

	int getId() const;
	std::string getName() const;
	std::string getType() const;
	virtual TripElement* getElementByName(std::string name) const;

	virtual std::string toString() const = 0;
	virtual int calculateCost() const = 0;

	virtual void add(std::unique_ptr<TripElement> elem);
	virtual std::unique_ptr<TripElement> remove(const int id);
	virtual std::unique_ptr<TripElement> clone() const = 0;

	void log(std::string filename) const;

protected:
	void setName(std::string name);
	
private:
	static const std::string NON_COMPOSITE_ERROR_MESSAGE;
	std::string name;
	std::string type;
	static int currentId;
	const int id;
};