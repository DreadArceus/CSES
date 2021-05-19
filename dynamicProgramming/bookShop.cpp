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
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    int dp[x + 1];
    memset(dp, 0, sizeof(dp));

    for (int j = 0; j < n; j++)
        for (int i = x; i >= price[j]; i--)
            dp[i] = max(dp[i], dp[i - price[j]] + pages[j]);

    int ans = 0;
    for (int i = 0; i <= x; i++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}