#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, unordered_map<int, bool>> visited_t;

vector<vector<int>> *SpaceMapPtr;
int rows, cols;

struct position
{
    int rn, cn;
    int from;

    position(int rn_, int cn_) : rn(rn_), cn(cn_)
    {
    }
    position() : position(0, 0)
    {
    }

    position copy()
    {
        position pos{rn, cn};
        return pos;
    }
};

vector<position> *qPtr;
visited_t *visitedPtr;

bool operator==(position &a, position &b)
{
    return ((a.cn == b.cn) && (a.rn == b.rn));
}

int state(position &pos)
{
    return (*SpaceMapPtr)[pos.rn][pos.cn];
}

position &prv(position &pos)
{
    return qPtr->at(pos.from);
}

position readMap(vector<vector<int>> &spaceMap)
{
    position end;
    int val;
    for (int rn = 0; rn < rows; rn++)
    {
        for (int cn = 0; cn < cols; cn++)
        {
            cin >> val;
            spaceMap[rn][cn] = val;
            if (val == 2)
                end = position(rn, cn);
        }
    }
    return end;
}

position up(position &from, int fromI)
{
    auto pos = from.copy();
    pos.rn = from.rn - 1;
    pos.from = fromI;
    return pos;
}

position down(position from, int fromI)
{
    auto pos = from.copy();
    pos.rn = from.rn + 1;
    pos.from = fromI;
    return pos;
}

position right(position from, int fromI)
{
    auto pos = from.copy();
    pos.cn = from.cn + 1;
    pos.from = fromI;
    return pos;
}

position left(position from, int fromI)
{
    auto pos = from.copy();
    pos.cn = from.cn - 1;
    pos.from = fromI;
    return pos;
}

bool isValid(position &pos)
{
    if (pos.cn >= cols || pos.cn < 0)
        return false;
    if (pos.rn >= rows || pos.rn < 0)
        return false;
    return (state(pos) != 1);
}

vector<position> possibleNeighbours(position &pos, int from)
{
    vector<position> neighbours;
    neighbours.push_back(up(pos, from));
    neighbours.push_back(down(pos, from));
    neighbours.push_back(right(pos, from));
    neighbours.push_back(left(pos, from));
    return neighbours;
}

bool isVisited(position &pos)
{
    return (*visitedPtr)[pos.rn][pos.cn];
}

void visit(position &pos)
{
    (*visitedPtr)[pos.rn][pos.cn] = true;
}

vector<position> validNeighbours(position &pos, int from)
{
    vector<position> neighbours;
    for (auto neighbour : possibleNeighbours(pos, from))
    {
        if (isValid(neighbour) && !isVisited(neighbour))
            neighbours.push_back(neighbour);
    }
    return neighbours;
}

ostream &operator<<(ostream &os, position &pos)
{
    os << pos.rn << " " << pos.cn;
    return os;
}

int main()
{
    position start, end;

    cin >> start.rn >> start.cn;
    cin >> rows >> cols;

    vector<vector<int>> spaceMap(rows, vector<int>(cols));
    vector<position> q;
    visited_t visited;
    SpaceMapPtr = &spaceMap;
    qPtr = &q;
    visitedPtr = &visited;

    end = readMap(spaceMap);

    q.push_back(start);

    size_t i;
    for (i = 0; i < q.size(); i++)
    {
        visit(q[i]);
        // cout << q[i] << endl;
        for (auto next : validNeighbours(q[i], i))
            q.push_back(next);
        if (q[i] == end)
            break;
    }
    auto pos = q[i];

    vector<position> traceback;

    while (1)
    {
        traceback.push_back(pos);
        if (pos == start)
            break;
        pos = prv(pos);
    }

    for (auto it = traceback.rbegin(); it != traceback.rend(); it++)
    {
        cout << *it << endl;
    }
}