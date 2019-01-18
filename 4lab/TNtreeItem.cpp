#include <iostream>
#include "TNtreeItem.hpp"
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

template <class T> TNtreeItem<T>::TNtreeItem() {
    (*this).child = nullptr;
    (*this).sibling = nullptr;
    (*this).id = "";
}

template <class T> TNtreeItem<T>::TNtreeItem(std::string id, std::shared_ptr<T> fig) {
    (*this).fig = fig;
    (*this).child = nullptr;
    (*this).sibling = nullptr;
    (*this).id = id;
}

template <class T>
void TNtreeItem<T>::SetChild(std::shared_ptr<TNtreeItem<T>> child) {
    (*this).child = child;
}

template <class T>
void TNtreeItem<T>::SetSibling(std::shared_ptr<TNtreeItem<T>> sibling) {
    (*this).sibling = sibling;
}

template <class T>
std::shared_ptr<T> TNtreeItem<T>::GetFigure() const {
    return (*this).fig;
}

template <class T>
std::shared_ptr<TNtreeItem<T>> TNtreeItem<T>::GetChild() {
    return (*this).child;
}

template <class T>
std::shared_ptr<TNtreeItem<T>> TNtreeItem<T>::GetSibling() {
    return (*this).sibling;
}

template <class T>
std::string TNtreeItem<T>::GetID() {
    return (*this).id;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TNtreeItem<A>>& obj) {
    os << obj.get()->fig << std::endl;
    return os;
}

template <class T>
TNtreeItem<T>::~TNtreeItem() {
    delete child.get();
    delete sibling.get();
}

template class TNtreeItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TNtreeItem<Figure>>& obj);