#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include <string>


std::string convert(std::string input)
{
    std::string r = "";
    int posToInsert = 0;
    int sr = 0;
    int s = input.length();

    int count = 0;
    for(int i = 0; i < s; i++)
    {
        if(input[i] == '[' ||  input[i] == ']')
        {
            count++;
        }
    }
    
    for(int i = 0; i < s; i++)
    {
        if(input[i] == '[')
        {
            if(input[i+1] != ']')
            {
                posToInsert = 0;
            }
            else
            {
                i+=1;
            }
            
        }
        else if(input[i] == ']')
        {
            sr = r.length();
            posToInsert = sr;
        }
        else
        {
            r.insert(posToInsert,std::string(1,input[i]));
            posToInsert++;
        }
    }
    
    return r;
}
int main() {
    int q;

    std::cin >> q;

    std::string s;
    std::vector<std::string> texts;

    for(int i = 0; i < q; i++)
    {
        std::cin >> s;
        texts.push_back(s);
    }

    for(int i = 0; i < q; i++)
    {
        s = texts[i];
        s = convert(s);
        std::cout << s << std::endl;
    }

    return 0;
}