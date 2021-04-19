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
    segTree() {}
    segTree(vector<segTreeItem> nodes, int size)
    {
        this->nodes = nodes;
        this->size = size;
    }
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
    vector<segTreeItem> getNodes() { return nodes; }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {0};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};

class segTree2D
{
public:
    segTree2D(int n)
    {
        this->nodes.resize(4 * n + 5, this->nullTree);
        this->size = n;
    }
    void pointUpdate(int x, segTree val, int index, int l, int r)
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
        nodes[index] = mergeTree(nodes[2 * index], nodes[2 * index + 1]);
    }
    segTreeItem query(int x1, int x2, int y1, int y2, int index, int l, int r)
    {
        if (x2 <= l || x1 >= r)
            return this->nullItem;
        if (l >= x1 && r <= x2)
            return nodes[index].query(y1, y2);
        return mergeItem(query(x1, x2, y1, y2, 2 * index, l, (r + l) / 2),
                         query(x1, x2, y1, y2, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, segTree val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    segTreeItem query(int x1, int x2, int y1, int y2)
    {
        return query(x1, x2, y1, y2, 1, 0, size);
    }

private:
    vector<segTree> nodes;
    segTree nullTree;
    segTreeItem nullItem = {0};
    int size;
    segTree mergeTree(segTree a, segTree b)
    {
        vector<segTreeItem> n1 = a.getNodes(), n2 = b.getNodes(), n3(n1.size());
        if (n1.size() == 0)
            return segTree(n2, size);
        if (n2.size() == 0)
            return segTree(n1, size);
        for (int i = 0; i < n1.size(); i++)
            n3[i] = mergeItem(n1[i], n2[i]);
        return segTree(n3, size);
    }
    segTreeItem mergeItem(segTreeItem a, segTreeItem b)
    {
        segTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    segTree2D st(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        segTree st2(n);
        for (int j = 0; j < s.length(); j++)
            st2.pointUpdate(j, (s[j] == '*' ? 1 : 0));
        st.pointUpdate(i, st2);
    }
    while (q--)
    {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        cout << st.query(x1 - 1, x2, y1 - 1, y2).element << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solveCase();
}