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
int main() {
    std::ios_base::sync_with_stdio(false);
   
    node* head = new node;
    node* tail = new node;

    //int num;
    //std::cin>>num;

    node* temp = new node;

    temp->value = 10000;
    head = temp;
    tail = temp;


    /*while(std::cin>>num)
    {
        temp = new node();
        
        temp->value = num;
        temp->next = nullptr;
        temp->prev = tail;

        tail->next = temp;
        tail = temp;
    }*/

    for(int i = 1; i <= 100000000; i++)
    {
        temp = new node;
        
        temp->value = 10000;
        temp->next = nullptr;
        temp->prev = tail;

        tail->next = temp;
        tail = temp;
    }
    temp = head;
    
    

    int min = 10001;
    int max = 0;
    long long sum = 0;
    

    while(temp->next != nullptr)
    {
        if(min > temp->value) min = temp->value;
        if(max < temp->value) max = temp->value;
        sum += temp->value;
        temp = temp->next;
    }
    
    if(min > temp->value) min = temp->value;
    if(max < temp->value) max = temp->value;
    sum += temp->value;

    std::cout << min << " " << max << " " << sum;
    
    return 0;
}