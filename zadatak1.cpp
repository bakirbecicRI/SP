#include <iostream>

using namespace std;

class MojaLista {
public:
  struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
  };

  MojaLista() : head(nullptr), tail(nullptr) {}

  void push_front(int val) { // ovo treba napisat, ko sa zadace
    Node *newNode = new Node(val);
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void drop(int n) { // treba napisat, uklanja prvih n elemenata i dealocira
                     // cvorove, pop front zapravo
    while (n != 0) {
      Node *temp = head;
      head = head->next;
      head->prev = nullptr;
      delete temp;
      --n;
    }
  }
  void drop_back(int n) { // treba napisat, uklanja zadnjih n elemenata i
                          // dealocira cvorove, pop back zapravo
    while (n != 0) {
      Node *temp = tail->prev;
      delete tail;
      tail = temp;
      tail->next = nullptr;
      --n;
    }
  }

  void push_back(int val) { // ovo se dobije napisano
    Node *newNode = new Node(val);
    if (!tail) {
      head = tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void print_reverse(
      std::ostream
          &os) { // treba napisat, printa u rikverc, ako treba unaprijed samo
                 // umjesto tail stavis head i umjesto prev stavis next
    Node *temp = tail;
    while (temp != nullptr) {
      os << temp->data << " ";
      temp = temp->prev;
    }
    os << endl;
  }

private:
  Node *head;
  Node *tail;
};

int main() {
  MojaLista lista;

  lista.push_front(2);
  lista.push_front(1);
  lista.push_back(3);
  lista.push_back(4);

  lista.print_reverse(std::cout); // Ispis: 4 3 2 1

  lista.drop(2);
  lista.print_reverse(std::cout); // Ispis: 4 3
  lista.push_front(7);
  lista.push_front(2);
  lista.push_front(1);
  lista.print_reverse(std::cout); // Ispis: 4 3 7 2 1
  lista.drop_back(3);
  lista.print_reverse(std::cout); // Ispis: 2 1

  // umjesto brojeva u njega u listi su bili stringovi, al sve je isto

  return 0;
}
