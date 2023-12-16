#include "basics.hpp"
#include <iostream>

using namespace std;

void mcppBasics02() {
  mcpp::fundamentalTypes();
  mcpp::conversionRules();
  mcpp::autoDecls();
  mcpp::operators();
}

void mcppBasics03() { mcpp::integralDataTypes(); }

int main() {
  mcppBasics03();

  auto res = 4 + 2;
  cout << "hello world " << res << endl;

  return 0;
}
