#include <iostream>
template<typename T>
class List {
  public:

    List(): head_(nullptr), tail_(nullptr), size(0) {}
    List(const List& other){
    auto temp=other.head_;
    while (temp!=nullptr){
      push_back(temp->element);
      temp=temp->naredni;
    }

    }
    List(List&& other): head_(other.head_), tail_(other.tail_), size(other.size){
      other.tail_=other.head_=0;
      other.size=0;
    }
    List& operator=(const List& other){
      if (this!=&other){
        empty();
        auto temp=other.head_;
        while (temp!=nullptr){
          push_back(temp->element);
          temp=temp->naredni;
        }
      }
      return *this;
    }
    List& operator=(List&& other){
        if (this!=&other){
        head_=other.head_;
        tail_=other.tail_;
        size=other.size;
        other.head_=0;
        other.size=0;
        other.tail_=0;
        }  
        return *this;
    }
    void push_back(const T& elem){
        auto temp=new Node(elem);
        if (size==0)
          tail_=head_=temp;
        else {
        tail_->naredni=temp;
        temp->prethodni=tail_;
        tail_=temp;
       }
        tail_->naredni=nullptr;
        size++;
    }
 void push_back(T&& elem){
        auto temp=new Node(std::move(elem));
        if (size==0)
          tail_=head_=temp;
        else {
        tail_->naredni=temp;
        temp->prethodni=tail_;
        tail_=temp;
       }
        tail_->naredni=nullptr;
        size++;
    }
    void push_front(const T& elem){
        auto temp=new Node(elem);
        if (size==0)
        tail_=head_=temp;
        else {
        auto next=head_;
        head_=temp;
        head_->naredni=next;
        }
        size++;
    }
void push_front(const T&&(elem)){
        auto temp=new Node(std::move(elem));
        if (size==0)
        tail_=head_=temp;
        else {
        auto next=head_;
        head_=temp;
        head_->naredni=next;
        }
        size++;
    }
    void pop_back() {
      auto new_tail=tail_->prethodni;
      auto tail_previous=tail_->prethodni->prethodni;
      delete tail_;
      tail_=new_tail;
      tail_->prethodni=tail_previous;
      tail_->naredni=nullptr;
      size--;
    }
    class iterator;
    void pop_front() {
      if (head_==nullptr) return;
      auto to_delete=head_;
      if (head_->naredni) {
      head_=head_->naredni;
      head_->prethodni=nullptr;
      }
      else {
        head_=tail_=nullptr;
      }
      delete to_delete;
      size--;
    }

    void empty() {
     while (head_!=nullptr){
        auto temp=head_;
        head_=head_->naredni;
        delete temp;
      }
    tail_=nullptr;
    size=0;
    }
    T front() {
    return head_->element;
    }
    T back() {
    return tail_->element;
    }
    T front() const{
    return head_->element;
    }
    T back() const{
    return tail_->element;
    }
    bool empty() const {
    return size==0;
    }

    ~List() {
      while (head_!=nullptr){
        auto temp=head_;
        head_=head_->naredni;
        delete temp;
      }
    }
    size_t getsize() {
    return size;
    }
    friend std::ostream& operator<<(std::ostream& out, List<T> l){
      while (l.head_!=nullptr){
        auto temp=l.head_;
        out<<temp->element<<" ";
        l.head_=l.head_->naredni;
      }
      return out;
    }
    iterator begin() {
      return iterator{head_};
    }
    iterator end() {
      return iterator{nullptr};
    }
    void insert(iterator position, const T& element);
    void insert(iterator position, T&& element);
    void erase(iterator position);
    List<T> split_front(iterator position);
    template<typename Predicate>
    void remove_if(Predicate pred){
      auto it=begin();
      while (it!=end()){
      if (pred(*it)){
        auto temp=it;
        ++it;
        erase(temp);
      }
      else {
        ++it;
      }

      }
    }
    void reverse(){
      auto temp=head_;
      auto temp2=tail_;
      while (temp!=nullptr){
        temp2=temp->naredni;
        temp->naredni=temp->prethodni;
        temp->prethodni=temp2;
        temp=temp2;
      }
      temp=head_;
      head_=tail_;
      tail_=temp;
    }
  private:
  template<typename U>
  struct Node{
    U element;
    Node* prethodni;
    Node* naredni;
    Node()=default;
    Node(const U& e, Node* ptr1=nullptr, Node* ptr2=nullptr) : element(e), prethodni(ptr1), naredni(ptr2) {}
    Node(T&& elem, Node* ptr1=nullptr, Node* ptr2=nullptr) : element(std::move(elem)), prethodni(ptr1), naredni(ptr2) {}
  };
  Node<T>* head_;
  Node<T>* tail_;
  size_t size=0;
};

