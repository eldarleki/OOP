#ifndef TNTREE_H
#define TNTREE_H
#include <iostream>
#include <string>
#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"
#include "TNtreeItem.hpp"

template<class T> 
class TNtree {
public:
    TNtree<T>();
    TNtree<T>(const TNtree< TNtreeItem<T> >& orig);

    void Push(std::string parent_id, std::string cur_id, std::shared_ptr<T> fig);
    void Remove(std::string cur_id);
    void NodeRemove(std::shared_ptr< TNtreeItem<T> > tree, std::string id);
    void PrintTree(std::shared_ptr<TNtreeItem<T> > tree, int num);
    void PrintItem(std::string id);
    void SetNull(std::shared_ptr<TNtreeItem<T> > tree);

    std::shared_ptr<TNtreeItem<T> > GetRoot();
    bool IsEmpty();
    virtual ~TNtree();
    
    std::shared_ptr<TNtreeItem<T>> root;
    std::shared_ptr<TNtreeItem<T> > FindNode(std::shared_ptr<TNtreeItem<T>> node, std::string id);
};

#endif