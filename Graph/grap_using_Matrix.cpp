#include <bits/stdc++.h>
using namespace std;
int nodearr[20][20];
int count = 0;
void displayMatrix(int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << nodearr[i][j] << " ";
        }
        cout << endl;
    }
}
void addEdge(int u, int v)
{
    nodearr[u][v] = 1;
    nodearr[v][u] = 1;
}
int main()
{
    int v = 6;
    addEdge(1, 2);
    addEdge(1, 5);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 3);
    addEdge(0, 4);
    addEdge(3, 5);
    addEdge(0, 3);
    addEdge(5, 4);
    displayMatrix(v);
    return 0;
}