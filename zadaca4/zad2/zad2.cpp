#include <iostream>
#include <string>
#include <stdexcept>
#include "zad2.hpp"

void test_basic_operations() {
    Stack<int> s;

    if (!s.empty() || s.size() != 0)
        std::cout << "test_basic_operations failed (initial state)\n";

    s.push(10);
    if (s.empty() || s.top() != 10 || s.size() != 1)
        std::cout << "test_basic_operations failed (after first push)\n";

    s.push(20);
    if (s.top() != 20 || s.size() != 2)
        std::cout << "test_basic_operations failed (after second push)\n";

    s.pop();
    if (s.top() != 10 || s.size() != 1)
        std::cout << "test_basic_operations failed (after first pop)\n";

    s.pop();
    if (!s.empty() || s.size() != 0)
        std::cout << "test_basic_operations failed (after second pop)\n";

    std::cout << "test_basic_operations passed\n";
}

void test_underflow() {
    Stack<int> s;
    bool caught = false;

    try {
        s.pop();
    } catch (const std::out_of_range& e) {
        caught = true;
    }
    if (!caught)
        std::cout << "test_underflow failed (pop)\n";

    caught = false;
    try {
        s.top();
    } catch (const std::out_of_range& e) {
        caught = true;
    }
    if (!caught)
        std::cout << "test_underflow failed (top)\n";

    std::cout << "test_underflow passed\n";
}

void test_overflow() {
    Stack<int> s(2);
    s.push(1);
    s.push(2);

    bool caught = false;
    try {
        s.push(3);
    } catch (const std::overflow_error& e) {
        caught = true;
    }
    if (!caught)
        std::cout << "test_overflow failed\n";

    std::cout << "test_overflow passed\n";
}

void test_with_strings() {
    Stack<std::string> s;
    s.push("hello");
    s.push("world");

    if (s.top() != "world")
        std::cout << "test_with_strings failed (top after push)\n";

    s.pop();
    if (s.top() != "hello")
        std::cout << "test_with_strings failed (top after pop)\n";

    std::cout << "test_with_strings passed\n";
}

int main() {
    test_basic_operations();
    test_underflow();
    test_overflow();
    test_with_strings();

    std::cout << "\nAll tests finished!\n";
    return 0;
}

