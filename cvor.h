//
// Created by denis on 14.12.2021..
//

#ifndef DOMACIASP_CVOR_H
#define DOMACIASP_CVOR_H
#include <string>
using namespace std;


class cvor {
public:
    cvor *roditelj;
    cvor *djeca[10];
    string sadrzaj;
    cvor *sledeci;
    int brojpotomaka;
    int ocjena;
    int id;
    int brojvezanihcvorova;



    cvor(string s) {
        sadrzaj=s;

        for(int i=0;i<10;i++) {
            djeca[i]= nullptr;

        }
        brojpotomaka=0;
        sledeci= nullptr;
        roditelj= nullptr;
        ocjena=0;
        id=0;
        brojvezanihcvorova=0;



    }

    friend class stabla;












};


#endif //DOMACIASP_CVOR_H
