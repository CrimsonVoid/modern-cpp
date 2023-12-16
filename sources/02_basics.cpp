#include "basics.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
// #include <stdfloat>

using namespace std;

void mcpp::fundamentalTypes() {
  // signed and unsigned types defined in cstdint
  bool b;
  char c;
  int8_t byte = 0b011;       // binary prefix 0b
  int16_t dbyte = 0600;      // octal prefix 0
  int32_t word = 0x00FF;     // hex prefix 0x
  int64_t dword = 1'000'000; // ' digit separator
  float f;                   // 32 bit float
  double d;                  // 64 bit float

  // decimal types defined in stdfloat (c++23)
  // bfloat16_t bf;
  // float16_t hf;
  // float32_t ff;
  // float64_t df;

  int* p1 = NULL;    // NULL macro 0l, defined in cstddef
  int* p2 = nullptr; // typeof(nullptr) == nullptr_t, prefered over NULL
}

void mcpp::conversionRules() {
  // implicit conversion rules applied in order, before any operation
  // @ := any operator: + - * / % etc
  //
  // a) fp promotion
  //    floatingType @ integralType -> floatingType
  //
  // b) integer promotion
  //    smallIntType := any (un)signed integral type smaller than int
  //    smallIntType @ smallIntType -> int
  //
  // c) size promotion
  //    smallType @ largeType -> largeType
  //
  // d) sign promotion
  //    signedType @ unsignedType -> unsignedType

  char a = 48;            // '0'
  cout << a << ' ';       // print '0'
  cout << +a << ' ';      // print 48
  cout << (a + 0) << ' '; // print 48
  cout << '\n';

  uint8_t a1 = 255, a2 = 255;
  cout << a1 + a2; // print 510 (no overflow)
  cout << '\n';
}

void mcpp::autoDecls() {
  auto a = 1 + 2;   // a is int
  auto b = 1 + 2.0; // double

  // function returns
  // auto g1(int x) -> int { return x * 2; }
  // auto g2(int x) -> decltype(x * 2) { return x * 2; } // c++11
  // auto g3(int x) { return x * 2; }                    // c++14

  // function parameters
  // void f(auto x) {} // like to templates but faster compile-time
  // f(3);   // x is int
  // f(3.0); // x is double
}

void mcpp::operators() {
  // operator precedence, left-to-right associativity unless noted otherwise
  //  1 | a++ a--           | postfix inc/dec
  //  2 | +a -a ++a --a ! ~ | prefix inc/dec, logical/bit not | right-to-left
  //  3 | a*b a/b a%b       | mul, div, mod
  //  4 | a+b a-b           | add, sub
  //  5 | <<  >>            | bitshift left/right
  //  6 | < <= > >=         | relational operators
  //  7 | == !=             | equality
  //  8 | &                 | bitwise and
  //  9 | ^                 | bitwise xor
  // 10 | |                 | bitwise or
  // 11 | &&                | bitwise and
  // 12 | ||                | bitwise or
  // 13 | { + - * / % << >> & ^ | }= | compound | right-to-left

  // operator precedences:
  //   unary ops
  //   standard math ops (+ * etc)
  //   bitshift
  //   comparison
  //   bitwise
  //   compound assignment
  //   comma

  // assignment associates right-to-left, exprs return the assigned value
  int g = 2;
  int h = g = 3; // g=3, then h=3; same as h = (g = 3)

  // comma oper associates left-to-right, evals left expr, discards its result,
  //   returns right expr
  int a = 5, b = 7;
  // int x = (3, 4); // discard 3, then x=4
  int y = 0, z;
  // z = y, x; // z=y (0), then returns x (4)

  // three way comparison operator <=>
  // returns pos, 0, or neg integer value (like strcmp)
  auto c1 = (3 <=> 5) == 0;     // false
  auto c2 = ('a' <=> 'a') == 0; // true
  auto c3 = (3 <=> 5) < 0;      // true
  auto c4 = (7 <=> 5) < 0;      // false

  // safe comparison operators, defined in <utility>
  // safely compare integers of different types (signed, unsigned)
  // bool cmp_equal(T1 a, T2 b);
  // cmp_not_equal, cmp_less, cmp_greater, cmp_less_equal, cmp_greater_equal
  unsigned n1 = 4;
  int n2 = -3;
  auto c5 = n1 < n2;             // false!!
  auto c6 = cmp_greater(n1, n2); // true
}
