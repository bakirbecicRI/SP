#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class TemperatureBase {
  public:
  int pickup(){
    std::ifstream fajl("lines.txt");
    if (!fajl){
      std::cout<<"Ne mogu otvoriti fajl.\n";
      return 1;
    }
    std::string linija;
    while (std::getline(fajl, linija)) {
      std::stringstream ss(linija);
      std::string grad;
      std::string temperatura_str;
      double temperatura;
      std::getline(ss,grad,';');
      std::getline(ss,temperatura_str);
      temperatura=std::stod(temperatura_str);
      auto& stats=base[grad];
      if (temperatura<stats.lowest_temp) stats.lowest_temp=temperatura;
      if (temperatura>stats.highest_temp) stats.highest_temp=temperatura;
      (stats.broj_temperatura)++;
      stats.suma_temperatura+=temperatura;
    }
    return 0;
  }  
  void play() {
  int x;
  std::string name;
  std::cout<<"Temperature database \nOptions: \n1. Find city\n2. Full report\n3. Quit\n0. Menu"<<std::endl;
  while (true){
  std::cin>>x;
  if (x==3){
    std::cout<<std::endl;
    std::cout<<"Quit"<<std::endl;
    break;
  }
  if (x==0){
   std::cout<<"Temperature database \nOptions: \n1. Find city\n2. Full report\n3. Quit\n0. Menu"<<std::endl;
  }
  if (x==1){
    std::cin.ignore();
    std::cout<<"Insert name of city: ";
    std::getline(std::cin, name);
    auto ix=base.find(name);
    if (ix!=base.end()){
      std::cout<<"'"<<name<<"' found: \nHighest temperature: "<<ix->second.highest_temp<<" C"<<"\nLowest temperature: "<<
        ix->second.lowest_temp<<" C"<<"\nAverage temperature: "<<(ix->second.suma_temperatura)/(ix->second.broj_temperatura)
        <<" C"<<std::endl;  
      std::cout<<std::endl;
      std::cout<<"Option: ";
    }
  
    else {
      std::cout<<"'"<<name<<"' is not found"<<std::endl;
      std::cout<<std::endl;
      std::cout<<"Option: ";
    }
  }
  if (x==2){
    output();
  }
  }
  }
int output(){
 std::cout<<"Generating reports for all "<<base.size()
        <<" cities loaded..."<<std::endl;
      std::ofstream fajl("report.txt");
      if (!fajl){
        std::cout<<"Greska pri otvaranju fajla!\n";
        return 1;
      }
      fajl<<"Name;Max;Min;Avg"<<std::endl;
      for (auto &el : base){
      fajl<<el.first<<";"<<el.second.highest_temp
        <<";"<<el.second.lowest_temp<<";"<<(el.second.suma_temperatura)/(el.second.broj_temperatura)<<std::endl;
      }
      std::cout<<"Report generated in 'report.txt'"<<std::endl;
      std::cout<<"Option: ";
      return 0;
}
  private:
    struct stats{
      double suma_temperatura=0;
      double broj_temperatura=0;
      double highest_temp=0;
      double lowest_temp=100;
    };
    std::map<std::string, stats> base;
};
