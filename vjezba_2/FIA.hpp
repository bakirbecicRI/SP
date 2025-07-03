#include <string>

class FIA {

  public:
    std::string get_name() {
return full_team_name;
    }
    std::string get_chasis(){
return chasis;
    }

int get_wc() const{
  return wc;
}

friend std::istream& operator>>(std::istream& in, FIA& f);

  private:
    std::string team;
    std::string full_team_name;
    std::string base;
    std::string team_chief;
    std::string tehnical_chief;
    std::string chasis;
    std::string power_unit;
    int first_team_entry; 
    int wc;
    std::string highest_race_finishing;
    int pole_positions;
    int fastest_laps;

};
