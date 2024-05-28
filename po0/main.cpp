#include <iostream>
#include <string.h>
using namespace std;

class angajator
{
public:
    angajator(char *nume, int virsta);
    void arata_angajator(void);

private:
    char nume[64];
    int virsta;
};

class personal : public angajator
{
public:
    personal(char *nume, int virsta);
    void arata_personal(void);

private:
    char nume_personal[64];
};

class personal_aux
{
public:
    personal_aux(char *adresa, int experienta);
    void arata_personal_aux(void);

private:
    char nume[64];
    int virsta;
};

class angajat : public personal, public personal_aux
{
public:
    angajat(char *nume, int virsta, char *telefon);
    void arata_angajat(void);

private:
    char telefon[64];
};

class manager : public angajat
{
public:
    manager(char *nume, int virsta, char *telefon, char *birou);
    void arata_manager(void);

private:
    char birou[64];
};

angajator::angajator(char *nume, int virsta)
{
    strcpy(angajator::nume, nume);
    angajator::virsta = virsta;
}

void angajator::arata_angajator(void)
{
    cout << "Angajator: " << nume << endl;
    cout << "Virsta: " << virsta << endl;
}

personal::personal(char *nume, int virsta) : angajator(nume, virsta)
{
    strcpy(personal::nume_personal, nume);
}

void personal::arata_personal(void)
{
    arata_angajator();
    cout << "Nume personal: " << nume_personal << endl;
}

personal_aux::personal_aux(char *adresa, int experienta)
{
    strcpy(personal_aux::adresa, adresa);
    personal_aux::experienta = experienta;
}
void personal_aux::arata_personal_aux(void)
{
    cout << "Adresa: " << adresa << endl;
    cout << "Experienta: " << experienta<< endl;
}

angajat::angajat(char *nume, int virsta, char *telefon) : personal(nume, virsta), personal_aux(adresa, experiena)
{
    strcpy(angajat::telefon, telefon);
}

void angajat::arata_angajat(void)
{
    arata_personal();
    cout << "Telefon: " << telefon << endl;
}

manager::manager(char *nume, int virsta, char *telefon, char *birou) : angajat(nume, virsta, telefon)
{
    strcpy(manager::birou, birou);
}

void manager::arata_manager(void)
{
    arata_angajat();
    cout << "Birou: " << birou << endl;
}

int main()
{
    angajat muncitor("Popescu Ion", 41, "0742.0....");
    angajat muncitot("Strada Independentei 11", 15)
    manager sef("Ionescu Ion", 50, "0743......", "222");

    muncitor.arata_angajat();
    muncitor.arata_angajat_aux();
    sef.arata_manager();

    return 0;
}
