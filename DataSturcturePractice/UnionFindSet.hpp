#pragma once
#include<vector>
#include<initializer_list>
#include<exception>
#include<iostream>

/**
* 并查集，将多个集合放在一个vector中，实现查找元素所在的集合，合并集合的功能
* 存储父节点的指针来表示一颗树，每个根结点所在的树是一个集合，以结点个数的负数值来作为根结点的父节点 
**/
template<typename T>
class UnionFindSet
{
public:
	struct UFNode {
		int parent;
		T data;
		bool operator==(const UnionFindSet<T>::UFNode u2) {
			return this->data == u2.data; // 意味着data必须提供了==运算
		}
	};
	typedef typename std::vector<UFNode>::iterator iterator;
	UnionFindSet(){}
	UnionFindSet(iterator b, iterator e) :ufs(b, e) {}
	explicit UnionFindSet(std::vector<UFNode>& v) :ufs(v) {}
	explicit UnionFindSet(std::initializer_list<T> ilst){
		auto ilst_iter = ilst.begin();
		for (size_t i = 0; i < ilst.size(); ++i) {
			ufs.push_back({ -1, *ilst_iter });
			++ilst_iter;
		}
	}
	
	UFNode operator[](int i) {
		return ufs[i];
	}
	iterator begin() { return ufs.begin(); }
	iterator end() { return ufs.end(); }
	int find(const T&)const;
	void unionSet(const T& x1, const T& x2);
	bool isConnected(const T& x1, const T& x2);
private:
	std::vector<UFNode> ufs;
};

/*** 查找x元素在哪个集合中, 返回集合根元素的下标，找不到返回-1 ***/
template<typename T>
int UnionFindSet<T>::find(const T& x)const {
	// i是元素下标。
	int i = 0;
	// 查找元素x的所在的下标
	while (i < ufs.size() && x != ufs[i].data) {
		++i;
	}
	// 若没有值为x的元素，返回-1
	if (i == ufs.size()) return -1;
	// 从x的父节点找它所在集合的根，父节点小于0为根。
	while (ufs[i].parent >= 0) i = ufs[i].parent;
	return i;
}

/*** 合并x1和x2所在集合 ***/
template<typename T>
void UnionFindSet<T>::unionSet(const T& x1, const T& x2) {
	int us1 = find(x1);
	int us2 = find(x2);
	try {
		if (us1 < 0 || us2 < 0) throw std::runtime_error("输入错误，x1或x2不存在于该并查集结构");
	}
	catch (std::runtime_error e) {
		std::cerr << e.what();
	}
	if (us1 != us2) {
		if (ufs[us1].parent > ufs[us2].parent) {
			ufs[us2].parent = ufs[us2].parent + ufs[us1].parent;
			ufs[us1].parent = us2;
		}
		else {
			ufs[us1].parent = ufs[us1].parent + ufs[us2].parent;
			ufs[us2].parent = us1;
		}
			
	}
}

template<typename T>
bool UnionFindSet<T>::isConnected(const T& x1, const T& x2) {
	int us1 = find(x1);
	int us2 = find(x2);
	if (us1 != us2 || us1 < 0 || us2 < 0) return false;
	return true;
}

void printUFSet(UnionFindSet<int> u);

void ufs_practice();