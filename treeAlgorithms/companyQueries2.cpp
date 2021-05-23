#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

class LCA
{
public:
    LCA(int n, int q)
    {
        this->tree.resize(n);
        this->queries.resize(n);
        this->visited.resize(n);
        this->parent.resize(n);
        this->rank.resize(n);
        this->answers.assign(q, -1);
    }
    void addEdge(int parent, int child)
    {
        tree[parent].push_back(child);
    }
    void addQuery(int a, int b, int i)
    {
        queries[a].push_back(make_pair(b, i));
        queries[b].push_back(make_pair(a, i));
    }
    vector<int> arise()
    {
        dfs(0);
        return answers;
    }

private:
    vector<vector<int>> tree;
    vector<vector<pii>> queries;
    vector<int> answers;
    vector<bool> visited;
    vector<int> parent, rank;
    void make_set(int v)
    {
        parent[v] = v;
        rank[v] = 0;
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
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
    void dfs(int source)
    {
        visited[source] = true;
        make_set(source);
        for (auto x : tree[source])
        {
            dfs(x);
            union_sets(source, x);
            parent[find_set(source)] = source;
            parent[source] = source;
        }
        for (auto [q, i] : queries[source])
        {
            if (!visited[q] || answers[i] != -1)
                continue;
            answers[i] = parent[find_set(q)];
        }
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    LCA l(n, q);
    for (int i = 1; i < n; i++)
    {
        int p = 0;
        cin >> p;
        l.addEdge(p - 1, i);
    }
    for (int i = 0; i < q; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        l.addQuery(a - 1, b - 1, i);
    }
    for (int x : l.arise())
        cout << x + 1 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    solveCase();
}