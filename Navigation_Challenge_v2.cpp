#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, int> point;
ostream &operator<<(ostream &os, point &p);

unordered_map<int, unordered_map<int, bool>> visited;
unordered_map<int, unordered_map<int, point>> trace;
vector<point> traceback;
queue<point> q;
vector<vector<int>> *spaceMapPtr;
int n, m;

vector<point> neighbours(point p);

bool isValid(point p);

vector<point> validNeighbours(point p);

int main()
{
    point start, end, pos;
    cin >> start.first >> start.second;
    cin >> n >> m;
    auto spaceMap = vector<vector<int>>(n, vector<int>(m, 0));
    spaceMapPtr = &spaceMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> spaceMap[i][j];
            if (spaceMap[i][j] == 2)
                end = {i, j};
        }
    }

    q.push(start);

    while (!q.empty())
    {
        pos = q.front();
        visited[pos.first][pos.second] = true;
        if (pos == end)
            break;
        for (auto neighbour : validNeighbours(pos))
            q.push(neighbour);
        q.pop();
    }

    while (1)
    {
        traceback.push_back(pos);
        if (pos == start)
            break;
        pos = trace[pos.first][pos.second];
    }

    for (auto it = traceback.rbegin(); it != traceback.rend(); it++)
    {
        cout << *it << endl;
    }
}

vector<point> neighbours(point p)
{
    vector<point> ns(4, p);
    ns[0].first++;
    ns[1].first--;
    ns[2].second++;
    ns[3].second--;
    return ns;
}

ostream &operator<<(ostream &os, point &p)
{
    os << p.first << " " << p.second;
    return os;
}

bool isValid(point p)
{
    if (p.first < 0 || p.first >= n)
        return false;
    if (p.second < 0 || p.second >= m)
        return false;
    if ((*spaceMapPtr)[p.first][p.second] == 1)
        return false;
    return (!visited[p.first][p.second]);
}

vector<point> validNeighbours(point p)
{
    vector<point> ns;
    for (auto neighbour : neighbours(p))
    {
        if (isValid(neighbour))
        {
            ns.push_back(neighbour);
            trace[neighbour.first][neighbour.second] = p;
        }
    }
    return ns;
}
