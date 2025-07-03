#include "zaposlenik.hpp"
#include <iostream>

std::istream& operator>>(std::istream& in, Zaposleni& z){
  std::getline(in,z.ime,',');
  in.ignore();
  std::getline(in,z.prezime,',');
  in.ignore();
  in>>z.broj_sati;
  in.ignore();
  return in;
  
}

std::ostream& operator<<(std::ostream& out, Zaposleni& z){
    out<<z.ime<<" "<<z.prezime<<" "<<z.status<<" "<<z.get_plata()<<" KM";
      return out;
}

void Zaposleni::formiranje_statusa(){
      if (broj_sati>=180){
      status="Pohvaljeni";
      }
      if (broj_sati<180){
      status="Nije plaćen";
      }

}

void Zaposleni::formiranje_plate(){
      if (broj_sati>=180){
        plata=5000;
      }
      if (broj_sati<180){
        plata=3000;
      }

}
