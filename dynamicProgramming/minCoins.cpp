#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

void solveCase()
{
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[x + 1];
    for (int i = 1; i <= x; i++)
        dp[i] = INT32_MAX;
    dp[0] = 0;

    for (auto coin : v)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - coin < 0)
                continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[x] != INT32_MAX ? dp[x] : -1) << "\n";
}

int32_t main()
{
    solveCase();
}