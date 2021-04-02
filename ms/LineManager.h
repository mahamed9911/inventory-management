#ifndef MS3_LINE_MANAGER_H
#define MS3_LINE_MANAGER_H

#include <vector>
#include "Task.h"
#include "CustomerOrder.h"


class LineManager {

private:
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

	size_t m_startTask = 0u;
	size_t m_endTask = 0u;

public:

	LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerOrders);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};

#endif