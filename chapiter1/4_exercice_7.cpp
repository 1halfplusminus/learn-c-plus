
#include "std_lib_facilities.h"
#include "set"

const vector<string> valid_numbers = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9"};

const vector<string> numbers_spellout = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"};

const std::set<string> valid_operators = {
    "+",
    "-"};

void prompt_operand(ostream &out)
{
    out << "Enter a number between 0-9 (digit or spellout) \n";
}
void prompt_operator(ostream &out)
{
    out << "Enter a operation (+,-,/,*) \n";
}

bool get_spellout_value(string spelloutOrDigit, int &value)
{
    unordered_map<string, string> spell_outs;
    std::for_each(valid_numbers.begin(), valid_numbers.end(), [idx = 0, &spell_outs](string i) mutable {
        spell_outs.insert({i, i});
        spell_outs.insert({numbers_spellout[idx], i});
        ++idx;
    });
    if (spell_outs.find(spelloutOrDigit) != spell_outs.end())
    {
        value = stoi(spell_outs[spelloutOrDigit]);
        return true;
    }
    return false;
}

bool read_operator_input(istream &in, ostream &out, char &inputOperator)
{
    string rawInput;
    cin >> rawInput;
    auto it = valid_operators.find(rawInput);
    bool goodOperator = it != valid_operators.end();
    if (!goodOperator)
    {
        read_operator_input(in, out, inputOperator);
    }
    inputOperator = it->begin()[0];
    return goodOperator;
}
bool read_operand_input(istream &in, ostream &out, int &input)
{
    string rawInput;
    cin >> rawInput;
    bool goodValue = get_spellout_value(rawInput, input);
    if (!goodValue)
    {
        read_operand_input(in, out, input);
    }
    return goodValue;
}
void calcule_show_result(ostream &cout, const vector<int> &operands, const char &myOperator)
{
    switch (myOperator)
    {
    case '+':
        cout << "The sum of " << operands[0] << " " << myOperator << " " << operands[1]
             << " is " << operands[0] + operands[1] << "\n";
        break;
    case '-':
        cout << "The difference of " << operands[0] << " " << myOperator << " " << operands[1]
             << " is " << operands[0] - operands[1] << "\n";
        break;
    default:
        cout << "Unkown operation: " << myOperator << "\n";
        break;
    }
}
// calculator
int main()
{

    vector<int> operands(2);
    char myOperator = {};
    // read first operand
    prompt_operand(cout);
    read_operand_input(cin, cout, operands[0]);
    // read operator
    prompt_operator(cout);
    read_operator_input(cin, cout, myOperator);
    // read second operand
    prompt_operand(cout);
    read_operand_input(cin, cout, operands[1]);
    //show result
    calcule_show_result(cout, operands, myOperator);
    return 0;
}