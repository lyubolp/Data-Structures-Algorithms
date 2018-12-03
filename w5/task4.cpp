#include <iostream>
#include <fstream>
#include <queue>
#include <vector>


int main()
{
    unsigned long long n, multi = 11;
    std::cin >> n;

    if(n > 10)
    {
        for(int i = 1; i < 10; i++)
        {
            std::cout << i << " ";
        }
        while(multi <= n)
        {
            if()
            std::cout << multi - 2 << " " << multi + 2 << " ";
            multi+=11;
        }

    }
    else
    {
        for(int i = 1; i < n; i++)
        {
            std::cout << i << " ";
        }
    }
    return 0;
}