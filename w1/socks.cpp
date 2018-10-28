#include <iostream>
#include <vector>
#include <algorithm>

struct sockPair
{
    int sock1Length;
    int sock2Length;
    int diff;
    bool operator<(const sockPair&);
};

bool sockPair::operator <(const sockPair& rhs)
{
    if(diff < rhs.diff) return true;
    else if(diff == rhs.diff)
    {
        if(sock1Length > sock2Length)
        {
            if(sock2Length < rhs.sock1Length || sock2Length < rhs.sock2Length) return true;
            else return false;
        }
        else
        {
            if(sock2Length < rhs.sock1Length || sock2Length < rhs.sock2Length) return true;
            else return false;
        }
    }
    else return false;
}
int main() {
    std::vector<int> socks;
    std::vector<sockPair> pairs;

    int n, k;
    
    std::cin>>n;
    std::cin>>k;

    int temp = 0;

    for(int i = 0; i < n; i++)
    {
        std::cin>>temp;
        socks.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            sockPair t;
            t.sock1Length = socks[i];
            t.sock2Length = socks[j];
            t.diff = t.sock2Length - t.sock1Length; 

            pairs.push_back(t);
        }
    }

    int s = pairs.size();
    /*sockPair swap;
    for(int i = 0; i < s-1; i++)
    {
        for(int j = 0; j < s - 1 - i; j++)
        {
            if(pairs[j].diff > pairs[j+1].diff)
            {
                swap = pairs[j];
                pairs
            }
        }
    }*/
    
    std::sort(pairs.begin(), pairs.end());
    
    
    std::cout << pairs[k-1].sock1Length << " " << pairs[k-1].sock2Length;

    return 0;
}