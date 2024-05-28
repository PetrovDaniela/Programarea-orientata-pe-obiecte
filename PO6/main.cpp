#include <iostream>
#include <string>

class Masina {
protected:
    std::string tip;
    std::string culoare;
    double pret;
public:
    Masina(const std::string& tip, const std::string& culoare, double pret) {
        this->tip = tip;
        this->culoare = culoare;
        this->pret = pret;
    }
    ~Masina() {
    }
    void afiseazaMasina() {
        std::cout << "Tip masina: " << tip << std::endl;
        std::cout << "Culoare: " << culoare << std::endl;
        std::cout << "Pret: " << pret << " euro" << std::endl;
    }
};

class Sofer {
protected:
    std::string nume;
    std::string prenume;
    int varsta;
    Masina masina;

public:
    Sofer(const std::string& tip, const std::string& culoare, double pret, const std::string& nume, const std::string& prenume, int varsta)
        : masina(tip, culoare, pret) {
        this->nume = nume;
        this->prenume = prenume;
        this->varsta = varsta;
    }
    ~Sofer() {
    }
    void afiseazaSofer() {
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Prenume: " << prenume << std::endl;
        std::cout << "Varsta: " << varsta << " ani" << std::endl;
        masina.afiseazaMasina();
    }
};

int main() {
    Sofer sofer1("Sedan", "Rosu", 7000.0, "Vasile", "Popescu", 30);
    sofer1.afiseazaSofer();
    return 0;
}
