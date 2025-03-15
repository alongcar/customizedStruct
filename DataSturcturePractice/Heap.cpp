#include "Heap.hpp"
#include<functional>
#include<iostream>
#include<sstream>
#include<string>
void heap_practice() {
	// less «x1 < x2µƒ°£
	Heap<int, std::greater<int>> h;
	std::string line;
	std::getline(std::cin, line);
	std::istringstream is(line);
	int i;
	std::string num;
	while (is >> num) {
		i = stoi(num);
		h.insert(i);
	}
	printHeap(h);
	h.deleteHeapRoot();
	std::cout << std::endl;
	printHeap(h);

	Heap<int, std::greater<int>> h1({23, 28, 78, 93, 121, 12, 5});
	std::cout << std::endl;
	printHeap(h1);
	while(std::cin >> i)
		h.print(i);
}

int gethigh(int n) {
	int h = 0;
	while (n != 0) {
		n /= 2;
		++h;
	}
	return h;
}

int mypow2(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	int half = mypow2(x, n / 2);
	if (n % 2) return x * half * half;
	else return half * half;
}

