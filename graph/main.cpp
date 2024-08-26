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

vector<int> adj[N];
bool visited[N];
void basic_dfs(int node)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if(visited[it] == 0)
            basic_dfs(it);
    }
}
int number_of_components(int start, int end){
    //assuming that nodes numbered from start to end
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (visited[i] == 0){
            basic_dfs(i);
            count++;
        }
    }
    return count;
}
bool is_cyclic(int parent,int node){
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if(visited[it] == 1 && it != parent)
            return true;
        else if (visited[it] == 0)
            if(is_cyclic(node, it))
                return true;
    }
    return false;
}
void solve()
{
    
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