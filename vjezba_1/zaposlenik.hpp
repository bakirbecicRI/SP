#pragma once
#include <string>

class Zaposleni{
  public:
  void formiranje_statusa();
  void formiranje_plate();
  int get_plata() const{
    return plata;
  }
  std::string get_ime() {
    return ime;
    }
  std::string get_prezime() {
    return prezime;
  }
  friend std::istream& operator>>(std::istream& in, Zaposleni& z);
  friend std::ostream& operator<<(std::ostream& out, Zaposleni& z);
  private:
  std::string ime;
  std::string prezime;
  int broj_sati;
  std::string status;
  int plata=0;
};
