#include "TNtreeItem.hpp"
#include "figure.hpp"

template <class T>
TBinTreeItem<T>::TBinTreeItem() {
    left_son = nullptr;
    right_son = nullptr;
    par = nullptr;
}

template <class T>
TBinTreeItem<T>::TBinTreeItem(const std::shared_ptr<T> &obj) {
    this->item = obj;
    left_son = nullptr;
    right_son = nullptr;
    par = nullptr;
}

template <class T> TAllocationBlock
TBinTreeItem<T>::btree_allocator(sizeof(TBinTreeItem<T>), 100);

template <class T>
TBinTreeItem<T>::~TBinTreeItem() {}

template <class T>
std::shared_ptr<T> TBinTreeItem<T>::GetFigure() {
    return this->item;
}

template <class T>
std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::GetNext() {   //for iterator
    if (this->left_son) {
        return this->left_son;
    } else if (this->right_son) {
        return this->right_son;
    } else if (!this->par) {
        return nullptr;
    } else {
        std::shared_ptr<TBinTreeItem<T>> tmp = this->par;
        while (!tmp->right_son) {
            if (!tmp->par) {
                return nullptr;
            }
            tmp = tmp->par;
        }
        return tmp->right_son;
    }
}

template <class T>
void *TBinTreeItem<T>::operator new(size_t size) {
    return btree_allocator.allocate();
}

template <class T>
void TBinTreeItem<T>::operator delete(void *ptr) {
    btree_allocator.deallocate(ptr);
}

template class TBinTreeItem<Figure>;