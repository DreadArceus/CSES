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
    int assignRoom(int x, int index, int l, int r)
    {
        if (nodes[index].element >= x && l == r - 1)
        {
            this->pointUpdate(l, {nodes[index].element - x});
            return l;
        }
        if (nodes[2 * index].element >= x)
        {
            return assignRoom(x, 2 * index, l, (r + l) / 2);
        }
        if (nodes[2 * index + 1].element >= x)
        {
            return assignRoom(x, 2 * index + 1, (r + l) / 2, r);
        }
        return -1;
    }
    int assignRoom(int x)
    {
        return assignRoom(x, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {INT32_MIN};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result = {max(a.element, b.element)};
        return result;
    }
};

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        int h = 0;
        cin >> h;
        st.pointUpdate(i, {h});
    }
    while (m--)
    {
        int x = 0;
        cin >> x;
        cout << st.assignRoom(x) + 1 << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}