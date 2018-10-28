#include <iostream>
#include <cstring>

void printNumbers(int arr[])
{
    for(int i = 0; i < 26; i++)
    {
        std::cout<<arr[i];
    }
}
int main() {
    
    std::string a, b;
    
    std::getline(std::cin,a);
    std::getline(std::cin,b);

    int lettersInA[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, lettersInB[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int lettersInRes[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int sa = a.length(), sb = b.length();
    
    for(int i = 0; i < sa; i++)
    {
        lettersInA[(int)a[i] - 97]++; 
    }
    for(int i = 0; i < sb; i++)
    {
        lettersInB[(int)b[i] - 97]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(lettersInA[i] != 0 && lettersInB[i] != 0)
        {
            if(lettersInA[i] < lettersInB[i]) lettersInRes[i] = lettersInA[i];
            else lettersInRes[i] = lettersInB[i];
        }
    }

    printNumbers(lettersInA);
    std::cout << "\n";
    printNumbers(lettersInB);
    std::cout << "\n";
    printNumbers(lettersInRes);
    std::cout << "\n";
    
    for(int i = 0; i < 26; i++)
    {
        if(lettersInRes[i] != 0) 
        {
            for(int j = 0; j < lettersInRes[i]; j++) std::cout<<(char)(i+96);
        }
    }
    return 0;
}