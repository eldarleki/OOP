#include "retrangle.h"
#include <iostream>
#include <cmath>

Retrangle::Retrangle(size_t a, size_t b) : side_a(a), side_b(b) {
    std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Retrangle::Retrangle(std::istream &in) {
    std::cin >> side_a >> side_b;
}

Retrangle::Retrangle(const Retrangle& orig) {
    std::cout << "Rectangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Retrangle::Square() {
    return double(side_a)*double(side_b);
}

void Retrangle::print(std::ostream& os = std::cout) {
    std::cout << "rec" << "(" << side_a << ", " << side_b << ")";
}

Retrangle& Retrangle::operator=(const Retrangle &other) {
	if (this == &other)
		return *this;
	side_a = other.side_a;
	side_b = other.side_b;
	return *this;
}
std::istream& operator>>(std::istream &is, Retrangle &r) {
	is >> r.side_a >> r.side_b;
	return is;
}

Retrangle::~Retrangle() {
    std::cout << "Rectangle deleted" << std::endl;
}