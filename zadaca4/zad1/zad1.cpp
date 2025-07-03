#include <iostream>
#include "zad1.hpp"

int main() {
    Queue<int> q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Veličina reda: " << q.size() << std::endl;
    std::cout << "Prvi element: " << q.front() << std::endl;

    q.pop();
    std::cout << "Nakon jednog popa:\n";
    std::cout << "Prvi element: " << q.front() << std::endl;

    q.push(40);
    q.push(50);

    std::cout << "Elementi reda:\n";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    try {
        q.pop();
    } catch (const std::out_of_range& e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }

    try {
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
    } catch (const std::overflow_error& e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }

    return 0;
}

