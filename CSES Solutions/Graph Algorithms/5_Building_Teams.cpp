#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<int> g[200005];
int vis[200005], col[200005];

bool isbipartite(int node, int colour){
    vis[node] = 1;
    col[node] = colour;

    for(auto child : g[node]){
        if(!vis[child]){
            if(!isbipartite(child, colour ^ 1))
                return 0;
        }else{
            if(col[child] == col[node]) return 0;
        }
    }

    return 1;
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

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(!isbipartite(i, 0)){
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << col[i] + 1 << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}