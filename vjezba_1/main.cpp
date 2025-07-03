#include <iostream>
#include <vector>
#include <fstream>
#include "zaposlenik.hpp"
#include <algorithm>
int main(){
  Zaposleni zaposleni;
  std::vector<Zaposleni> uposlenici;
  std::ifstream in("zaposleni.csv");
  if(!in){
    std::cout<<"Neuspjesan unos!"<<std::endl;
  }
  std::string s;
  std::getline(in, s);
  while (in>>zaposleni){
    uposlenici.push_back(zaposleni);
  }
  in.close();
  std::cout<<"Ucitano : "<<uposlenici.size()<<" uposlenika."<<std::endl; 
  
  std::ofstream out("place.csv");
  if(!out){
    std::cout<<"Neuspjesan unos!"<<std::endl;
  }
  out<<"Ime Prezime Status"<<std::endl;
  for (auto it=uposlenici.begin(); it!=uposlenici.end(); it++){
        it->formiranje_statusa();
        out<<*it<<std::endl;
  }
  out.close();
  for (auto& e: uposlenici){
      e.formiranje_plate();
  }
  auto kriterij=[](const Zaposleni& uno, const Zaposleni& due){
      return uno.get_plata()<due.get_plata();
  };
  std::sort(uposlenici.begin(), uposlenici.end(), kriterij);
  std::ofstream out2("sorted.csv");
  if(!out2){
    std::cout<<"Neuspjesan unos!"<<std::endl;
  }
  out2<<"Radnici sa sortiranom platom: "<<std::endl;
  for (auto it=uposlenici.begin(); it!=uposlenici.end(); it++){
      out2<<it->get_ime()<<" "<<it->get_prezime()<<" "<<it->get_plata()<<" KM"<<std::endl;
  }
  out2.close();
return 0;
}
