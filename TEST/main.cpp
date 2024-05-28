#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produs {
public:
    std::string denumire;
    double pret;
    std::string unitate_masura;
    Produs(std::string denumire, double pret, std::string unitate_masura)
        : denumire(denumire), pret(pret), unitate_masura(unitate_masura) {}
};

class Oferta {
public:
    std::vector<Produs> produse;

    // Adaugarea unui produs la oferta
    void adauga_produs() {
        std::string denumire;
        double pret;
        std::string unitate_masura;

        std::cout << "Introduceti denumirea produsului: ";
        std::cin >> denumire;

        std::cout << "Introduceti pretul produsului in lei: ";
        std::cin >> pret;

        std::cout << "Introduceti unitatea de masura a produsului: ";
        std::cin >> unitate_masura;

        produse.emplace_back(denumire, pret, unitate_masura);
    }

    // Afisarea listei de preturi in lei si in euro
    void lista_preturi(double nivel_pret, double curs_euro) const {
        std::cout << "Lista de produse mai ieftine decat " << nivel_pret << ":\n";
        for (const auto& produs : produse) {
            if (produs.pret < nivel_pret) {
                std::cout << produs.denumire << ": " << produs.pret << " lei | "
                          << produs.denumire << ": " << (produs.pret / curs_euro) << " euro\n";
            }
        }
    }
};

int main() {
    Oferta oferta_magazin;

    // Introducere produse de la tastatura
    int numar_produse;
    std::cout << "Introduceti numarul de produse: ";
    std::cin >> numar_produse;

    for (int i = 0; i < numar_produse; ++i) {
        std::cout << "\nIntroduceti detaliile pentru produsul " << i + 1 << ":\n";
        oferta_magazin.adauga_produs();
    }

    // Introduceti nivelul de pret in lei sau in euro de la tastatura
    double nivel_pret, curs_euro;
    std::cout << "\nIntroduceti nivelul de pret: ";
    std::cin >> nivel_pret;

    std::cout << "Introduceti cursul de schimb euro/lei: ";
    std::cin >> curs_euro;

    // Afiseaza lista de produse mai ieftine decat nivelul de pret
    oferta_magazin.lista_preturi(nivel_pret, curs_euro);

    return 0;
}
