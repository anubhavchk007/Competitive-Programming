// Anubhav Chakravarty
// 2114074

// ───────▄▀▀▀▀▀▀▀▀▀▀▄▄
// ────▄▀▀░░░░░░░░░░░░░▀▄
// ──▄▀░░░░░░░░░░░░░░░░░░▀▄
// ──█░░░░░░░░░░░░░░░░░░░░░▀▄
// ─▐▌░░░░░░░░▄▄▄▄▄▄▄░░░░░░░▐▌
// ─█░░░░░░░░░░░▄▄▄▄░░▀▀▀▀▀░░█
// ▐▌░░░░░░░▀▀▀▀░░░░░▀▀▀▀▀░░░▐▌
// █░░░░░░░░░▄▄▀▀▀▀▀░░░░▀▀▀▀▄░█
// █░░░░░░░░░░░░░░░░▀░░░▐░░░░░▐▌
// ▐▌░░░░░░░░░▐▀▀██▄░░░░░░▄▄▄░▐▌
// ─█░░░░░░░░░░░▀▀▀░░░░░░▀▀██░░█
// ─▐▌░░░░▄░░░░░░░░░░░░░▌░░░░░░█
// ──▐▌░░▐░░░░░░░░░░░░░░▀▄░░░░░█
// ───█░░░▌░░░░░░░░▐▀░░░░▄▀░░░▐▌
// ───▐▌░░▀▄░░░░░░░░▀░▀░▀▀░░░▄▀
// ───▐▌░░▐▀▄░░░░░░░░░░░░░░░░█
// ───▐▌░░░▌░▀▄░░░░▀▀▀▀▀▀░░░█
// ───█░░░▀░░░░▀▄░░░░░░░░░░▄▀
// ──▐▌░░░░░░░░░░▀▄░░░░░░▄▀
// ─▄▀░░░▄▀░░░░░░░░▀▀▀▀█▀
// ▀░░░▄▀░░░░░░░░░░▀░░░▀▀▀▀▄▄▄▄▄
//
// thak gaya hu vro
// code likhte likhte

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define get(a,n) vi a(n); fr(i,0,n) cin>>a[i];
#define pi M_PI
#define int long long
#define ll long long
#define ul unsigned long long
#define ld long double
#define vi vector <int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>> 
#define vs vector<string>
#define pb push_back
#define pp pop_back
#define fr(var,start,to) for(int var=start; var<to; var++)
#define fr2(var,start,to) for(int var=start; var<=to; var++)
#define fr3(var,start,to) for(int var=start; var>to; var--)
#define google cout<<"Case #"<<i+1<<": ";
#define nn '\n'
#define huehuehue cout<<"huehuehue"<<nn;
#define mine min_element
#define maxe max_element
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define sqrt(x) sqrtl(x)
#define ff first
#define ss second
#define yes cout<<"YES"<<nn
#define no cout<<"NO"<<nn
#define ook(x) order_of_key(x)
#define fbo(x) find_by_order(x)
#define setbits(x) __builtin_popcountll(x)
#define trailzeroes(x) __builtin_ctzll(x)
#define acc accumulate
#define inf 1e18+10
#define MOD 1000000007
#define MOD2 998244353


template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

//////////////////////////// TEMPLATES ////////////////////////////

#define print(x)  pr(x); cout << endl
void     pr(int t) {cout << t;}
void     pr(string t) {cout << t;}
void     pr(char t) {cout << t;}
void     pr(double t) {cout << t;}
void     pr(ul t) {cout << t;}
template <class T, class V> void    pr(pair <T, V> p);
template <class T> void     pr(vector <T> v);
template <class T> void     pr(set <T> v);
template <class T, class V> void     pr(map <T, V> v);
template <class T> void     pr(multiset <T> v);
template <class T> void     pr(stack<T> v);
template <class T> void     pr(list<T> v);
template <class T> void     pr(stack<T> v){while(!v.empty()){    pr(v.top()); cout<<' ' ; v.pop();}}
template <class T> void     pr(list<T> v) {  for(auto i: v){    pr(i);cout << ' ' ;} }
template <class T, class V> void     pr(pair <T, V> p) { cout<<nn;    pr(p.first); cout <<' ';pr(p.second);}
template <class T> void     pr(vector <T> v) {  for (T i : v) {    pr(i); cout<<" ";} }
template <class T> void     pr(set <T> v) {  for (T i : v) {    pr(i); cout << ' ';}  }
template <class T> void     pr(multiset <T> v) {  for (T i : v) {    pr(i); cout << ' ';} }
template <class T, class V> void     pr(map <T, V> v) {  for (auto i : v) {    pr(i); cout <<nn;} }
template <class T, class V> void     pr(unordered_map <T, V> v) {for (auto i : v) {pr(i); cout <<nn;} }
template<class T1, class T2> void pr(map<T1,vector<T2>> m) {for(auto x:m) {cout<<x.F<<"->"; pr(x.S);} cout<<nn;}


bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}



int gcd(int a, int b);
int lcm(int a, int b);
int power(int a, int b);
bool isprime(int n);
bool ispowerof2(int n);
bool sieve(int n);
int mul_inverse(int a, int m);
int power2(int a, int b, int m);
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];}  //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m 



const int N = 1e6+10;
bool prime[N];



void anubhav(){
    int n, sum; cin >> n >> sum;
    get(a, n);

    vi dp(sum + 1);
    dp[0] = 1;
    fr(i, 1, sum + 1){
        fr(j, 0, n){
            if(i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }

    cout << (dp[sum] == inf ? -1 : dp[sum]) << nn;
}





signed main(){
    raftaar
    cout<<fixed<<setprecision(10);
    int t = 1;
    // cin>>t;
    for(int i = 0; i<t; i++){
        // google 
        anubhav();
    }

    return 0;
}







bool sieve(int n){
    if(n<=1) return 0;
    memset(prime,1, sizeof(prime));

    for (int p = 2; p * p <= n; p++){
        if (prime[p] == 1){
            for (int i = p * 2; i <= n; i += p) prime[i] = 0;
        }
    }
    prime[0] = 0, prime[1] = 0;
        if (prime[n]) return true;
        else return false;
}

bool ispowerof2(int n){
    return (n!=0) &&  (!(n & (n-1)));
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int power(int a, int b){
    if(b==0){
        return 1;
    }

    if(b%2==0){
        int t = power(a, b/2);
        return t*t;
    }
    else{
        int t = power(a, (b-1)/2);
        t = t*t;
        return a*t;
    }
}
ll power2(ll a, ll b, ll m){
    if(b==0){
        return 1;
    }

    if(b%2==0){
        ll t = power2(a, b/2, m);
        return t*t % m;
    }
    else{
        ll t = power2(a, (b-1)/2, m);
        t = (t*t)%m;
        return a*t % m;
    }
}

int mul_inverse(int a, int m){
    return power2(a, m-2, m);
}

int introot(int x){
    int ans = sqrtl(x) + 2;
    while(ans*ans > x) ans--;

    return ans;
}

bool isprime(int n)
{
    if (!(n & 1) && n > 2)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
