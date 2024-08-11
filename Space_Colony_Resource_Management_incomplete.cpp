#include <iostream>
#include <tuple>
#include <vector>
#include <array>

using namespace std;

typedef tuple<double, double, double> state;
typedef tuple<int, state> record;

ostream &operator<<(ostream &os, state &s);
ostream &operator<<(ostream &os, record &r);
state operator-(state &a, state &b);

int main()
{

    vector<record> records;
    double oxy, water, food;
    int hour;
    state s;
    record r;
    int expire[3];
    array<double, 3> elements, limit;

    while (cin >> hour >> oxy >> water >> food)
    {
        s = tie(oxy, water, food);
        if (!records.empty())
            s = get<state>(records.back()) - s;
        if (records.empty())
        {
            oxy *= .2;
            water *= .1;
            food *= .15;
            limit = {oxy, water, food};
        }
        r = tie(hour, s);
        records.push_back(r);
    }

    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < records.size(); j++)
        {
            tie(hour, s) = records[j];
            tie(oxy, water, food) = s;
            elements = {oxy, water, food};
            if (elements[i] <= limit[i])
            {
                expire[i] = j;
                break;
            }
        }
    }

    for (auto i : records)
    {
        cout << i << endl;
    }

    cout << limit[0] << " " << limit[1] << " " << limit[2];
    // cout << limit;
    // state s1, s2, s3;
    // s1 = {100, 23, 4};
    // s2 = {23, 4, 5};
    // s3 = s1 - s2;
    // cout << s3;

    // s1 = tie(oxy, water, food);
    // r1 = tie(hour, s1);

    // cout << r1;
}

state operator-(state &a, state &b)
{
    double oxy, water, food;
    oxy = get<0>(a) - get<0>(b);
    water = get<1>(a) - get<1>(b);
    food = get<2>(a) - get<2>(b);
    return state{oxy, water, food};
}

ostream &operator<<(ostream &os, state &s)
{
    os << get<0>(s) << " " << get<1>(s) << " " << get<2>(s);
    return os;
}

ostream &operator<<(ostream &os, record &r)
{
    cout << get<0>(r) << " " << get<1>(r);
    return os;
}