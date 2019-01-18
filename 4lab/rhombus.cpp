#include "rhombus.hpp"
#include <iostream>
#include <cmath> 

Rhombus::Rhombus(size_t a, size_t h) : side_a(a), side_h(h) {
    std::cout << "Rhombus created: " << side_a << ", " << side_h << std::endl;
}

Rhombus::Rhombus(std::istream &in) {
    std::cout << "Rhombus's side: " << std::endl;
    in >> side_a;
    std::cout << "Rhombus's height: " << std::endl;
    in >> side_h;
}

Rhombus::Rhombus(const Rhombus& orig) {
    std::cout << "Rhombus copy created" << std::endl;
    side_a = orig.side_a;
    side_h = orig.side_h;
}

double Rhombus::Square() {
    return double(side_a)*double(side_h);
}

void Rhombus::Print() {
    std::cout << "rho" << "(" << side_a << ", " << side_h << ")" << std::endl;
}

Rhombus::~Rhombus() {
    std::cout << "Rhombus deleted" << std::endl;
}