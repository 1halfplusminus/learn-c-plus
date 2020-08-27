#include "std_lib_facilities.h"
#include "numeric"
#include "set"
#include "ratio"
#include <iomanip>

constexpr double cm_to_m = 0.01;
constexpr double in_to_m = 0.0254;
constexpr double ft_to_m = 0.3048;

void print_intro(ostream &stream)
{
    stream << "Enter two length (cm,m,ft,in) \n";
}
struct Input
{
public:
    double ratio = 0.0;
    double number = 0.0;
    bool valid = false;
    string unit = "";
    Input() {}
    Input(double number, string unit)
    {
        number = number;
        unit = unit;
    }
    const bool almostEqual(Input &a)
    {
        return abs(number - a.number) <= 1.0 / 100;
    }
    const double toMeter()
    {
        return number * ratio;
    }
    friend Input operator+(Input &a, Input &b)
    {
        Input res = {};
        if (b.valid && a.valid)
        {
            double valueInMeter = a.toMeter() + b.toMeter();
            res.ratio = a.ratio;
            res.unit = a.unit;
            res.number = valueInMeter * (1 / res.ratio);
        }
        return res;
    }
    friend const bool &operator<(Input &a, Input &b)
    {
        if (!b.valid)
        {
            return true;
        }
        if (a.valid)
        {
            return a.toMeter() < b.toMeter();
        }
        return false;
    }
    friend const bool &operator>(Input &a, Input &b)
    {
        if (!b.valid)
        {
            return true;
        }
        if (a.valid)
        {
            return a.toMeter() > b.toMeter();
        }
        return false;
    }
    friend const bool &operator==(Input &a, Input &b)
    {
        if (a.toMeter() == b.toMeter())
            return true;
        return false;
    }
    friend const double &operator-(Input &a, Input &b)
    {
        return a.number - b.number;
    }
    friend std::ostream &operator<<(std::ostream &out, Input a)
    {
        out << (string)a;
        return out;
    }

    explicit operator double() const
    {
        return number * ratio;
    }
    explicit operator bool() const
    {
        return valid;
    }
    explicit operator string() const
    {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << number;
        return stream.str() + unit;
    }
};
// program that read two int and write them
int main()
{
    const std::unordered_map<std::string, double> known_units = {
        {"m", 1.0},
        {"cm", cm_to_m},
        {"in", in_to_m},
        {"ft", ft_to_m}};
    const int inputPerLoop = 1;
    string input = "";
    Input smallest;
    Input greatest;
    vector<Input> numbers;
    print_intro(cout);
    while (getline(cin, input))
    {
        Input currentInput;
        string::size_type sz;
        string unit;
        input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
        try
        {
            currentInput.number = stod(input, &sz);
            string unit = input.substr(sz);
            auto it = known_units.find(unit);
            if (it != known_units.end())
            {
                currentInput.unit = it->first;
                currentInput.ratio = it->second;
                currentInput.valid = true;
                numbers.push_back(currentInput);
            }
            else
            {
                throw invalid_argument("invalid unit input");
            }
        }
        catch (invalid_argument e)
        {
            if (!all_of(input.begin(), input.end(), isspace))
            {
                cout << input << " Is not a valid input \n";
                print_intro(cout);
            }
            else
                break;
        }
        if (currentInput < smallest)
        {
            smallest = currentInput;
        }
        if (currentInput > greatest)
        {
            greatest = currentInput;
        }
    }
    if (numbers.size() > 0)
    {
        sort(numbers.begin(), numbers.end(), [](Input &a, Input &b) {
            return a < b;
        });
        string joined = accumulate(
            numbers.begin() + 1, numbers.end(), (string)numbers[0],
            [](const string &a, auto b) { return a + "," + (string)b; });
        Input sum = accumulate(
            numbers.begin() + 1, numbers.end(), numbers[0],
            [](Input &a, Input &b) { return b + a; });
        cout << "You have enter: "
             << joined << "\n";
        cout << "sum :" << sum << "\n";
        if (smallest)
        {
            cout << "smallest " << smallest << "\n";
        }
        if (greatest)
        {
            cout << "greatest " << greatest << "\n";
        }
    }
}