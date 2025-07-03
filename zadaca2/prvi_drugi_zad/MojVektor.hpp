#include <initializer_list>
#include <iostream>
template<typename T>
class MojVektor {
  public:
  MojVektor() : size_(0), capacity(10), data(new T[capacity]) {} 
  MojVektor(const std::initializer_list<T>& x){
      size_=x.size();
      capacity=2*(x.size());
      data=new T[capacity];
      std::copy(x.begin(),x.end(),data);       
  } 
  MojVektor(const MojVektor& other) : size_(other.size_), capacity(other.capacity), data(new T[capacity])  
  { std::copy(other.data, other.data+size_, data);
  }
  MojVektor& operator=(const MojVektor& other){
     if (this==&other)
       return *this;
     delete[] data;
     size_=other.size_;
     capacity=other.capacity;
     data=new T[capacity];
     std::copy(other.data, other.data+size_, data);
     return *this;
  }
  MojVektor(MojVektor&& other){
      size_=other.size_;
      capacity=other.capacity;
      data=other.data;
      other.size_=0;
      other.capacity=0;
      other.data=nullptr;
  }
  MojVektor& operator=(MojVektor&& other){
    if (this!=&other){
        delete [] data;
        size_=other.size_;
        capacity=other.capacity;
        data=other.data;
        other.size_=0;
        other.capacity=0;
        other.data=nullptr;
        return *this;
    }
    else {
        return *this;
    }
      
  }
  MojVektor& push_back(const T& elem){
      if (capacity==size_){
        if (capacity==0){
        ++capacity;
        capacity=2*capacity;}
        else {
        capacity=2*capacity;
        }
        T* new_data=new T[capacity];
        for (auto i=0; i<size_; i++){
          new_data[i]=data[i];
        }
        new_data[size_++]=elem;
        delete [] data;
        data=new_data;

        return *this;
      }
      else {
        data[size_++]=elem;
        return *this;
      }

  }
  MojVektor& push_back(T&& elem){
      if (capacity==size_){
          if(capacity==0){
              ++capacity;
              capacity = capacity*5;
          }
          else {
              capacity = capacity*5;
          }
        T* new_data=new T[capacity];
        std::move(data,data+size_,new_data);
        delete[]data;
        data=new_data;
        data[size_++]=std::move(elem);
        return *this;
      }
      else {
        data[size_++]=std::move(elem);
        return *this;
      }
  }
  MojVektor& push_front(const T& elem){
    if (capacity==size_){
      if (capacity==0){
        ++capacity;
        capacity=capacity*5;
      }
      else {
        capacity=capacity*2;
      }
        T* new_data=new T[capacity];
        for (auto i=0; i<size_; i++){
          new_data[i+1]=data[i];  
        }
        new_data[0]=elem;
        delete[] data;
        data=new_data;
        size_++;
        return *this;
    }
    else {
        T* new_data=new T[capacity];
        for (auto i=0; i<size_; i++){
          new_data[i+1]=data[i];
        }
        new_data[0]=elem;
        delete[] data;
        data=new_data;
        size_++;
        return *this;
    }
  }
  MojVektor& push_front(T&& elem){
    if (capacity==size_){
      if (capacity==0){
        ++capacity;
        capacity=capacity*5;
      }
      else {
        capacity=capacity*2;
      }
        T* new_data=new T[capacity];
        for (auto i=0; i<size_; i++){
          new_data[i+1]=std::move(data[i]);  
        }
        new_data[0]=std::move(elem);
        delete[] data;
        data=new_data;
        size_++;
        return *this;
    }
    else {
        T* new_data=new T[capacity];
        for (auto i=0; i<size_; i++){
          new_data[i+1]=std::move(data[i]);
        }
        new_data[0]=std::move(elem);
        delete[] data;
        data=new_data;
        size_++;
        return *this;
    }

  }
  size_t size() const {
      return size_;
  }
  bool empty() const {
  return size_==0;
  }
  size_t capacity_() const{
    return capacity;
  }

