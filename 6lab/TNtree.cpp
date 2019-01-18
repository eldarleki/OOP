#include "TNtree.hpp"
#include "figure.hpp"

template <class T>
TBinTree<T>::TBinTree() {
    root = nullptr;
}

template <class T>
std::shared_ptr<TBinTreeItem<T>> TBinTree<T>::Find(std::shared_ptr<T> &obj) {
    std::shared_ptr<TBinTreeItem<T>> item = root;
    while (item != nullptr) {
        if (item->item->Square() == obj->Square()) {
            return item;
        } else if (item->item->Square() > obj->Square()) {
            item = item->left_son;
        } else if (item->item->Square() < obj->Square()) {
            item = item->right_son;
        }
    }
    return nullptr;
}

template <class T>
std::shared_ptr<TBinTreeItem<T>> TBinTree<T>::minValueNode(std::shared_ptr<TBinTreeItem<T>> root) {
     std::shared_ptr<TBinTreeItem<T>> min = root;
 
    while (min->left_son != nullptr) {
        min = min->left_son;
    }
 
    return min;
}

template <class T>
std::shared_ptr<TBinTreeItem<T>> TBinTree<T>::RemoveNode(std::shared_ptr<TBinTreeItem<T>> root, double square) {
    if (root == nullptr) {
        return root;
    }
 
    if (square < root->item->Square()) {
        root->left_son = RemoveNode(root->left_son, square);
    } else if (square > root->item->Square()) {
        root->right_son = RemoveNode(root->right_son, square);
    } else {
        if (root->left_son == nullptr) {
            std::shared_ptr<TBinTreeItem<T>> temp = root->right_son;
            root->left_son = nullptr;
            root->right_son = nullptr;
            root->par = nullptr;
            return temp;
        } else if (root->right_son == nullptr) {
            std::shared_ptr<TBinTreeItem<T>> temp = root->left_son;
            root->left_son = nullptr;
            root->right_son = nullptr;
            root->par = nullptr;
            return temp;
        }
    
        std::shared_ptr<TBinTreeItem<T>> temp = minValueNode(root->right_son);
        root->item = temp->item;
        root->right_son = RemoveNode(root->right_son, temp->item->Square());
    }
    return root;
}

template <class T>
void TBinTree<T>::Remove(double square) {
    root = TBinTree<T>::RemoveNode(root, square);

}

template <class T>
void TBinTree<T>::Push(std::shared_ptr<T> &obj) {
    if (root == nullptr) {
        root = std::make_shared<TBinTreeItem<T>>(obj);
        return;
    }

    std::shared_ptr<TBinTreeItem<T>> item = root;
    while (true) {
        if (obj->Square() <= item->item->Square()) {
            if (item->left_son == nullptr) {
                item->left_son = std::make_shared<TBinTreeItem<T>>(obj);
                break;
            } else {
                item = item->left_son;
            }
        } else {
            if (item->right_son == nullptr) {
                item->right_son = std::make_shared<TBinTreeItem<T>>(obj);
                break;
            } else {
                item = item->right_son;
            }
        }
    }
}

template <class T>
void TBinTree<T>::PrintTree(std::shared_ptr<TBinTreeItem<T>> item, size_t a, std::ostream& os) {
    for (size_t i = 0; i < a; i++) {
        os << "  ";
    }
    item->GetFigure()->Print();
    if (item->left_son != nullptr) {
        TBinTree<T>::PrintTree(item->left_son, a + 1, os);
    } else if (item->right_son != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
    if (item->right_son != nullptr) {
        TBinTree<T>::PrintTree(item->right_son, a + 1, os);
    } else if (item->left_son != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
}


template <class T>
void TBinTree<T>::PrintBTS() {
    if (root != nullptr) {
        TBinTree<T>::PrintTree(root, 0, std::cout);
    }
}

template <class T>
void TBinTree<T>::PrintBTS(std::ostream& os) {
    if (root != nullptr) {
        TBinTree<T>::PrintTree(root, 0, os);
    }
}

template <class T>
bool TBinTree<T>::empty() {
    return root == nullptr;
}

template <class T>
TBinTree<T>::~TBinTree() {}

template <class T>
std::ostream& operator<<(std::ostream& os, TBinTree<T> &tree) {
    tree.PrintBTS(os);
    return os;
}

template <class T>
TIterator<TBinTreeItem<T>,T> TBinTree<T>::begin() {
    return TIterator<TBinTreeItem<T>,T>(root);
}

template <class T>
TIterator<TBinTreeItem<T>,T> TBinTree<T>::end() {
    std::shared_ptr<TBinTreeItem<T>> tmp = root;
    while (tmp->right_son) {
        tmp = tmp->right_son;
    }
    return TIterator<TBinTreeItem<T>,T>(tmp);
}

template class TBinTree<Figure>;
template std::ostream& operator<<(std::ostream& os, TBinTree<Figure> &tree);