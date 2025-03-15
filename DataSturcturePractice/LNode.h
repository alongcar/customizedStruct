#pragma once
#include<initializer_list>
#include<stdexcept>
#include<iostream>
#define MAXSIZE 1000


//LNode<int> ln({ 1, 2, 3, 4 });
//std::cout << ln.last << " ";
//for (int i = 5; i < 9; i++) ln.insert(i, i - 1);
//std::cout << ln.find(6);

/*** 顺序表的实现 ***/
template<typename T>class LNode
{
public:
	T data[MAXSIZE];
	int last;
	LNode() :last(-1) {}
	int length() { return last+1; }
	T findKth(int k) { return data[k]; }
	int find(T x);
	void insert(T x, int i);
	LNode(std::initializer_list<T> ilst);
	// ~LNode() {}

};



template<typename T>
int LNode<T>::find(T x) {
	for (int i = 0; i < last; i++) {
		if (data[i] == x) return i;
	}
	return -1;
}

template<typename T>
void LNode<T>::insert(T x, int i) {
	try {
		if (last + 1 < i || i < 0) {
			throw std::out_of_range("越界异常！ ");
		}
	}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	if (i == last + 1) {
		data[last + 1] = x; ++last;
		return;
	}

	for (int j = last; j >= i; j--) {
		data[j + 1] = data[j];
	}
	data[i] = x; // x必须有拷贝构造函数
	++last;
}

template<typename T>
LNode<T>::LNode(std::initializer_list<T> ilst) :last(-1) {
	auto iter = ilst.begin();
	int i = 0;
	while (iter != ilst.end()) {
		insert(*iter, i);
		++iter;
		++i;
	}
}
