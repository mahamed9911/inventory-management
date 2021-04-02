#include "Utilities.h"
#include "Item.h"
#include <iomanip>
unsigned int Item::m_widthField = 0;

Item::Item(const std::string& record) {
	size_t m_count = 0u;
	size_t m_pos = 0u;
	bool m_more = true;
	Utilities utilities;
	while (m_more && m_count < 4) {
		if (m_count == 0) {
			m_name = utilities.extractToken(record, m_pos, m_more);
		}
		else if (m_count == 1) {
			m_serialNumber = (unsigned)std::stoi(utilities.extractToken(record, m_pos, m_more));
		}
		else if (m_count == 2) {
			m_quantity = (unsigned int)std::stoi(utilities.extractToken(record, m_pos, m_more));
			if (utilities.getFieldWidth() > m_widthField) {
				m_widthField = utilities.getFieldWidth();
			}
		}
		else m_description = utilities.extractToken(record, m_pos, m_more);
		m_count++;
	}
}


const std::string& Item::getName() const {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
}


const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity > 0)
		m_quantity--;
}

void Item::display(std::ostream& os, bool full) const {

	if (full) {
		os << std::setw(m_widthField) << std::left << m_name;
		os << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left;
		os << "] Quantity: " << std::setw(m_widthField) << std::left << m_quantity;
		os << " Description: " << m_description << std::endl;
	}
	else {
		os << std::setw(m_widthField) << std::left << m_name;
		os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left << "]" << std::endl;
	}

}