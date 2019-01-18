#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Trapezium : public Figure {
public:
    Trapezium();
    Trapezium(std::istream &in);
    Trapezium(size_t a, size_t b, size_t h);
    Trapezium(const Trapezium& orig);

    double Square() override;
    void Print() override;

    virtual ~Trapezium();
private:
    size_t side_a;
    size_t side_b;
    size_t side_h;
};

#endif