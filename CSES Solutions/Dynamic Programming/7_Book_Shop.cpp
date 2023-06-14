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
#define inf 1e9
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



const int N = 1e6+10;
bool prime[N];


void anubhav(){
    int n, x; cin >> n >> x;
    get(price, n);
    get(pages, n);
    vvi dp(n, vi(x + 1, -inf));

    dp[0][0] = 0;
    dp[0][price[0]] = pages[0];

    fr(i, 1, n){
        dp[i][0] = 0;
        fr(j, 0, x + 1){
            dp[i][j] = dp[i - 1][j];

            if(j >= price[i])
            dp[i][j] = max(dp[i][j], pages[i] + dp[i - 1][j - price[i]]);
        }
    }
    int ans = -inf;
    fr(i, 0, x + 1){
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans << nn;
    
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