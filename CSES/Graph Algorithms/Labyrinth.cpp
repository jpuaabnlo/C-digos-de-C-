#include <bits/stdc++.h>
using namespace std;
void rec(int x, int y, const vector<vector<tuple<int,int,char>>> &save){
    auto [nx, ny, c] = save[x][y];
    if(nx == -1) return;
    rec(nx, ny, save);
    cout << c;
    return;
}
void solve(){
    int n, m, x1, y1, x2, y2;
    int mx[] = {1,-1,0,0}, my[] = {0,0,1,-1};
    char l[] ={'D', 'U', 'R', 'L'};
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<tuple<int, int, char>>> save(n, vector<tuple<int,int, char>>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A') x1=i, y1=j;
            else if(s[i][j]=='B') x2=i, y2=j;
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({x1, y1, 0});
    vis[x1][y1] = true;
    save[x1][y1] ={-1,-1,'0'};
    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();
        if(x==x2 && y==y2){
            cout << "YES\n" << z << "\n";
            rec(x, y, save);
            cout << "\n";
            return;
        }
        for(int i=0; i<4; i++){
            int nx = x + mx[i], ny = y + my[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny] != '#' && !vis[nx][ny]){
                q.push({nx, ny, z+1});
                vis[nx][ny]=true;
                save[nx][ny] = {x, y, l[i]};
            }
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
