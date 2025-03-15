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
	/*** ����һ���������������ù�����������������ȫ������ ***/
	~HFTreeNode();
	void operator delete(void*) noexcept;
};

/*** 
* ����һ���������������ɵĶ��У�
* ��ð�ݵķ�ʽ��Ȩֵ��С�Ĺ��������ŵ���β��
* �����أ�ע�⣬����һ����ı����ֵ�Ĳ����� 
***/
HaffmanTree sortMinNode(std::deque<HaffmanTree> &hfdq);


/*** ���ݽ��Ȩֵ��ʼ��һ�Ź������������������� ***/
HaffmanTree createHaffmanTree();

void printBinTree_null(HaffmanTree tree);

