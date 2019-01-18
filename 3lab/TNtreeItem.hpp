#ifndef TNTREEITEM_H
#define TNTREEITEM_H
#include <string>
#include <memory>
#include <cstdlib>
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"

class TNtreeItem {
public:
    TNtreeItem ();
    TNtreeItem (std::string id, std::shared_ptr<Figure> fig);
    friend std::ostream& operator<<(std::ostream& os, const TNtreeItem& obj);
    void SetChild(TNtreeItem* child);
    void SetSibling(TNtreeItem* sibling);
    TNtreeItem* GetChild();
    TNtreeItem* GetSibling();
    std::shared_ptr<Figure> GetFigure() const; //не изменяет нестат. элементы
    std::string GetID();

    virtual ~TNtreeItem();

private:
    std::shared_ptr<Figure> fig;
    std::string id;
    TNtreeItem* child;
    TNtreeItem* sibling;
};

#endif