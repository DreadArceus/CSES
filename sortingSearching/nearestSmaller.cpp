#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

void solveCase()
{
    int n = 0;
    cin >> n;
    stack<pii> s;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        while (!s.empty() && s.top().first >= x)
            s.pop();
        if (s.empty())
            cout << "0 ";
        else
            cout << s.top().second << " ";
        s.push(make_pair(x, i + 1));
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}