#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

struct node
{
    int value;
    node* next;
    node* prev;

    node()
    {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }
};
bool containsBoth(int c[], int e1, int e2)
{
    return (c[e1] == 1 && c[e2] == 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int sec[1235] = {0};
    
    node* head = new node();
    node* tail = new node();

    int n,p;
    std::cin >> n;
    
    int num;
    std::cin>>num;

    node* temp = new node;

    temp->value = num;
    head = temp;
    tail = temp;


    for(int i = 1; i < n; i++)
    {
        std::cin>>num;
        temp = new node();
        
        temp->value = num;
        temp->next = nullptr;
        temp->prev = tail;

        tail->next = temp;
        tail = temp;
    }
    
    temp = head;
    
    std::cin>>p;

    for(int i = 0; i < p; i++)
    {
        std::cin >> num;
        if(num < 1235) sec[num] = 1;
    }
    long long r = 0;

    if(temp->next != nullptr)
    {
        if(containsBoth(sec,temp->value, temp->next->value)) r++;
        temp = temp->next;
    }
    for(int i = 1; i < n-1; i++)
    {
        if(!(temp->next->value == temp->prev->value))
        {
            if(containsBoth(sec,temp->value, temp->next->value)) r++;
        }
        temp = temp->next;
    }

    std::cout << r;
    
    return 0;
}