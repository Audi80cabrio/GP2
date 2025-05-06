#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& pnames)
{
    std::cout << "names: ";
    for (const auto& n: pnames)
        std::cout << n << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<std::string> names(4, "noname");    // constructor
    print(names);

    std::cout << "size:  " << names.size() << '\n'; // size of vector
    std::cout << "empty: " << names.empty() << '\n';// is vector empty?

    names.insert(names.begin()+1, "Bernd");         // insert element
    print(names);
    names[0] = "Anna";                              // change element
    print(names);
    names.at(2) = "Caro";                           // change element
    print(names);
    names.back() = "Daniel";                        // last element
    print(names);
    names.push_back("Elisa");                       // add element
    print(names);
    names.erase(names.end()-3);                     // delete element
    print(names);

    return 0;
}
