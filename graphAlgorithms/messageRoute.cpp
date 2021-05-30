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

vector<vector<int>> graph;

vector<int> bfs(int n, int source, int target)
{
    vector<int> p(n, -1);
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty() && !visited[target])
    {
        int u = q.front();
        q.pop();
        for (auto v : graph[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                p[v] = u;
            }
        }
    }

    if (p[target] == -1)
        return {};

    vector<int> path;
    for (int x = target; x != -1; x = p[x])
        path.push_back(x);
    reverse(path.begin(), path.end());

    return path;
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> ans = bfs(n, 0, n - 1);
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x + 1 << " ";
}

int32_t main()
{
    solveCase();
}