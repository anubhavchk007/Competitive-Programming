#include "bits/stdc++.h"
using namespace std;

#define int long long
int n, m;
string a[1004];
int vis[1005][1005], dist[1005][1005], dist2[1005][1005];
char par[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char dd[] = {'D', 'L', 'U', 'R'};

bool isval(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != '#' && !vis[i][j];
}

void anubhav(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j] = 1e18;
        }
    }

    queue<pair<int, int>> q;
    int row, col;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'M'){
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
            if(a[i][j] == 'A') row = i, col = j;
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(isval(xx, yy)){
                q.push(make_pair(xx, yy));
                vis[xx][yy] = 1;
                dist[xx][yy] = dist[x][y] + 1;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    q.push(make_pair(row, col));
    vis[row][col] = 1;
    dist2[row][col] = 0;



    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(dist2[x][y] >= dist[x][y]) continue;

        if(x == 0 || y == 0 || x == n - 1 || y == m - 1){
            string s = "";
            if(x == row and y == col) goto A;
            while(1){
                s += par[x][y];
 
                if(s.back() == 'L') y++;
                if(s.back() == 'R') y--;
                if(s.back() == 'U') x++;
                if(s.back() == 'D') x--;
 
                if(x == row and y == col){
                    reverse(s.begin(), s.end());
                    A:
                    cout << "YES\n" << s.size() << endl << s << endl;
                    return;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(isval(xx, yy)){
                q.push(make_pair(xx, yy));
                vis[xx][yy] = 1;
                dist2[xx][yy] = dist2[x][y] + 1;
                par[xx][yy] = dd[i];
            }
        }
    }

    cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) anubhav();

    return 0;
}