#include <iostream>
#include <stdlib.h>
using namespace std;

class Pointer {
public:

void afiseaza_float(float* vector, int numar_elemente)
{
for (int i=0;i<numar_elemente;i++)
cout << *vector++ <<endl;
};

public:
    int lungime_sir (char *sir)
{
int lungime =0;
while (*sir != '\0')
{
lungime++;
sir++;
}
return(lungime);
};

public:
    void afiseaza_sir(char *string)
{
while (*string != '\0')
{
cout << *string<<endl;
string++;
}
};
};


int main ()
{
float valori [5] = {2.75, 3.56, 4.56, 5.68, 10.21};
Pointer p;
p.afiseaza_float(valori,5);
cout << "\n";
char titlu[] = "Laborator de C++";
Pointer a;
cout <<'"'<< titlu <<'"'<< " contine " <<

a.lungime_sir(titlu)<<" caractere"<<endl;

Pointer b;
b.afiseaza_sir("\nLaborator C++");
return 0;
}
