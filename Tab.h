#pragma once
#include"DoublyLinkedList.hpp"


class Tab {
public:
	Tab();
	Tab(string url);
	friend ostream& operator<<(ostream& os, const Tab& tab);
private:
	string url;
	time_t timestamp;
};

