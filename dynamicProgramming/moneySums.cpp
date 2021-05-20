#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxSum += v[i];
    }

    bool dp[maxSum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int coin : v)
        for (int i = maxSum; i >= coin; i--)
            dp[i] |= dp[i - coin];

    vector<int> ans;
    for (int i = 1; i <= maxSum; i++)
        if (dp[i])
            ans.push_back(i);

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}