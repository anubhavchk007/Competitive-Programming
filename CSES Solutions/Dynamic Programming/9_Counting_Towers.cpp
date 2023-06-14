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

using namespace std;


#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define get(a,n) vi a(n); fr(i,0,n) cin>>a[i];
#define pi M_PI
// #define int long long
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
#define MOD2 998244353



int dp[1000001][2];
const int MOD = 1e9 + 7;

void anubhav(){
    int n; cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << nn;
}


signed main(){
    raftaar
    // cout << fixed << setprecision(10);
    dp[1][0] = dp[1][1] = 1;
    fr(i, 2, 1000001){
        int x = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        int y = dp[i - 1][0];
        int z = (2 * dp[i - 1][0]) % MOD;
        int w = dp[i - 1][1];

        dp[i][0] = ((x + y) % MOD + z) % MOD;
        dp[i][1] = (x + w) % MOD;
    }
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        // google 
        anubhav();
    }

    return 0;
}