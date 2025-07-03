#include <iostream>
#include <fstream>
#include <vector>
#include "student.hpp"
int main(){
  
  std::ifstream input("students.csv");
    if(!input){
      std::cout<<"Nije se mogao otvoriti file"<<std::endl;
      return 1;
    }
    std::string temp;
    std::getline(input, temp);
    std::vector<Student> studenti;
    Student s;
    while (input>>s){ 
        studenti.push_back(s);
    }
    input.close();
    std::cout<<"ucitano: "<<studenti.size()<<" studenata"<<std::endl;
     
  std::ofstream output("ocjena.csv");
  if (!output){
    std::cout<<"nije moguce otvoriti"<<std::endl;
  return 1;
  }
  output<<"Ime Prezime Ocjena"<<std::endl;
  for (auto it=studenti.begin(); it!=studenti.end(); it++){
                  it->formiranje_ocjene();  
  output<<it->get_ime()<<" "<<it->get_prezime()<<" "<<it->get_grade()<<std::endl;
  }
return 0;
}
