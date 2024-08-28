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
using namespace std;

string ll_to_binary(ll n){
    string binary_number = "";
    while(n > 0){
      binary_number += to_string(n % 2);
      n /= 2;
    }
    reverse(binary_number.begin(), binary_number.end());
    return binary_number;
}
ll fast_pow_two(int k){
  return ((ll)1 << k);
}
bool is_even(ll n){
  return (!(n & (ll)1));
}
bool get_bit(ll n,int k){
  return ((n >> k) & 1);
}
ll to_on(ll n,int k){
  return (n | ((ll)1 << k));
}
ll to_off(ll n, int k){
  return (n & ~((ll)1 << k));
}
ll flip_bit(ll n,int k){
  return (n ^ ((ll)1 << k));
}
int count_ones(ll n){
  // when we & n with n - 1 we off the first on bit
  int count = 0;
  while(n){
    n &= (n - 1);
    count++;
  }
  return count;
}
bool is_pow_of_two(ll n){
  return (!(n & (n - 1)) && n != 0);
}
void solve()
{
  
}
int main() 
{
  //the_forgotten_line
  mr prince;
  int tc = 1;
  //cin >> tc;
  while (tc--)
  {
    solve();
  }
}

