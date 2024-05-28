#include <iostream>
#include <cmath>

class Punct {
private:
    double x, y;

public:
    Punct(double xVal, double yVal) : x(xVal), y(yVal) {}

    void afiseazaCoordonatele() const {
        std::cout << "Coordonatele punctului: (" << x << ", " << y << ")\n";
    }

    friend class Triunghi;
};

class Triunghi {
private:
    Punct v1, v2, v3;

public:
    Triunghi(const Punct& v1, const Punct& v2, const Punct& v3) : v1(v1), v2(v2), v3(v3) {}

    void afiseazaVarfurile() const {
        std::cout << "Varfurile triunghiului:\n";
        v1.afiseazaCoordonatele();
        v2.afiseazaCoordonatele();
        v3.afiseazaCoordonatele();
    }

    std::string determinaTipulTriunghiului() const {
        double latura1 = distantaPuncte(v1, v2);
        double latura2 = distantaPuncte(v2, v3);
        double latura3 = distantaPuncte(v3, v1);

        if (latura1 == latura2 && latura2 == latura3) {
            return "Triunghi echilateral";
        } else if (latura1 == latura2 || latura2 == latura3 || latura3 == latura1) {
            return "Triunghi isoscel";
        } else {
            return "Triunghi oarecare";
        }
    }

private:
    double distantaPuncte(const Punct& p1, const Punct& p2) const {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

int main() {
    Punct v1(0, 0), v2(1, 0), v3(0, 1);
    Triunghi triunghi(v1, v2, v3);

    triunghi.afiseazaVarfurile();
    std::cout << "Tipul triunghiului: " << triunghi.determinaTipulTriunghiului() << std::endl;

    return 0;
}