  friend std::ostream& operator<<(std::ostream& out, const MojVektor<T>& niz){
        for (auto i=0; i<niz.size_; i++){
            std::cout<<niz.data[i]<<" ";
        }   
        return out;
    }
  T& at(size_t index){
      if(index>size_-1||index<0)
        throw std::out_of_range("Nevalidan indeks, greska!");
      return data[index];
    
  }
  const T& at(size_t index) const {
      if(index>size_-1||index<0)
        throw std::out_of_range("Nevalidan indeks, greska!");
      return data[index];
  }
  T& operator[](size_t index){
        return data[index];

  }
  const T& operator[](size_t index) const{
        return data[index];
  }
  void clear(){
    size_=0;
  }
  void resize(size_t newSize, const T& value){
      if (newSize<size_){
        T* new_data=new T[capacity];
        for (auto i=0; i<newSize; i++){
            new_data[i]=data[i];
        }
        delete[] data;
        data=new_data;

      }
      if (newSize>size_){
        for (auto i=size_-1; i<newSize; i++){
          data[i]=value;

        }
      
      }
  }
  MojVektor& pop_back(){
     size_--; 
     return *this;

  }
  MojVektor& pop_front(){
      T* new_data=new T[capacity];
      for (auto i=0; i<size_; i++){
        new_data[i]=data[i+1];
      }
      delete[] data;
      size_--;
      data=new_data;
      return *this;

  }
    T& front(){
      return data[0];

    }
    const T& front() const {
      return data[0];

    }
    T& back(){
      return data[size_-1];
    }
    const T& back() const{
      return data[size_-1];
    }
    bool operator==(const MojVektor& other) {
        if (size_!=other.size_)
          return false;
        for (auto i=0; i<size_; i++){
            if (data[i]!=other.data[i])
              return false;
        }
        return true;

    }
    bool operator!=(const MojVektor& other) {
        if (size_!=other.size_)
          return true;
        for (auto i=0; i<size_; i++){
            if (data[i]!=other.data[i])
              return true;
  
        }
        return false;

    }
    bool operator<(const MojVektor& other){
      return this->size_<other.size_;

    }
    bool full() const {
    return capacity==size_;
    }
  ~MojVektor(){
    delete [] data;
  }
  class Iterator;
      Iterator begin() const {
          return Iterator(data);
      }
      Iterator end() const {
        return Iterator(data+size_);
      }
      Iterator find(const T& value) const {
            for (auto i=0; i<size_; i++){
              if (data[i]==value)
                return data+i;
            }
            return data+size_;
      }

      void rotate(){

      T* new_data=new T[capacity];
      auto pos=0;
      for (int i=size_-1; i>=0; i--){
          new_data[pos++]=data[i];
      }
      delete[] data;
      data=new_data;

      }
      template <typename F> 
      void for_each(F f){
        for (auto i=0; i<size_; i++){
          data[i]=f(data[i]);

        }

      }
      Iterator insert(Iterator pos, const T& value){
          for (auto it=end()-1; it>=pos; it--){
              *(it+1)=*it;
          }
              size_++;
              *pos=value;
              return pos;
      }
      Iterator erase(Iterator beginIt, Iterator endIt) {
            for (auto it=beginIt; it!=endIt; it++){
                  *it=0;
            }
            auto num=0;
            auto index=0;
              T* new_data=new T[capacity];
              for (auto i=0; i<size_; i++){
                      if (data[i]==0){
                          num++;
                      }
                      else {
                      new_data[index]=data[i];
                      index++;
                      }
                  }
              size_=size_-num;
              return endIt;
      }
      template<typename Predicate>
      void remove_if(Predicate pred){
            size_t index=0;
        for (size_t i=0; i<size_; i++){
            if (!pred(data[i])){
                data[index++]=data[i];
            }
        }
        size_=index;
      }

      class Iterator{
      public:
      Iterator(T* pon): p(pon) {}    
      Iterator operator+(int n) const{
        return Iterator(p+n);
      }
      Iterator operator-(int n) const{
        return Iterator(p-n);
      }
      Iterator& operator++() {
          ++p;
          return *this;
      }
      Iterator operator++(int){ 
        auto temp=*this;
        ++p;
        return temp;
      }
      Iterator& operator--() {
          --p;
          return *this;
      }
      Iterator operator--(int) {
          auto temp=*this;
          --p;
          return temp;
      }
      bool operator!=(const Iterator& other){
        return p!=other.p;
      }
      bool operator==(const Iterator& other){
        return p==other.p;
      }
      bool operator>=(const Iterator& other) const {
          return this->p >= other.p;
      }
      bool operator<(const Iterator& other) const {
          return this->p<other.p;
      }
      T& operator*(){
          return *p;
      }
      using value_type=T;
      using difference_type=size_t;
      using pointer=T*;
      using reference=T&;
      using iterator_category=std::random_access_iterator_tag;
      private:
      T* p;
    }; 
     Iterator erase(Iterator pos){
        if (pos==end()) return pos;
        for (Iterator it=pos; it!=end(); it++){
              *it=*(it+1);
        }
        size_--;
        return pos;
      }
  private:
  size_t size_;
  size_t capacity;
  T* data;
};

   

