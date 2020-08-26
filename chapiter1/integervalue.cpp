// prompts the user to enter three integer values, and then outputs the values
// in numerical sequence separated by commas
#include "std_lib_facilities.h"
#include <numeric>

int main() {
  vector<int> values(3);
  cin >> values[0] >> values[1] >> values[2];
  sort(values.begin(), values.end(),
       [](const auto &lhs, const auto &rhs) { return lhs < rhs; });
  string imploded = accumulate(
      values.begin() + 1, values.end(), std::to_string(values[0]),
      [](const string &a, int b) { return a + ',' + std::to_string(b); });
  cout << imploded;
}