#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<int> g[200005];
int vis[200005], par[200005];

void anubhav(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) par[i] = -1;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    par[1] = 0;
    vis[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto child : g[node]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                par[child] = node;
            }
        }
    }

    if(par[n] == -1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    int cnt = 0;
    vector<int> a;
    int node = n;
    a.push_back(node);
    do{
        a.push_back(par[node]);
        node = par[node];
    }while(node != 1);

    cout << a.size() << endl;
    reverse(a.begin(), a.end());
    for(auto x : a){
        cout << x << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}