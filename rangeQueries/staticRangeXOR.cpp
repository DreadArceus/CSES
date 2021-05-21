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

class SparseTable
{
public:
    SparseTable(int n) : n(n)
    {
        this->activated = false;
        this->k = 0;
        while ((1 << k) < n)
            k++;
        this->table = vector<vector<int>>(n, vector<int>(k + 1));
    }
    void insert(int ind, int val)
    {
        this->table[ind][0] = val;
        this->activated = false;
    }
    int query(int l, int r)
    {
        if (!this->activated)
            this->arise();
        int ans = this->null;
        for (int j = k; j >= 0; j--)
        {
            if ((1 << j) <= r - l + 1)
            {
                ans = merge(ans, table[l][j]);
                l += 1 << j;
            }
        }
        return ans;
    }

private:
    int n, k;
    bool activated;
    vector<vector<int>> table;
    int null = 0;
    void arise()
    {
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        activated = true;
    }
    int merge(int x, int y)
    {
        return x ^ y;
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    SparseTable st(n);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        st.insert(i, x);
    }
    while (q--)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << st.query(a - 1, b - 1) << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}