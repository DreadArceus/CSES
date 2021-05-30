#include <iostream>
#include <queue>
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

vector<vector<pii>> graph;

vector<int> dijkstraSparse(int n, int m, int source)
{
    vector<int> d(n, INT64_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[source] = 0;
    pq.push(make_pair(0, source));
    for (int i = 0; i < n; i++)
    {
        auto top = pq.top();
        pq.pop();
        while (top.first != d[top.second])
        {
            top = pq.top();
            pq.pop();
        }
        int v = top.second;
        if (d[v] == INT64_MAX)
            break;

        for (auto [u, w] : graph[v])
            if (d[v] + w < d[u])
                d[u] = d[v] + w, pq.push(make_pair(d[u], u));
    }
    return d;
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        graph[u - 1].push_back(make_pair(v - 1, w));
    }
    vector<int> ans = dijkstraSparse(n, m, 0);
    for (auto x : ans)
        cout << x << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}