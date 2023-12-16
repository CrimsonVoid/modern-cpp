#include "basics.hpp"
#include <cstdint>
#include <iostream>

using namespace std;

void mcpp::integralDataTypes() {
  // five fundamental types: char, short, int, long, long long
  // four int*_t typedefs: int{8, 16, 32, 64}_t
  // io streams treat uint8_t and int8_t as char, not interger values
  int8_t v = '2';
  cout << v << ' ' << +v << '\n'; // print '2 50'
}
