#include <iostream>
#include <string>
#include "figure.hpp"
#include "TNtree.hpp"
#include "retrangle.hpp"
#include "trapezium.hpp"
#include "rhombus.hpp"

int main(int argc, char** argv)
{
    TNtree<Figure> *tree = new TNtree<Figure>();
    std::string action;

    std::cout << "Type 'h' for help." << std::endl;
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;
       
        if (action == "q") {
            if (tree->GetRoot() != nullptr) {
                //delete &tree;
                std::cout << "The tree is deleted" << std::endl;
            }
            break;
        } else if (action == "i") {                             //insert
            size_t side_a, side_b, side_h;
            std::string parent_id, id;
            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            int type_of_Rhombus = 0;
            std::cout << "Enter type of Rhombus:" << std::endl <<
                          "1 - rectangle;" << std::endl <<
                          "2 - rhombus;" << std::endl <<
                          "3 - trapezium." << std::endl;
            std::cin >> type_of_Rhombus;
            if (type_of_Rhombus == 1){
                std::cout << "Enter side_a, side_b" << std::endl;
                if (!(std::cin >> side_a >> side_b)) {
                    std::cout << "Incorrect values." << std::endl;
                    continue;
                }
                std::shared_ptr<Retrangle> fig(new Retrangle(side_a, side_b));
                tree->Push(parent_id, id, fig);
            }
            if (type_of_Rhombus == 2) {
                std::cout << "Enter side_a, side_h" << std::endl;
                if (!(std::cin >> side_a >> side_h)) {
                    std::cout << "Incorrect values." << std::endl;
                    continue;
                }
                std::shared_ptr<Rhombus> fig(new Rhombus(side_a, side_h));
                tree->Push(parent_id, id, fig);
            }
            if (type_of_Rhombus == 3) {
                std::cout << "Enter side_a, side_b, side_h" << std::endl;
                if (!(std::cin >> side_a >> side_b >> side_h)) {
                    std::cout << "Incorrect values." << std::endl;
                    continue;
                }
                std::shared_ptr<Trapezium> fig(new Trapezium(side_a, side_b, side_h));
                tree->Push(parent_id, id, fig);
            }
        } else if (action == "d") {                             //delete tree
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

            tree->PrintItem(id);
        } else if (action == "help" || action == "h") {
            std::cout << "'h'       - display the help." << std::endl;
            std::cout << "'d'       - delete the tree." << std::endl;
            std::cout << "'p'       - output the tree." << std::endl;
            std::cout << "'i'       - insert a octagon into the tree." << std::endl;
            std::cout << "'pitem'   - print item by id." << std::endl;
            std::cout << "'q'       - exit the program." << std::endl;
        }
    }
    
    return 0;
}