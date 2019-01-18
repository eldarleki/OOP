#include <iostream>
#include "TNtreeItem.hpp"
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

TNtreeItem::TNtreeItem() {
    (*this).child = nullptr;
    (*this).sibling = nullptr;
    (*this).id = "";
}

TNtreeItem::TNtreeItem(std::string id, std::shared_ptr<Figure> fig) {
    (*this).fig = fig;
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

std::shared_ptr<Figure> TNtreeItem::GetFigure() const {
    return (*this).fig;
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
    os << obj.fig << std::endl;
    return os;
}

TNtreeItem::~TNtreeItem() {
    delete child;
    delete sibling;
}