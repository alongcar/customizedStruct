#pragma once
#include<vector>
#include<iostream>
#include<exception>
#include<string>

template<typename T = int, typename F = int>
struct NkeyHashNode {
	typedef typename T AttributeType;
	T name;
	F attr;
	NkeyHashNode operator=(const NkeyHashNode& hn) {
		this->attr = hn.attr;
		this->name = hn.name;
		return *this;
	}
};

template<typename T, typename F>
using HashTable = std::vector<NkeyHashNode<T, F>> ;


void pracHashTable();

HashTable<int, int> createNkeyHashTable(size_t tableSize);


void listInitHashTable(HashTable<int, int>& ht, std::initializer_list<NkeyHashNode<int, int>> lst);


bool isIn(HashTable<int, int> ht, int name);

NkeyHashNode<int, int>::AttributeType find(HashTable<int, int>& ht, int name);

void insertht(HashTable<int, int>& ht, int name, int attr);

void deleteht(HashTable<int, int>& ht, int name);