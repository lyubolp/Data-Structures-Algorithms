#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>


int main() {
    std::string s;

    getline(std::cin, s);

    int t[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int size = s.length();

    for(int i = 0; i < size; i++)
    {
        t[s[i] - 97]++;
    }

    int max = 0, maxIndex = -1;
    for(int i = 0; i < 27; i++)
    {
        if(t[i] > max)
        {
            max = t[i];
            maxIndex = i;
        }
    }
    if(max-1 <= s.length() - max)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    return 0;
}