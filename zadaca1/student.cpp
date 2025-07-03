#include "student.hpp"
#include <iostream>

void Student::formiranje_ocjene() {
  auto sum=0;
  if (prvi_test<50){
    sum++;
  }
  if (drugi_test<50)
    sum++;
  if (treci_test<50)
    sum++;
  if (cetvrti_test<50)
    sum++;
  if (peti_test<50)
    sum++;
   double bodovi_prvog_testa = 20.0*(prvi_test/100.0); 
   double bodovi_drugog_testa = 10.0*(drugi_test/100.0);
   double bodovi_treceg_testa = 25.0*(treci_test/100.0); 
   double bodovi_cetvrtog_testa =25.0*(cetvrti_test/100.0);
   double bodovi_petog_testa = 20.0*(peti_test/100.0);
  auto grade=bodovi_prvog_testa+bodovi_drugog_testa+bodovi_treceg_testa+bodovi_cetvrtog_testa+bodovi_petog_testa;

  if (grade<54&&sum<3){
    ocjena="Nije polozio";
  }
  else if(sum>=3){
    ocjena="*";
  }
  else if ((grade>=54 && grade <=63)){
    ocjena="6";
  }
  else if ((grade>=64 && grade <=73)){
    ocjena="7";
  }
  else if ((grade>=74 && grade <= 83)){
    ocjena="8";
  }
  else if ((grade>=84 && grade <=93)){
    ocjena="9";
  }
  else if ((grade>=94 &&grade<=100)){
    ocjena="10";
  }
}
std::istream& operator>>(std::istream& in, Student& student){
  std::string temp;
  if(!std::getline(in, temp, ','))
    return in;
  student.ucitaj_ime(temp);
  std::getline(in, temp, ',');
  student.ucitaj_prezime(temp);
  std::getline(in,temp,',');
  student.prvi_test=std::stod(temp);
  std::getline(in,temp,',');
  student.drugi_test=std::stod(temp);
  std::getline(in,temp,',');
  student.treci_test=std::stod(temp);
  std::getline(in,temp,',');
  student.cetvrti_test=std::stod(temp);
  std::getline(in,temp);
  student.peti_test=std::stod(temp);
  return in;

}

std::ostream& operator<<(std::ostream& out, Student& student){
  out<<student.ime<<" "<<student.prezime<<" "<<student.get_first()<<" "<<student.get_second()<<" "<<student.get_third()<<" "<<
      student.get_4th()<<" "<<student.get_5th()<<std::endl;
  return out;
  


}
