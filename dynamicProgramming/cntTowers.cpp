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

int dp[1000001][2];

void solveCase()
{
    int n = 0;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
}

int32_t main()
{
    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i <= 1e6; i++)
    {
        dp[i][1] = (dp[i - 1][1] * 2 + dp[i - 2][0]) % mod;
        dp[i][0] = (dp[i - 1][0] * 4 + dp[i][1]) % mod;
    }

    int t = 0;
    cin >> t;
    while (t--)
        solveCase();
}