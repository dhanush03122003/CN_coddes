#include <bits/stdc++.h>
using namespace std;

#define V 9

void dijkstra(vector<vector<int>> graph, int source)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int min = INT_MAX, min_index;

        for (int i = 0; i < V; i++)
        {
            if (sptSet[i] == false && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
        }

        sptSet[min_index] = true;

        for (int i = 0; i < V; i++)
        {
            if (!sptSet[i] && graph[min_index][i] && dist[min_index] != INT_MAX && dist[min_index] + graph[min_index][i] < dist[i])
                dist[i] = dist[min_index] + graph[min_index][i];
        }
    }
    cout << "destination \t cost" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t" << dist[i] << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    for(int i=0;i<=8;i++)
    {
      cout<<"Source node:"<<i<<endl;
      dijkstra(graph, i);
    }
    return 0;
}
