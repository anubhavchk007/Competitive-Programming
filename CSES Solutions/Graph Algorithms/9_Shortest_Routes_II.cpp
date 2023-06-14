#include "bits/stdc++.h"
using namespace std;

#define int long long
int dist[505][505];
int n, m, q;

void anubhav(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 1e18;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;

        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = min(dist[y][x], z);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    while(q--){
        int x, y;
        cin >> x >> y;

        cout << (dist[x][y] == 1e18 ? -1 : dist[x][y]) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}