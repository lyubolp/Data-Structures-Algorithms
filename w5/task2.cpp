#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>

int main() {
    std::stack<int> c;
    int n, k;
    std::string s;

    std::cin >> n;


    for(int i = 0; i < n; i++)
    {
        std::cin >> s;
        std::cin >> k;

        if(s == "white")
        {
            c.push(k);
        }
        else if(s == "green")
        {
            int sum = 0;
            if(k > c.size()) k = c.size();
            for(int j = 0; j < k; j++)
            {
                sum+= c.top();
                c.pop();
            }
            c.push(sum);
        }
        else if(s == "blue")
        {
            int max = c.top();
            if(k > c.size()) k = c.size();
            for(int j = 0; j < k; j++)
            {
                if(c.top() > max) max = c.top();
                c.pop();
            }
            c.push(max);
        }
    }
    int size = c.size();
    std::stack<int> result;
    for(int i = 0; i < size; i++)
    {
        result.push(c.top());
        c.pop();
    }
    for(int i = 0; i < size; i++)
    {
        std::cout << result.top() << " ";
        result.pop();
    }
    
    return 0;
}