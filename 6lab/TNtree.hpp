#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include <iostream>
#include "TNtreeItem.hpp"
#include "TIterator.hpp"

template <class T> 
class TBinTree {
public:
    TBinTree();
    
    void Push(std::shared_ptr<T> &obj);
    std::shared_ptr<TBinTreeItem<T>> Find(std::shared_ptr<T> &obj);
    void PrintBTS();
    void PrintBTS(std::ostream& os);
    void Remove(double square);
    bool empty();
    template <class A> friend std::ostream& operator<<(std::ostream& os, TBinTree<A> &tree);

    TIterator<TBinTreeItem<T>,T> begin();
    TIterator<TBinTreeItem<T>,T> end();

    virtual ~TBinTree();
private:
    std::shared_ptr<TBinTreeItem<T>> root;
    std::shared_ptr<TBinTreeItem<T>> minValueNode(std::shared_ptr<TBinTreeItem<T>> root);
    std::shared_ptr<TBinTreeItem<T>> RemoveNode(std::shared_ptr<TBinTreeItem<T>> root, double square);
    void PrintTree(std::shared_ptr<TBinTreeItem<T>> item, size_t a, std::ostream& os);
};

#endif