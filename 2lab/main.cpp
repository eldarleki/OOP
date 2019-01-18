#include <iostream>
#include <string>

#include "TNtree.hpp"
#include "retrangle.hpp"

int main(int argc, char** argv)
{
    TNtree *tree = new TNtree();
    std::string action;

    std::cout << "Type 'h' for help." << std::endl;
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;
       
        if (action == "q") {
            if (tree->GetRoot() != nullptr) {
                delete tree;
                std::cout << "The tree is deleted" << std::endl;
            }
            break;
        } else if (action == "i") {                             //insert
            int side_a, side_b;
            std::string parent_id, id;
            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            std::cout << "Enter Rectangle's sides:\n";
            if (!(std::cin >> side_a >> side_b)) {
                std::cout << "Incorrect values." << std::endl;
                continue;
            }
            Retrangle* fig = new Retrangle(side_a, side_b);
            tree->Push(tree, parent_id, id, *fig);
            delete fig;
        } else if (action == "r") {                             //remove
            std::string id;
            if (!(std::cin >> id)) {
                std::cout << "Incorrect value." << std::endl;
                continue;
            }
            tree->Remove(id);
        } else if (action == "d") {                             //delete tree
            delete tree;
            tree = new TNtree();
            std::cout << "The tree was deleted." << std::endl;
        } else if (action == "p") {                             //print
            if (!tree->IsEmpty()) {
                tree->PrintTree(tree->GetRoot(), 0);
            }
            else {
                std::cout << "The tree is empty." << std::endl;
            }
        } else if (action == "pitem") { //print item
            std::string id;
            std::cout << "Enter item id: ";
            std::cin >> id;

            tree->PrintItem(tree, id);
        } else if (action == "help" || action == "h") {
            std::cout << "'h'       - display the help." << std::endl;
            std::cout << "'r'       - remove the retrangle with area s." << std::endl;
            std::cout << "'d'       - delete the tree." << std::endl;
            std::cout << "'p'       - output the tree." << std::endl;
            std::cout << "'i'       - insert a retrangle into the tree." << std::endl;
            std::cout << "'pitem'   - print item by id." << std::endl;
            std::cout << "'q'       - exit the program." << std::endl;
        }
    }
    
    return 0;
}