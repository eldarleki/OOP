#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "figure.hpp"
#include "retrangle.hpp"
#include "rhombus.hpp"
#include "trapezium.hpp"
#include "TNtree.hpp"

void menu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1) Insert rectangle" << std::endl;
    std::cout << "2) Insert rhombus" << std::endl;
    std::cout << "3) Insert trapezium" << std::endl;
    std::cout << "4) Delete the figure from tree by square" << std::endl;
    std::cout << "5) Print tree"  << std::endl;
    std::cout << "6) Print tree items by iterators"  << std::endl;
    std::cout << "0) Exit the program" << std::endl;
}

int main(void) {
    int act = 0;
    TBinTree<Figure> tree;
    std::shared_ptr<Figure> ptr;
    std::cout << "To display help enter 7" << std::endl;
    do {
        std::cin >> act;
        int side_a, side_b, side_h;
        switch(act) {
            case 1:
                std::cout << "Enter sides of rectangle" << std::endl;
                std::cin >> side_a >> side_b;
                ptr = std::make_shared<Retrangle>(side_a, side_b);
                tree.Push(ptr);
                break;
            case 2:
                std::cout << "Enter sides of rhombus" << std::endl;
                std::cin >> side_a >> side_h;
                ptr = std::make_shared<Rhombus>(side_a, side_h);
                tree.Push(ptr);
                break;
            case 3:
            std::cout << "Enter sides of trapezium" << std::endl;
                std::cin >> side_a >> side_b >> side_h;
                ptr = std::make_shared<Trapezium>(side_a, side_b, side_h);
                tree.Push(ptr);
                break;
            case 4:
                
                if (tree.empty()) {
                    std::cout << "Tree is empty" << std::endl;
                } else {
                    int32_t numb;
                    std::cin >> numb;
                    tree.Remove(numb);
                }
                break;
            case 5:
                if (tree.empty()) {
                    std::cout << "Tree is empty" << std::endl;
                } else {
                    std::cout << tree << std::endl;
                }
                break;
            case 6:
                if (tree.empty()) {
                    std::cout << "Tree is empty" << std::endl;
                } else {
                    for(auto i : tree) {
                        i->Print();
                    }
                    tree.end()->Print();
                }
                break;
            case 7:
                menu();
                break;
            case 0:
                break;
            default:
                std::cout << "No such comand" << std::endl;;
                break;
        }
    } while (act);
    return 0;
}