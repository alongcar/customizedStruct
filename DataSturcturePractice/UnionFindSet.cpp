#include "UnionFindSet.hpp"
#include<iomanip>

struct Edge {
	int left;
	int right;
};

void ufs_practice() {
	UnionFindSet<int> u{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	printUFSet(u);
	std::vector<Edge> e{ {1, 2}, {2, 4}, {3, 5}, {4, 7}, {5, 8}, {6, 9}, {6, 10} };
	for (auto e_it = e.begin(); e_it < e.end(); ++e_it) {
		u.unionSet(e_it->left, e_it->right);
	}
	std::cout << std::endl;
	printUFSet(u);
	std::cout << "2与7 " << (u.find(2) == u.find(7) ? "是连通的" : "不连通") << std::endl;

}

void printUFSet(UnionFindSet<int> u) {
	UnionFindSet<int>::iterator iter = u.begin();
	for (auto iter = u.begin(); iter != u.end(); ++iter) {
		std::cout << std::setw(4) << iter->parent << std::setw(4) << iter->data << std::endl;
	}
}