#include <string>

#include "TNtree.hpp"
#include "TNtreeItem.hpp"
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

template<class T>
TNtree<T>::TNtree() {
    root = nullptr;
}

template<class T>
std::shared_ptr<TNtreeItem<T>> TNtree<T>::FindNode(std::shared_ptr<TNtreeItem<T>> tree_item, std::string find_id) {
    if (tree_item->GetID() == find_id) {
        return tree_item;
    }
    if (tree_item->GetChild()) {
        std::shared_ptr<TNtreeItem<T>> tr = FindNode(tree_item->GetChild(), find_id);
        if (tr != nullptr) {
            return tr;
        }
    }
    if (tree_item->GetSibling()) {
        std::shared_ptr<TNtreeItem<T>> tr = FindNode(tree_item->GetSibling(), find_id);
        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}

template<class T> 
void TNtree<T>::Push(std::string parent_id, std::string cur_id, std::shared_ptr<T> fig) {
    if (!root) {
        root = std::shared_ptr<TNtreeItem<T>>(new TNtreeItem<T>(cur_id, fig));
        return;
    }
    else {
        std::shared_ptr<TNtreeItem<T>> parent_node = FindNode(root, parent_id);
        if (parent_node) {
            std::shared_ptr<TNtreeItem<T>> p(new TNtreeItem<T>(cur_id, fig));
            if(!parent_node->GetChild()) {
                parent_node->SetChild(p);
            }
            else {
                std::shared_ptr<TNtreeItem<T>> sibling = parent_node->GetChild();
                while (sibling->GetSibling()) {
                    sibling = sibling->GetSibling();
                }
                sibling->SetSibling(p);
            }
        }
        else {
            std::cout << "No such parent" << std::endl;
        }
    }
}

template<class T>
bool TNtree<T>::IsEmpty() {
    return root == nullptr;    
}

template<class T>
void TNtree<T>::NodeRemove(std::shared_ptr<TNtreeItem<T>> tree_item, std::string id) {
    if (tree_item->GetChild()) {
        if (tree_item->GetChild()->GetID() == id) {
            std::shared_ptr<TNtreeItem<T>> tr = tree_item->GetChild();
            tree_item->SetChild(tree_item->GetChild()->GetSibling());
            SetNull(tr->GetSibling());
            delete tr.get();
            return;
        }
        else {
            NodeRemove(tree_item->GetChild(), id);
        }
    }
    if (tree_item->GetSibling()) {
        if(tree_item->GetSibling()->GetID() == id) {
            std::shared_ptr<TNtreeItem<T>> tr = tree_item->GetSibling();
            tree_item->SetSibling(tree_item->GetSibling()->GetSibling());
            SetNull(tr->GetSibling());
            delete tr.get();
            return;
        }
        else {
            NodeRemove(tree_item->GetSibling(), id); 
        }
    }
}

template<class T>
void TNtree<T>::SetNull(std::shared_ptr<TNtreeItem<T>> tr) {
    tr = nullptr;
}

template<class T>
std::shared_ptr<TNtreeItem<T>> TNtree<T>::GetRoot() {
    return this->root;
}

template<class T>
void TNtree<T>::Remove(std::string id) {
    if (root->GetID() == id && !root->GetChild()) {
        delete root.get(); 
    } else if(root->GetID() == id && root->GetChild()) {
        std::cout<<"Root has child !!!" << std::endl;
    }
    else {
        NodeRemove(root, id);
    }
}

template<class T>
void TNtree<T>::PrintTree (std::shared_ptr<TNtreeItem<T>> tree_item, int num) {
    if (tree_item) {
        for (int i = 0; i < num; ++i) {
            printf("\t");
        }
        std::cout << tree_item->GetID() << " ";
        tree_item->GetFigure()->Print();
        std::cout << std::endl;
        if (tree_item->GetChild()) {
            PrintTree(tree_item->GetChild(), num + 1);
        }
        if (tree_item->GetSibling()) {
            PrintTree(tree_item->GetSibling(), num);
        }
    }
}

template<class T>
void TNtree<T>::PrintItem(std::string id) {
    std::shared_ptr<TNtreeItem<T>> tmp = FindNode(root, id);
    if(tmp) {
        std::cout << tmp->GetID() << " ";
        tmp->GetFigure()->Print();
    }
}

template<class T>
TNtree<T>::~TNtree() {
    delete root.get();
}

template class TNtree<Figure>;