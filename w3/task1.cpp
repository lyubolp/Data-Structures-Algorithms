#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

int main() {

    int t;
    std::vector<int> tests;
    
    std::cin  >> t;
    int temp;
    for(int i = 0; i < t; i++)
    {
        std::cin >> temp;
        tests.push_back(temp);
    }
    int c = 0, r = 0;
    for(int i = 0; i < t; i++)
    {
        c = tests[i];
        r = 0;
        while(c != 0)
        {
            c = c /2;
            r++;
        }
        std::cout << r << std::endl;
    }
    return 0;
}