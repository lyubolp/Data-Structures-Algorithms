#include <bits/stdc++.h>

using namespace std;

const long long inf = 2000000000;

void shortestReach(int n, vector<vector<int>> &edges, int s)
{
    std::vector<std::vector<std::pair<int, long long>>> adjacencyList;

    for (int i = 0; i <= n; i++)
    {
        adjacencyList.push_back(std::vector<std::pair<int, long long>>());
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int firstIndex = edges[i][0];
        int secondIndex = edges[i][1];
        long long weight = edges[i][2];

        adjacencyList[firstIndex].push_back({secondIndex, weight});
        adjacencyList[secondIndex].push_back({firstIndex, weight});
    }

    bool *visited = new bool[n + 1];
    long long *dist = new long long[n + 1];


        
            std::priority_queue<std::pair<int, long long>, std::vector<std::pair<int, long long>>, greater<std::pair<int, long long>>> q;
            for (int i = 1; i <= n; i++)
            {
                visited[i] = false;
                dist[i] = inf;
            }
            dist[s] = 0;
            q.push({0, s});

            while (!q.empty())
            {
                std::pair<long long, int> currentNode = q.top();
                q.pop();
                
                if(visited[currentNode.second])
                    continue;
                
                visited[currentNode.second] = true;
 
                for(auto v: adjacencyList[currentNode.second])
                {
                  
                    int nodeGo = v.first;
                    long long weightGo = v.second;
                        
                    long long altL = dist[currentNode.second] + weightGo;
                        
                    if(dist[nodeGo] > altL)
                    {
                        dist[nodeGo] = altL;
                        q.push({altL, nodeGo});
                    }
                    
                }
            }
            for(int i = 1; i <= n; i++)
            {
                if (dist[i] == inf && i != s)
                    std::cout << "-1 ";
                else if (i != s)
                    std::cout << dist[i] << " ";
            }
        
    
}
int main()
{
    int t, n, m, p, s;
    long long w;
    std::cin >> t;
    std::ios_base::sync_with_stdio(false);


    std::vector<std::vector<int>> inputs;
    for (int j = 0; j < t; j++)
    {
        inputs.clear();
        std::cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            inputs.push_back(std::vector<int>(3));

            std::cin >> p;
            inputs[i][0] = p;
            std::cin >> p;
            inputs[i][1] = p;
            std::cin >> p;
            inputs[i][2] = p;
        }
        std::cin >> s;
        shortestReach(n, inputs, s);
        std::cout << std::endl;
    }

    return 0;
}
