#include "HFTreeNode.h"
#include<initializer_list>


void printBinTree_null(HaffmanTree tree) {
	MyQueue<HaffmanTree> q;
	if (tree != nullptr) q.inqueue(tree);
	else return;
	int ncnt = 0;
	while (!q.isEmpty()) {
		QNode<HaffmanTree>* p = q.first;
		p->value->print();
		std::cout << " ";
		if (p->value->left != nullptr) {
			while (ncnt) {
				std::cout << "null ";
				--ncnt;
			}
			q.inqueue(p->value->left);
			if (p->value->right == nullptr) {
				++ncnt;
			}
		}
		if (p->value->right != nullptr) {
			if (p->value->left == nullptr) ++ncnt;
			q.inqueue(p->value->right);

		}
		if (p->value->left == nullptr && p->value->right == nullptr) ncnt += 2;
		q.dequeue();
	}
	std::cout << std::endl;

}

HaffmanTree createHaffmanTree() {
	std::deque<HaffmanTree> hfdq;
	int weight;
	while (std::cin >> weight) {
		HaffmanTree hfNode = new HFTreeNode(weight);
		hfdq.push_front(hfNode);
	}
	while (hfdq.size() > 1) {
		HaffmanTree hfroot = new HFTreeNode();
		hfroot->left = sortMinNode(hfdq);
		hfdq.pop_back();
		hfroot->right = sortMinNode(hfdq);
		hfdq.pop_back();
		hfroot->weight = hfroot->left->weight + hfroot->right->weight;
		hfdq.push_front(hfroot);
	}
	return hfdq.back();

}




void HFTreeNode::print() {
	std::cout << weight;
}


HaffmanTree sortMinNode(std::deque<HaffmanTree>& hfdq) {
	std::deque<HaffmanTree>::iterator p = hfdq.begin();
	std::deque<HaffmanTree>::iterator q = p + 1;
	while (q != hfdq.end()) {
		if ((*p)->weight < (*q)->weight) {
			// swap(p, q);
			HaffmanTree temp = *p;
			*p = *q;
			*q = temp;
			temp = nullptr;
		}
		++p;
		++q;
	}
	return hfdq.back();
}



HFTreeNode::~HFTreeNode() {
	if (left != nullptr) {
		left->~HFTreeNode();
		operator delete(left);
		left = nullptr;

	}
	if (right != nullptr) {
		right->~HFTreeNode();
		operator delete(right);
		right = nullptr;
	}
}


void HFTreeNode::operator delete(void* p) noexcept {
	free(p);
}