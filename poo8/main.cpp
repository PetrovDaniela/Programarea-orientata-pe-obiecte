#include <iostream>
#include <cmath>

class Punct {
protected:
    double x, y, z;

public:
    Punct(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    virtual double calculeazaLungimeaSegmentului() const {
        return 0.0;
    }
};

class Segment : public Punct {
private:
    Punct punct1, punct2;

public:
    Segment(double x1, double y1, double z1, double x2, double y2, double z2)
        : Punct(x1, y1, z1), punct1(x1, y1, z1), punct2(x2, y2, z2) {}

    virtual double calculeazaLungimeaSegmentului() const override {
        double deltaX = punct2.getX() - punct1.getX();
        double deltaY = punct2.getY() - punct1.getY();
        double deltaZ = punct2.getZ() - punct1.getZ();

        return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
    }
};

class Triunghi : public Segment {
private:
    Punct punct3;

public:
    Triunghi(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
        : Segment(x1, y1, z1, x2, y2, z2), punct3(x3, y3, z3) {}

    virtual double calculeazaLungimeaSegmentului() const override {
        return Segment::calculeazaLungimeaSegmentului() + punct3.calculeazaLungimeaSegmentului();
    }

    double calculeazaPerimetrulTriunghiului() const {
        return Segment::calculeazaLungimeaSegmentului();
    }
};

int main() {
    Triunghi triunghi(0, 0, 0, 1, 0, 0, 0, 1, 0);
    double perimetru = triunghi.calculeazaPerimetrulTriunghiului();
    std::cout << "Perimetrul triunghiului: " << perimetru << std::endl;

    return 0;
}
