#include <bits/stdc++.h>
using namespace std;
void rec(int x, int y, const vector<vector<tuple<int, int, char>>> &mrk, vector<char> &ans){
    if(get<1>(mrk[x][y])==-1){
        return;
    }
    ans.push_back(get<2>(mrk[x][y]));
    rec(get<0>(mrk[x][y]), get<1>(mrk[x][y]), mrk, ans);
}
void solve(){
    int n, m, x1, y1;
    int mx[] = {1,-1,0,0}, my[] = {0,0,1,-1};
    char c[] = {'D', 'U', 'R', 'L'};
    cin >> n >> m;
    vector<string> s(n);
    vector<char> ans;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<tuple<int, int, char>>> mrk(n, vector<tuple<int,int,char>>(m));
    queue<pair<int, int>> q;
    queue<tuple<int, int, int>> q1; 
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='M'){
                q.push({i,j});
                dp[i][j]=1;
            }
            else if(s[i][j]=='A') x1=i, y1=j;
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        //cout << x << " " << y << "\n";
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + mx[i], ny = y + my[i];
            //cout << "---" << nx << " " << ny << "\n";
            if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]!='#' && dp[nx][ny]==0){
                q.push({nx, ny});
                dp[nx][ny] = dp[x][y]+1;
            }
        }
    }
    /*for(auto x: dp){
        for(auto y: x){
            cout << y <<" ";
        }
        cout << "\n";
    }*/
    q1.push({x1,y1, 1});
    mrk[x1][y1] = {-1,-1,'A'};
    vis[x1][y1] = true;
    while(!q1.empty()){
        auto [x, y, cont] = q1.front();
        //cout << x << " " << y << "\n";
        q1.pop();
        for(int i=0; i<4; i++){
            int nx = x + mx[i], ny = y + my[i];
            //cout << "----" << nx << " " << ny << "\n";
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                rec(x, y, mrk, ans);
                cout << "YES\n" << ans.size() << "\n";
                reverse(ans.begin(), ans.end());
                for(auto x: ans) cout << x;
                cout << "\n";
                return;
            }
            if(s[nx][ny]!='#' && (dp[nx][ny]>cont+1 || dp[nx][ny]==0) && !vis[nx][ny]){
                q1.push({nx, ny, cont+1});
                mrk[nx][ny] = {x, y, c[i]};
                vis[nx][ny]=true;
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