#include "rhombus.h"
#include <iostream>
#include <cmath> 

Rhombus::Rhombus(size_t a, size_t h) : side_a(a), side_h(h) {
    std::cout << "Rhombus created: " << side_a << ", " << side_h << std::endl;
}

Rhombus::Rhombus(std::istream &in) {
    std::cin >> side_a >> side_h;
}

Rhombus::Rhombus(const Rhombus& orig) {
    std::cout << "Rhombus copy created" << std::endl;
    side_a = orig.side_a;
    side_h = orig.side_h;
}

double Rhombus::Square() {
    return double(side_a)*double(side_h);
}

void Rhombus::print(std::ostream& os = std::cout) {
    std::cout << "rho" << "(" << side_a << ", " << side_h << ")";
}

Rhombus& Rhombus::operator=(const Rhombus &other) {
	if (this == &other)
		return *this;
	side_a = other.side_a;
	side_h = other.side_h;
	return *this;
}
std::istream& operator>>(std::istream &is, Rhombus &r) {
	is >> r.side_a >> r.side_h;
	return is;
}

Rhombus::~Rhombus() {
    std::cout << "Rhombus deleted" << std::endl;
}