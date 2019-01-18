#ifndef TNTREEITEM_H
#define TNTREEITEM_H
#include <string>
#include <cstdlib>
#include "retrangle.hpp"

class TNtreeItem {
public:
    TNtreeItem ();
    TNtreeItem (std::string id, const Retrangle& retrangle);
    friend std::ostream& operator<<(std::ostream& os, const TNtreeItem& obj);
    void SetChild(TNtreeItem* child);
    void SetSibling(TNtreeItem* sibling);
    TNtreeItem* GetChild();
    TNtreeItem* GetSibling();
    Retrangle GetRetrangle() const; //не изменяет нестат. элементы
    std::string GetID();

    virtual ~TNtreeItem();

private:
    Retrangle retrangle;
    std::string id;
    TNtreeItem* child;
    TNtreeItem* sibling;
};

#endif