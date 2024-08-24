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
#define the_forgetten_line freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all_list list.begin(), list.end()
#define endl "\n"
#define esle else
using namespace std;
const long long N = 2e6;

bool not_prime[N];
vector<long long> primes;
vector<long long> prime_divisor(N);
void sieves(long long n)
{
    not_prime[0] = 1;
    not_prime[1] = 1;
    for (long long i = 2; i * i <= n; i++)
    {
        if(not_prime[i] == 0){
            prime_divisor[i] = i;
            for (long long j = i * i; j <= n; j += i)
            {
                not_prime[j] = 1;
                prime_divisor[j] = i;
            }
        }
    }
    for (long long i = 0; i <= n; i++)
    {
        if(not_prime[i] == 0)
            primes.push_back(i);
    }
}

vector<long long> divisors_of_number(long long n)
{
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++)
    {
        if(n % i == 0){
            divisors.push_back(i);
            if(i * i != n)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

vector<pair<long long,long long>>prime_factors(long long n){
    vector<pair<long long,long long>> primes;
    for (long long i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if(count > 0)
            primes.push_back({i, count});
    }
    if(n != 1)primes.push_back({n,1});
    return primes;
}

bool is_prime(long long n){
    if(n < 2)
        return 0;
    for (long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int trailling_zeros(long long n){
    int count = 0;
    while (n > 0)
    {
        count += n / 5;
        n /= 5;
    }
    return count;
}

void solve(){
    long long n;
    cin >> n;
    while(n > 1){
        cout << prime_divisor[n] << endl;
        n /= prime_divisor[n];
    }
}

int main(){
    mr prince;
    int tc = 1;
    //cin >> tc;
    sieves(1e6);
    while(tc--){
        solve();
    }
    return 0;
}