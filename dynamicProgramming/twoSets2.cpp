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
    if ((n * (n + 1)) % 4)
    {
        cout << "0\n";
        return;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    int target = (n * (n + 1)) / 4;

    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (auto x : v)
        for (int i = target; i >= x; i--)
            dp[i] = (dp[i] + dp[i - x]) % mod;

    cout << dp[target] * ((mod + 1) / 2) % mod << "\n";
}

int32_t main()
{
    solveCase();
}