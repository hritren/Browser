#include"Browser.h"

Browser::Browser(){
	tabs.pushBack(Tab());
	current = 0;
}

void Browser::start() {
	while (true) {
		string op;
		cin >> op;
		if (op == "EXIT") {
			return;
		}
		operation(op);
	}
}

void Browser::operation(const string& op) {
	if (op == "GO") {
		string url;
		cin >> url;
		tabs.updateAt(Tab(url), current);
		return;
	}
	if (op == "INSERT")	{
		string url;
		cin >> url;
		tabs.insertAt(Tab(url), ++current);
		return;
	}
	if (op == "BACK") {
		if (current > 0) {
			current--;
		}
		return;
	}
	if (op == "FORWARD") {
		if (current < tabs.size() - 1) {
			current++;
		}
		return;
	}
	if (op == "REMOVE") {
		if (current < tabs.size() - 1) {
			tabs.removeAt(current);
			return;
		}
		if (current == tabs.size() - 1 && current > 0) {
			tabs.removeAt(current--);
			return;
		}
		if (current == 0) {
			tabs.removeAt(current);
			tabs.pushBack(Tab());
			return;
		}
	}
	if (op == "PRINT") {
		tabs.print(current);
		return;
	}
}