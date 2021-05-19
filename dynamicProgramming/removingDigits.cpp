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
    int n = 0;
    cin >> n;

    int dp[n + 1];
    for (int i = 1; i <= n; i++)
        dp[i] = INT32_MAX;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (char c : s)
        {
            int digit = c - '0';
            dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }

    cout << dp[n] << "\n";
}

int32_t main()
{
    solveCase();
}