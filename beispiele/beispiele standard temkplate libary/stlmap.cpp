#include <exception>
#include <iostream>
#include <string>
#include <map>

void print(const std::map<std::string, std::string>& pnames)
{
    std::cout << "names: ";
    for (const auto& n: pnames)
        std::cout << n.first << ':' << n.second << ' ';
    std::cout << '\n';
}

int main()
{
    std::map<std::string, std::string> names;            // constructor
    print(names);

    names.insert(std::make_pair("Bernd", "28.02.2000")); // insert key/value pair
    print(names);
    names.insert(std::make_pair("Bernd", "30.02.2002")); // insert key/value pair
    print(names);
    names.insert(std::make_pair("Anna", "01.03.2002"));  // insert key/value pair
    print(names);
    names.erase("Bernd");                                // delete key/value pair
    print(names);
    names.erase("Bernd");                                // delete key/value pair
    print(names);
    std::cout << "read:  " << names["Anna"] << '\n';     // read value
    std::cout << "read:  " << names["Bernd"] << '\n';    // read value
    print(names);

    try
    {
        std::cout << names.at("Caro") << '\n';           // read value
    }
    catch (std::out_of_range& error)
    {
        std::cout << "read:  " << error.what() << '\n';
    }

    names["Anna"] = "30.03.2002";                        // change value
    print(names);
    names["Caro"] = "01.03.2002";                        // change value
    print(names);

    return 0;
}
