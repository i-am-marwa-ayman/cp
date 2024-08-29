#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define mr ios_base::sync_with_stdio(0);
#define prince cin.tie(0),cout.tie(0)
#define the_forgotten_line freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all_list list.begin(), list.end()
#define all_ans ans.begin(), ans.end()
#define all_out out.begin(), out.end()
#define endl "\n"
#define esle else 
#define ll long long 
#define itn int
using namespace std;
const long long N = 200;

vector<vector<int>> adj(N);
vector<bool> visited(N);
vector<int> level(N);
void reset(int n) {
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
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
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