#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<sstream>
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
using namespace std;
const int N = 1e5;

vector<vector<int>> adj(N);
vector<int> visited(N);
void reset(int n) {
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        visited[i] = false;
    }
}
// big O(N + M) for dfs
void basic_dfs(int node)
{
    visited[node] = 1;
    for (auto it : adj[node]){
        if(visited[it] == 0)
            basic_dfs(it);
    }
}
int number_of_cc(int start, int end){
    //assuming that nodes numbered from start to end
    int count = 0;
    for (int i = start; i <= end; i++){
        if (visited[i] == 0){
            basic_dfs(i);
            count++;
        }
    }
    return count;
}
bool is_cyclic_undirected(int parent,int node){
    visited[node] = 1;
    for (auto it : adj[node]){
        if(visited[it] == 1 && it != parent)
            return true;
        else if (visited[it] == 0)
            if(is_cyclic_undirected(node, it))
                return true;
    }
    return false;
}
// 0 mean not visited
// 1 mean in progress 
// 2 mean visited
bool is_cyclic_directed(int node){
    visited[node] = 1;
    for (auto i : adj[node]){
        if(visited[i] == 1)
            return 1;
        else if(visited[i] == 0){
            if(is_cyclic_directed(i))
                return 1;
        }
    }
    visited[node] = 2;
    return 0;
}
// dag is a directed acycilc graph
// you need to iterate on all the node 
bool is_DAG(int nodes){
    for (int i = 0; i <= nodes; i++){
        if(visited[i] == 0){
            if(is_cyclic_directed(i))
                return 0;
        }
    }
    return 1;
}
/*
only dag has a vaild topological_sorting means not having circles
sort directed graph based on logical order (who came first)
have to finish x to start y
y depens on x in other word (y -> x)
you have to iterate for all nodes what if there a other cc

note if you are given x -> y (you have to finish x to start y) just do the normal code then reverse the output
*/
void topological_sorting(int node){
    visited[node] = 1;
    for (auto i : adj[node]){
        if(visited[i] == 0)
            topological_sorting(i);
    }
    cout << node << " ";
}
void solve()
{
    int n, m;
    cin >> n >> m;
    //reset(N);
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
}
int main()
{
    // the_forgotten_line
    mr prince;
    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}