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

vector<vector<int>> adj;
vector<int> visited;
void dfs(int source)
{
    visited[source] = true;
    for (auto v : adj[source])
        if (!visited[v])
            dfs(v);
}

struct Edge
{
    int u, v, w;
};
vector<Edge> graph;

int bellmanTargetted(int n, int m, int source, int target)
{
    vector<int> d(n, INT64_MAX);
    d[source] = 0;
    bool going = true, cycle = false;
    int cnt = 0;
    while (going)
    {
        if (++cnt == n)
        {
            cycle = true;
            break;
        }
        going = false;
        for (int i = 0; i < m; i++)
        {
            int u = graph[i].u, v = graph[i].v, w = graph[i].w;
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
                d[v] = d[u] + w, going = true;
        }
    }
    if (cycle)
    {
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            int u = graph[i].u, v = graph[i].v, w = graph[i].w;
            if (d[u] != INT64_MAX && d[v] > d[u] + w)
                d[v] = d[u] + w, q.push(v);
        }
        visited.resize(n);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            dfs(cur);
            if (visited[target])
                return INT64_MIN;
        }
    }
    return d[target];
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(m);
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        graph[i] = {u - 1, v - 1, -1 * w};
        adj[u - 1].push_back(v - 1);
    }
    int ans = bellmanTargetted(n, m, 0, n - 1);
    if (ans != INT64_MIN)
        cout << -1 * ans;
    else
        cout << -1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solveCase();
}