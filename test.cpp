#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<char> adj[N], ans, vertex;
vector<int> tin(N), low(N);
bool vis[N], mark[N];
int timer = 1;
// User function Template for C++

void dfs(int node, int parent)
{
    vis[node] = true;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
            {
                mark[node] = true;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (child > 1 && parent == -1)
    {
        mark[node] = true;
    }
}
void articulationPoints()
{
    // for (auto it : vertex)
    // {
    //     if (!vis[it])
    //     {
    //         dfs(it, -1);
    //     }
    // }
      for (auto i=0 ;i< vertex.size();i++)
    {
        if (!vis[vertex[i]])
        {
            dfs(vertex[i], -1);
        }
    }

    for (auto it : vertex)
    {
        if (mark[it])
        {
            ans.push_back(it);
        }
    }
    if (ans.size() == 0)
        cout << "No Articulation Point" << endl;
    else
    {
        cout << "Articulation Point: ";
        for (auto ap : ans)
        {
            cout << ap << " ";
        }
        cout << endl;
    }
}
int main()
{
    int v;
    cout << "Enter the number of nodes: ";
    cin >> v;
    cout << "Enter the nodes: ";
    for (int i = 0; i < v; i++)
    {
        char x;
        cin >> x;
        vertex.push_back(x);
    }
    int n;
    cout << "Enter the number of edges: ";
    cin >> n;
    cout << "Enter adjacent list: " << endl;
    for (int i = 0; i < n; i++)
    {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    articulationPoints();

    return 0;
}
