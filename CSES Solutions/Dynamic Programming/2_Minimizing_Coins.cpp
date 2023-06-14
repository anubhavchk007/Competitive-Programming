// Anubhav Chakravarty
// 2114074

#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

#define get(a,n) vi a(n); fr(i,0,n) cin>>a[i];
#define pi M_PI
#define int long long
#define ll long long
#define ld long double
#define vi vector <int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>> 
#define pb push_back
#define fr(var,start,to) for(int var=start; var<to; var++)
#define fr3(var,start,to) for(int var=start; var>to; var--)
#define google cout<<"Case #"<<i+1<<": ";
#define nn '\n'
#define mine min_element
#define maxe max_element
#define ub upper_bound
#define lb lower_bound
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define sqrt(x) sqrtl(x)
#define ff first
#define ss second
#define yes cout<<"Yes"<<nn
#define no cout<<"No"<<nn
#define inf 1e18+10
#define MOD 1000000007
#define MOD2 998244353


// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// template<class key, class value, class cmp = std::less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

int lcm(int a, int b){return (a / __gcd(a, b)) * b;}
bool isprime(int n){if(!(n & 1) && n > 2) return false; for(int i = 3; i * i <= n; i += 2){ if(n % i == 0) return false;} return true;};
bool ispowerof2(int n){return (n!=0) &&  (!(n & (n-1)));};
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int power(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mul_inverse(int a, int m){return power(a, m - 2, m);};
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];}  //for non prime b
int mminvprime(int a, int b) {return power(a, b - 2, b);}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m 



void anubhav(){
    int n, sum; cin >> n >> sum;
    get(a, n);

    vi dp(sum + 1, inf);
    dp[0] = 0;
    fr(i, 1, sum + 1){
        fr(j, 0, n){
            if(i >= a[j]){
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
            }
        }
    }

    cout << (dp[sum] == inf ? -1 : dp[sum]) << nn;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        // google 
        anubhav();
    }

    return 0;
}