#include "retrangle.hpp"
#include <iostream>
#include <cmath>

Retrangle::Retrangle(size_t a, size_t b) : side_a(a), side_b(b) {
    std::cout << "Retrangle created: " << side_a << ", " << side_b << std::endl;
}

Retrangle::Retrangle(std::istream &in) {
    std::cout << "Retrangle's 1 side: " << std::endl;
    in >> side_a;
    std::cout << "Retrangle's 2 side: " << std::endl;
    in >> side_b;
}

Retrangle::Retrangle(const Retrangle& orig) {
    std::cout << "Retrangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Retrangle::Square() {
    return double(side_a)*double(side_b);
}

void Retrangle::Print() {
    std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

Retrangle::~Retrangle() {
    std::cout << "Retrangle deleted" << std::endl;
}