template<typename T>
class List<T>::iterator {
  public:
    using iterator_category= std::bidirectional_iterator_tag;
    using value_type= T;
    using pointer= T*;
    using reference= T&;
    using difference_type= long int;
    iterator(Node<T>* p) : p_(p) {}
    friend List<T>;
    T& operator*() {
    return p_->element;
    }
    T* operator->() {
    return &p_->element;
    }
    iterator& operator++() {
      if (p_)
        p_=p_->naredni;
      return *this;
    }
    iterator operator++(int) {
      auto temp=*this;
      if (p_)
        p_=p_->naredni;
      return temp;
    }
    iterator& operator--() {
      if (p_->prethodni)
        p_=p_->prethodni;
      return *this;
    }
    iterator operator--(int) {
      auto temp=*this;
      if (p_->prethodni)
        p_=p_->prethodni;
      return temp;

    }
    bool operator==(const iterator& other){
      return p_==other.p_;
    }
    bool operator!=(const iterator& other){
      return p_!=other.p_;
    }

  private:
  Node<T>* p_;
};

template<typename T>
List<T> List<T>::split_front(iterator position){
  List<T> nova_lista;
  nova_lista.head_=this->head_;
  auto it=this->head_;
  while (it->naredni!=position.p_){
    it=it->naredni;
  }
  it->naredni=nullptr;
  nova_lista.tail_=position.p_->prethodni;
  nova_lista.tail_->naredni=nullptr;
  nova_lista.head_->prethodni=nullptr;
  this->head_=position.p_;
  this->head_->prethodni=nullptr;

  return nova_lista;
}

template<typename T>
void List<T>::insert(iterator position, T&& element) {
  auto temp=new Node<T>{std::move(element), position.p_->prethodni, position.p_->naredni};
  if (position.p_->naredni){
    position.p_->naredni->prethodni=temp;
  }
  position.p_->naredni=temp;
  std::swap(position.p_->element, temp->element);
  ++size;
}
template<typename T>
void List<T>::insert(iterator position, const T& element) {
  auto temp=new Node<T>{element, position.p_->prethodni, position.p_->naredni};
  if (position.p_->naredni){
    position.p_->naredni->prethodni=temp;
  }
  position.p_->naredni=temp;
  std::swap(position.p_->element, temp->element);
  ++size;
}
template<typename T>
void List<T>::erase(iterator position) {
    if (position == end()) return;
    if (position.p_ == head_) {
        auto temp = head_->naredni;
        delete head_;
        head_ = temp;
        if (head_) {
            head_->prethodni = nullptr;
        } else {
            tail_ = nullptr; // Ako je lista sada prazna
        }
    } else if (position.p_ == tail_) {
        auto temp = tail_;
        tail_ = tail_->prethodni;
        if (tail_) {
            tail_->naredni = nullptr;
        } else {
            head_ = nullptr; // Ako je lista sada prazna
        }
        delete temp;
    } else {
        position.p_->prethodni->naredni = position.p_->naredni;
        if (position.p_->naredni) {
            position.p_->naredni->prethodni = position.p_->prethodni;
        }
        delete position.p_;
    }
    --size;
}



