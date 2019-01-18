#ifndef TNTREE_H
#define TNTREE_H
#include <iostream>
#include <string>
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"
#include "TNtreeItem.hpp"

class TNtree {
public:
    TNtree();
    TNtree(const TNtree& orig);

    void Push(std::string parent_id, std::string cur_id, std::shared_ptr<Figure> fig);
    void Remove(std::string cur_id);
    void NodeRemove(TNtreeItem* tree, std::string id);
    void PrintTree(TNtreeItem* tree, int num);
    void PrintItem(std::string id);
    void SetNull(TNtreeItem* tree);
    
    TNtreeItem* GetRoot();
    bool IsEmpty();
    virtual ~TNtree();
    
    TNtreeItem* root;
    TNtreeItem* FindNode(TNtreeItem* node, std::string id);
};

#endif