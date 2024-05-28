#include <iostream>
#include <cmath>

class Punct {
private:
    double x, y;

public:
    Punct(double xVal, double yVal) : x(xVal), y(yVal) {}

    void afiseaza_Coordonatele() const {
        std::cout << "Coordonatele punctului: (" << x << ", " << y << ")\n";
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

class Patrulater {
private:
    Punct punct1, punct2, punct3, punct4;

public:
    Patrulater(const Punct& p1, const Punct& p2, const Punct& p3, const Punct& p4)
        : punct1(p1), punct2(p2), punct3(p3), punct4(p4) {}

    void afiseazaVarfurile() const {
        std::cout << "Varfurile patrulaterului:\n";
        punct1.afiseaza_Coordonatele();
        punct2.afiseaza_Coordonatele();
        punct3.afiseaza_Coordonatele();
        punct4.afiseaza_Coordonatele();
    }

    std::string determina_natura_patrulaterului() const {
        double lungime1 = distantaPuncte(punct1, punct2);
        double lungime2 = distantaPuncte(punct2, punct3);
        double lungime3 = distantaPuncte(punct3, punct4);
        double lungime4 = distantaPuncte(punct4, punct1);

        if (lungime1 == lungime2 && lungime2 == lungime3 && lungime3 == lungime4) {
            return "Patrulaterul este un patrat.";
        } else if (lungime1 == lungime3 && lungime2 == lungime4) {
            return "Patrulaterul este un dreptunghi.";
        } else if (lungime1 == lungime3 || lungime2 == lungime4) {
            return "Patrulaterul este un paralelogram.";
        } else if (lungime1 == lungime2 && lungime3 == lungime4) {
            return "Patrulaterul este un romb.";
        } else {
            return "Patrulaterul este un patrulater oarecare.";
        }
    }

    double calculeazaAria() const {
        return 0.0;
    }

private:
    double distantaPuncte(const Punct& p1, const Punct& p2) const {
        return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY(), 2));
    }
};

int main() {
    Punct v1(0, 0), v2(1, 0), v3(1, 1), v4(0, 1);
    Patrulater patrulater(v1, v2, v3, v4);

    patrulater.afiseazaVarfurile();
    std::cout << "Natura patrulaterului: " << patrulater.determina_natura_patrulaterului() << std::endl;

    return 0;
}
