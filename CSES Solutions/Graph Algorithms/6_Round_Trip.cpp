#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<int> g[200005];
int vis[200005], par[200005];


bool dfs(int node, int parent){
    vis[node] = 1;
    par[node] = parent;

    for(auto child : g[node]){
        if(!vis[child]){
            if(dfs(child, node))
            return 1;
        }else{
            if(child != parent){
                vector<int> a;
                a.push_back(child);
                while(1){
                    a.push_back(node);
                    node = par[node];

                    if(node == child) break;
                }
                a.push_back(child);
                cout << a.size() << endl;
                for(auto x : a){
                    cout << x << " ";
                }
                return 1;
            }
        }
    }
    return 0;
}

void anubhav(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool res = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            res |= dfs(i, 0);
            if(res == 1){
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}