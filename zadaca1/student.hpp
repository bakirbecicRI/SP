#include <iostream>
#include <string>

class Student{
  public:
    Student()=default;
    void ucitaj_ime(std::string& name) {
    ime=name;}
    std::string get_ime (){
      return ime;
    }
    std::string get_prezime (){
      return prezime;
    }
    void ucitaj_prezime(std::string& surname) {
    prezime=surname;}
    void ucitaj_1(int temp){
    prvi_test=temp;
    }
    int get_first(){
      return prvi_test;}
    void ucitaj_2(int temp){
      drugi_test=temp;
    }
    int get_second(){  
      return drugi_test;}

    void ucitaj_3(int temp){
      treci_test=temp;
    }
    int get_third(){
      return treci_test;
    }
    void ucitaj_4(int temp){
      cetvrti_test=temp;
    }
    int get_4th(){
      return cetvrti_test;
    }
    void ucitaj_5(int temp){
      peti_test=temp;
    }
    int get_5th(){
      return peti_test;
    }
    void formiranje_ocjene();
    std::string get_grade(){
      return ocjena;
    }
 friend std::ostream& operator<<(std::ostream& out, Student& student);
 friend std::istream& operator>>(std::istream& in, Student& student);
  
  private:
  std::string ime;
  std::string prezime;
  double prvi_test;
  double drugi_test;
  double treci_test;
  double cetvrti_test;
  double peti_test;
  std::string ocjena="";

};
