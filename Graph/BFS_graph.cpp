#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    queue<int> q;

    // Make the current node is visited and push a queue
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] == true;
                q.push(neighbor);
            }
        }
    }
}
void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}
int main()
{
    int node = 5;
    vector<vector<int>> adjList(node);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 3, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    vector<bool> visited(node, false);
    cout << "Breath First Traversel Starting from Node 0 : ";
    bfs(adjList, 0, visited);

    return 0;
}