// prompts the user to enter three integer values, and then outputs the values
// in numerical sequence separated by commas
#include "std_lib_facilities.h"
#include <numeric>

int main()
{
	vector<int> numbers_spellout(3);
	cin >> numbers_spellout[0] >> numbers_spellout[1] >> numbers_spellout[2];
	sort(numbers_spellout.begin(), numbers_spellout.end(),
		 [](const auto &lhs, const auto &rhs) { return lhs < rhs; });
	string imploded = accumulate(
		numbers_spellout.begin() + 1, numbers_spellout.end(), std::to_string(numbers_spellout[0]),
		[](const string &a, int b) { return a + ',' + std::to_string(b); });
	cout << imploded;
}