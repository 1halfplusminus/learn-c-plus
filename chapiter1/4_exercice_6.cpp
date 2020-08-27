
#include "std_lib_facilities.h"

// spell out number
int main()
{
    unordered_map<string, string> spell_outs;
    vector<string> letters = {
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"};
    vector<string> words = {
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"};
    vector<string> values = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};
    std::for_each(letters.begin(), letters.end(), [idx = 0, &spell_outs, values](string i) mutable {
        spell_outs.insert({i, values[idx]});
        spell_outs.insert({values[idx], i});
        ++idx;
    });
    string input;
    cin >> input;
    cout << "Number is " << spell_outs[input];
}