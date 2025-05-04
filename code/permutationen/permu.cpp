#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    int n = 3;
    std::vector<int> indices;
    // füllen von indices mit 0, 1, 2, ..., n-1
    for (int i = 0; i < n; ++i) {
        indices.push_back(i);
    }
    while (next_permutation(indices.begin(), indices.end())) {
        // Hier können Sie die Permutation verwenden
        for (auto i : indices) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}