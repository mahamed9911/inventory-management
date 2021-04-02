#ifndef MS3_ITEM_H
#define MS3_ITEM_H

#include <iostream>
#include <iomanip>

class Item {

private:
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	static unsigned int m_widthField;

public:
	// from the input file specified by the user.
	Item(const std::string& record);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif