#ifndef RETRANGLE_H
#define RETRANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Retrangle : public Figure{
public:
    Retrangle();
    Retrangle(std::istream &in);
    Retrangle(size_t a, size_t b);
    Retrangle(const Retrangle& orig);

    double Square() override;
    void print(std::ostream&) override;
    Retrangle& operator=(const Retrangle&);
    friend std::istream& operator>>(std::istream&, Retrangle&);
   
    virtual ~Retrangle();
private:
    size_t side_a;
    size_t side_b;
};

#endif