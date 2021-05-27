#include <iostream>
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

vector<vector<int>> graph, graphT;
vector<int> ans;
vector<bool> visited;
vector<int> exitT;

void dfs1(int source)
{
    visited[source] = true;
    for (int v : graph[source])
        if (!visited[v])
            dfs1(v);
    exitT.push_back(source);
}

void dfs2(int source, int sccNum)
{
    visited[source] = true;
    ans[source] = sccNum;
    for (int v : graphT[source])
        if (!visited[v])
            dfs2(v, sccNum);
}

void solveCase()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n);
    graphT.resize(n);
    while (m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graphT[v].push_back(u);
    }

    visited.resize(n);
    exitT.resize(n);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    reverse(exitT.begin(), exitT.end());

    visited = vector<bool>(n, false);
    ans.resize(n);
    int num = 1;
    for (auto i : exitT)
    {
        if (visited[i])
            continue;
        dfs2(i, num++);
    }

    cout << num - 1 << "\n";
    for (auto x : ans)
        cout << x << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}