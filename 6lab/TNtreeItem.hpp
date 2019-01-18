#ifndef TBINTREEITEM_H
#define TBINTREEITEM_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"
#include "TAllocator.hpp"

template <class T> class TBinTree;

template <class T> class TBinTreeItem {
public:
    TBinTreeItem();
    TBinTreeItem(const std::shared_ptr<T> &obj);

    std::shared_ptr<T> GetFigure();
    ~TBinTreeItem();
    std::shared_ptr<TBinTreeItem<T>> GetNext();

    void *operator new(size_t size);
    void operator delete(void *ptr);
    
    friend class TBinTree<T>;
private:
    std::shared_ptr<T> item;
    std::shared_ptr<TBinTreeItem<T>> left_son;
    std::shared_ptr<TBinTreeItem<T>> right_son;
    std::shared_ptr<TBinTreeItem<T>> par;

    static TAllocationBlock btree_allocator;
};

#endif