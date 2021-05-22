#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
public:
    DSU(int n)
    {
        this->parent.resize(n);
        this->sz.resize(n);
    }
    void make_set(int v)
    {
        parent[v] = v;
        sz[v] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

private:
    vector<int> parent, sz;
};

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    DSU d(n);
    for (int i = 0; i < n; i++)
        d.make_set(i);
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        d.union_sets(a - 1, b - 1);
    }
    vector<int> ans;
    int ult = d.find_set(0);
    for (int i = 1; i < n; i++)
    {
        int cur = d.find_set(i);
        if (ult == cur)
            continue;
        ans.push_back(i);
        d.union_sets(0, i);
        ult = d.find_set(0);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << 1 << " " << x + 1 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}