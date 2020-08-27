
#include "std_lib_facilities.h"

void read_answer(istream &in, bool &result)
{
    char input = {};
    in >> input;
    switch (input)
    {
    case 'y':
        result = true;
        break;
    case 'n':
        result = false;
        break;
    default:
        cout << "Please ! Enter y or n \n";
        read_answer(in, result);
        break;
    }
}
// guest number beetwen 0 and 100
int main()
{
    int number{0};

    //define range
    int upper{100};
    int lower{0};
    int range{upper - lower};

    int question{0};

    cout << "Please think of a number beetwen "
         << lower << " and " << upper << "\n";
    while (upper != lower)
    {
        range = upper - lower;
        if (range == 1)
            number = upper;
        else
            number = lower + range / 2;
        bool anwser{};
        if (question % 2 != 0)
        {
            cout << "Is your number greater than " << number << "?\n";
            read_answer(cin, anwser);
            if (!anwser)
            {
                upper = number;
            }
            else
            {
                lower = number - 1;
            }
        }
        else
        {
            cout << "Is your number lower that " << number << "?\n";
            read_answer(cin, anwser);
            if (anwser)
            {
                upper = number + 1;
            }
            else
            {
                lower = number;
            }
        }

        ++question;
        cout << "Lower " << lower << " Upper " << upper << "\n";
    }
    cout << "Find in " << question << " Number is : " << number << "\n";
}