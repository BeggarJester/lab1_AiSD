#include "lab1_AiSD_MapRBTree.h"

int main()
{
	cout << "Create and fill in our test Map based on RBTree step by step:\n\n";

	CustomMap<int, int> MyCustomMap;
	MyCustomMap.insert(13, 31);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(8, 18);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(17, 71);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(1, 3);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(11, 42);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(15, 51);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(25, 52);
	MyCustomMap.print();
	cout << '\n';
	MyCustomMap.insert(6, 9);
	MyCustomMap.print();
	cout << '\n';
	cout << "Try to delete the node with key 7:\n\n";
	try {
		MyCustomMap.remove(7);
	}
	catch (const out_of_range error) {
		cout << error.what();
	}
	cout << '\n';
	cout << "Delete the node with key 17:\n\n";
	MyCustomMap.remove(17);
	MyCustomMap.print();
	cout << '\n';
	cout << "Return the node with key 17 back:\n\n";
	MyCustomMap.insert(17, 71);
	MyCustomMap.print();
	cout << '\n';
	cout << "Get the list of Map keys:\n\n";
	Linked_list<int> map_keys = MyCustomMap.get_keys();
	while (map_keys.head != NULL) {
		cout << map_keys.get_head() << " ";
		map_keys.set_next();
	}
	cout << '\n';
	cout << '\n';
	cout << "Get the list of Map values:\n\n";
	Linked_list<int> map_values = MyCustomMap.get_values();
	while (map_values.head != NULL) {
		cout << map_values.get_head() << " ";
		map_values.set_next();
	}
	return 0;
}

