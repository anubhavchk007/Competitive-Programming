
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
vector<int> g[200005];
int vis[200005];
 
void dfs(int node){
    vis[node] = 1;
 
    for(auto child : g[node]){
        if(!vis[child])
            dfs(child);
    }
}
 
void anubhav(){
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
 
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    vector<pair<int, int>> a;
    int cnt = 0, prev;
 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            if(cnt >= 1){
                a.push_back(make_pair(prev, i));
            }
            prev = i;
            cnt++;
        }
    }
 
    cout << a.size() << endl;
    for(auto x : a){
        cout << x.first << " " << x.second << endl;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();
 
    return 0;
}
