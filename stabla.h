
#ifndef DOMACIASP_STABLA_H
#define DOMACIASP_STABLA_H
#include "cvor.h"
#include <bits/stdc++.h>
using namespace std;

class stabla {
public:
    cvor *korijen;

    stabla() {
        korijen= nullptr;
    }

    cvor *preOrder(string s1,string s2);
    cvor *pretragaPitanja(string s);
    void dodajOdgovor(string s,string k);
    void dodajPitanje(string s);
    void povecanjeOcjene(string pitanje,string odgovor,int ocje);
    void ispisPitanja();
    void ispis(string s);
    void obrisiCvor(string p,string s);
    cvor *maxDjece();
    void obrisiPitanje(string p);
    void brisiPreorder(cvor *p);
    void uredi();

};



#endif //DOMACIASP_STABLA_H
