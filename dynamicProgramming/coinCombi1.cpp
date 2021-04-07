#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int solve(vector<int> nums, int target)
{
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i >= nums[j])
            {
                dp[i] += dp[i - nums[j]] % int(1e9 + 7);
                dp[i] %= int(1e9 + 7);
            }
        }
    }
    return dp[target];
}

int main()
{
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = solve(nums, target);
    cout << ans;
}