#include <string>

#include "TNtree.hpp"
#include "TNtreeItem.hpp"
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

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
void TNtree::Push(std::string parent_id, std::string cur_id, std::shared_ptr<Figure> fig) {
    if (!root) {
        root = new TNtreeItem(cur_id, fig);
        return;
    }
    else {
        TNtreeItem *parent_node = FindNode(root, parent_id);
        if (parent_node) {
            if(!parent_node->GetChild()) {
                parent_node->SetChild(new TNtreeItem(cur_id, fig));
            }
            else {
                TNtreeItem* sibling = parent_node->GetChild();
                while (sibling->GetSibling()) {
                    sibling = sibling->GetSibling();
                }
                sibling->SetSibling(new TNtreeItem(cur_id, fig));
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
    if (root->GetID() == id && !root->GetChild()) {
        delete root; 
    } else if(root->GetID() == id && root->GetChild()) {
        std::cout<<"Root has child !!!" << std::endl;
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

void TNtree::PrintItem(std::string id) {
    TNtreeItem* tmp = FindNode(root, id);
    if(tmp) {
        std::cout << tmp->GetID() << " ";
        tmp->GetFigure()->Print();
    }
}

TNtree::~TNtree() {
    delete root;
}