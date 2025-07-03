#include <iostream>
#include <stdexcept>
#include <string>

class Duration{
  public:
  Duration() : s(0), m(0), h(0) {}
  Duration(int x) {
    if (x<60){
      s=x;
    }
    if (x>=60 && x<3600){
      m=x/60;
      s=x%60;
    }
    if (x>=3600){
      h=x/3600;
      int temp=x%3600;
      m=temp/60;
      s=temp%60;
    }
  }
  Duration(int a, int b, int c) : h(a), m(b), s(c) {
    if (c>59){
    throw std::out_of_range("Greska u konstrukciji. ");
    }
    else if(m>59){
    throw std::out_of_range("Greska u konstrukciji. ");
    }


  }
  Duration(std::string x) {
    int korak=0;
    std::string num="";
    for (auto i=0; i<x.size(); i++){
    if (x.at(i)==':'&&korak==0){
      h=std::stoi(num);
      num="";
      korak++;
    }
    else if (x.at(i)==':'&&korak==1){
      m=std::stoi(num);
      num="";
    }
    else {
    num+= x.at(i);
    }


  }
    s=std::stoi(num);
  }
  Duration& set_s(int x){
    if (x>59){
      throw std::out_of_range("Error!");
    }
    else {
    this->s=x;
    return *this;
    }
  }
  Duration& set_m(int x){
    if (x>59){
      throw std::out_of_range("Error!");
    }
    else {
    this->m=x;
    return *this;
    }
  }
  Duration& set_h(int x){
    this->h=x;
    return *this;
  }
  int get_s(){
  return s;
  }
  int get_m(){
    return m;
  }
  int get_h(){
    return h;
  }
  bool operator==(const Duration& other){
    return ((*this).h==other.h && (*this).m==other.m && (*this).s==other.s);

  }
  bool operator !=(const Duration& other){
    return (!((*this).h==other.h && (*this).m==other.m && (*this).s==other.s));
  }
  bool operator >(const Duration& other){
    return ((*this).h>=other.h && (*this).m>=other.m && (*this).s>other.s);
  }

  explicit operator bool() const {
      return (h!=0||m!=0||s!=0);
  }
  bool operator!() const {
      return (h==0&&m==0&&s==0);
  }
  friend std::ostream& operator<<(std::ostream& out, Duration& d){
      out<<d.get_h()<<":"<<d.get_m()<<":"<<d.get_s()<<std::endl;
      return out;
        

  }  
  private:
    int s;
    int m;
    int h;

};
