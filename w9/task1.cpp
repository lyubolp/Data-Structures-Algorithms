#include <iostream>
#include <vector>
#include <cmath>

int hashAlgo(long long num)
{
    return abs(((185432 * num + 1998) % 200003) % 200000);
}
int main()
{
    //-9223372036854775807 to 9223372036854775807
    int n, count = 0;
    long long a;
    
    std::cin >> n;
    std::vector<std::vector<long long>> arr;
    
    for(int i = 0; i < 200000; i++)
    {
		std::vector<long long> t;
		t.push_back(-1);
		arr.push_back(t);
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> a;
        int key = hashAlgo(a);

        if(arr[key][0] == -1) 
        {
            arr[key][0] = 1;
			arr[key].push_back(a);
            count++;
        }
		else
		{
			bool exists = false;
			for(int i = 1; i < arr[key].size(); i++)
			{
				if(arr[key][i] == a)
				{
					exists = true;
					i = arr[key].size();
					i +=10;
				} 
			}
			if(!exists)
			{
				arr[key].push_back(a);
				count++;
			}
		}    
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    std::cout << count;
    return 0;
}