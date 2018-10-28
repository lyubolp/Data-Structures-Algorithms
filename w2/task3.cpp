#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>


void merge(std::vector<int>& arr, int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;

    std::vector<int> L;
    std::vector<int> R;

    for(i = 0 ; i < n1; i++)
        L.push_back(arr[l + i]);

    for(j = 0; j < n2; j++)
        R.push_back(arr[m + 1 + j]);
        
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
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

void mergeSort(std::vector<int>& arr, int l, int r)
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
    std::vector<int> c;
    int n, k;

    std::cin>>n;
    std::cin>>k;

    int t;
    for(int i = 0; i<n; i++)
    {
        std::cin>>t;
        c.push_back(t);
    }
    mergeSort(c, 0, n-1);
    std::reverse(c.begin(),c.end());

    int sum = 0, sumC = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(sum + c[i] <= k)
        {
            sum += c[i];
            sumC++;
        } 
    }
    std::cout << sumC;
    return 0;

}
