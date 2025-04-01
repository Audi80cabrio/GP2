#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "Hello World";
    cout << s << '\n';
    cout << s[0] << '\n';
    s[0] = 'X';
    cout << s.at(0) << '\n';
    cout << s.length() << '\n';
    string t = s;
    cout << t + " Again" << '\n';
    cout << s.find("World") << '\n';
    s.replace(s.find("World"), s.length(), "THI");
    cout << s;
}