#ifndef MS3_CUSTOMER_ORDER_H
#define MS3_CUSTOMER_ORDER_H

#include "Item.h"

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

private:
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem = nullptr;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string& record);
	CustomerOrder(CustomerOrder& other);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&& other) noexcept;
	CustomerOrder& operator=(CustomerOrder&& other);
	~CustomerOrder();
	bool getItemFillState(std::string item) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif