#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>

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
    
    node* head = new node();
    node* tail = new node();
    node* mid = new node();
    int count = 0;

    std::string command;
    int n;

    std::cin >> n;

    int val = 0;
    int swap = 0;

    std::cin >> command;
    std::cin >> val;

    node* temp = new node();
    if(command == "add")
    {
        temp->value = val;
        temp->prev = nullptr;
        temp->next = nullptr;
    }
    head = temp;
    tail = temp;
    mid = temp;
    count++;

    for(int i = 1; i < n; i++)
    {
        std::cin>>command;

        if(command == "add")
        {
            if(count != 0)
            {
                std::cin>>val;

                temp = new node();

                temp->value = val;
                temp->next = nullptr;
                temp->prev = tail;

                tail->next = temp;
                tail = temp;
            
                count++;

                if(count % 2 == 1)
                {
                    mid = mid->next;
                }
            }
            else
            {
                std::cin>>val;

                temp = new node();
                
                temp->value = val;
                temp->prev = nullptr;
                temp->next = nullptr;
                
                head = temp;
                tail = temp;
                mid = temp;
                count++;
            }
        }
        else if(command == "gun")
        {
            if(count != 1)
            {
                temp = tail;
                tail = tail->prev;
                head->prev = nullptr;      
                tail->next = nullptr;
            
                count--;

                if(count % 2 == 0)
                {
                    mid = mid->prev;
                }
            }
            else
            {
                //Should clear head, tail and mid
                head->prev = nullptr;
                head->next = nullptr;
                
                tail->prev = nullptr;
                tail->next = nullptr;
                
                mid->prev = nullptr;
                mid->next = nullptr;
                
                count--;
            }
            
        }
        else if(command == "milen")
        {
            if(head != mid)
            {
                if(count % 2 == 0)
                {
                    mid = mid->next;
                }
            
                temp = tail;

                tail->next = head;
                head->prev = tail;

                head = mid;
                tail = head->prev;
                mid = temp;

                head->prev = nullptr;      
                tail->next = nullptr;   
            }
            else
            {
                temp = head;
                tail->next = head;
                head->prev = tail;

                head = tail;
                tail = temp;

                mid = head;
                head->prev = nullptr;
                tail->next = nullptr;
            }
        }
    }
    
    std::cout << count << std::endl;
    
    if(count == 0) std::cout << 0;
    else
    {
        temp = head;
        while(temp->next != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << temp->value << " ";

    }
    
    return 0;
}