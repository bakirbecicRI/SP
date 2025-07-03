#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

struct Nalog {
    string knjiga;
    string korisnik;
    int brojStranica;
    int vrijemePrijema; 
};

int pretvoriUVrijeme(const string& vrijeme) {
    int sati = (vrijeme[0] - '0') * 10 + (vrijeme[1] - '0');
    int minute = (vrijeme[3] - '0') * 10 + (vrijeme[4] - '0');
    return sati * 60 + minute;
}

string pretvoriUString(int minute) {
    int sati = (minute / 60) % 24;
    int min = minute % 60;
    string rezultat;
    if (sati < 10) rezultat += "0";
    rezultat += to_string(sati);
    rezultat += ":";
    if (min < 10) rezultat += "0";
    rezultat += to_string(min);
    return rezultat;
}

int main() {
    ifstream ulaz("nalozi.txt");
    if (!ulaz) {
        cout << "Greska pri otvaranju fajla.\n";
        return 1;
    }

    int brojKorisnika;
    ulaz >> brojKorisnika;
    string* korisnici = new string[brojKorisnika];

    for (int i = 0; i < brojKorisnika; ++i)
        ulaz >> korisnici[i];

    int brzina;
    ulaz >> brzina;

    queue<Nalog> red;
    string imeKnjige, korisnik, vrijeme;
    int brojStranica;

    string linija;
    getline(ulaz, linija); 

    int prethodnoVrijeme = -1;
    int danOffset = 0;

    while (getline(ulaz, linija)) {
        size_t poc = linija.find('\"') + 1;
        size_t kraj = linija.find('\"', poc);
        imeKnjige = linija.substr(poc, kraj - poc);

        size_t poz = kraj + 2;
        size_t razmak1 = linija.find(' ', poz);
        korisnik = linija.substr(poz, razmak1 - poz);

        size_t razmak2 = linija.find(' ', razmak1 + 1);
        brojStranica = stoi(linija.substr(razmak1 + 1, razmak2 - razmak1 - 1));

        vrijeme = linija.substr(razmak2 + 1);
        int vrijemeMin = pretvoriUVrijeme(vrijeme);

        if (vrijemeMin < prethodnoVrijeme)
            danOffset += 1440;
        
        vrijemeMin += danOffset;
        prethodnoVrijeme = vrijemeMin;

        red.push({imeKnjige, korisnik, brojStranica, vrijemeMin});
    }

    int trenutnoVrijeme = red.front().vrijemePrijema;

    auto num=1;
    while (!red.empty()) {
        Nalog n = red.front();
        red.pop();

        if (n.vrijemePrijema > trenutnoVrijeme)
            trenutnoVrijeme = n.vrijemePrijema;
  
        int trajanje = (n.brojStranica + brzina - 1) / brzina;

        cout <<"Nalog #"<<num<<"\n"<<"Knjiga: "<<n.knjiga<<"\n"<<"Korisnik: "<<n.korisnik<<"\n"
          <<"Zaprimljeno: "<< pretvoriUString(trenutnoVrijeme)<<"\n"<<
          "Zavrseno: "<< pretvoriUString(trenutnoVrijeme + trajanje) <<std::endl;
          std::cout<<std::endl;    

        trenutnoVrijeme += trajanje;
        num++;
    }

    delete[] korisnici;
    return 0;
}

