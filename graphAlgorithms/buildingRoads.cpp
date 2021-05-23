#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int read()
{
    int x = 0;
    while (1)
    {
        char ch = getchar_unlocked();
        if (ch >= '0' && ch <= '9')
            x = x * 10 + (ch - '0');
        else
            return x;
    }
}

inline void write(int x, char ch = 0)
{
    if (x == 0)
        putchar_unlocked('0');
    char s[20];
    int y = 0;
    while (x)
        s[y++] = '0' + x % 10, x /= 10;
    while (y--)
        putchar_unlocked(s[y]);
    if (ch)
        putchar_unlocked(ch);
}

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
    int n = read(), m = read();
    DSU d(n);
    for (int i = 0; i < n; i++)
        d.make_set(i);
    for (int i = 0; i < m; i++)
    {
        int a = read(), b = read();
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
    write(ans.size(), '\n');
    for (auto x : ans)
        write(1, ' '), write(x + 1, '\n');
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}