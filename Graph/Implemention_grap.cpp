#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdg(int u, int v, bool direction)
    {

        // direction =0 ->undirection
        // direction =1 ->direction

        // creation an Edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (int j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of Nodes" << endl;
    cin >> n;
    int m;
    cout << "Enter the number of Edges:" << endl;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // graph creating an Undirected graph
        g.addEdg(u, v, 0);
    }
    // graph printing
    g.printAdjlist();
    return 0;
}