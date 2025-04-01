#include <iostream>
using namespace std;

int main()
{
    int number1;
    int number2;

    cin >> number1 >> number2;      //stream operator   >> <<
    int sum = number1 + number2;
    cout << "sum=" << sum << '\n';

    return 0;
}