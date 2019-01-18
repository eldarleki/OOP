#include <cstdlib>
#include "retrangle.hpp"
#include "trapezium.hpp"
#include "rhombus.hpp"

int main() {
    int matching = 0;
    std::cout << "Enter the number of figure:" << std::endl
              << "1 - retrangle" << std::endl 
              << "2 - trapezium" << std::endl 
              << "3 - rhombus" << std::endl
              << "0 - exit" << std::endl;
    while (std::cin >> matching) {
        if (matching == 1) {
            Figure *ptr_ret = new Retrangle(std::cin);
            ptr_ret->Print();
            std::cout << ptr_ret->Square() << std::endl;
            delete ptr_ret;
        }
        if (matching == 2) {
            Figure *ptr_tra = new Trapezium(std::cin);
            ptr_tra->Print();
            std::cout << ptr_tra->Square() << std::endl;
            delete ptr_tra;
        }
        if (matching == 3) {
            Figure *ptr_rho = new Rhombus(std::cin);
            ptr_rho->Print();
            std::cout << ptr_rho->Square() << std::endl;
            delete ptr_rho;
        }
        if (matching == 0)
            break;
        std::cout << "Enter the number of figure:" << std::endl
              << "1 - retrangle" << std::endl 
              << "2 - trapezium" << std::endl 
              << "3 - rhombus" << std::endl
              << "0 - exit" << std::endl;
    }
    return 0;
}