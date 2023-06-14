#include "bits/stdc++.h"
using namespace std;

#define int long long

int vis[1005][1005];
int dist[1005][1005];
char dir[1005][1005];

bool isval(vector<string> &a, int i, int j){
    int n = a.size();
    int m = a[0].size();

    return i >= 0 and j >= 0 and i < n and j < m and a[i][j] != '#' and !vis[i][j];
}

void anubhav(){
    int n, m;
    cin >> n >> m;

    int rooti, rootj;
    vector<string> a(n);

    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'A'){
                rooti = i;
                rootj = j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    // cout << rooti << " " << rootj << endl;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};


    queue<pair<int, int>> q;
    q.push(make_pair(rooti, rootj));
    vis[rooti][rootj] = 1;
    dist[rooti][rootj] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // cout << x << " " << y << endl;

        if(a[x][y] == 'B'){
            string s = "";
            while(1){
                s += dir[x][y];

                if(s.back() == 'L') y++;
                if(s.back() == 'R') y--;
                if(s.back() == 'U') x++;
                if(s.back() == 'D') x--;

                if(x == rooti and y == rootj){
                    reverse(s.begin(), s.end());
                    cout << "YES\n" << s.size() << endl << s << endl;
                    return;
                }
            }
        }

        if(isval(a, x + 1, y)) {dir[x + 1][y] = 'D'; q.push(make_pair(x + 1, y)); vis[x + 1][y] = 1; dist[x + 1][y] = dist[x][y] + 1;}
        if(isval(a, x, y + 1)) {dir[x][y + 1] = 'R'; q.push(make_pair(x, y + 1)); vis[x][y + 1] = 1; dist[x][y + 1] = dist[x][y] + 1;}
        if(isval(a, x - 1, y)) {dir[x - 1][y] = 'U'; q.push(make_pair(x - 1, y)); vis[x - 1][y] = 1; dist[x - 1][y] = dist[x][y] + 1;}
        if(isval(a, x, y - 1)) {dir[x][y - 1] = 'L'; q.push(make_pair(x, y - 1)); vis[x][y - 1] = 1; dist[x][y - 1] = dist[x][y] + 1;}

    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}