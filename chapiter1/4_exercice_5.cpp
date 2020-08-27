
#include "std_lib_facilities.h"

// calculator
int main()
{
    string input{"Enter three arguments: two double operands and a character ('+','-','*','/') representing an operation (followed by 'Enter').\n"};

    cout << input;

    vector<double> operands(2);
    char myOperator = {};
    while (cin >> operands[0] >> myOperator >> operands[1])
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
        cout << input;
    }
}