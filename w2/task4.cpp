#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long sum = 0;
struct entry
{
    unsigned long long value;
    int pos;
    void operator=(const entry& rhs)
    {
        value = rhs.value;
        pos = rhs.pos;
    }
};
struct query
{
    int n;
    std::vector<entry> inputs;
};

void merge(std::vector<entry>& arr, int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;

    std::vector<entry> L;
    std::vector<entry> R;

    for(i = 0 ; i < n1; i++)
        L.push_back(arr[l + i]);

    for(j = 0; j < n2; j++)
        R.push_back(arr[m + 1 + j]);
        
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if(L[i].value <= R[j].value)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            sum+= L.size() - i;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}   

void mergeSort(std::vector<entry>& arr, int l, int r)
{
    if(l < r)
    {
        int m = l+(r-l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    
    unsigned long long q;
    std::vector<query> c;

    std::cin >> q;

    unsigned long long nt;
    for(unsigned long long i = 0; i < q; i++)
    {

        query t;
        std::cin >> t.n;
        for(unsigned long long j = 0; j < t.n; j++)
        {
           entry nt2;
           nt2.pos = j;
           std::cin >> nt2.value;
           t.inputs.push_back(nt2); 
        }
        c.push_back(t);
    }

    for(unsigned long long i = 0; i < q; i++)
    {
        mergeSort(c[i].inputs, 0, c[i].inputs.size() - 1);
        std::cout << sum<< std::endl;
        sum = 0;
    }

        
    return 0;
}