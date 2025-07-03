#include "MojVektor.hpp"
#include <iostream>
// CPP fajl sa testiranjem implementacija
int main() {

  MojVektor<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(7);
  std::cout<<vec<<std::endl;
  vec.push_front(24);
  std::cout<<vec;
  std::cout<<"Element na zadnjoj poziciji: "<<vec.at(3)<<std::endl;
  vec.rotate();
  std::cout<<vec<<std::endl;
  auto it=vec.begin();
  it++;
  vec.erase(it);
  std::cout<<vec<<std::endl;
  vec.insert(it, 100);
  std::cout<<vec<<std::endl;
  MojVektor<int> niz{1,2,3,4,5};
  for (auto it=niz.begin(); it!=niz.end(); it++){
    std::cout<<*it<<" ";
  }
  std::cout<<std::endl;
  auto it1=niz.begin();
  it1++;
  niz.erase(it1, niz.end());
  std::cout<<niz<<std::endl;
  MojVektor<int> primjer={1,2,3,4,5};
  primjer.remove_if([](int a){return a%2==1;});
  std::cout<<primjer;
  return 0;

}
