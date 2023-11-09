//
// Created by denis on 14.12.2021..
//

#include "stabla.h"




cvor *stabla::preOrder(string s1, string s2) {
    cvor *root= pretragaPitanja(s1);
    if (root== nullptr) {
        cout<<"Ne postoji takvo pitanje"<<endl;
        return 0;
    }

    stack<cvor*>Stek;
    Stek.push(root);
    cvor *tmp;
    while(!Stek.empty()) {
        tmp=Stek.top();

        if (tmp->sadrzaj==s2) {

            return tmp;


        }
        Stek.pop();
        for (int i=tmp->brojpotomaka-1;i>=0;i--) {
            if(tmp->djeca[i]!= nullptr) {
                Stek.push(tmp->djeca[i]);

            }

        }
    }
    return nullptr;
}

cvor *stabla::pretragaPitanja(string s) {
    cvor *tmp=korijen;
    while (tmp) {
        if (tmp->sadrzaj==s) {
            return tmp;

        }
        tmp=tmp->sledeci;
    }
    cout<<"Pitanje nije pronadjeno"<<endl;
    return nullptr;



}

void stabla::dodajOdgovor(string s, string k) {
    cvor *tmp=korijen;
    while (tmp) {

        stack<cvor*>Stek;
        Stek.push(tmp);
        cvor *x;
        while(!Stek.empty()) {
            x=Stek.top();

            if(x->sadrzaj==s) {
                if(x->brojpotomaka<10) {
                    x->djeca[x->brojpotomaka]=new cvor(k);
                    x->djeca[x->brojpotomaka]->id=x->brojpotomaka;
                    x->djeca[x->brojpotomaka]->roditelj=x;
                    x->brojpotomaka++;
                }
                else {
                    cout<<"Greska,cvor ima max. broj potomaka!";
                    return;
                }



            }
            Stek.pop();
            for (int i=x->brojpotomaka-1;i>=0;i--) {
                if(x->djeca[i]!= nullptr) {
                    Stek.push(x->djeca[i]);

                }

            }

        }
        tmp=tmp->sledeci;
    }

    return;
}

void stabla::dodajPitanje(string s) {
    cvor *novi=new cvor(s);

    if (korijen== nullptr) {
        korijen=novi;
        korijen->sledeci= nullptr;
        return;
    }

    cvor *tmp=korijen;
    while (tmp->sledeci) {
        tmp=tmp->sledeci;

    }
    tmp->sledeci=novi;
}

void stabla::povecanjeOcjene(string pitanje,string odgovor, int ocje) {
    cvor *odg= preOrder(pitanje,odgovor);
    odg->ocjena=ocje;


}

void stabla::ispisPitanja() {
    cvor *tmp=korijen;
    while(tmp) {
        cout<<tmp->sadrzaj<<endl;
        tmp=tmp->sledeci;
    }

}

void stabla::ispis(string s) {
    cvor *pitanje= pretragaPitanja(s);
    stack<cvor*>Stek;
    Stek.push(pitanje);
    cvor *x;
    while(!Stek.empty()) {

        x = Stek.top();

        cout<<x->sadrzaj<<endl;

        Stek.pop();


        for (int i = 0; i < x->brojpotomaka; i++) {
            if (x->djeca[i] != nullptr) {
                Stek.push(x->djeca[i]);


            }

        }
    }
}

void stabla::obrisiCvor(string p,string s) {
    cvor *nadjen= preOrder(p,s);
    cvor *roditelj=nadjen->roditelj;
    stack<cvor*>Stek;
    Stek.push(nadjen);
    cvor *x;

    while(!Stek.empty()) {
        x=Stek.top();

        Stek.pop();



        for (int i=0;i<x->brojpotomaka;i++) {
            if(x->djeca[i]!= nullptr) {
                Stek.push(x->djeca[i]);

            }

        }

        delete x;



    }
    for (int i=nadjen->id;i<roditelj->brojpotomaka;i++) {
        roditelj->djeca[i]=roditelj->djeca[i+1];

    }
    roditelj->brojpotomaka--;



}

cvor *stabla::maxDjece() {
    cvor *tmp=korijen;
    cvor *max= tmp;
    while (tmp) {

        stack<cvor *> Stek;
        Stek.push(tmp);
        cvor *x;
        while (!Stek.empty()) {
            x = Stek.top();


            Stek.pop();



            for (int i = 0; i < x->brojpotomaka; i++) {
                if (x->djeca[i] != nullptr) {
                    Stek.push(x->djeca[i]);
                    tmp->brojvezanihcvorova++;
                }

            }

        }

        if(tmp->brojvezanihcvorova>max->brojvezanihcvorova) {
            max=tmp;
        }
        tmp=tmp->sledeci;
    }


    return max;
}

void stabla::obrisiPitanje(string p) {
    cvor *tmp=korijen;
    cvor *pitanje= pretragaPitanja(p);
    if (tmp->sadrzaj==pitanje->sadrzaj) {
        korijen=korijen->sledeci;
        brisiPreorder(tmp);

    }
    else {
        while(tmp->sledeci->sadrzaj!=pitanje->sadrzaj) {
            tmp=tmp->sledeci;
        }
        tmp->sledeci=pitanje->sledeci;
        brisiPreorder(tmp);

    }

}

void stabla::brisiPreorder(cvor *p) {
    stack<cvor*>Stek;
    Stek.push(p);
    cvor *x;
    while(!Stek.empty()) {
        x=Stek.top();

        Stek.pop();


        for (int i=0;i<x->brojpotomaka;i++) {
            if(x->djeca[i]!= nullptr) {
                Stek.push(x->djeca[i]);

            }

        }

        delete x;



    }

}

void stabla::uredi() {
    cvor *tmp=korijen;
    while (tmp) {
        stack<cvor*>Stek;
        Stek.push(tmp);
        cvor *x;
        while(!Stek.empty()) {
            x=Stek.top();
            for (int i=0;i<x->brojpotomaka-1;i++) {
                cvor *privremeni;
                if(x->djeca[i]->ocjena>x->djeca[i+1]->ocjena) {
                    privremeni=x->djeca[i];
                    x->djeca[i]=x->djeca[i+1];
                    x->djeca[i+1]=privremeni;
                }
            }

            Stek.pop();


            for (int i=0;i<x->brojpotomaka;i++) {
                if(x->djeca[i]!= nullptr) {
                    Stek.push(x->djeca[i]);
                }

                }

            }











        tmp=tmp->sledeci;
    }

}







