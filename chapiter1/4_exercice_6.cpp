
#include "std_lib_facilities.h"

// spell out number
int main()
{
    unordered_map<string, string> spell_outs;
    vector<string> valid_numbers = {
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"};
    vector<string> numbers_spellout = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};
    std::for_each(valid_numbers.begin(), valid_numbers.end(), [idx = 0, &spell_outs, numbers_spellout](string i) mutable {
        spell_outs.insert({i, numbers_spellout[idx]});
        spell_outs.insert({numbers_spellout[idx], i});
        ++idx;
    });
    string input;
    cin >> input;
    cout << "Number is " << spell_outs[input];
}