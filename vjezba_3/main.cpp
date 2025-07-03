#include <iostream>
#include "duration.hpp"


int main() {

  //try{
  //Duration d{34,25,05};
  //}
  //catch(std::out_of_range &e){
  //  std::cout<<e.what()<<std::endl;
  //}
  //Duration d{4564};
  //std::cout<<d.get_h()<<"h, "<<d.get_m()<<"m, "<<d.get_s()<<"s "<<std::endl;
  //Duration g;
  //g.set_h(5).set_m(23).set_s(45);
  //Duration d1{10, 35, 15};
  //Duration d2{10, 40, 15};
  Duration d{"10:30:25"};
  std::cout<<d;  




return 0;
}
