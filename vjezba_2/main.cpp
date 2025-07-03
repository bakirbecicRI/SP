#include <iostream>
#include <vector>
#include "FIA.hpp"
#include <fstream>
#include <algorithm>

int main(){
    FIA driver;
    std::vector<FIA> drivers;
    std::ifstream in("formula1_2021season_teams.csv");
    if(!in)
      std::cout<<"nije moguce otvoriti"<<std::endl;
    std::string temp;
    std::getline(in,temp);
    while (in>>driver){
      drivers.push_back(driver);
    }
    in.close();
  auto predicate=[](const FIA& f1, const FIA& f2){return f1.get_wc()<f2.get_wc();};
    std::sort(drivers.begin(), drivers.end(), predicate);
    for (auto it=drivers.begin(); it!=drivers.end(); it++){
        std::cout<<it->get_name()<<" "<<it->get_chasis()<<" "<<it->get_wc()<<std::endl;

    }





  return 0;
}
