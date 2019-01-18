#include <iostream>
#include "TNtreeItem.hpp"
#include "retrangle.hpp"

TNtreeItem::TNtreeItem() {
    (*this).child = nullptr;
    (*this).sibling = nullptr;
    (*this).id = "";
}

TNtreeItem::TNtreeItem(std::string id, const Retrangle& retrangle) {
    (*this).retrangle = retrangle;
    (*this).child = nullptr;
    (*this).sibling = nullptr;
    (*this).id = id;
}

void TNtreeItem::SetChild(TNtreeItem* child) {
    (*this).child = child;
}

void TNtreeItem::SetSibling(TNtreeItem* sibling) {
    (*this).sibling = sibling;
}

Retrangle TNtreeItem::GetRetrangle() const {
    return (*this).retrangle;
}

TNtreeItem* TNtreeItem::GetChild() {
    return (*this).child;
}

TNtreeItem* TNtreeItem::GetSibling() {
    return (*this).sibling;
}

std::string TNtreeItem::GetID() {
    return (*this).id;
}

std::ostream& operator<<(std::ostream& os, const TNtreeItem& obj) {
    os << obj.retrangle << std::endl;
    return os;
}

TNtreeItem::~TNtreeItem() {
    delete child;
    delete sibling;
}