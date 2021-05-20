#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define pii pair<int, int>
int32_t mod = 1e9 + 7;

struct segTreeItem
{
    int element;
};

class segTree
{
public:
    segTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->size = n;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        if (x < l || x >= r)
            return;
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        if (y <= l || x >= r)
            return this->null;
        if (l >= x && r <= y)
            return nodes[index];
        return merge(query(x, y, 2 * index, l, (r + l) / 2),
                     query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, segTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    segTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {0};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.element = max(a.element, b.element);
        return result;
    }
};

void solveCase()
{
    int n = 0;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    auto cmp = [](pii a, pii b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    };
    sort(v.begin(), v.end(), cmp);

    segTree st(n);
    for (auto p : v)
    {
        int i = p.second;
        int j = st.query(i + 1, n).element;
        st.pointUpdate(i, j + 1);
    }

    cout << st.query(0, n).element << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}