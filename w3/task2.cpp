#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

int binarySearch(std::vector<unsigned int>t, unsigned int l, unsigned int r, unsigned int x, bool minA)
{
    if(l > r) return -2;
    if(t[r] < x) return -2;

    if(minA == true)
    {
        int mid = (r+l) / 2;
        if(t[mid] == x && t[mid-1] != x) return mid;

        if(x > t[mid]) return binarySearch(t, mid+1, r, x, 1);
        else if(x < t[mid] || (x == t[mid] && x == t[mid-1])) return binarySearch(t, l, mid-1, x, 1);
        
    }
    else
    {
        int mid = (r+l) / 2; 
        if(t[mid] == x && t[mid+1] != x) return mid;

        if(x > t[mid] || (t[mid] == x&&(t[mid+1] == x))) return binarySearch(t, mid+1, r, x, 0);
        else if(x < t[mid]) return binarySearch(t, l, mid-1, x, 0);
    }
    return -2;
}
int main() {
    
    
    std::vector<unsigned int> arr;
    std::vector<unsigned int> queries;

    int n, q;

    std::cin >> n;

    unsigned int t;
    for(int i = 0; i < n; i++)
    {
        std::cin >> t;
        arr.push_back(t);
    }
    std::cin >> q;
    for(int i = 0; i < q; i++)
    {
        std::cin>>t;
        queries.push_back(t);
    }
   
    std::sort(arr.begin(), arr.end());

    
    for(int i = 0; i < q; i++)
    {
        std::cout << binarySearch(arr, 0 , arr.size() - 1, queries[i], 1) +1<< " " << binarySearch(arr, 0, arr.size() - 1, queries[i],0) +1 << std::endl;
    }


    return 0;
}
