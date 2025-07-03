#include "big_int.hpp"
#include <iostream>

int main(){
  bigint niz=-53242424;
  std::cout<<niz<<std::endl;
  std::string number="2020";
  bigint niz2=number;
  std::cout<<niz2<<std::endl;
  bigint niz3="123456789";
  std::cout<<niz3<<std::endl;
  bigint prvi=-54;
  bigint drugi=9999;
  auto temp=prvi+drugi;
  std::cout<<temp<<std::endl;
  bigint treci=1568;
  bigint cetvrti=1012;
  auto temp1=treci-cetvrti;
  std::cout<<temp1<<std::endl;
  bigint prefix=9676;
  ++prefix;
  std::cout<<prefix<<std::endl;
  bigint prod1=201;
  bigint prod2=130;
  auto prod=prod1*prod2;
  std::cout<<prod<<std::endl;
  bigint del1=237;
  bigint del2=24;
  auto del=del1/del2;
  std::cout<<del<<std::endl;
  auto ostatak=del1%del2;
  std::cout<<ostatak<<std::endl;
return 0;
}
