#include <bits/stdc++.h>
#define mr ios_base::sync_with_stdio(0);
#define prince cin.tie(0), cout.tie(0)
#define the_forgotten_line freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define all_list list.begin(), list.end()
#define pqueue priority_queue
#define endl "\n"
#define esle else
#define ll long long
using namespace std;
const long long N = 3e5;
const ll INF = 1e18;
vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};

int leader[N];
int sz[N];
void init(int n){
  for (int i = 1; i <= n; i++){
    leader[i] = i;
    sz[i] = 1;
  }
}
int get_leader(int u){
  if(leader[u] == u)
    return u;
  return leader[u] = get_leader(leader[u]);
}
bool are_friends(int u, int v){
  return (get_leader(u) == get_leader(v));
}
void make_friends(int u,int v){
  u = get_leader(u);
  v = get_leader(v);
  if(u != v){
  leader[u] = v;
  sz[v] += sz[u];
  }
}
void solve(){
  int n, m;
  cin >> n >> m;
  init(n);
  while(m--){
    int u, v;
    cin >> u >> v;
    make_friends(u, v);
  }
  cout << *max_element(sz + 1, sz + n + 1) << endl;
}
int main()
{
  // the_forgotten_line
  mr prince;
  int tc = 1;
  cin >> tc;
  while (tc--){
    solve();
  }
}

