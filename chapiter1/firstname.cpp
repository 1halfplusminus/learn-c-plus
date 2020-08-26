// Read and write a first name
#include "std_lib_facilities.h"

int main()
{
    string first_name{""}, friend_name{""};
    cout << "Enter the name of the person you want to write to \n";
    cin >> first_name;
    cout << "How are you ? I am fine. I miss you. \n";
    cout << "Enter the name of a friend \n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately ?";
    char friend_sex;
    do
    {
        cout << "\nEnter friend sex (m or f) \n";
        cin >> friend_sex;
    } while (friend_sex != 'm' && friend_sex != 'f');
    if (friend_sex == 'm')
    {
        cout << "\nIf you see " << friend_name << " please ask him to call me. \n";
    }
    if (friend_sex == 'f')
    {
        cout << "\nIf you see " << friend_name << " please ask her to call me. \n";
    }
    cout << "\nEnter friend age \n";
    int friend_age;
    cin >> friend_age;
    if (friend_age <= 100)
    {
        cout << "I hear you just had a birthday and you are " << friend_age << " years old.\n";
        if (friend_age < 12)
        {
            cout << "Next year you will be " << friend_age + 1 << ".\n";
        }
        if (friend_age == 17)
        {
            cout << "Next year you will be able to vote.\n";
        }
        if (friend_age > 70)
        {
            cout << "I hope you are enjoying retirement.\n";
        }
        cout << "Yours sincerely. \n\n"
             << first_name;
    }
    else
    {
        simple_error("you're kidding!");
    }
}