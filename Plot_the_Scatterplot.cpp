#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, unordered_map<int, bool>> graph;
int size_x, size_y;

void draw()
{
    for (int i = size_y; i; i--)
    {
        cout << i;
        for (int j = 1; j <= size_x; j++)
        {
            cout << (graph[i][j] ? "x " : "  ");
        }
        cout << "\n";
    }
    for (int i = 1; i <= size_x; i++)
    {
        cout << " " << i;
    }
}

int main()
{
    cin >> size_x;
    vector<int> x(size_x);
    for (int i = size_x; i--;)
    {
        cin >> x[i];
    }
    cin >> size_y;
    vector<int> y(size_y);
    for (int i = size_y; i--;)
    {
        cin >> y[i];
    }

    for (int i = size_y; i--;)
    {
        graph[y[i]][x[i]] = true;
    }
    draw();
}