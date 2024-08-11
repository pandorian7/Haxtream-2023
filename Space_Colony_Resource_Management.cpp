#include <iostream>
#include <array>
#include <vector>

using namespace std;

typedef array<double, 3> state;

vector<state> records;

vector<state>::iterator find(int item, double val)
{
    auto it = records.begin();
    while ((it++) != records.end())
    {
        if (it->at(item) <= val)
            break;
    }
    return it;
}

int main()
{
    int hour, len;
    bool ok = true;
    double oxygen, water, food;
    vector<int> timestamps;
    state limit;
    array<vector<state>::iterator, 3> crysis;

    while (cin >> hour >> oxygen >> water >> food)
    {
        if (timestamps.empty())
            limit = {oxygen * 0.2, water * 0.1, food * 0.15};
        timestamps.push_back(hour);
        records.push_back({oxygen, water, food});
    }

    len = timestamps.size();

    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            records[i][j] = records[i - 1][j] - records[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        crysis[i] = find(i, limit[i]);
    }

    for (auto it : crysis)
    {
        if (it != records.end())
            ok = false;
    }

    if (ok)
        cout << "good";
    else
    {
        if (crysis[0] != records.end())
            cout << "oxygen-" << crysis[0] - records.begin() << endl;
        if (crysis[1] != records.end())
            cout << "water-" << crysis[1] - records.begin() << endl;
        if (crysis[2] != records.end())
            cout << "food-" << crysis[2] - records.begin();
    }
}