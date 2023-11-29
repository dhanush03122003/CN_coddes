#include <bits/stdc++.h>
using namespace std;

int Bellman_Ford(vector<vector<int>> &G, int V, int E, vector<pair<int, int>> &edge)
{
    int i, u, v, k, S, flag = 1;
    vector<int> distance(V, 1000);

    cout << "\nEnter source : ";
    cin >> S;

    distance[S] = 0;

    for (i = 0; i < V - 1; i++)
    {
        for (k = 0; k < E; k++)
        {
            u = edge[k].first;
            v = edge[k].second;
            if (distance[u] + G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v];
        }
    }

    for (k = 0; k < E; k++)
    {
        u = edge[k].first;
        v = edge[k].second;
        if (distance[u] + G[u][v] < distance[v])
            flag = 0;
    }

    if (flag)
        for (i = 0; i < V; i++)
            cout << "\nDistance from source " << S << " to vertex " << i + 1 << " is " << distance[i];

    return flag;
}

int main()
{
    int V, i, j, k = 0;
    //cout << "Enter no. of vertices: ";
    //cin >> V;
    V=9;
    //vector<vector<int>> G(V, vector<int>(V, 0));
        vector<vector<int>> G = {{0, -4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    vector<pair<int, int>> edge;

    cout << "Enter graph in matrix form:\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            //cin >> G[i][j];
            if (G[i][j] != 0)
                edge.emplace_back(i, j);
        }
    }

    if (Bellman_Ford(G, V, edge.size(), edge))
    {

    }
    else
    {
        cout<<"ggg";
    }
        //cout << "\nNo negative weight cycle exists\n";


    return 0;
}
