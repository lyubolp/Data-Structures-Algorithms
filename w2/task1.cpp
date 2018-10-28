#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

bool isGreater(std::string a, std::string b)
{
    int sa = a.length(), sb = b.length();
    double ai = std::stod(a), bi = std::stod(b);
    
    if(ai == bi) return false;
    if(sa > sb)
    {
        ai = ai / (pow(10,sb));
        bi += bi/ (pow(10,sb));
    }
    else if(sa < sb)
    {
        bi = bi / (pow(10, sa));
        ai += ai/ (pow(10,sa));
    }

    /*if(sa != 1)
    {
        ai = ai / (pow(10,sa-1));
    }
    else
    {
        ai += ai/10;
    }

    if(sb != 1)
    {
        bi = bi / (pow(10, sb-1));
    }
    else
    {
        bi += bi/10;
    }*/

    std::cout << a << " " << b << " " << ai << " " << bi << std::endl;

    if(ai == bi)
    { 
        return (sa < sb);
    }
    return ai>bi;
}

std::string removeZero(std::string c)
{
    if(c == "0") return c;
    bool flag = true;
    for(int i = 0; i < c.length(); i++)
    {
        if((c[i] - '0') != 0)
        {
            flag = false;
            break;
        }   
    }
    if(flag) return "0";
    while(c[0] - '0' == 0)
    {
        c = c.substr(1);
    }
    return c;
}
int main() {

    int n = 0;

    std::cin>>n;

    std::string t;
    std::vector<std::string> container;
    
    for(int i = 0; i < n; i++)
    {
        std::cin>>t;
        t = removeZero(t);
        container.push_back(t);
    }

    std::string swap;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(isGreater(container[j+1], container[j]))
            {
                swap = container[j];
                container[j] = container[j+1];
                container[j+1] = swap;
            }
        }
    }
    bool onlyZero = true;
    for(int i = 0; i < n; i++)
    {
        if(container[i] != "0") onlyZero = false;
        if(!onlyZero) std::cout<<container[i];
    }
    if(onlyZero) std::cout << "0";

    //std::cout << isGreater(std::to_string(1020), std::to_string(102));
    return 0;
}