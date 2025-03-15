#pragma once
#include<initializer_list>
#include<deque>
#include<iostream>
#include<string>
#include"BinTreeNode.h"
extern class HFTreeNode;
typedef HFTreeNode* HaffmanTree;
//HaffmanTree hftree = createHaffmanTree();
//printBinTree_null(hftree);
//delete(hftree);
struct HFTreeNode
{
	int weight;
	HaffmanTree left;
	HaffmanTree right;
	HFTreeNode() : weight(0),left(nullptr), right(nullptr) {} 
	HFTreeNode(int w) : weight(w), left(nullptr), right(nullptr){}
	HFTreeNode(const HFTreeNode& hf) :weight(hf.weight), left(hf.left), right(hf.right) {}
	void print();
	/*** 析构一个哈夫曼树结点则该哈夫曼结点的所有子树全部析构 ***/
	~HFTreeNode();
	void operator delete(void*) noexcept;
};

/*** 
* 输入一个哈夫曼树结点组成的队列，
* 用冒泡的方式将权值最小的哈夫曼结点放到队尾，
* 并返回（注意，这是一个会改变队列值的操作） 
***/
HaffmanTree sortMinNode(std::deque<HaffmanTree> &hfdq);


/*** 根据结点权值初始化一颗哈夫曼树并返回其根结点 ***/
HaffmanTree createHaffmanTree();

void printBinTree_null(HaffmanTree tree);

