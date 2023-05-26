#include <bits/stdc++.h>
using namespace std;
class graph
{

public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        // Direction = 0 -->undirected
        // Direction = 1 -->Directed
        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n, m;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;
    cout << "Enter the number of edges:" << endl;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Creating and undirected graph
        g.addEdge(u, v, 0);
    }
    // Printing graph
    g.printadjlist();
}