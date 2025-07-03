#include "big_int.hpp"
#include <iostream>
#include <limits>
#include <random>
#include <vector>

// Assume your bigInt class is already defined above or included
void runTestCase(long a, long b, int index) {
  bigint A(a);
  bigint B(b);
  std::cout << A << std::endl;
  std::cout << B << std::endl;
  bigint result = A + B;
  bigint expected(a + b);
  std::cout << result << std::endl;
  std::cout << "*********" << std::endl;

  if (!(result == expected)) {
    std::cout << "❌ Test failed at case " << index << ":\n";
    std::cout << "   a = " << a << "\n";
    std::cout << "   b = " << b << "\n";
    std::cout << "   Expected: " << (a + b) << "\n";
    std::cout << "   Got:      " << result << "\n";
  }
}

void testAddition() {
  std::vector<std::pair<long long, long long>> testCases = {
      {0, 0},
      {123, 0},
      {0, -456},
      {-123, 123}, // should be 0
      {999, 1},    // carry
      {-1, -999},  // negative carry
      {1000000, 1000000},
      {-1000000, -1000000},
      {std::numeric_limits<int>::max(), 1},
      {std::numeric_limits<int>::min(), -1},
      {std::numeric_limits<long long>::max() / 1000, 42},
      {std::numeric_limits<long long>::min() / 1000, -42},
      {9999999999LL, -9999999999LL}, // = 0
  };

  // Add random small values
  std::mt19937 gen(42); // fixed seed for reproducibility
  std::uniform_int_distribution<long long> dist(-10000, 10000);
  for (int i = 0; i < 5000; ++i) {
    testCases.push_back({dist(gen), dist(gen)});
  }

  int index = 1;
  for (const auto &[a, b] : testCases) {
    runTestCase(a, b, index++);
  }

  std::cout << "✅ Completed " << index - 1 << " test cases.\n";
}

int main() {
  testAddition();
  return 0;
}
