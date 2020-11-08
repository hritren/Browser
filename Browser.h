#pragma once
#include"Tab.h"

class Browser {
public:
	Browser();
	void start();
private:
	DoublyLinkedList<Tab> tabs;
	size_t current;
	void operation(const string& op);
};

