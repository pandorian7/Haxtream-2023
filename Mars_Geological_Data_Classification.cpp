#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n, a, b, start, end;
    cin >> n;

    vector<int> hights(n);
    vector<string> changes;
    string state;

    for (int i = 0; i < n; i++)
    {
        cin >> hights[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        a = hights[i];
        b = hights[i + 1];
        if (a < b)
            state = "hill";
        if (a > b)
            state = "slope";
        if (a == b)
            state = "flat";
        changes.push_back(state);
    }
    changes.push_back("");
    start = end = 0;
    state = "";
    for (int i = 0; i < n; i++)
    {
        if (state == changes[i])
            continue;
        end = i;
        if (!state.empty())
            cout << start << "-" << end << "=" << state << endl;
        start = i;
        state = changes[i];
    }
}