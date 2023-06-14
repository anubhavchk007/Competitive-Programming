#include "bits/stdc++.h"
using namespace std;

#define int long long
vector<pair<int, int>> g[100005];
int dist[100005], vis[100005];
int n, m;

void dijkstra(int root){
    set<pair<int, int>> s;
    s.insert(make_pair(0, root));
    dist[root] = 0;

    while(!s.empty()){
        int d = s.begin()->first;
        int node = s.begin()->second;

        s.erase(s.begin());

        if(vis[node]) continue;
        vis[node] = 1;

        for(auto child : g[node]){
            if(vis[child.first]) continue;
            if(d + child.second < dist[child.first]){
                dist[child.first] = d + child.second;
                s.insert(make_pair(dist[child.first], child.first));
            }
        }
    }
}

void anubhav(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;

        g[x].push_back(make_pair(y, z));
    }

    for(int i = 1; i <= n; i++) dist[i] = 1e18;

    dijkstra(1);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}