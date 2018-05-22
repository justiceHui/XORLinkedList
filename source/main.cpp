#include "XORlist.cpp"

int main() {
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(0);
	l.printList(); std::cout << "\n";
	l.pop_back();
	l.printList(); std::cout << "\n";
	l.pop_front();
	l.printList(); std::cout << "\n";
	l.pop_back();
	l.pop_front();
	l.printList();
	l.pop_back();
	l.printList();
}
