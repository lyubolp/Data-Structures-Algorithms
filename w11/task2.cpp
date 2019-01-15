#include <iostream>
#include <vector>


int main()
{
    const int min = -2000000000;
    int n, m, t,s, v1, v2, w;
    
    
    std::cin >> n >> m >> s >> t;

    int* dist = new int[n+1];
    std::vector<std::vector<std::pair<int,int>>> adj;
    for(int i = 0; i <= n; i++)
    {
        dist[i] = min;
        adj.push_back(std::vector<std::pair<int,int>>());
    }
    dist[s] = 0;
    for(int i = 0; i < m ; i++)
    {
        std::cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
    }



    int r = 0;
    bool change = false;
    for(int i = 0; i < m-1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int g = 0; g < adj[j].size(); g++)
            {
                int node = adj[j][g].first;
                int weight = adj[j][g].second;
                if(weight + dist[j] >= dist[node]) dist[node] = weight + dist[j];
            }
        }
    }

    if(dist[t] != min)std::cout << dist[t];
    else std::cout << "-1";



    return 0;
}

