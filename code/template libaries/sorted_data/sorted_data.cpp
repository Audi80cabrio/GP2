#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> data;
    int n;
    std::cin >> n;

    while (n >= 0) 
    {
        auto iter = data.begin();                   //iteratior to the beginning of the vector
        while (iter != data.end() && *iter < n) 
        {
            iter++;                                 //increment the iterator until it finds the right position
            if (iter == data.end()) 
            {
                data.push_back(n);                  //if the iterator reaches the end, push the number to the end of the vector
            }
            else 
            {
                data.insert(iter, n);               //insert the number at the iterator positiond
            }
            for (int i: data)                       //i hat für jeden durchlauf den jeweiligen wert von data
            {
                std::cout << i << ' ';              //print the vector
                std::cout << '\n';                  //print a new line
            } 
        }
    }
}