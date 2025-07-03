#pragma once
#include <iostream>

template<typename V, typename K>
class map{
  public:

  private:
    struct Node {
      K key;
      V value;
      Node* left;
      Node* right;

      Node (const K& k, const V& v= V{}) : key(k), value(v), left(nullptr), right(nullptr) {};
    };
    Node* root;
    size_t count;
    
    void copyTree(Node*& thisNode, Node* otherNode){
      if (!otherNode) return;
      thisNode = new Node(otherNode->key, otherNode->value);
      copyTree(thisNode->left, otherNode->left);
      copyTree(thisNode->right, otherNode->right);
    }

    void deleteTree(Node* node) {
      if (!node) return;
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }

    Node* findNode(Node* node, const K& key) const {
      if (!node) return nullptr;
      if (key==node->key) return node;
      if (key<node->key) return findNode(node->left, key);
      return findNode(node->right, key);
    }
     Node*& findNodeRef(Node* node, const K& key) const {
      if (!node) return nullptr;
      if (key==node->key) return node;
      if (key<node->key) return findNodeRef(node->left, key);
      return findNodeRef(node->right, key);
    }
   
    Node*& findOrCreateNode(Node*& node, const K& key) {
      if (!node) {
        ++count;
        node=new Node(key);
        return node;
      }
      if (key<node->key) return findOrCreateNode(node->left, key);
      if (key>node->key) return findOrCreateNode(node->right, key);
      return node;

    }
    Node* minNode(Node* node){
      while (node && node->left)
        node=node->left;
      return node;
    }

    Node* eraseNode(Node* node, const K& key, bool erased){
      if (!node) return nullptr;
    if (key < node->key) {
            node->left = eraseNode(node->left, key, erased);
        } else if (key > node->key) {
            node->right = eraseNode(node->right, key, erased);
        } else {
            erased = true;
            --count;
            if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            } else if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            } else {
                Node* successor = minNode(node->right);
                node->key = successor->key;
                node->value = successor->value;
                bool d = false;
                node->right = eraseNode(node->right, successor->key, d);
            }
        }
        return node;
    }
    public:
    map() : root(nullptr), count(0) {}
    
    map(const map& other): root(nullptr), count(0) {
      copyTree(root, other.root);
      count=other.count;
    }
    map(map&& other) : root(other.root), count(other.count) {
        other.root = nullptr;
        other.count = 0;
    }

    map& operator=(const map& other) {
        if (this != &other) {
            clear();
            copyTree(root, other.root);
            count = other.count;
        }
        return *this;
    }

    map& operator=(map&& other) {
        if (this != &other) {
            clear();
            root = other.root;
            count = other.count;
            other.root = nullptr;
            other.count = 0;
        }
        return *this;
    }

    ~map() {
        clear();
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    V& at(const K& key) {
        Node* n = findNode(root, key);
        if (!n) throw std::out_of_range("Key not found");
        return n->value;
    }

    const V& at(const K& key) const {
        Node* n = findNode(root, key);
        if (!n) throw std::out_of_range("Key not found");
        return n->value;
    }

    V* find(const K& key) {
        Node* n = findNode(root, key);
        return n ? &(n->value) : nullptr;
    }

    const V* find(const K& key) const {
        Node* n = findNode(root, key);
        return n ? &(n->value) : nullptr;
    }

    V& operator[](const K& key) {
        Node*& n = findOrCreateNode(root, key);
        return n->value;
    }

    template <typename F>
    void insert(const K& key, F&& value) {
        Node*& n = findNodeRef(root, key);
        if (n) throw std::runtime_error("Key already exists");
        n = new Node(key, std::forward<F>(value));
        ++count;
    }

    bool erase(const K& key) {
        bool erased = false;
        root = eraseNode(root, key, erased);
        return erased;
    }

    void clear() {
        deleteTree(root);
        root = nullptr;
        count = 0;
    }
};

