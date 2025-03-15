#pragma once
#include<memory>
#include<functional>
#include<vector>
#include<iostream>
#include<initializer_list>
/*** 默认为小顶堆 ***/
template<typename T, typename F = std::less<T>>
class Heap
{
public:
	typedef typename T HNode;
	typedef typename std::vector<T>::iterator iterator;
	Heap():Harray() {}
	Heap(std::initializer_list<T> ilst);
	iterator begin() { return Harray.begin(); }
	iterator end() { return Harray.end(); }
	HNode operator[](int i) { return Harray[i]; }
	int insert(HNode x);
	void print(int index);
	T deleteHeapRoot();
private:
	std::vector<T> Harray;

};

template<typename T, typename F>
int Heap<T, F>::insert(HNode x) {
	if (Harray.empty()) {
		Harray.push_back(x);
		return 0;
	}
	Harray.push_back(x);
	int curIndex = Harray.size() - 1;
	int parIndex = (curIndex - 1) / 2;
	F f;
	while (parIndex >= 0 && f(Harray[curIndex], Harray[parIndex])) {
		std::iter_swap(Harray.begin() + parIndex, Harray.begin() + curIndex); 
		curIndex = parIndex;
		parIndex = (curIndex - 1) / 2;
	}
	return curIndex;
}


template<typename T, typename F>
void Heap<T, F>::print(int index) {
	for (int i = index + 1; i > 0; i /= 2) {
		int j = i - 1;
		std::cout << *(begin()+j) << " ";
	}
	// std::cout << *(begin());
	std::cout << std::endl;
}

template<typename T, typename F>
void printHeap(Heap<T, F> h) {
	int i = 0;
	for (auto iter = h.begin(); iter < h.end(); ++iter) {
		std::cout << i++ << " " << *iter << std::endl;
	}
}

/*** 删除堆的根节点，并调整堆 ***/
template<typename T, typename F>
T Heap<T, F>::deleteHeapRoot() {
	F compare;
	HNode oldroot = Harray[0];
	int n = Harray.size();
	Harray[0] = Harray[n - 1];
	Harray.pop_back(); --n;
	int i = 0; 		
	HNode temp = Harray[0];
	while (i * 2 + 1 < n) {
		int left = i * 2 + 1, right = i * 2 + 2 , sp = left;
		if (right < n) {
			if (!compare(Harray[left], Harray[right])) {
				sp = right;
			}
		}
		if (compare(Harray[sp], temp)) {
			Harray[i] = Harray[sp];
			Harray[sp] = temp;
			i = sp;
		}
		else break;
		
	}
	return oldroot;
}


int gethigh(int n);

int mypow2(int x, int n);

template<typename T, typename F>
Heap<T, F>::Heap(std::initializer_list<T> ilst): Harray(ilst) {
	F compare;
	int n = Harray.size();
	// int h = log(double(n)) / log(2.00); 
	int h = gethigh(n);
	int i = mypow2(2, h - 1) - 1; --i;
	int cnt = 1;
	while (i >= 0) {
		int left = 2 * i + 1, right = 2 * i + 2, sp = left;
		for (int j = i; 2 * j + 1 < n;) {
			left = 2 * j + 1;
			right = left + 1;
			sp = left;
			if (right < n) {
				if (compare(Harray[right], Harray[left])) sp = right;
			}
			if (compare(Harray[sp], Harray[j])) {
				T temp = Harray[j];
				Harray[j] = Harray[sp];
				Harray[sp] = temp;
				j = sp;
			}
			else break;
		}
		/* std::cout << "第" << cnt << "次调整" << std::endl;++cnt; printHeap(*this);*/
		--i;
	}

}


void heap_practice();