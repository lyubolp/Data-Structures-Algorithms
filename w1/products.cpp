#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> products;
    int n, k;

    std::cin>>n;
    std::cin>>k;

    int t = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin>>t;
        products.push_back(t);
    }

    std::sort(products.begin(), products.end());
    std::reverse(products.begin(), products.end());
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if((i+1) % k != 0) 
        {
            sum += products.at(i);
        }
    }

    std::cout << sum;
    return 0;
}