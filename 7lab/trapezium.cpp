#include "trapezium.h"
#include <iostream>
#include <cmath>

Trapezium::Trapezium(size_t a, size_t b, size_t h) : side_a(a), side_b(b), side_h(h) {
    std::cout << "Trapezium created: " << side_a << ", " << side_b << ", " << side_h << std::endl;
}

Trapezium::Trapezium(std::istream &in) {
    std::cin >> side_a >> side_b >> side_h;
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

void Trapezium::print(std::ostream& os = std::cout) {
    std::cout << "tra" << "(" << side_a << "," << side_b << "," << side_h << ")";
}

Trapezium& Trapezium::operator=(const Trapezium &other) {
	if (this == &other)
		return *this;
	side_a = other.side_a;
	side_b = other.side_b;
    side_h = other.side_h;
	return *this;
}

std::istream& operator>>(std::istream &is, Trapezium &r) {
	is >> r.side_a >> r.side_b >> r.side_h;
	return is;
}

Trapezium::~Trapezium() {
    std::cout << "Trapezium deleted" << std::endl;
}