#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>

/*struct dataItem
{
    std::stack<int> ball;
    int sum;

    dataItem& operator=(const dataItem& rhs)
    {
        ball = rhs.ball;
        sum = rhs.sum;
        return *this;
    }
};*/
struct node
{
    int val = 0;
    int top = 0;
    int input = 0;
    node* prev = nullptr;
    node* origin = nullptr;

    node& operator=(const node& rhs)
    {
        val = rhs.val;
        top = rhs.top;
        prev = rhs.prev;

        return *this;
    }
};

int main() {
    /*std::vector<dataItem> container;

    int n, p, m;

    std::cin >> n;


    dataItem temp;
    temp.ball.push(0);
    temp.sum = 0;

    container.push_back(temp);

    for(int i = 0; i < n; i++)
    {
        std::cin >> p;
        std::cin >> m;
        
        temp = container[p];
temp.sum+=m;
        if(m != 0)
        {
            temp.ball.push(m);
            temp.sum+=m;
        } 
        else
        {
            temp.sum -=temp.ball.top();
            temp.ball.pop();
        }
        container.push_back(temp);
    }

    long long r = 0;

    for(int i = 0; i <= n; i++)
    {
        
        r += container[i].sum;
    }

    std::cout << r;*/

    std::vector<node*> container;
    int n, p, m;

    std::cin >> n;

    node* tail = nullptr;

    node* temp = new node();
    temp->val = 0;
    temp->top = 0;
    temp->prev = nullptr;
    temp->origin = nullptr;

    tail = temp;
    container.push_back(temp);
    for(int i = 0; i < n; i++)
    {
        std::cin >> p;
        std::cin >> m;
        

        if(m != 0)
        {
            temp = new node();

            temp->origin = container[p];
            temp->input = m;
            temp->top = m; 
            temp->val = container[p]->top + container[p]->val;
            temp->prev = tail;
        } 
        else
        {
            temp = new node();
            
            node* temp2 = new node();

            temp->input = 0;
            
            if(container[p]->input != 0) //Problem is here
            {   
                temp->origin = container[p]->origin;
                temp->top = container[p]->origin->top;
                temp->val = container[p]->origin->val;
                temp->prev = tail;
            }
            else
            {
                temp2 = container[p]->origin;

                while(temp2->input == 0) temp2 = temp2->origin;    
                
                temp->origin = temp2->origin;
                temp->top = temp2->origin->top;
                temp->val = temp2->origin->val;
                temp->prev = tail;
            }
        }
        container.push_back(temp);
    }

    long long r = 0;

    for(int i = 0; i <= n; i++)
    {
        r += container[i]->val + container[i]->top;
    }

    std::cout << r;


    return 0;
}