#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

struct segTreeItem
{
    int element;
};

class segTree
{
public:
    segTree(int n)
    {
        this->nodes.resize(4 * n, this->null);
        this->size = n;
    }
    void pointUpdate(int x, segTreeItem val, int index, int l, int r)
    {
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        if (x < l || x >= r)
        {
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void pointUpdate(int x, segTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    segTreeItem query(int x, int y, int index, int l, int r)
    {
        if (l >= x && r <= y)
        {
            return nodes[index];
        }
        if (y <= l || x >= r)
        {
            return this->null;
        }
        return merge(query(x, y, 2 * index, l, (r + l) / 2),
                     query(x, y, 2 * index + 1, (r + l) / 2, r));
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
        segTreeItem result = {a.element + b.element};
        return result;
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        st.pointUpdate(i, {x});
    }
    while (q--)
    {
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            int k = 0, u = 0;
            cin >> k >> u;
            st.pointUpdate(k - 1, {u});
        }
        else
        {
            int a = 0, b = 0;
            cin >> a >> b;
            cout << st.query(a - 1, b).element << "\n";
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}