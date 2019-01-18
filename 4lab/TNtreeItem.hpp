#ifndef TNTREEITEM_H
#define TNTREEITEM_H
#include <string>
#include <memory>
#include <cstdlib>
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

template<class T> class TNtreeItem {
public:
    TNtreeItem ();
    TNtreeItem (std::string id, const std::shared_ptr<T> fig);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TNtreeItem<A>>& obj);
    void SetChild(std::shared_ptr<TNtreeItem<T>> child);
    void SetSibling(std::shared_ptr<TNtreeItem<T>> sibling);
    std::shared_ptr<TNtreeItem<T> > GetChild();
    std::shared_ptr<TNtreeItem<T> > GetSibling();
    std::shared_ptr<T> GetFigure() const; //не изменяет нестат. элементы
    std::string GetID();

    virtual ~TNtreeItem();

    std::shared_ptr<T> fig;
    std::string id;
    std::shared_ptr<TNtreeItem<T>> child;
    std::shared_ptr<TNtreeItem<T>> sibling;
};

#endif