#pragma once
#include<initializer_list>

//MaxHeap maxh = new MaxHeapNode(1);
//for (int i = 2;i < 5;i++) {
//       maxh->push(i);
   //	printMaxHeap_null(maxh);
   //}
   //maxh->push(17);
   //printMaxHeap_null(maxh);



extern struct MaxHeapNode;
typedef MaxHeapNode* MaxHeap;
struct MaxHeapNode
{
	int val;
	MaxHeap left;
	MaxHeap right;
	int size;
	MaxHeapNode() : val(0), left(nullptr), right(nullptr), size(0) {}
	MaxHeapNode(int v) : val(v), left(nullptr), right(nullptr), size(0) {}
	bool isFull();
	bool isEmpty();
	/*** 插入一个值到堆中，仍保持堆的完全二叉树结构 ***/
	void push(int x);
	/*** 删除堆中的最大值，将删除后的堆中结点最大值作为新的根结点 ***/
	void pop();
	void createMaxHeap(std::initializer_list<int> ilist);
	~MaxHeapNode();
};
void printMaxHeap_null(const MaxHeap& b);
void printMaxHeap(const MaxHeap& b);

