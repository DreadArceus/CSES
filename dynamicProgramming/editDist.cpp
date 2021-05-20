#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solveCase()
{
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    int dp[n + 1][m + 1];
    dp[n][m] = 0;
    for (int i = 0; i < n; i++)
        dp[i][m] = n - i;
    for (int i = 0; i < m; i++)
        dp[n][i] = m - i;

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
                continue;
            }
            dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
        }

    cout << dp[0][0] << "\n";
}

int32_t main()
{
    solveCase();
}