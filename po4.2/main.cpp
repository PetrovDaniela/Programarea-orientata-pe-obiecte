#include <iostream>
#include <stdlib.h>
using namespace std;

class Alias {
public:
void modif_val(int& val_referinta)
{
val_referinta=1500;
};

public:
    void apel_prin_valoare(int a,int b,int c)
{
a=3;b=2;c=1;
}
void apel_prin_pointer_referinta(int* a,int* b,int* c)
{
*a=3;*b=2;*c=1;
}
void apel_prin_referinta(int& a,int& b,int& c)
{
a=2;b=1;c=3;
};
};

class Valori{
public:
int a=1;
int b=2;
int c=3;
int *p, *n, *m;
int& a_alias=a;
int& b_alias=b;
int& c_alias=c;
*p = &a;
*n = &b;
*m = &c;
};

int main()
{
Alias d;
Valori f;
int valoare=10;
int& alias=valoare;
cout<<"Valoarea inaintea functiei: "<<valoare<<'\n';
d.modif_val(alias);
cout<<"Valoare dupa functie: "<<valoare<<endl;
cout << "\n";

d.apel_prin_valoare(f.a, f.b, f.c);
cout<<"Prin valoare: "<<f.a<<f.b<<f.c<<endl;
d.apel_prin_referinta(f.a,f.b,f.c);
cout<<"Prin referinta: "<<f.a_alias<<f.b_alias<<f.c_alias<<endl;
apel_prin_pointer_referinta(&p,&n,&m);
cout<<"Prin pointer: "<<p<<n<<m<<endl;
return 0;
}
