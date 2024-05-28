#include <iostream>
#include <string>

class Masina {
private:
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
private:
    std::string nume;
    std::string prenume;
    int varsta;
    Masina masina;
public:
    Sofer(const std::string& nume, const std::string& prenume, int varsta, const Masina& masina) : masina(masina) {
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
    Masina masina1("Sedan", "Rosu", 25000.0);
    Sofer sofer1("Vasile", "Popescu", 30, masina1);
    sofer1.afiseazaSofer();
    return 0;
}
