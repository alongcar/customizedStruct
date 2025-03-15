#pragma once
#include<vector>
#include<initializer_list>
#include<exception>
#include<iostream>

/**
* ���鼯����������Ϸ���һ��vector�У�ʵ�ֲ���Ԫ�����ڵļ��ϣ��ϲ����ϵĹ���
* �洢���ڵ��ָ������ʾһ������ÿ����������ڵ�����һ�����ϣ��Խ������ĸ���ֵ����Ϊ�����ĸ��ڵ� 
**/
template<typename T>
class UnionFindSet
{
public:
	struct UFNode {
		int parent;
		T data;
		bool operator==(const UnionFindSet<T>::UFNode u2) {
			return this->data == u2.data; // ��ζ��data�����ṩ��==����
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

/*** ����xԪ�����ĸ�������, ���ؼ��ϸ�Ԫ�ص��±꣬�Ҳ�������-1 ***/
template<typename T>
int UnionFindSet<T>::find(const T& x)const {
	// i��Ԫ���±ꡣ
	int i = 0;
	// ����Ԫ��x�����ڵ��±�
	while (i < ufs.size() && x != ufs[i].data) {
		++i;
	}
	// ��û��ֵΪx��Ԫ�أ�����-1
	if (i == ufs.size()) return -1;
	// ��x�ĸ��ڵ��������ڼ��ϵĸ������ڵ�С��0Ϊ����
	while (ufs[i].parent >= 0) i = ufs[i].parent;
	return i;
}

/*** �ϲ�x1��x2���ڼ��� ***/
template<typename T>
void UnionFindSet<T>::unionSet(const T& x1, const T& x2) {
	int us1 = find(x1);
	int us2 = find(x2);
	try {
		if (us1 < 0 || us2 < 0) throw std::runtime_error("�������x1��x2�������ڸò��鼯�ṹ");
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