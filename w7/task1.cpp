#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>

struct node
{
    int data;
    node* left;
    node* right;

    
    node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
void insert(node* root, int val)
{
    if(root->left == nullptr && val < root->data)
    {
        root->left = new node(val);
        return;
    }
    else if(root->right == nullptr && val >= root->data)
    {
        root->right = new node(val);
        return;
    }
    if(val >= root->data) insert(root->right, val);
    else insert(root->left, val);
    
}
int height(node* root)
{
    if(root == nullptr) return -1;

    int left = height(root->left);
    int right = height(root->right);

    if(left > right) return 1 + left;
    else return 1 + right;
}
std::pair<int,int> sum;


std::pair<int,int> printLevel(node* root, int level)
{
    if(root == nullptr) return std::pair<int,int>(-1,0);
    
    if(level == 1) 
    {
        sum.first+= root->data;
        sum.second++;
    }
    else if(level > 1)
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
    return sum;
    
}
int main() {

    int n, t;

    //n = 50;
    //t = 30000;
    std::cin >> n;
    std::cin >> t;
    node* root = new node(t);

    node* last = root;
    

    std::queue<node*> toAdd;

    toAdd.push(last);
    /*for(int i = 1; i < n; i++)
    {
        std::cin >> t;
        
        if(last->left != nullptr && last->right != nullptr)
        {   
            toAdd.pop();
            last = toAdd.front();
            
        }
        if(t >= last->data) 
        {
            last->right = new node(t);
            //last->right = new node(i);
            toAdd.push(last->right);
        }
        else
        {
            last->left = new node(t);
            //last->left = new node(i);
            toAdd.push(last->left);
        } 
    }*/


    for(int i = 1; i < n; i++)
    {
        std::cin >> t;
        insert(root, t);
    }

    int h = height(root);

    sum.first = 0;
    sum.second = 0;
    double res = 0;
    for(int i = 1; i <= h+1; i++) 
    {
        res = (double)printLevel(root, i).first / (double)((printLevel(root, i).second/2));
        std::cout << std::setprecision(2) << std::fixed<< res;
        sum.first = 0;
        sum.second = 0;
        std::cout << std::endl;
    }



    return 0;
}