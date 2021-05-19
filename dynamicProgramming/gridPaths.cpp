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
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == '*')
            break;
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
                continue;
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
        }

    cout << dp[n - 1][n - 1] << "\n";
}

int32_t main()
{
    solveCase();
}