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
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
    int dp[n][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
        dp[n - 1][i] = 1;
 
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i + 1] != 0)
        {
            dp[i][v[i + 1]] = dp[i + 1][v[i + 1]];
            if (v[i + 1] != 1)
                dp[i][v[i + 1] - 1] = dp[i + 1][v[i + 1]];
            if (v[i + 1] != m)
                dp[i][v[i + 1] + 1] = dp[i + 1][v[i + 1]];
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i + 1][j];
            if (j != 1)
                dp[i][j] += dp[i + 1][j - 1];
            if (j != m)
                dp[i][j] += dp[i + 1][j + 1];
            dp[i][j] %= mod;
        }
    }
 
    if (v[0] != 0)
    {
        cout << dp[0][v[0]] << "\n";
        return;
    }
 
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[0][i]) % mod;
    cout << ans << "\n";
}
 
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}