#include "big_int_moj.hpp"
#include <iostream>

int main(){
  bigint prvi;
  bigint drugi;
  std::cout<<"Unesi prvi broj: ";
  std::cin>>prvi;
  std::cout<<"Unesi drugi broj: ";
  std::cin>>drugi;
  bigint zbir=prvi+drugi;
  bigint razlika=prvi-drugi;
  bigint proizvod=prvi*drugi;
  bigint kolicnik=prvi/drugi;
  std::cout<<"Zbir: "<<zbir<<std::endl;
  std::cout<<"Razlika: "<<razlika<<std::endl;
  std::cout<<"Proizvod: "<<proizvod<<std::endl;
  std::cout<<"Kolicnik: "<<kolicnik<<std::endl;
return 0;
}
