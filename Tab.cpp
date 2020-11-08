#include"Tab.h"

Tab::Tab(){
	timestamp = clock();
	url = "about:blank";
}

Tab::Tab(string url) {
	this->url = url;
	timestamp = clock();
}

ostream& operator<<(ostream& os, const Tab& tab) {
	return os << tab.url << " " << tab.timestamp;
}
