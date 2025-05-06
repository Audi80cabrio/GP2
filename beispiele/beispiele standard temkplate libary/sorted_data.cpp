#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;
    int number;

    cout << "input integers until < 0:\n";
    cin >> number;

    while (number >= 0)
    {
        // add number
        auto iter = data.begin();

        while (iter != data.end() && *iter < number)
            iter++;

        data.insert(iter, number);

        // print data
        cout << "data: ";
        iter = data.begin();

        while (iter != data.end())
        {
            cout << *iter << ' ';
            iter++;
        }

        cout << '\n';

        // input next number
        cin >> number;
   }

    return 0;
}
