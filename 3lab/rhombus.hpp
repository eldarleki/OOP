#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(std::istream &in);
    Rhombus(size_t a, size_t h);
    Rhombus(const Rhombus& orig);

    double Square() override;
    void Print() override;

    virtual ~Rhombus();
private:
    size_t side_a;
    size_t side_h;
};

#endif