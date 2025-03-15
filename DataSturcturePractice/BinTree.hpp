#pragma once
#include<iostream>
#include"MyQueue.hpp"
#include"myStack.hpp"
#include<initializer_list>

/*
* ��֤���룬ճ����main�У�����֤����Ŀ�ִ�жȣ�
    BinTree<int> b;
    // ����һ����Ŵ����Ҵ��ϵ��µ���������
	createIntNode(b, 1, 3);
	// �����ӡ
	printBinTree(b);
	// �����ӡ
	b.preOrderTraversal();
	std::cout << std::endl;
	// ��֤�Ƿ��ܿ�������һ��������
	BinTree<int> b1(b);
	printBinTree(b);

*/


template<typename T>
struct BinTree;

template<typename T>
struct TreeNode
{
	T data;
	BinTree<T> left;
	BinTree<T> right;
	// TreeNode() :left(nullptr), right(nullptr) {}
	explicit TreeNode(T dt) :data(dt),left(),right() {}
	/*** ������һ�����Ľ��, �ᴴ���������������ӽڵ�Ŀ��� ***/
	TreeNode(const TreeNode& x):data(x.data), left(x.left), right(x.right){}
	
};

/*** ������ ***/
template<typename T>
class BinTree {
public:
	TreeNode<T>* root;
	BinTree():root(nullptr) {}
	/*** ����һ������ʼ�������� ***/
	BinTree(const BinTree &b){
		if (b.root == nullptr) {
			root = nullptr;
			return;
		}
		root = new TreeNode<T>(*(b.root));
	}

	BinTree& operator=(const BinTree& b) {
	  BinTree<T> temp(b);
		deleteBinTree();
		if (temp.root == nullptr) {
			root = nullptr;
			return *this;
		}
		root = new TreeNode<T>(*(b.root));
		if (temp.root->left.root != nullptr)
			root->left = b.root->left;
		if (temp.root->right.root != nullptr)
			root->right = b.root->right;
		
	  return *this;
	}

	explicit BinTree(const T &dt) {
		root = new TreeNode<T>(dt);
	}

	/*** ���������ӡ������ ***/
	void preOrderTraversal();

	/*** ����ǵݹ���� ***/
	void midOrderTraversal();

	/*** ÿ�������Ὣ������Ӧ�������������һ������ ***/
	~BinTree() {
		deleteBinTree();
	}
private:
	void deleteBinTree();
};

template<typename T>
void BinTree<T>::deleteBinTree() {
	if (root == nullptr) return;
	if (root->left.root != nullptr)
		root->left.deleteBinTree();
	if (root->right.root != nullptr)
		root->right.deleteBinTree();
	delete(root);
	root = nullptr;
}

template<typename T>
void BinTree<T>::preOrderTraversal() {
	if (root == nullptr) return;
	std::cout << root->data << " ";
	if (root->left.root != nullptr)
		root->left.preOrderTraversal();
	if (root->right.root != nullptr)
		root->right.preOrderTraversal();
}

template<typename T>
void BinTree<T>::midOrderTraversal() {
	if (root == nullptr) return;
	MyStack<TreeNode<T>*> s;
	TreeNode<T>* p = root;
	s.push(p);
	while (!s.isEmpty()) {
		if (p->left.root == nullptr) {
			std::cout << (*(s.top()))->data << " ";
			s.pop();
			if (p->right.root != nullptr) {
                p = p->right.root;
			    s.push(p);
			}
			else {
				while (!s.isEmpty() && (*s.top())->right.root == nullptr) {
					std::cout << (*(s.top()))->data << " ";
					s.pop();
				}
				if (s.isEmpty()) break;
				p = (*(s.top()))->right.root;
				std::cout << (*(s.top()))->data << " ";
				s.pop();
				s.push(p);
			}
		}
		else if (p->left.root != nullptr) {
			p = p->left.root;
			s.push(p);
		}
		
	}
	
}

int mypow(int i, int j);

/*** ����һ���߶�Ϊh����������������ֵΪ�����Ҵ��ϵ��µ����ֱ�� ***/
template<typename T>
void createIntNode(BinTree<T> &b, int i, int h) {
	b.root = new TreeNode<T>(i);
	if (2 * i <= mypow(2, h) - 1)
		createIntNode(b.root->left, 2 * i, h);
	if(2 * i + 1 <= mypow(2, h) - 1)
		createIntNode(b.root->right, 2 * i + 1, h);
	if (i == 1) std::cout << std::endl;
}

/*** ���������ӡ������ ***/
template<typename T>
void printBinTree(const BinTree<T>& b) {
	MyQueue<TreeNode<T>*> q;
	if(b.root != nullptr) q.inqueue(b.root);
	while (!q.isEmpty()) {
		QNode<TreeNode<T>*> *p = q.first;
		std::cout << p->value->data << " ";
		if(p->value->left.root != nullptr)
			q.inqueue(p->value->left.root);
		if (p->value->right.root != nullptr)
			q.inqueue(p->value->right.root);
		q.dequeue();
	}
	std::cout << std::endl;
}


//BinTree<int> b;
//// ����һ����Ŵ����Ҵ��ϵ��µ���ȫ������
//createIntNode(b, 1, 3);
//b.root->left = BinTree<int>(9);
//// �����ӡ
//printBinTree_null(b);
void printBinTree_null(const BinTree<int>& b);

