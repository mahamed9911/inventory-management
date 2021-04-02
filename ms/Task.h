#ifndef MS3_TASK_H
#define MS3_TASK_H

#include <deque>
#include "Item.h"
#include "CustomerOrder.h"
class Task : public Item { 

private:
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:


	Task(const std::string&);
	Task(Task&) = delete;
	Task& operator=(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);

	Task& operator+=(CustomerOrder&&);
};

#endif 