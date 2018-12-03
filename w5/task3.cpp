#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

struct node
{
    bool wall;
    bool visited;
    int path;
};
struct cord
{
    int x;
    int y;  
};

void wave(std::queue<cord> start, int left, node** matrix, int m, int n)
{
    while(!start.empty())
    {
        int initSize = start.size();
        cord temp, newCord;
        int value;
        int currentLeft = left;
        
    
        while(initSize > 0)
        {
            temp = start.front();        
            start.pop();

            if(matrix[temp.x][temp.y].wall == true) matrix[temp.x][temp.y].path = -2;

            value = matrix[temp.x][temp.y].path;
            matrix[temp.x][temp.y].visited = true;
            
            if(temp.x + 1 < m && matrix[temp.x + 1][temp.y].visited == false && matrix[temp.x + 1][temp.y].wall == false) //Move right
            {
                newCord.x = temp.x + 1;
                newCord.y = temp.y;
                start.push(newCord);
                matrix[newCord.x][newCord.y].visited = true;
                matrix[newCord.x][newCord.y].path = value + 1;
                currentLeft--;
            }
            if(temp.x > 0 && matrix[temp.x - 1][temp.y].visited == false && matrix[temp.x - 1][temp.y].wall == false ) //Move left
            {
                newCord.x = temp.x - 1;
                newCord.y = temp.y;
                start.push(newCord);
                matrix[newCord.x][newCord.y].path = value + 1;
                matrix[newCord.x][newCord.y].visited = true;
                currentLeft--;
            }
            if(temp.y > 0 && matrix[temp.x][temp.y - 1].visited == false && matrix[temp.x][temp.y - 1].wall == false ) //Move up
            {
                newCord.x = temp.x;
                newCord.y = temp.y - 1;
                start.push(newCord);
                matrix[newCord.x][newCord.y].path = value + 1;
                matrix[newCord.x][newCord.y].visited = true;    
                currentLeft--;
            }
            if(temp.y + 1 < n && matrix[temp.x][temp.y + 1].visited == false && matrix[temp.x][temp.y + 1].wall == false) //Move down
            {
                newCord.x = temp.x;
                newCord.y = temp.y + 1;
                start.push(newCord);
                matrix[newCord.x][newCord.y].path = value + 1;
                matrix[newCord.x][newCord.y].visited = true;
                currentLeft--;
            }
            initSize--;
        }
    }
    
}

int main()
{
    std::vector<cord> cords;
    int m, n, k, walls = 0;
    std::cin>>m>>n>>k;

    node** matrix = new node*[m];
    for(int i = 0; i < m; i++)
    {
        matrix[i] = new node[n];
    }

    int input;
    node temp;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin>>input;
            if(input == 0)
            {  
                temp.wall = false;
                temp.visited = false;
                temp.path = -1;
            }
            else if(input == 1)
            {
                temp.wall = true;
                temp.visited = false;
                walls++;
                temp.path = -1;
            }
            matrix[i][j] = temp;
        }
    }

    cord t;
    for(int i = 0; i < k; i++)
    {
        std::cin >> input;
        t.x = input;
        std::cin >> input;
        t.y = input;
        cords.push_back(t);
    }

    node tmp;
    
    t.x = 0;
    t.y = 0;
    std::queue<cord> q;
    q.push(t);

    matrix[0][0].path = 0;
    wave(q,(m*n)-walls-1, matrix, m,n);

    for(int i = 0; i < k; i++)
    {
        if(matrix[cords[i].x][cords[i].y].wall == true) std::cout << -1 << std::endl;
        else std::cout << matrix[cords[i].x][cords[i].y].path << std::endl;
       
    }
    return 0;
}
