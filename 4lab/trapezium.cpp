#include "trapezium.hpp"
#include <iostream>
#include <cmath>

Trapezium::Trapezium(size_t a, size_t b, size_t h) : side_a(a), side_b(b), side_h(h) {
    std::cout << "Trapezium created: " << side_a << ", " << side_b << ", " << side_h << std::endl;
}

Trapezium::Trapezium(std::istream &in) {
    std::cout << "Trapezium's top side: " << std::endl;
    in >> side_a;
    std::cout << "Trapezium's bottom side: " << std::endl;
    in >> side_b;
    std::cout << "Trapezium's height: " << std::endl;
    in >> side_h;
}

Trapezium::Trapezium(const Trapezium& orig) {
    std::cout << "Trapezium copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_h = orig.side_h;
}

double Trapezium::Square() {
    return (double(side_a)+double(side_b))*double(side_h)/2;
}

void Trapezium::Print() {
    std::cout << "tra" << "(" << side_a << ", " << side_b << ", " << side_h << ")" << std::endl;
}

Trapezium::~Trapezium() {
    std::cout << "Trapezium deleted" << std::endl;
}