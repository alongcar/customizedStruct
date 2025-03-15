#include "HashTable.h"


void printHashTable(const HashTable<int, int> &ht) {
	for (const auto& hn : ht) {
		std::cout << hn.name << " ";
	}
	std::cout << std::endl;
	for (const auto& hn : ht) {
		std::cout << hn.attr << " ";
	}
}

void pracHashTable() {
	size_t n = 17;
	HashTable<int, int> ht = createNkeyHashTable(n);
	listInitHashTable(ht, { {18, 19}, {23, 24}, {2, 3}, {11, 12}, {20, 21}, {3, 4}, {7, 8}, {27, 28}, {30, 31}, {42, 43}, {15, 16}, {34, 35} });
	printHashTable(ht);
	insertht(ht, 55, 56 );
	deleteht(ht, 27);
	std::cout << "\n插入删除以后:" << std::endl;
	printHashTable(ht);
}

HashTable<int, int> createNkeyHashTable(size_t tableSize) {
	return HashTable<int, int>(tableSize, { -1, -1 });
}


bool isIn(HashTable<int, int> ht, int name) {
	int key = name % ht.size();
	if (ht[key].name == name) {
		return true;
	}
	return false;
}


void listInitHashTable(HashTable<int, int>& ht, std::initializer_list<NkeyHashNode<int, int>> ilst) {int n = ilst.size();
	for (auto iter = ilst.begin();iter != ilst.end(); ++iter) {
		int key =  iter->name % ht.size();
		if(ht[key].name == -1) {
			ht[key] = *iter;
		}
		
	}
}

NkeyHashNode<int, int>::AttributeType find(HashTable<int, int>& ht, int name) {
	int key = name % ht.size();
	try {
		if (ht[key].name == name) {
			return ht[key].attr;
		}
		else {
			std::string s = "没有名为 ";
			s += name;
			s.append(" 的元素");
			throw std::runtime_error(s);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what();
	}
	return -1;
}

void insertht(HashTable<int, int>& ht, int name, int attr) {
	int key = name % ht.size();
	ht[key] = NkeyHashNode<int, int>({ name, attr });

}

void deleteht(HashTable<int, int>& ht, int name) {
	int key = name % ht.size();
	if (ht[key].name != -1) {
		ht[key] = NkeyHashNode<int, int>({ -1, -1 });
	}
}