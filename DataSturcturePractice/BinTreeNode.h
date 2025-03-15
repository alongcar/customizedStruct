#pragma once
#include"MyQueue.hpp"
struct BinTreeNode
{
	BinTreeNode* left;
	BinTreeNode* right;
	virtual void print() = 0;
	BinTreeNode() :left(nullptr), right(nullptr) {}
	BinTreeNode(const BinTreeNode& bt) :left(bt.left), right(bt.right) {}
	virtual ~BinTreeNode() {};
};

