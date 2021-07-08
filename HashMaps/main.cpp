#include "HashTable.h"

int main() {
	HashMap map(50);

	map.set("grapes", 10);
	map.set("orange", 20);
	map.set("apple", 30);
	map.set("grapes", 50);  //example of a collision
	map.set("kiwi", 60);
	map.displayKeys();

	map.remove("apple");
	std::cout << std::endl;
	map.displayKeys();
}