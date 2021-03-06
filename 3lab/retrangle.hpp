#ifndef RETRANGLE_H
#define RETRANGLE_H
#include <cstdlib>
#include <iostream>
#include "figure.hpp"

class Retrangle : public Figure{
public:
    Retrangle();
    Retrangle(std::istream &in);
    Retrangle(size_t a, size_t b);
    Retrangle(const Retrangle& orig);

    double Square() override;
    void Print() override;

    friend std::ostream& operator<<(std::ostream& os, const Retrangle& obj);
    friend bool operator==(const Retrangle& fst, const Retrangle& snd);
      
    virtual ~Retrangle();
private:
    size_t side_a;
    size_t side_b;
};

#endif