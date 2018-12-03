#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

bool canDry(std::vector<long long> v, long long n, long long k, long long t)
{
    long long q = 0, s = 0;
    for(int i = 0; i < n; i++)
    {
        q = v[i] - t;
        if(q >= 0)
        {
            if(q % (k-1) == 0)s += q/(k-1);
            else s += (q/(k-1)) + 1;
        } 
    }

    return (s <= t);

}
int check(std::vector<long long> v, long long n, long long k, long long min, long long max)
{
    if(min >= max) return min;

    long long t = (max + min) / 2;
    
    if(canDry(v,n,k,t)) return check(v,n,k,min, t);
    else return check(v,n,k,t+1, max);
}
int main() {
    long long n = 90000, k = 12345;

    std::vector<long long> v;
    long long t;
    
    std::cin >> n;
    std::cin >> k;

    for(long long i = 0; i < n; i++)
    {
        std::cin >> t;
        v.push_back(t);
    }

    if(k == 1)
    {
        int max = v[0];
        for(int i = 0; i < n; i++)
        {
            if(max < v[i]) max = v[i];
        }
        std::cout << max;
    }
    else
    {
        long long d = 1000000000;
        std::cout << check(v,n,k,0,d)<< std::endl;
    }

    

    return 0;
}
