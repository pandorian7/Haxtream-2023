#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int, int> point;

int n, dir;
point pos;
unordered_map<int, unordered_map<int, int>> visited, input;

point next(point p)
{
    switch (dir)
    {
    case 0:
        p.second++;
        break;

    case 1:
        p.first++;
        break;

    case 2:
        p.second--;
        break;
    case 3:
        p.first--;
        break;
    }
    return p;
}

bool isValid(point p)
{
    if (p.first < 0 || p.first >= n)
        return false;
    if (p.second < 0 || p.second >= n)
        return false;
    return !visited[p.first][p.second];
}

void changeDir()
{
    dir = (dir + 1) % 4;
}

point nextValid()
{
    while (!isValid(next(pos)))
        changeDir();
    return next(pos);
}

int main()
{
    cin >> n;
    int steps = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    pos = {0, -1};
    while (steps--)
    {
        pos = nextValid();
        cout << input[pos.first][pos.second] << " ";
        visited[pos.first][pos.second] = 1;
    }
}