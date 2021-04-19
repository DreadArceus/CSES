// Completely wrong approach, min + abs is not the proper min of a branch
// Need to use 2 seg trees for this, brb after other questions
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
            return;
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void pointUpdate(int x, segTreeItem val)
    {
        pointUpdate(x, val, 1, 0, size);
    }
    segTreeItem minPriceQuery(int x, int index, int l, int r)
    {
        if (l == r - 1)
            return {nodes[index].element + abs(x - l)};
        if (nodes[2 * index + 1].element + min(abs(r - x - 1), abs((r + l) / 2 - x)) > nodes[2 * index].element + max(x, abs((r + l) / 2 - 1 - x)))
            return minPriceQuery(x, 2 * index, l, (r + l) / 2);
        if (nodes[2 * index].element + min(x, abs((r + l) / 2 - 1 - x)) > nodes[2 * index + 1].element + max(abs(r - x - 1), abs((r + l) / 2 - x)))
            return minPriceQuery(x, 2 * index + 1, (r + l) / 2, r);
        return merge(minPriceQuery(x, 2 * index, l, (r + l) / 2),
                     minPriceQuery(x, 2 * index + 1, (r + l) / 2, r));
    }
    segTreeItem minPriceQuery(int x)
    {
        return minPriceQuery(x, 1, 0, size);
    }

private:
    vector<segTreeItem> nodes;
    segTreeItem null = {INT32_MAX};
    int size;
    segTreeItem merge(segTreeItem a, segTreeItem b)
    {
        segTreeItem result = {min(a.element, b.element)};
        return result;
    };
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    segTree st(n);
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        cin >> p;
        st.pointUpdate(i, {p});
    }
    while (q--)
    {
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            int k = 0, x = 0;
            cin >> k >> x;
            st.pointUpdate(k - 1, {x});
        }
        else
        {
            int k = 0;
            cin >> k;
            cout << st.minPriceQuery(k - 1).element << "\n";
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