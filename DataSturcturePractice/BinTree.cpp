#include"BinTree.hpp"

int mypow(int i, int j) {
	if (j == 1) return i;
	if (j == 0) return 1;
	if (j % 2 == 0) {
		int res = mypow(i, j / 2);
		return res * res;
	}
	else {
		int res = mypow(i, (j - 1) / 2);
		return res * res * i;
	}
}

void printBinTree_null(const BinTree<int>& b) {
	MyQueue<TreeNode<int>*> q;
	if (b.root != nullptr) q.inqueue(b.root);
	else return;
	int ncnt = 0;
	while (!q.isEmpty()) {
		QNode<TreeNode<int>*> *p = q.first;
		std::cout << p->value->data << " ";
		if (p->value->left.root != nullptr) {
			while (ncnt) {
				std::cout << "null ";
				--ncnt;
			}
			q.inqueue(p->value->left.root);
			if (p->value->right.root == nullptr) {
				++ncnt;
			}
		}
		if (p->value->right.root != nullptr) {
			if (p->value->left.root == nullptr) ++ncnt;
			q.inqueue(p->value->right.root);

		}
		if (p->value->left.root == nullptr && p->value->right.root == nullptr) ncnt += 2;
		q.dequeue();
	}
	std::cout << std::endl;
}
