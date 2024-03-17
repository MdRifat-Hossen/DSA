#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adjList, int start, vector<bool> &visited)
{
    // using stack;
    stack<int> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty())
    {
        int front = s.top();
        s.pop();
        cout << front << " ";
        for (auto neighbor : adjList[front])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}
void AddEdg(vector<vector<int>> adjList, int u, int v)
{
    adjList[u].push_back(v);
}
int main()
{
    int node = 6;
    vector<vector<int>> adjList(node);
    AddEdg(adjList, 0, 4);
    AddEdg(adjList, 4, 2);
    AddEdg(adjList, 2, 3);
    AddEdg(adjList, 3, 5);
    AddEdg(adjList, 5, 1);
    AddEdg(adjList, 1, 4);
    vector<bool> visited(node, false);
    cout << "DFS is start 0 Index: ";
    dfs(adjList, 0, visited);
    return 0;
}