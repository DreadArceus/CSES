#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

void solveCase()
{
    int a = 0, b = 0;
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    int dp[a + 1][b + 1];
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            dp[i][j] = INT32_MAX;
    for (int i = 1; i <= a; i++)
        dp[i][i] = 0;

    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            for (int k = j - 1; k >= (j + 1) / 2; k--)
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            for (int k = i - 1; k >= (i + 1) / 2; k--)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
        }

    cout << dp[a][b] << "\n";
}

int32_t main()
{
    solveCase();
}