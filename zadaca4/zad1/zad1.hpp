#pragma once
#include <iostream>

template<typename T>
class Queue{
  public:
  Queue(int size=100) : capacity(size), front_index(0), rear_index(-1), size_(0) { 
    data=new T[capacity];
  }
  
  ~Queue(){
    delete[] data;
  }
  void push(const T& val){
    if (size_==capacity)
      throw std::overflow_error("Queue overflow");
    rear_index=(rear_index+1)%capacity;
    data[rear_index]=val;
    size_++;
  }
  void pop(){
    if (empty())
      throw std::out_of_range("Queue is empty");
    front_index=(front_index+1)%capacity;
    size_--;

  }
  T& front(){
    if (empty())
      throw std::out_of_range("Queue is empty");
    return data[front_index];
  }
  bool empty() const{
  return size_==0;
  }
  int size() const{
    return size_;
 }

  private:
  int size_;
  int capacity;
  int front_index;
  int rear_index;
  int* data;
};
