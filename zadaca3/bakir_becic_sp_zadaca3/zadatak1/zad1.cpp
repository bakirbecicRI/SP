#include "zad1.hpp"

int main() {
  List<int> lista;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_front(3);
  lista.push_front(4);
  lista.push_front(5);
  std::cout<<"Size of list: "<<lista.getsize() <<std::endl;
  std::cout<<"lista"<<std::endl;
  std::cout<<lista<<std::endl;
  lista.pop_back();
  std::cout<<"pop-back"<<std::endl;
  std::cout<<lista<<std::endl;
  lista.pop_front();
  std::cout<<"pop-front"<<std::endl;
  std::cout<<lista<<std::endl;
  std::cout<<"Testiranje iteratora"<<std::endl;
  for (auto it=lista.begin(); it!=lista.end(); it++){
      std::cout<<*it<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"insert"<<std::endl;
  lista.insert(lista.begin(), 45);
  std::cout<<lista<<std::endl;
  std::cout<<"erase"<<std::endl;
  auto iterator=lista.begin();
  std::cout<<*iterator<<std::endl;
  lista.erase(iterator);
  std::cout<<lista<<std::endl;
  std::cout<<"Push front 123"<<std::endl;
  lista.push_front(123);
  std::cout<<lista<<std::endl;
  auto predicate=[](int a){
  return a%2==0;
  };
  std::cout<<"Testiranje erasea"<<std::endl;
  List<int> lista1;
  lista1.push_back(1);
  lista1.push_back(2);
  lista1.push_back(3);
  std::cout<<lista1<<std::endl;
  auto iterator1=++(lista1.begin());
  std::cout<<"Iterator na drugom elementu"<<std::endl;
  lista1.erase(iterator1);
  std::cout<<lista1<<std::endl;
  List<int> lst;
  std::cout<<"Testiranje remove_if"<<std::endl;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);
  lst.push_back(5);
  std::cout<<lst<<std::endl;
  lst.remove_if(predicate);
  std::cout<<"Remove-if %2"<<std::endl;
  std::cout<<lst<<std::endl;
  std::cout<<"Reverse"<<std::endl;
  lst.reverse();
  std::cout<<lst<<std::endl;
  std::cout<<"Testiranje split-front, iterator na '3'"<<std::endl;
  List<int> lista2;
  auto i=0;
  while (i!=5)
  {
  lista2.push_back(i);
  i++;
  }
  std::cout<<"Prije:\n";
  std::cout<<lista2<<std::endl;
  auto pos=lista2.begin();
  for(auto i=0; i<3; i++)
    pos++;
  std::cout<<"Lista poslije splita: "<<std::endl;
  auto new_l=lista2.split_front(pos);
  std::cout<<new_l<<std::endl;
  std::cout<<"Originalna lista: "<<std::endl;
  std::cout<<lista2<<std::endl;
}
