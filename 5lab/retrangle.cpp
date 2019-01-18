#include "retrangle.hpp"
#include <iostream>
#include <cmath>

Retrangle::Retrangle() : Retrangle(0, 0) {}

Retrangle::Retrangle(size_t a, size_t b) : side_a(a), side_b(b) {
    std::cout << "Retrangle created: " << side_a << ", " << side_b << std::endl;
}

Retrangle::Retrangle(const Retrangle& orig) {
    //std::cout << "Retrangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Retrangle::Square() {
    return double(side_a)*double(side_b);
}

bool operator==(const Retrangle& fst, const Retrangle& snd) {
    if (fst.side_a == snd.side_a && fst.side_b == snd.side_b) {
        return true;
    }
    else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Retrangle& obj) {
    os << "(" << obj.side_a << ", " << obj.side_b << ")" << std::endl;
    return os;
}

void Retrangle::Print() {
    std::cout << "rec" << "(" << side_a << ", " << side_b << ")" << std::endl;
}

/*std::istream& operator>>(std::istream& is, Retrangle& obj) {
    is >> obj.side_a;
    is >> obj.side_b;
    return is;
}*/

Retrangle::~Retrangle() {
    std::cout << "Retrangle deleted" << std::endl;
}