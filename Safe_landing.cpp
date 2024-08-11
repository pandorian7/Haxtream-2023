#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, int> point;

int n, m;
unordered_map<int, unordered_map<int, int>> visited, land;

vector<point> validNeighbours(point p)
{
    vector<point> possible_ns(4, p), ns;
    possible_ns[0].first++;
    possible_ns[1].first--;
    possible_ns[2].second++;
    possible_ns[3].second--;

    for (auto n : possible_ns)
    {
        if (!visited[n.first][n.second] && land[n.first][n.second])
            ns.push_back(n);
    }
    return ns;
}

bool findLand(point &pos)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 1 && !visited[i][j])
            {
                pos = make_pair(i, j);
                return true;
            }
        }
    }
    return false;
}

void exhaustLand(point pos)
{
    queue<point> q;
    q.push(pos);
    point p;

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        visited[p.first][p.second] = 1;
        for (auto p1 : validNeighbours(p))
        {
            q.push(p1);
        }
    }
}

int main()
{
    int landmasses = 0;
    cin >> n >> m;
    point pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }

    while (findLand(pos))
    {
        landmasses++;
        exhaustLand(pos);
    }
    cout << landmasses;
}