#include <iostream>
#include <map>
#include <string>
#include "person.h"
using namespace std;

int main()
{
    map<string, Person*>* persons = new map<string, Person*>();
    persons->insert({"1001", new Person("Castro", "Fidel", {1900, 10, 15})});
    persons->insert({"1002", new Person("Lopez", "Jennifer", {1991, 6, 3})});
    persons->insert({"1009", new Person("Duck", "Donald", {1923, 4, 1})});
    persons->insert({"1013", new Person("Alster", "Ingrid", {1991, 6, 3})});

    cout << "Age of person with id Id 1009: " << (*persons)["1009"]->age() << "\n\n";

    for (const auto& p: *persons)
    {
        cout << "Id:         " << p.first << '\n';
        p.second->print();
        cout << '\n';
    }

    return 0;
}
