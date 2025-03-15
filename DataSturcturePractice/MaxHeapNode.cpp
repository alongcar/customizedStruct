#include "MaxHeapNode.hpp"
#include<queue>
#include<stack>
#include<iostream>
#include"MyQueue.hpp"

void printMaxHeap(const MaxHeap& b) {
	MyQueue<MaxHeap> q;
	if (b != nullptr) q.inqueue(b);
	while (!q.isEmpty()) {
		QNode<MaxHeap>* p = q.first;
		std::cout << p->value->val << " ";
		if (p->value->left != nullptr)
			q.inqueue(p->value->left);
		if (p->value->right != nullptr)
			q.inqueue(p->value->right);
		q.dequeue();
	}
	std::cout << std::endl;
}

void printMaxHeap_null(const MaxHeap& b) {
	MyQueue<MaxHeap> q;
	if (b != nullptr) q.inqueue(b);
	int ncnt = 0;
	while (!q.isEmpty()) {
		QNode<MaxHeap>* p = q.first;
		/*if (p->value == nullptr) std::cout << "null ";
		else {*/
			std::cout << p->value->val << " ";
			if (p->value->left != nullptr) {
				while (ncnt) {
					std::cout << "null ";
					--ncnt;
				}
				q.inqueue(p->value->left);
				if (p->value->right == nullptr) {
					++ncnt;
					// q.inqueue(QNode<MaxHeap>(nullptr));
				}
			}
			if (p->value->right != nullptr) {
				if (p->value->left == nullptr) ++ncnt; // q.inqueue(QNode<MaxHeap>(nullptr));
				q.inqueue(p->value->right);
				
			}
		// }
			if(p->value->left != nullptr && p->value->right == nullptr) ncnt += 2;
		q.dequeue();
	}
	std::cout << std::endl;
}

void findAncestor(MaxHeap root, std::queue<MaxHeap>& acs);

void MaxHeapNode::push(int x) {
	MaxHeap p = new MaxHeapNode(x);
	std::queue<MaxHeap> tvsq;
	tvsq.push(this);
	MaxHeap pa;
	while (!tvsq.empty()) {
		if (tvsq.front()->left != nullptr) tvsq.push(tvsq.front()->left);
		else {
			pa = tvsq.front();
			std::cout << "找到了插入位置，编号为:" << tvsq.front()->val << std::endl;
			tvsq.front()->left = p; break;
		}
		if (tvsq.front()->right != nullptr) tvsq.push(tvsq.front()->right);
		else {
			pa = tvsq.front();
			std::cout << "找到了插入位置，编号为:" << tvsq.front()->val << std::endl;
			tvsq.front()->right = p; break;
		}
		tvsq.pop();
	}
	while(!tvsq.empty()) tvsq.pop();
	tvsq.~queue<MaxHeap>();
	// 找插入位置的祖先节点
	std::queue<MaxHeap> acs;
	acs.push(p);
	findAncestor(this, acs);
	acs.pop();
	// 接下来进行堆的调整，将调整结点与其父节点比较，大于交换（调整结点值与父节点交换且调整结点变为其父节点），小于或调整结点已经是根节点，退出循环，完成插入
	while (!acs.empty() && p->val > acs.front()->val) {
		std::cout << acs.front()->val << " ";
		int temp = acs.front()->val;
		acs.front()->val = p->val;
		p->val = temp;
		p = acs.front();
		acs.pop();
	}
	std::cout << std::endl;
}

void findAncestor(MaxHeap root, std::queue<MaxHeap> &acs) {
	if (root == nullptr) return;
	if (root == acs.front()) return;
	findAncestor(root->left, acs);
	findAncestor(root->right, acs);
	if (root->left == acs.back()) {
		acs.push(root);
	}
	else if (root->right == acs.back()){
		acs.push(root);
	}
	
}

void MaxHeapNode::createMaxHeap(std::initializer_list<int> ilist) {
	
}