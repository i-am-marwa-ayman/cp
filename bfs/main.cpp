#include <bits/stdc++.h>
#define mr ios_base::sync_with_stdio(0);
#define prince cin.tie(0),cout.tie(0)
#define the_forgotten_line freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all_list list.begin(), list.end()
#define endl "\n"
#define ll long long 
using namespace std;
const long long N = 200;
const long long INF = 1e18;

vector<vector<int>> adj(N);
vector<vector<pair<int, int>>> adj_w(N);
vector<bool> visited(N);
vector<int> level(N);
vector<int> path(N,-1);
vector<long long> dis(N,INF);
void reset(int n)
{
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        visited[i] = false;
    }
}
// basic bfs tracking the level of the node
void bfs(int scr){
    queue<int> q;
    q.push(scr);
    visited[scr] = 1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << " " << level[parent] << endl;
        for (auto &&i : adj[parent])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                level[i] = level[parent] + 1;
            }
        }
    }
}
// graph coloring problem
// bicolor == bipartit
vector<int> color(N);
bool is_bipartit(int scr)
{
    queue<int> q;
    q.push(scr);
    color[scr] = 1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto &&i : adj[parent])
        {
            if(color[i] == 0){
                color[i] = (color[parent] == 1 ? 2 : 1);
                q.push(i);
            }
            else if(color[i] == color[parent])
                return 0;
        }
    }
    return 1;
}
void Dijkstra(int src){
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[node])continue;
        visited[node] = 1;
        for (auto [a, b] : adj_w[node]){
            if(cost + b < dis[a]){
                pq.push({cost + b, a});
                dis[a] = cost + b;
                path[a] = node;
            }
        }
    }
}
void get_path(int node){
    if(node == -1)
        return;
    get_path(path[node]);
    cout << node << " ";
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_w[u].push_back({v, w});
        adj_w[v].push_back({u, w});
    }
    Dijkstra(1);
    get_path(n);
    cout << endl;
}
int main()
{
    // the_forgotten_line
    mr prince;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}