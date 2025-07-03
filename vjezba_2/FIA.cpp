#include "FIA.hpp"
#include <iostream>
#include <string>

std::istream& operator>>(std::istream& in, FIA& f){
  std::string temp;
  if(!std::getline(in, temp, ','))
    return in;
  f.team=temp;
  std::getline(in, f.full_team_name, ',');
  std::getline(in, f.base, '"');
  std::getline(in, f.team_chief, ',');
  std::getline(in, f.tehnical_chief, ',');
  std::getline(in, f.chasis, ',');
  std::getline(in, f.power_unit, ',');
  std::getline(in, temp, ',');
  f.first_team_entry=std::stoi(temp);
  std::getline(in, temp, ',');
  f.wc=std::stoi(temp);
  std::getline(in, f.highest_race_finishing, ',');
  std::getline(in, temp, ',');
  f.pole_positions=std::stoi(temp);
  std::getline(in, temp);
  f.fastest_laps=std::stoi(temp);
  return in;

}
