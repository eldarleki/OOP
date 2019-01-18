#include <string>

#include "TNtree.hpp"
#include "TNtreeItem.hpp"

TNtree::TNtree() {
    root = nullptr;
}

TNtree::TNtree(const TNtree& orig) {
    root = orig.root;
}

TNtreeItem* TNtree::FindNode(TNtreeItem* tree_item, std::string find_id) {
    if (tree_item->GetID() == find_id) {
        return tree_item;
    }
    if (tree_item->GetChild()) {
        TNtreeItem* tr = FindNode(tree_item->GetChild(), find_id);
        if (tr != nullptr) {
            return tr;
        }
    }
    if (tree_item->GetSibling()) {
        TNtreeItem* tr = FindNode(tree_item->GetSibling(), find_id);
        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}

// Дописать, если что, добавление без проверки на существование родителя
//(введением текущей высоты) 
void TNtree::Push(TNtree* tree, std::string parent_id, std::string cur_id, Retrangle &retrangle) {
    if (!tree->root) {
        tree->root = new TNtreeItem(cur_id,retrangle);
        return;
    }
    else {
        TNtreeItem *parent_node = FindNode(tree->root, parent_id);
        if (parent_node) {
            if(!parent_node->GetChild()) {
                parent_node->SetChild(new TNtreeItem(cur_id, retrangle));
            }
            else {
                TNtreeItem* sibling = parent_node->GetChild();
                while (sibling->GetSibling()) {
                    sibling = sibling->GetSibling();
                }
                sibling->SetSibling(new TNtreeItem(cur_id, retrangle));
            }
        }
        else {
            std::cout << "No such parent" << std::endl;
        }
    }
}

bool TNtree::IsEmpty() {
    return root == nullptr;    
}

void TNtree::NodeRemove(TNtreeItem* tree_item, std::string id) {
    if (tree_item->GetChild()) {
        if (tree_item->GetChild()->GetID() == id) {
            TNtreeItem* tr = tree_item->GetChild();
            tree_item->SetChild(tree_item->GetChild()->GetSibling());
            SetNull(tr->GetSibling());
            delete tr;
            return;
        }
        else {
            NodeRemove(tree_item->GetChild(), id);
        }
    }
    if (tree_item->GetSibling()) {
        if(tree_item->GetSibling()->GetID() == id) {
            TNtreeItem* tr = tree_item->GetSibling();
            tree_item->SetSibling(tree_item->GetSibling()->GetSibling());
            SetNull(tr->GetSibling());
            delete tr;
            return;
        }
        else {
            NodeRemove(tree_item->GetSibling(), id); 
        }
    }
}

void TNtree::SetNull(TNtreeItem* tr) {
    tr = nullptr;
}

TNtreeItem* TNtree::GetRoot() {
    return this->root;
}

void TNtree::Remove(std::string id) {
    if (root->GetID() == id) {
        root = root->GetChild();
    }
    else {
        NodeRemove(root, id);
    }
}

void TNtree::PrintTree (TNtreeItem* tree_item, int num) {
    if (tree_item) {
        for (int i = 0; i < num; ++i) {
            printf("\t");
        }
        std::cout << tree_item->GetID() << " ";
        tree_item->GetRetrangle().Print();
        std::cout << std::endl;
        if (tree_item->GetChild()) {
            PrintTree(tree_item->GetChild(), num + 1);
        }
        if (tree_item->GetSibling()) {
            PrintTree(tree_item->GetSibling(), num);
        }
    }
}

void TNtree::PrintItem(TNtree* tree, std::string id) {
    TNtreeItem* tmp = FindNode(tree->root, id);
    if(tmp) {
        std::cout << tmp->GetID() << " ";
        tmp->GetRetrangle().Print();
    }
    delete tmp;
}

TNtree::~TNtree() {
    delete root;
}