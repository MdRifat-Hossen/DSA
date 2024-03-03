#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void Insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int perent = index / 2;
            if (arr[perent] < arr[index])
            {
                swap(arr[perent], arr[index]);
                index = perent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleted()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        // take  root node currect positon
        int i = 1;
        while (1 < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
};
void heaplify(int arr[], int n, int i)
{
    int leargest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[leargest] < arr[left])
    {
        leargest = left;
    }
    if (right < n && arr[leargest] < arr[right])
    {
        leargest = right;
    }

    if (leargest != i)
    {
        swap(arr[leargest], arr[i]);
        heaplify(arr, n, leargest);
    }
}
int main()
{
    heap h;
    h.Insert(50);
    h.Insert(55);
    h.Insert(53);
    h.Insert(52);
    h.Insert(54);
    h.print();
    h.deleted();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heaplify(arr, n, 1);
    }
    cout << "heap print Now: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}