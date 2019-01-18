#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>
#include <cstdlib>
#include "TIterator.h"

using namespace std;

template<typename T>
struct node {
	shared_ptr<T> obj;
	node<T> *leftson, *rightson, *par;
	node(T*);
};

template<typename T>
node<T>::node(T *obj_ptr) {
	obj = shared_ptr<T>(obj_ptr);
	leftson = rightson = par = nullptr;
}

template<typename T>
class BinTree {
	friend class Iterator<T>;
	friend ostream& operator<<(ostream &os, BinTree<T> &bintree) {
		bintree.print(os, bintree.m_root, 0);
		return os;
	}
	typedef node<T>* node_ptr;
public:
	BinTree();
	~BinTree();
	void Insert(T *obj_ptr);
	void Remove(T&);
	void Print();
	Iterator<T> Find(T&);
	void Clear();
	Iterator<T> begin();
	Iterator<T> end();
private:
	node_ptr m_root;
	void insert(node_ptr, node_ptr);
	void remove(node_ptr, T&);
	void print(ostream&, node_ptr, int);
	node_ptr find(node_ptr, T&);
	static node_ptr min(node_ptr);
	static node_ptr max(node_ptr);
	static node_ptr next(node_ptr);
	static node<T>* prev(node_ptr tree, BinTree<T>* bin_tree_ptr);
	void clear(node_ptr);
};


template<typename T>
BinTree<T>::BinTree() : m_root(nullptr) {}

template<typename T>
BinTree<T>::~BinTree() {
	clear(m_root);
}

template<typename T>
void  BinTree<T>::Insert(T *obj_ptr) {
	insert(m_root, new node<T>(obj_ptr));
}

template<typename T>
void BinTree<T>::Print() {
	print(cout, m_root, 0);
}

template<typename T>
Iterator<T> BinTree<T>::Find(T &obj){
	return Iterator<T>(find(m_root, obj), this);
}

template<typename T>
void BinTree<T>::Remove(T &obj) {
	remove(m_root, obj);
}

template<typename T>
void BinTree<T>::Clear() {
	clear(m_root);
	m_root = nullptr;
}

template<typename T>
Iterator<T> BinTree<T>::begin() {
	return Iterator<T>(min(m_root), this);
}

template<typename T>
Iterator<T> BinTree<T>::end() {
	return Iterator<T>(nullptr, this);
}

template<typename T>
void BinTree<T>::insert(node_ptr tree, node_ptr ins) {
	if (m_root == nullptr) {
		m_root = ins;
		m_root->par = nullptr;
		return;
	}
	node_ptr par = nullptr;
	while (tree != nullptr) {
		par = tree;
		if (*(ins->obj) < *(tree->obj))
			tree = tree->leftson;
		else
			tree = tree->rightson;
	}
	if (*(ins->obj) < *(par->obj)) {
		par->leftson = ins;
		ins->par = par;
	}
	else {
		par->rightson = ins;
		ins->par = par;
	}
}

template<typename T>
void BinTree<T>::remove(node_ptr tree, T &obj) {
	bool is_leftson_side = true;
	node_ptr par = nullptr;

	while (!(*(tree->obj) == obj)) {
		par = tree;
		if (obj < *(tree->obj)) {
			is_leftson_side = true;
			tree = tree->leftson;
		}
		else if (obj > *(tree->obj)) {
			is_leftson_side = false;
			tree = tree->rightson;
		}
		if (tree == nullptr)
			return;
	}

	if (par == nullptr) {
		node_ptr minimal = min(m_root->rightson);
		if (m_root->rightson == minimal) {
			minimal->leftson = m_root->leftson;
			if (minimal->leftson != nullptr)
				minimal->leftson->par = m_root;
		}
		else {
			minimal->par->leftson = minimal->rightson;
			if (minimal->rightson != nullptr)
				minimal->rightson->par = minimal->par;
			minimal->leftson = m_root->leftson;
			if (minimal->leftson != nullptr)
				minimal->leftson->par = minimal;
			minimal->rightson = m_root->rightson;
			if (minimal->rightson != nullptr)
				minimal->rightson->par = minimal;
		}
		minimal->par = nullptr;
		delete m_root;
		m_root = minimal;
		return;

	}
	if (tree->leftson == nullptr && tree->rightson == nullptr) {
		if (is_leftson_side)
			par->leftson = nullptr;
		else
			par->rightson = nullptr;
	}
	else if (tree->leftson == nullptr) {
		if (is_leftson_side)
			par->leftson = tree->rightson;
		else
			par->rightson = tree->rightson;
	}
	else if (tree->rightson == nullptr) {
		if (is_leftson_side)
			par->leftson = tree->leftson;
		else
			par->rightson = tree->leftson;
	}
	else {
		node_ptr minimal = min(tree->rightson);
		if (tree->rightson == minimal) {
			minimal->leftson = tree->leftson;
			minimal->par = par;
			if (is_leftson_side) {
				par->leftson = minimal;
			}
			else {
				par->rightson = minimal;
			}
		}
		else {
			minimal->par->leftson = minimal->rightson;
			if (minimal->rightson != nullptr)
				minimal->rightson->par = minimal->par;
			minimal->par = par;
			minimal->leftson = tree->leftson;
			if (minimal->leftson != nullptr)
				minimal->leftson->par = minimal;
			minimal->rightson = tree->rightson;
			if (minimal->rightson != nullptr)
				minimal->rightson->par = minimal;
			if (is_leftson_side) {
				par->leftson = minimal;
			}
			else {
				par->rightson = minimal;
			}
		}
	}
	delete tree;
	return;
}

template<typename T>
void BinTree<T>::print(ostream &os, node_ptr tree, int tab) {
	const int tab_increment = 2;
	if (tree == nullptr)
		return;
	print(os, tree->leftson, tab + tab_increment);
	for (int i = 0; i < tab; ++i)
		os << ' ';
	os << *(tree->obj) << endl;
	print(os, tree->rightson, tab + tab_increment);
}

template<typename T>
node<T>* BinTree<T>::find(node_ptr tree, T &obj) {
	while (tree != nullptr && !(*(tree->obj) == obj)) {
		if (obj < *(tree->obj))
			tree = tree->leftson;
		else
			tree = tree->rightson;
	}
	return tree;
}

template<typename T>
node<T>* BinTree<T>::min(node_ptr tree) {
	if (tree == nullptr)
		return nullptr;
	while (tree->leftson != nullptr)
		tree = tree->leftson;
	return tree;
}

template<typename T>
node<T>* BinTree<T>::max(node_ptr tree) {
	if (tree == nullptr)
		return nullptr;
	while (tree->rightson != nullptr)
		tree = tree->rightson;
	return tree;
}

template<typename T>
node<T>* BinTree<T>::next(node_ptr tree) {
	if (tree->rightson != nullptr)
		return min(tree->rightson);
	while (tree->par != nullptr && tree->par->leftson != tree) {
		tree = tree->par;
	}
	return tree->par;
}

template<typename T>
node<T>* BinTree<T>::prev(node_ptr tree, BinTree<T> *bin_tree_ptr) {
	if (tree == nullptr)
		return max(bin_tree_ptr->m_root);
	if (tree->leftson != nullptr)
		return max(tree->leftson);
	while (tree->par != nullptr && tree->par->rightson != tree) {
		tree = tree->par;
	}
	return tree->par;
}

template<typename T>
void BinTree<T>::clear(node_ptr tree) {
	if (tree == nullptr)
		return;
	clear(tree->leftson);
	clear(tree->rightson);
	delete tree;
}

#endif