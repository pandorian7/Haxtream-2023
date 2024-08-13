#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> visited;
vector<int> match;
string str1, str2;

int get_length(int index)
{
    int head = match[index];
    int length = 1;
    for (size_t i = index + 1; i < match.size(); i++)
    {
        if (match[i] > head)
        {
            head = match[i];
            length++;
            visited[i] = true;
        }
    }
    return length;
}

string get_str(int start)
{
    string ret;
    ret += str2[start];
    size_t i = start;
    int head = match[i];
    for (; i < match.size(); i++)
    {
        if (match[i] > head)
        {
            head = match[i];
            ret += str2[i];
        }
    }
    return ret;
}

int main()
{
    cin >> str1 >> str2;
    pair<int, int> longest{0, 0}; // length, index

    for (char ch : str2)
    {
        match.push_back(find(str1.begin(), str1.end(), ch) - str1.begin());
    }

    // for (auto it = match.begin(); it != match.end(); it++)
    // {
    //     vector<int> streak;
    //     vector<int>::iterator val;

    //     for (auto pos = it; it != match.end(); it++)
    //     {

    //     }
    // }

    int length;
    for (size_t i = 0; i < match.size(); i++)
    {
        if (!visited[i])
        {
            length = get_length(i);
            if (length > longest.first)
            {
                longest = {length, i};
            }
        }
    }

    cout << get_str(longest.second);
}