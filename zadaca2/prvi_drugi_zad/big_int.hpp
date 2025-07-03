#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
class bigint {
  public:
bigint()=default;
bigint(long int x) {
  negative= (x<0);
  if (negative){
    x=-x;
  }
  for (auto i=0; i<x; i++){
    int cifra=x%10;
    x=x/10;
    numbers.push_back(cifra);
  }
  if (x!=0)
    numbers.push_back(x);
  std::reverse(numbers.begin(),numbers.end());
}
bigint(const std::string& word){
  if (word.at(0)=='-'){
    negative=1;
    for (auto i=1; i<word.size(); i++){
        int temp=word.at(i)-'0';
        numbers.push_back(temp);

    }
  }
  else {
      for (auto i=0; i<word.size(); i++){
          int temp=word.at(i) - '0';
          numbers.push_back(temp);
     }
  }
  }
bigint(const char* p){
    auto num=strlen(p);
    if (p[0]=='-'){
    for (auto i=1; i<num; i++){
        int temp=p[i]-'0';
        numbers.push_back(temp);
    }
    }
    else {
    for (auto i=0; i<num; i++){
      int temp=p[i]-'0';
      numbers.push_back(temp);
    }
    }
}
// 54
// 67
//121
bigint add(bigint& first, bigint& second){
    bigint novi;
    auto max = std::max(first.numbers.size(), second.numbers.size());
    auto min = std::min(first.numbers.size(), second.numbers.size());
    auto ostatak = 0;

    for (auto i = 0; i < max; i++) {
        int digit1 = (i < first.numbers.size()) ? first.numbers[first.numbers.size() - 1 - i] : 0;
        int digit2 = (i < second.numbers.size()) ? second.numbers[second.numbers.size() - 1 - i] : 0;

        auto zbir = digit1 + digit2 + ostatak;
        novi.numbers.push_back(zbir % 10);
        ostatak = zbir / 10;
    }

    if (ostatak > 0) {
        novi.numbers.push_back(ostatak);
    }
    while (novi.numbers.back()==0){
            novi.numbers.pop_back();
    }

    std::reverse(novi.numbers.begin(), novi.numbers.end());
    return novi;
}
bigint operator-(bigint& other) {
    if (other.negative) {
        other.negative = false;
        bigint res = *this + other;
        other.negative = true;
        return res;
    }

    if (this->negative) {
        bigint temp = *this;
        temp.negative = false;
        bigint res = temp + other;
        res.negative = true;
        return res;
    }

    if (*this < other) {
        bigint res = other - *this;
        res.negative = true;
        return res;
    }

    bigint result;
    int borrow = 0;

    int i1 = (int)this->numbers.size() - 1;
    int i2 = (int)other.numbers.size() - 1;
//  17
//   8
//   9

    while (i1 >= 0 || i2 >= 0) {
        int digit1 = (i1 >= 0) ? this->numbers[i1] : 0;
        int digit2 = (i2 >= 0) ? other.numbers[i2] : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.numbers.insert(result.numbers.begin(), diff);
        i1--; i2--;
    }

    while (result.numbers.size() > 1 && result.numbers[0] == 0)
        result.numbers.erase(result.numbers.begin());

    return result;
}

// operator-
// %
// /
//  300
//   35
//  265 
//
// -12+5
// 5-12
//
bigint operator+(bigint& other){
  if (!this->negative&&!other.negative){
  return add(*this, other);
  }
  if (this->negative&&!other.negative){
      this->negative=false;
      bigint novi=other-*this;
      return novi;
  }
  if (!this->negative&&other.negative){
    other.negative=false;
    bigint novi=*this-other;
      return novi;
  }
  else {
      bigint novi=add(*this, other);
      novi.negative=true;
      return novi;
  }
}
bigint& operator++(){
      auto pos=this->numbers.begin();
      auto index=this->numbers.size();
      if(this->numbers.at(index-1)==9){
        auto i=1;
      while (this->numbers.at(index-i)==9){
          this->numbers.at(index-i)=0;
          ++i;
          this->numbers.at(index-i)++;
          if (this->numbers.at(index-i)==*pos){
            numbers.insert(pos, 0);
          }
          if (this->numbers.at(index-i)==10)
            this->numbers.at(index-i)=9;
      }
      }
      else {
        this->numbers.at(index-1)++;
      }
      std::reverse(this->numbers.begin(),this->numbers.end());
      if (this->numbers.back()==0){
        this->numbers.pop_back();
      }
      std::reverse(this->numbers.begin(),this->numbers.end());
      return *this;
}
bigint operator++(int){
      auto temp=*this;
      auto pos=this->numbers.begin();
      auto index=this->numbers.size();
      if(this->numbers.at(index-1)==9){
        auto i=1;
      while (this->numbers.at(index-i)==9){
          this->numbers.at(index-i)=0;
          ++i;
          this->numbers.at(index-i)++;
          if (this->numbers.at(index-i)==*pos){
            numbers.insert(pos, 0);
          }
          if (this->numbers.at(index-i)==10)
            this->numbers.at(index-i)=9;
      }
      }
      else {
        this->numbers.at(index-1)++;
      }
      return temp;
}

//  900
//  100
// 1000
// 20*13
// 
bigint operator*(bigint& other){

  auto sum=0;
  auto number=0;
  bigint suma;
  if (this->negative && !other.negative){
    suma.negative=true;
  }
  if (!this->negative && other.negative){
    suma.negative=true;
  }
  if (this->negative && other.negative){
    suma.negative=false;
  }
  for (int i=other.numbers.size()-1; i>=0; i--){
    number=0;
      std::vector<int> clan;
      for (int j=this->numbers.size()-1; j>=0; j--){
            clan.push_back(other.numbers.at(i)*this->numbers.at(j));
      }
      std::reverse(clan.begin(),clan.end());
      if (i!=other.numbers.size()-1){
      for (size_t k=0; k<(other.numbers.size()-1-i); k++)
        clan.push_back(0);

      }
      
      for (int digit : clan){
        number = number * 10 + digit;
        }
      sum += number;

            
  }
    suma=sum;
    return suma;


}
bigint operator/(bigint& other) {
    if (other.numbers.size()==1 && other.numbers.at(0)==0) {
        throw std::runtime_error("Dijeljenje sa nulom nije dozvoljeno.");
    }
     bigint result;
     if (this->negative && !other.negative){
    result.negative=true;
  }
  if (!this->negative && other.negative){
    result.negative=true;
  }
  if (this->negative && other.negative){
    result.negative=false;
  }
   
    bigint remainder;

    for (int i=0; i<this->numbers.size(); i++)
    {
      remainder.numbers.push_back(this->numbers[i]);

      int q=0;
      while (remainder>=other){
        remainder=remainder-other;
        q++;
      }
      result.numbers.push_back(q);
    } 
    while (result.numbers.size()>1 && result.numbers.front() == 0)
    {
      result.numbers.erase(result.numbers.begin());
    }

    return result;
}
bigint operator%(bigint& other){
  bigint div=*this/other;
  bigint ful=div*other;
  bigint result=*this-ful;
  return result;
}


bool operator==(bigint& other){
      if (this->numbers.size()!=other.numbers.size())
        return false;
      for (auto it=0; it<numbers.size(); it++){
            if(numbers.at(it)!=other.numbers.at(it)) return false; 
      }
      return true;
}
bool operator !=(bigint& other){
      if (this->numbers.size()!=other.numbers.size())
        return true;
      for (auto it=0; it<numbers.size(); it++){
            if(numbers.at(it)!=other.numbers.at(it)) return true;
      }
      return false;
}
bool operator<(bigint& other){
  if (this->negative && !other.negative)
    return true;
  if (!this->negative && other.negative){
    return false;  
  }
  if (this->negative && other.negative){
        if (this->numbers.size()>other.numbers.size()){
              return true;
        }
        if (this->numbers.size()<other.numbers.size()){
              return false;
        }
        for (auto i=0; i<this->numbers.size(); i++){
          if (numbers[i]>other.numbers[i])
            return true;
          else if(numbers[i]<other.numbers[i])
            return false;

        }
        return false;
    }
  if  (this->numbers.size()<other.numbers.size()){
    return true;}
  if  (this->numbers.size()>other.numbers.size()){
    return false;}
    for (auto i=0; i<numbers.size(); i++){
          if (numbers[i]<other.numbers[i])
            return true;
          else if(numbers[i]>other.numbers[i])
            return false;
    }
          return false;


}
bool operator>(bigint& other){
  if (this->negative && !other.negative)
    return false;
  if (!this->negative && other.negative){
    return true;  
  }
  if (this->negative && other.negative){
        if (this->numbers.size()>other.numbers.size()){
              return false;
        }
        if (this->numbers.size()<other.numbers.size()){
              return true;
        }
        for (auto i=0; i<this->numbers.size(); i++){
          if (numbers[i]>other.numbers[i])
            return false;
          else if(numbers[i]<other.numbers[i])
            return true;

        }
        return false;
    }
  if  (this->numbers.size()<other.numbers.size()){
    return false;}
  if  (this->numbers.size()>other.numbers.size()){
    return true;}
    for (auto i=0; i<numbers.size(); i++){
          if (numbers[i]<other.numbers[i])
            return false;
          else if(numbers[i]>other.numbers[i])
            return true;
    }
          return false;
}

bool operator>=(bigint& other)  {
    return (*this>other) || (*this==other);
}
bool operator<=(bigint& other) {
    return (*this<other) || (*this==other);
}


//    
friend std::ostream& operator<<(std::ostream& out, bigint& niz){
  if(niz.negative){
    out<<"-";
  }
    for  (auto it=niz.numbers.begin(); it!=niz.numbers.end(); it++){
            out<<*it;
    }
    return out;

  }
friend std::istream& operator>>(std::istream& in, bigint& niz) {
    std::string input;
    in >> input;

    niz.numbers.clear();
    niz.negative = false;

    if (input.empty()) return in;

    size_t i = 0;
    if (input[0] == '-') {
        niz.negative = true;
        i = 1;
    }

    for (; i < input.size(); ++i) {
        if (!std::isdigit(input[i])) {
            niz.numbers.clear();
            niz.numbers.push_back(0);
            niz.negative = false;
            return in;
        }
        niz.numbers.push_back(input[i] - '0');
    }

    while (niz.numbers.size() > 1 && niz.numbers[0] == 0) {
        niz.numbers.erase(niz.numbers.begin());
    }

    return in;
}




private:
  std::vector<int> numbers;
  bool negative=0;
};
// 12345
