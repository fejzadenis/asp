#include <iostream>
using namespace std;
#include "stabla.h"

int main() {
    stabla s;
    string prvi;
    string drugi;
    string treci;
    cvor *pronadjenoPitanje;
    cvor *pronadjenOdgovor;
    cvor *max;
    int ocjena;

    while (true) {
        cout << "Odaberite opciju:" << endl << "1.Kreiranje strukture" <<endl<< "2.Dodavanje novog pitanja" << endl
             << "3.Dodavanje odgovora na pitanje ili odgovor" << endl << "4.Pretraga pitanja"
             << endl << "5.PREORDER pretraga odgovora" << endl << "6.Povecanje ocjene nekog odgovora" << endl
             << "7.Sortiranje cvorova po ocjeni" << endl << "8.Ispis pitanja" << endl
             << "9.Ispis cijelog stabla(pitanja)" <<
             endl << "10.Brisanje cvora" << endl << "11.Brisanje pitanja" << endl
             << "12.Pronalazak pitanja sa najvise potomaka" << endl << "13.Izlaz iz programa" << endl;

        int opcija;
        cin >> opcija;

        switch (opcija) {
            case 1:
                cout << "Uspjesno napravljena struktura" << endl;
                break;
            case 2:

                cout << "Unesite tekst pitanja:" << endl;
                cin.ignore();
                getline(cin, prvi);
                s.dodajPitanje(prvi);
                cout << "Pitanje uspjesno dodato!" << endl;
                break;


            case 3:
                cout << "Unesite tekst pitanja na koje zelite da dodate odgovor a zatim i zeljeni sadrzaj odgovora:"<< endl;
                cin.ignore();
                getline(cin, prvi);
                getline(cin, drugi);
                s.dodajOdgovor(prvi, drugi);
                break;
            case 4:
                cout << "Unesite sadrzaj pitanja koje zelite da pronadjete:" << endl;
                cin.ignore();
                getline(cin, prvi);
                pronadjenoPitanje = s.pretragaPitanja(prvi);
                if (pronadjenoPitanje) {
                    cout << "Pitanje uspjesno pronadjeno!" << endl;
                }

                break;

            case 5:
                cout<<"Unesi pitanje a zatim i sadrzaj odgovora koji zelis da pronadjes:"<<endl;
                cin.ignore();
                getline(cin,prvi);
                getline(cin,drugi);
                pronadjenOdgovor=s.preOrder(prvi,drugi);
                if (pronadjenOdgovor) {
                    cout<<"Odgovor uspjesno pronadjen"<<endl;
                }
                else {
                    cout<<"Odgovor nije pronadjen"<<endl;
                }

                break;
            case 6:
                cout<<"Unesi pitanje a zatim i sadrzaj odgovora kao i ocjenu na koju zelis da mu je povecas:" <<endl;
                cin.ignore();
                getline(cin,prvi);
                getline(cin,drugi);
                cin>>ocjena;
                s.povecanjeOcjene(prvi,drugi,ocjena);
                break;

            case 7:
                cout<<"Uspjesno pozvana fukncija za uredjivanje cvorova!"<<endl;
                s.uredi();
                break;
            case 8:
                s.ispisPitanja();
                break;
            case 9:
                cout<<"Unesi sadrzaj pitanja koje zelis da ispises:"<<endl;
                cin.ignore();
                getline(cin,prvi);
                s.ispis(prvi);
                cout<<endl;
                break;
            case 10:
                cout<<"Unesi pitanje a zatim i sadrzaj odgovora koga ces obrisati zajedno sa njegovim potomcima: "<<endl;
                cin.ignore();
                getline(cin,prvi);
                getline(cin,drugi);
                s.obrisiCvor(prvi,drugi);
                cout<<"Brisanje uspjesno!"<<endl;
                break;
            case 11:
                cout<<"Unesi sadrzaj pitanja koje zelis da obrises: "<<endl;
                cin.ignore();
                getline(cin,prvi);
                s.obrisiPitanje(prvi);
                cout<<"Pitanje uspjesno obrisano!";
                break;
            case 12:
                max=s.maxDjece();
                cout<<"Uspjesno nadjeno pitanje sa najvise potomaka!"<<endl;
                cout<<"'"<<max->sadrzaj<<"'"<<" sa "<<max->brojvezanihcvorova<<" potomaka!"<<endl;
                break;
            case 13:
                return 0;
            default:
                cout<<"Nepoznata opcija!"<<endl;
                break;
        }


    }


}







