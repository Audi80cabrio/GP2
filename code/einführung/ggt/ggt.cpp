#include <iostream>
using namespace std;

int num1;
int num2;

int gcd(int a, int b)
{
    while(a != b){
    if (a<b)
    {
        b = b - a;
    }
    if (b<a)
        a = a - b;
    }
        return a;
}

int main()
{
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    cout << gcd(num1, num2);
    return 0;
}