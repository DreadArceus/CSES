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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp[n + 1][n + 1][2];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            int turn = (i + n - 1 - j) % 2;
            if (j == 0 || dp[i + 1][j][turn] + v[i] > dp[i][j - 1][turn] + v[j])
            {
                dp[i][j][turn ^ 1] = dp[i + 1][j][turn ^ 1];
                dp[i][j][turn] = dp[i + 1][j][turn] + v[i];
            }
            else
            {
                dp[i][j][turn ^ 1] = dp[i][j - 1][turn ^ 1];
                dp[i][j][turn] = dp[i][j - 1][turn] + v[j];
            }
        }
    }

    cout << dp[0][n - 1][0] << "\n";
}

int32_t main()
{
    solveCase();
}