#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

struct node
{
    int value;
    node* next;
};

int main() {

    int n, count = 1;
    std::cin >> n;

    node* head = new node;
    node* tail = new node;

    head->next = nullptr;
    head->value = -1;

    tail->next = nullptr;
    tail->value = -1;

    node* temp = new node;

    temp->next = nullptr;
    temp->value = 1;
    head = temp;
    tail = temp;

    for(int i = 3; i < n; i+=2)
    {
        temp = new node;
        temp->next = nullptr;
        temp->value = i;

        tail->next = temp;
        tail = temp;

        count++;
    }
    tail->next = head;

    temp = head;
    node* kill = temp->next;
    while(count != 1)
    {
        temp->next = kill->next;
        
        if(kill == tail)
        {
            tail = temp;
        }
        if(kill == head)
        {
            head = temp;
        }
        temp = kill->next;
        kill = temp->next;

        count--;
    }
    std::cout << head->value;

    return 0;
}